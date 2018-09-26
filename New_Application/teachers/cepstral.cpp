//#include "cepstral.h"
//#include "iostream"
// levinson_durbin.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "fstream"
#include <string>
#include "math.h"
#include "windows.h"

using namespace std ;
void dcshift(std:: string s)
{
	
	ifstream inf;
	inf.open(s);
	if(!inf)
	{
		cerr<<"Unable to open in normalization file";
		exit(1);
	}
	int shift=0,count=0;
	while(!inf.eof())
	{	
		int val;
		inf>>val;
		shift=shift+val;		//counting total shift
		count++;
	}
	shift=shift/count;			//averaging total shift
	inf.close();
	inf.open(s);
	ofstream outf;
	outf.open("dcshift.txt");
	if(!outf)
	{
		cerr<<"Unable to open in out shift file";
		exit(1);
	}
	
	int x;
	while(!inf.eof())
	{
		
		inf>>x;						//subtracting dc shift
		x=x-shift;
		outf<<x<<endl;
	}
	outf.close();
	inf.close();

}
void normalize(string s)
{
	ifstream inf;
	inf.open(s);
	if(!inf)
	{
		cerr<<"Unable to open in normalization file";
		exit(1);
	}
	int max;
	inf>>max;
	int x;
	while(!inf.eof())
	{	
	
		inf>>x;
		if(max < abs(x))
			max=abs(x);					//maximum counting for normalization
	}
	float norm=(5000.00/(float)max);			//calculating the fraction
	inf.close();
	inf.open(s);
	ofstream outf;
	outf.open("normalize.txt");
	if(!outf)
	{
		cerr<<"Unable to open in out shift file";
		exit(1);
	}
	
	float y;
	while(!inf.eof())
	{
		
		inf>>y;
		y=y*norm;
		outf<<y<<endl;
	}
	inf.close();
	outf.close();
}
void croping(string str)
{
//average count of each 100 samples
	ifstream filein;
	filein.open(str);
	if(!filein)
	{
	cerr<<"Cant open file to crop";
	return;
	}
	//cout<<"Into crop "<<endl;
	double i=0,j=0,ptr1=0,prev=0,ptr2=0,ptr3=0,maxspanptr=0,maxspan=0,span=0;
	int k;
	float sum;
	float p=0,n;
	while(!filein.eof())
	{	
		k=0;
		sum=0;
		int zcr=0;

		float y=0;
		while(k<300 && !filein.eof())
		{
			
			filein>>y;
			n=y;
			if((p>0)&&(n<=0)||(p<0 && n>=0))				//zcr count for 100 samples each returnnig the number of counts in output set
				zcr++;
			p=n;
			sum=sum+abs(y);
			j++;
			k++;
		}
		p=y;
		sum=sum/k;

	/*	if(prev==1)
			{
				if(sum>150 || (sum>50  && zcr>30))		//counting first part for normal energy second part for zcr high >23
				{
					ptr2=ptr2+400;
				}
				else
				{
					if(maxspan<(ptr2-ptr1))
					{
						maxspan=ptr2-ptr1;
						maxspanptr=ptr1;				//taking the max spam of information content
					}
				}

			}
		else{
		
				if(sum>80)
				{
					prev=1;
					ptr1=j-1;
				}
				else
				{
					ptr1=ptr1+100;
					ptr2=ptr1;
				}

			}*/
		if(prev==0)
		{
			if(sum>100 && zcr>20)
			{
				prev=1;
				ptr1=j-1;
				ptr2=ptr1;
			}
		}
		else
		{
			if(sum>300)
			{
				ptr2=ptr2+300;
				span=0;
			}
			else if(span<20)
			{
				if(span==0)
				{
					ptr3=ptr2;
					
				}
				span++;				
				ptr2+=300;
			}
			else
			{
				if(maxspan<(ptr3-ptr1))
				{
					
					maxspanptr=ptr1;
					maxspan=ptr3-ptr1;
					ptr1=ptr2=ptr3=0;
					prev=0;
				}
				
			}
		}
	}

	filein.close();
	ofstream fileout;
	fileout.open("test_cropped.txt");
	filein.open(str);
	double m=0;
	string line;
	while(m<maxspanptr-400)
	{
		getline(filein,line);
		m++;

	}
	while(m<(maxspanptr+maxspan+2000))
	{
	float x;
	filein>>x;
	fileout<<x<<endl;
	m++;
	}
	filein.close();
	fileout.close();

}
void trim()
{	
	//apply dc shift and normalization
	//triming data for 5 frames
	long i=1,j=0;
	int max;
	ifstream inf;
	inf.open("file.txt");//opening file
	inf>>max;
	int temp;
	while(!inf.eof())
	{
		inf>>temp;
		if(temp>max)
		{
		max=temp;	//calculating maximum amplitude
		j=i;
		}
		i++;
	}
	inf.close();
	inf.open("file.txt");
	ofstream of;
	of.open("temp.txt");//storing max 640 samples for 5 frames in temp.txt fail
	j=j-320;
	i=0;
	
	while(1)
	{
		inf>>temp;
		if(i==j)
		{
		while(i<=j+640)
			{
				of<<temp<<endl;
				inf>>temp;
				i++;
			}
		break;
		}
		i++;
	}
	inf.close();
	of.close();

}
long double* autocor(long double *arr )
{	//autocorrelation method value calculation
	long double *r=new long double[13];
	for(int k=0;k<=12;k++)
	{
		long double sum=0,cal=arr[0];

		for(int i=0;i+k<320;i++)
		{	
			cal=(arr[i])*(arr[i+k]);
			sum=sum+cal;
			
		}
		r[k]=sum;
	}
	return r;
}
 long double* lpccoef(long double* r)
{	//lpc value calculation for a[i] returning lpc
	int p=12;
	long double *lpc=new  long double[12];
	long double *tmp=new  long double[12];
	long double e;
	e=r[0];
	lpc[0]=1;
	for(int i=1;i<=p;i++)
	{	
		long double k=0;
		for(int j=1;j<i;j++)
		{
			k=k+lpc[j]*r[i-j];
		}
		k=(r[i]-k)/e;
		lpc[i]=k;
		for(int j=1;j<i;j++)
			tmp[j]=lpc[j]-k*lpc[i-j]; 
		for(int j=1;j<i;j++) 
			lpc[j]=tmp[j]; 
		e=(1-k*k)*e;

	}
	return lpc;
}
long double* cepstral_cal(long double *a)
 {	//cepstral values calculation c[i]
	 int p=12;
	 int q=18;
	 long double *c=new long double[18];
	 c[0]=1;
	 for(int m=1;m<=p;m++)
		 {
 
			 long double sum=0;
			 float f;
			 for(int k=1;k<=m-1;k++)
			 {
				f=(float)k/m;
				sum=sum+f*a[m-k]*c[k];

			 }
			 c[m]=a[m]+sum;
		 }
	 return c;
 }
 


