#include "hmm.h"

#include "stdafx.h"
// hmm_prob3.cpp : Defines the entry point for the console application.
//
#include<iostream>
#include "fstream"
#include "string"
#include "math.h"
#include "windows.h"
#include <time.h>
#include "list"
#include <iomanip>
#include <iterator>
#include <conio.h>
#include <cmath>
#include <sstream>
#include "cepstral.h"
#include "codebook.h"

using namespace std;
#define N 5
#define M 8
#define T_max 161
/*
long double a[N][N];
long double b[N][M];
long double pi[N];
int o[T];*/
long double a[N][N] = {{0.9,0.1,0,0,0},{0,0.9,0.1,0,0},{0,0,0.9,0.1,0},{0,0,0,0.9,0.1},{0,0,0,0,1}};//{{0.5,0.1,0.1,0.1,0.2},{0.1,0.5,0.1,0.1,0.2},{0.1,0.2,0.5,0.1,0.1},{0.2,0.1,0.1,0.5,0.1},{0.6,0.1,0.1,0.1,0.1}}; //state transition matrix (NxN)
long double b[N][M] = {{.125,.125,.125,.125,.125,.125,.125,.125},{.125,.125,.125,.125,.125,.125,.125,.125},{.125,.125,.125,.125,.125,.125,.125,.125},{.125,.125,.125,.125,.125,.125,.125,.125},{.125,.125,.125,.125,.125,.125,.125,.125},}; //{{0.246,0.004,0.12,0.13,0.11,0.14,0.19,0.06},{0.12,0.13,0.125,0.125,0.125,0.125,0.125,0.125},{0.125,0.125,0.125,0.125,0.125,0.125,0.125,0.125},{0.125,0.125,0.125,0.125,0.125,0.125,0.125,0.125},{0.125,0.125,0.125,0.125,0.125,0.125,0.125,0.125}}; //observation symbol probablity distribution(NxM)
long double pi[N] ={1,0,0,0,0}; //{.1,.2,.3,.3,.1}; //initial state distribution (N)
int o[T_max]={0};
long double alp[N][T_max] = {0};// alpha matrix
long double beta[N][T_max] = {0};//beta matrix
long double gamma[N][T_max] = {0};//gamma matrix
long double del[N][T_max] = {0};//delta
int si[N][T_max]={0};//si matrix
int qs[T_max]={0};//q* matrix
long double xi[T_max][N][N]={0};//3D xai matrix
int T;
ofstream outA;
int w[12];
string link,folder;//link=filename,folder=from where to read
int limit;//no of files
void runtime_VQ()
{
	w[0]=1;//these are tokhura weights given by sir
	w[1]=3;
	w[2]=7;
	w[3]=13;
	w[4]=19;
	w[5]=22;
	w[6]=25;
	w[7]=33;
	w[8]=42;
	w[9]=50;
	w[10]=56;
	w[11]=61;
	//system("..\\Recording_Module.exe 3 ..\\test.wav ..\\test.txt");
	dcshift(link);
	normalize("dcshift.txt");
	croping("normalize.txt");
	remove("normalize.txt");
	remove("dcshift.txt");
	/*system("..\\Recording_Module.exe 3 ..\\test.wav ..\\test.txt");*/
	
	int p;
	long double arr[320];
	cout<<"init";
	ifstream inf;
	load_codebook();
	string filename= "test_cropped";
		inf.open(filename+".txt");//openig trimmed file
		ofstream of;
		of.open("final_ceps.txt");//opening a file to store cepstral	
		for(int i=0;i<320;i++)
		{
			//store first  320 samples in array
			inf>>arr[i];
		}
		cout<<"init";
		while(1)
		{	
			for(int n=0;n<320;n++)
			{
				arr[n]=arr[n]*(0.54-.46*cos(2*3.1415*n/319));//applying hamming window
			}
			long double *r=new long double[13];
			r=autocor(arr);	
			long double *a=new  long double[13];
			a=lpccoef(r);
			long double *c=new long double[13];
			c=cepstral_cal(a);
			for(int m=1;m<=12;m++)
			{
				c[m]=c[m]*(1+6*sin((3.1415*m)/12));//parameter weighting
			}
			of<<c[1]<<" "<<c[2]<<" "<<c[3]<<" "<<c[4]<<" "<<c[5]<<" "<<c[6]<<" "<<c[7]<<" "<<c[8]<<" "<<c[9]<<" "<<c[10]<<" "<<c[11]<<" "<<c[12]<<endl;
			for(int i=0;i<240;i++)
			{
				arr[i]=arr[i+80];//shift 80 samples back ward and store 80 samples more from file to array
			}
			for(int i=0;i<80;i++)
			{
				if(inf.eof()) break;
				inf>>arr[240+i];	//shifting to 80 samples of next frame
			}
			if(inf.eof()) break;
		//	cout<<"frame"<<endl;
		}
		of.close();	
		inf.close();
		quantize();
}

string IntToString (int myInt)
{
    ostringstream temp;
    temp<<myInt;
    return temp.str();
}
long double forword( )
{
	//cout<<endl<<"VALUE IN ALPHA MATRIX"<<endl<<endl;
	//initialization of alpha[N][T]
	for(int i=0 ; i<N ; i++)
	{
		alp[i][0] = (pi[i]*b[i][0]);	//intial alpha value is start state probablity multiplied by observing first output on that state
		//cout<<"sum i o :"<<alp[i][0]<<endl;
	}
	//induction steps::
	for(int t = 0; t<T-1 ;t++)
	{	
		
		//long double sum=0;//caculating inner sum
		for( int j = 0; j<N ;j++)
		{
			long double sum_t=0;
			for( int i = 0; i<N ;i++)
				sum_t += alp[i][t]*a[i][j];//multiplying alpha with a matix at time t
			
			
			alp[j][t+1]=sum_t*b[j][o[t+1]];//multiplying output symbol probablity with sum 
			//cout<<setw(15)<<alp[j][t+1]<<" ";
			//cout<<"sum :"<<alp[j][t+1]<<endl;
		}
		//cout<<endl;
	}
	// terminating probablity
	long double sum = 0;
	for(int i = 0; i<N ; i++)
	{
		sum+=alp[i][T-1];//summing all up
	}
	
	return sum ;
}
void backword( )
{
	cout<<endl<<"VALUE IN BETA MATRIX"<<endl<<endl;
	//initialization
	for( int i = 0; i<N ; i++)
	{
		beta[i][T-1] = 1;
	}

	//induction
	for( int t = T-2; t>=0; t--)
	{
		for(int i = 0; i < N ; i++)
		{
			long double sum=0;
			for( int j = 0; j< N ; j++)
			{
				sum+=(a[i][j]*b[j][o[t+1]]*beta[j][t+1]);
			}
			beta[i][t]=sum;
			cout<<setw(15)<<beta[i][t]<<" ";
			//cout<<"beta :"<<sum<<endl;
		}
		cout<<endl;
	}
	
}
void gamma_matrix( )
{
	cout<<endl<<"VALUE IN GAMMA MATRIX"<<endl<<endl;
	for( int t = 0 ;t < T ; t++)
	{
		long double d=0;
		//suming value for denomiator
		for( int i = 0; i<N ; i++)
		{
			d+=alp[i][t]*beta[i][t];
		}
		for( int j = 0; j<N ; j++)
		{
			gamma[j][t]=(alp[j][t]*beta[j][t])/d;
			//cout<<setw(15)<<gamma[j][t]<<" ";
		}
		//cout<<endl;
	}
	
}
void viterbi()
{
	cout<<endl<<"_______________________________VALUE IN DELTA MATRIX________________________________"<<endl<<endl;
	//initialization
	for(int i = 0;i<N;i++)
	{
		del[i][0] = (pi[i]*b[i][o[1]]);
		si[i][0] = 0; 
	}
	//recursion
	for(int t = 1;t<T;t++)
	{
		for(int j=0;j<N;j++)
		{
			long double max_val=del[0][t-1]*a[0][j];
			int max_index=0;
			for(int i=1;i<N;i++)
			{
				if(del[i][t-1]*a[i][j]>max_val)
				{
					max_val=del[i][t-1]*a[i][j];
					max_index=i;
				}
			}
			del[j][t]=max_val*b[j][o[t]];
			si[j][t]=max_index;
		}
	}
/*	for(int t = 1;t<T;t++)
	{
		for(int j=0;j<N;j++)
		{
		 cout<<setw(12)<<del[j][t]<<"     ";
		}
		cout<<endl;
	}
	
	*/

}
long double pstar()
{
	long double max=0;
	for(int i=0;i<N;i++)
		if(del[i][T-1]>max)
		{
			max=del[i][T-1];		//p* matrix
			//index=si[i][T-1];
		}
	return max;
}
int qstar()
{
	int index=0;
	long double max=0;
	for(int i=0;i<N;i++)
		if(del[i][T-1]>max)
		{
			max=del[i][T-1];
			index=si[i][T-1];	//q star matrix
		}
	return index;
}
void backtrack(int q)
{	
	qs[T-1]=q;
	for(int t= T-2;t>=0;t--)
	{
		qs[t]=si[qs[t+1]][t+1];		
	}
	for(int t= 0;t<=T-2;t++)
	{
		cout << " "<<qs[t]<<" ";
	}
	cout<<endl;
	for(int t= 0;t<=T-2;t++)
	{
		cout << " "<<o[t]<<" ";
	}
}
void xi_matrix()
{
	//cout<<"################# New XI Matrix"<<endl;
for(int t=0;t<T-1;t++)
{
		long double sum=0;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			sum+=alp[i][t]*a[i][j]*b[j][o[t+1]]*beta[j][t+1];
			
		}
		//cout<<"sum ::"<<sum<<endl;
	}
	if(sum!=0)
	{
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)
			{
				xi[t][i][j]=(alp[i][t]*a[i][j]*b[j][o[t+1]]*beta[j][t+1])/sum;
				//cout<<"  ";
				//cout<<setw(15)<<xi[t][i][j];
			}
			//cout<<endl;
		}
	}
}
}
void reest_gamma()
{
	for(int t=0;t<T-1;t++)
		{
			for(int i=0;i<N;i++)
			{
				for(int j=0;j<N;j++)
				{
					gamma[i][t]=0;
				}
			}
		}
	//cout<<"################# New GAMMA Matrix"<<endl;
		for(int t=0;t<T-1;t++)
		{
			for(int i=0;i<N;i++)
			{
				for(int j=0;j<N;j++)
				{
					gamma[i][t]+=xi[t][i][j];
				}
				//cout<<""<<setw(15)<<gamma[i][t];
			}
			//cout<<endl;
		}

}
void reest_pi()
{
	cout<<endl<<"________________________ PI vlues_______________________";
	for(int i=0;i<N;i++)
	{
		pi[i]=gamma[i][0];
		cout<<setw(15)<<pi[i]<<" ";
	}
	cout<<endl<<endl;

}
void reest_A()
{
	cout<<"________________ New  A Matix___________________"<<endl;
	
for(int i=0;i<N;i++)
{
	long double denominator=0;
	for(int t=0;t<T-1;t++)
	{
		denominator+=gamma[i][t];
	}
	for(int j=0;j<N;j++)
	{
	
		long double numerator=0;
		for(int t=0;t<T-1;t++)
		{
			numerator+=xi[t][i][j];
		}
		a[i][j]=numerator/denominator;
		cout<<" "<<setw(15)<<a[i][j];
		outA<<a[i][j]<<" ";
	}
	outA<<endl;
	cout<<endl;
}
outA<<"__________________________________________________"<<endl;
}
void adjust_B_matrix()
{
	long double val = pow(10.00,-50);
	int count = 0;
	for(int j = 0 ; j < N ; j++)
	{
		int max_b = 0;
		for(int k = 0 ; k < M ; k++)
		{
			if(b[j][k]>b[j][max_b])
			{
				max_b = k;
			}
			if(b[j][k]==0)
			{
				count++;
				b[j][k] = val;
			}
		}
		b[j][max_b] -= count*val;
	}
}
void show_A()
{
	cout<<"______________   A Matix________________"<<endl;
	for(int j = 0 ; j < N ; j++)
	{
		for(int k = 0 ; k < N ; k++)
		{
			cout<<setw(15)<<a[j][k];
		}
		cout<<endl;
	}
}
void show_pi()
{
	cout<<"______________   Pi Matix________________"<<endl;
		for(int k = 0 ; k < N ; k++)
		{
			cout<<setw(15)<<pi[k];
		}
		cout<<endl;
	
}
void show_B()
{
	cout<<"______________   B Matix________________"<<endl;
	for(int j = 0 ; j < N ; j++)
	{
		for(int k = 0 ; k < M ; k++)
		{
			cout<<setw(15)<<b[j][k];
		}
		cout<<endl;
	}
}
void reest_B()
{
	cout<<"______________ New  B Matix________________"<<endl;

	for(int j=0;j<N;j++)
	{
		long double sum=0;
		for(int k=0;k<M;k++)
		{
	
			long double numerator=0,denominator=0;
			for(int t=0;t<T-1;t++)
			{
				if(o[t]==k)
				{
					numerator+=gamma[j][t];
				}
			denominator+=gamma[j][t];
			}
			b[j][k]=numerator/denominator;
			//sum+=b[j][k];
		}
		
	}
	adjust_B_matrix();
	show_B();
}
void store_log_file()
{
	string log_file;
	ofstream output_log;
	cout<<"Input log file name :";
	cin>>log_file;
	output_log.open("..//log_file//"+log_file+".txt");
	for(int t= 0;t<=T-2;t++)
	{
		output_log <<qs[t]<<" ";
	}
	output_log<<endl;
	for(int t= 0;t<=T-2;t++)
	{
		output_log<<o[t]<<" ";
	}
	output_log.close();
}
void store_model(string model_path)
{
	ofstream output_model;
	output_model.open(model_path);
	for(int i= 0;i<N;i++)
	{
		output_model <<pi[i]<<"  ";
	}
	output_model<<endl;
	for(int i = 0; i < N ;i++)
	{
		for(int j = 0; j < N; j++)
		{
			output_model<<a[i][j]<<" ";
		}
			output_model<<endl;
	}
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			output_model<<b[i][j]<<" ";
		}
			output_model<<endl;
	}
	
	output_model.close();
}
void set_all_to_zero()
{
	for(int i= 0;i<N;i++)
	{
		pi[i]=0;
	}
	for(int i = 0; i < N ;i++)
	{
		for(int j = 0; j < N; j++)
		{
			a[i][j]=0;
		}
	}
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			b[i][j]=0;
		}
	}
}
void averaging_model(int no_of_model)
{
	//int no_of_model=0;
	//cout<<"No of models :";
	//cin>>no_of_model;
	
	for(int digit=0;digit<10;digit++ )
		{
			set_all_to_zero();
			for(int iterator=no_of_model;iterator>0;iterator--)
			{
				string filename= IntToString(digit)+"_"+IntToString(iterator);
				ifstream input_model;
				input_model.open("..//model_file//"+filename+".txt");
				long double temp=0;
				for(int i= 0;i<N;i++)
				{
					input_model >>temp;
					pi[i]+=temp;
				}
		
				for(int i = 0; i < N ;i++)
				{
					for(int j = 0; j < N; j++)
					{
						input_model >>temp;
						a[i][j]+=temp;
					}
				}
				for(int i = 0; i < N; i++)
				{
					for(int j = 0; j < M; j++)
					{
						input_model >>temp;
						b[i][j]+=temp;
					}
			
				}
				show_A();
				show_B();
				show_pi();
				input_model.close();
			}
		
		for(int i= 0;i<N;i++)
		{
			pi[i]=pi[i]/no_of_model;
		}
		
		for(int i = 0; i < N ;i++)
		{
			for(int j = 0; j < N; j++)
			{
				a[i][j]=a[i][j]/no_of_model;
			}
		}
		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < M; j++)
			{
				b[i][j]=b[i][j]/no_of_model;
			}
			
		}
		show_A();
		show_B();
		show_pi();
		store_model("..//final//"+IntToString(digit)+".txt");
	}
}
void load_model(int model_no)
{
		ifstream input_model;
		input_model.open(folder+IntToString (model_no)+".txt");
		long double temp=0;
		for(int i= 0;i<N;i++)
		{
			input_model >>temp;
			pi[i]=temp;
		}
		
		for(int i = 0; i < N ;i++)
		{
			for(int j = 0; j < N; j++)
			{
				input_model >>temp;
				a[i][j]=temp;
			}
		}
		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < M; j++)
			{
				input_model >>temp;
				b[i][j]=temp;
			}
			
		}
		//show_A();
		//show_B();
		//show_pi();
		input_model.close();
	
}
void flush_alp_beta()
{
	for(int i=0;i<N;i++)
			for(int j=0;j<T_max;j++)
				{
					beta[i][j]=0;
					alp[i][j]=0;
				}
	
}
int testing_model()
{
	ifstream input_obs;
	int testing_digit=9;
	int testing_utter=3;
	//string myfile=IntToString (testing_digit)+"_"+IntToString (testing_utter) ;
	string myfile="obs_seq";
	input_obs.open(myfile+".txt");
	int Tval=0;
	while(!input_obs.eof())
	{
		input_obs>>o[Tval];
		//cout<<o[Tval]<<" ";
		Tval++;
	}
	cout<<endl;
	if(Tval>160)
		Tval=160;
	T=Tval;
	long double minimum=0;
	int minimum_index=0;
	for(int i=1;i<=limit;i++)
	{
		set_all_to_zero();
		load_model(i);
		//flush alp values
		flush_alp_beta();
		long double prob;
		prob = forword();
		if(prob>minimum)
		{
			minimum=prob;
			minimum_index=i;
		}
			/*for(int i=0;i<N;i++)
			{
				for(int j=0;j<T;j++)
					cout<<alp[i][j]<<" ";
				cout<<endl;
			}*/
			
		cout<<"probablity of being "<<i<<" is "<<prob<<endl;
		
	}
	cout<<"Digit is :"<<minimum_index<<endl;
	return minimum_index;
}
void re_initialize_A_B_pi(int digit)
{
	string filename=IntToString(digit);
	ifstream input_model;
	input_model.open("final//"+filename+".txt");
	long double temp;
		for(int i= 0;i<N;i++)
		{
			input_model >>temp;
			pi[i]=temp;
		}
		
		for(int i = 0; i < N ;i++)
		{
			for(int j = 0; j < N; j++)
			{
				input_model >>temp;
				a[i][j]=temp;
			}
		}
		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < M; j++)
			{
				input_model >>temp;
				b[i][j]=temp;
			}
			
		}
		
}
void retraining_model()
{
	
		for(int digit=0;digit<10;digit++)
		{	
			
			for(int utter_no=1;utter_no<=15;utter_no++)
			{
				re_initialize_A_B_pi(digit);
			flush_alp_beta();
			string filename= IntToString(digit)+"_"+IntToString(utter_no);
				outA.open("..//Alog.txt");
				ifstream input_obs;
				input_obs.open("..//quantized//"+filename+".txt");
				int Tval=0;
				while(!input_obs.eof())
				{
					input_obs>>o[Tval];
					Tval++;
				}
				input_obs.close();
				T=Tval;
				long double prob;// probablity of problem 1
				prob = forword();// forword matrix fromulation
				cout<<"prob 1 :"<<prob<<endl;
				cout<<endl;
				backword();// backword matrix beta formulation
				cout<<endl;
				gamma_matrix();
				viterbi();
				long double p = pstar();
				int q= qstar();
	
				for(int i=0;i<20;i++)
				{
					store_model("..//model_file//"+filename+".txt");
					xi_matrix();
					reest_gamma();//new gamma matrix
					reest_pi();//new Pi matrix
					reest_A();//new A matrix
					reest_B();//new B_matrix
					viterbi();
					
					long double p_new = pstar();
					cout<<"P star : at loop no :"<<i<<" is "<<p_new<<endl;
					q= qstar();
					backtrack( q);
					if(p_new<p)
					{
						//store_log_file();
						break;
					}
					p=p_new;
					cout<<"NoW HMM Hero is doing training, push up no :"<<filename;
				}
				//remove("..//model_file//"+filename+".txt");
				//store_model("..//model_file//"+filename+".txt");
			}
		}
}
void initialize_A_B_pi()
{
	for(int i= 0;i<N;i++)
	{
		pi[i]=0;
		if(i==0)
			pi[i]=1;
	}
	for(int i = 0; i < N ;i++)
	{
		for(int j = 0; j < N; j++)
		{
			a[i][j]=0;
			if(i==j)
			{
				a[i][j]=.9;
				if(i==N-1)
					a[i][j]=1;
			}
			if(i==j-1)
			{
			a[i][j]=0.1;
			}
			
		}
	}
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			b[i][j]=.125;
		}
	}
}
int testing(int sec)
{
	if(sec==1)
	{
		link="test1.txt";
		folder="subs//";
		limit=3;
	}
	else
	{
		link="test2.txt";
		folder="final//";
		limit=8;
	}

	//vector_quantize(); 
	/*for(int utter_no=1;utter_no<=15;utter_no++)
		for(int digit=0;digit<10;digit++)
		{
			flush_alp_beta();
			initialize_A_B_pi();
			string filename= IntToString(digit)+"_"+IntToString(utter_no);
				outA.open("..//Alog.txt");
				ifstream input_obs;
				input_obs.open("..//quantized//"+filename+".txt");
				int Tval=0;
				while(!input_obs.eof())
				{
					input_obs>>o[Tval];
					Tval++;
				}
				input_obs.close();
				T=Tval;
				long double prob;// probablity of problem 1
				prob = forword();// forword matrix fromulation
				cout<<"prob 1 :"<<prob<<endl;
				cout<<endl;
				backword();// backword matrix beta formulation
				cout<<endl;
				gamma_matrix();
				viterbi();
				long double p = pstar();
				int q= qstar();
	
				for(int i=0;i<20;i++)
				{
					store_model("..//model_file//"+filename+".txt");
					xi_matrix();
					reest_gamma();//new gamma matrix
					reest_pi();//new Pi matrix
					reest_A();//new A matrix
					reest_B();//new B_matrix
					viterbi();
					
					long double p_new = pstar();
					cout<<"P star : at loop no :"<<i<<" is "<<p_new<<endl;
					q= qstar();
					backtrack( q);
					if(p_new<p)
					{
						//store_log_file();
						break;
					}
					p=p_new;
					cout<<"NoW HMM Hero is doing training, push up no :"<<filename;
				}
				//store_model("..//model_file//"+filename+".txt");
		}*/
	//cout<<"Hero need re training "<<endl;
	//retraining_model();
	cout<<"Hero is ready for battle";
	//averaging_model(15);
	runtime_VQ();
	outA.close();
	return testing_model();
	 
	// prob = forword();// forword matrix fromulation
	//cout<<"prob 1 :"<<prob<<endl;
	//system("pause");
	//return 0;
}

