#include "cepstral.h"
#include "stdafx.h"
#include "iostream"
#include "fstream"
#include "string"
#include "math.h"
#include "windows.h"
#include <iomanip>
#include <sstream>
#define MAX 8

using namespace std ;
	//tokhura distance initialization in main

//codebbok property
struct cnode{
	long double element[12];
	int index;
} typedef node;	//the node of a code book
node* codebook;
string ToString (int myInt)
{
    ostringstream temp;
    temp<<myInt;
    return temp.str();
}
void load_codebook()
{	
	ifstream inf;
	inf.open("codebook.txt");
	codebook=(node*)malloc(sizeof(node)*MAX);//codebook size memory allocation
	for(int counter=0;counter<MAX;counter++)
	{
		inf>>(codebook+counter)->element[0]>>(codebook+counter)->element[1]>>(codebook+counter)->element[2]>>(codebook+counter)->element[3]>>(codebook+counter)->element[4]>>(codebook+counter)->element[5]>>(codebook+counter)->element[6]>>(codebook+counter)->element[7]>>(codebook+counter)->element[8]>>(codebook+counter)->element[9]>>(codebook+counter)->element[10]>>(codebook+counter)->element[11];
		(codebook+counter)->index=counter;
	}
	inf.close();

	
}
void view_codebook()
{
	for(int counter=0;counter<MAX;counter++)
			{	
				cout<<(codebook+counter)->index<<" : ";
				for(int i=0;i<12;i++)
				{
					
					cout<<setw(10)<<(codebook+counter)->element[i]<<"  ";
				}
				cout<<endl;
			}
}
int indexing(long double* test_ceps)
{
	int w[12];
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
	long double min=0;
	int min_index=0;
	long double sum_temp[MAX]={0,0,0,0,0,0,0,0};
	for(int i=0;i<MAX;i++)
	{
		
		//cout<<"sum : "<<sum_temp<<" <--sum"<<endl;
		for(int j=0;j<12;j++)
		{	
			//cout<<(codebook+i)->element[j]<<" "<<test_ceps[j+1]<<" "<<endl;
			sum_temp[i]+=w[j]*((codebook+i)->element[j]-test_ceps[j])*((codebook+i)->element[j]-test_ceps[j]);
		}
		//cout<<"sum : "<<i<<"  "<<sum_temp[i]<<" <--sum"<<endl;
		if(i==0)
		{
			min=sum_temp[0];
		}
		//cout<<endl;
	}
	for(int i=1;i<MAX;i++)
		if(sum_temp[i]<min)
			{
				min=sum_temp[i];
				min_index=i;
			}
	
	//cout<<"one done"<<endl;
	return min_index;
}
void quantize()
{
	ifstream inputtest;
	inputtest.open("final_ceps.txt");
	ofstream opf;
	opf.open("obs_seq.txt");
	if(!opf)
	{
		cerr<<"Cant open file to crop";
		return;
	}
	long double test_ceps[12];
	while(!inputtest.eof())
	{
		int r_ind=0;
		for(int i=0;i<12;i++)
		{
		
			inputtest>>test_ceps[i];
			//cout<<test_ceps[i]<<" ";
		
		}
		cout<<endl;
		r_ind=indexing(test_ceps);
		opf <<r_ind<<endl;
		cout<<r_ind<<" ";
	}
	inputtest.close();
	opf.close();
}