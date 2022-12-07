#include<iostream>
using namespace std;
int x[1000];
int subset[1000]={5,10,12,13,15,18} ;
void sum_of_subset(int s,int k,int r,int m,int n)
{
	x[k]=1;
        if(s+subset[k]==m)
        {
        	cout<<endl;
               for(int i=0;i<n;i++)
               {
               if(x[i]==1) 
               printf("%d \t",subset[i]);}}
               else if((s+subset[k]+subset[k+1])<=(m))
               sum_of_subset(s+subset[k],k+1,r-subset[k],m,n);
               if((s+r-subset[k]>=m)&&(s+subset[k+1]<=m))
               {x[k]=0;sum_of_subset(s,k+1,r-subset[k],m,n);
        }           
}                  

int main()
{	int i,n=6,sum,m;
	//int n,i;
	//Enter Number of Elements
	//cin>>n;
	//int op[n],sub1[n],sum=0;
	for(i=0;i<n;i++){sum=sum+subset[i];}	
//	for(i=0;i<n;i++){cin>>sub1[i];sum=sum+subset[i];}
	//Enter Target to search for
	//cin>>m;
	cout<<sum;
	sum_of_subset(0,0,sum,30,n);
//	cin>>n;
//	sum=0;
//	for(i=0;i<n;i++){cin>>subset[i];sum=sum+subset[i];}
//	for(i=0;i<n;i++){cout<<subset[i];}
	//sum_of_subset(0,0,sum,m);
}
