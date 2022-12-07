#include <iostream>
using namespace std;
int main(){
	int n,i,j,k;
	//Size of matrix
        cin>>n;
        //Init matrices of given size
        int d[n][n];
        int p[n][n];
        //Initialize all elements of p to zero
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                p[i][j]=0;
                
            }
        }
        //Fill values of matrix a and p matrix
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                cin>>d[i][j];
                if(i!=j && d[i][j]<10000000){
                	p[i][j]=i+1;
                }
            }
        }
        //Run Floyd Warshall Over the matrices
        for(k=0;k<n;k++)
        {
            for(i=0;i<n;i++)
            {
                for(j=0;j<n;j++)
                {
                	if(d[i][j]<=d[i][k]+d[k][j]){
                		d[i][j]=d[i][j];
                		p[i][j]=p[i][j];
                	}
                	else{
                		d[i][j]=d[i][k]+d[k][j];
                		p[i][j]=p[k][j];
                	}}}}
        //Print Matrices
        
        cout<<endl<<"Printing Matrix d"<<endl;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(d[i][j]==10000000)
                cout<<"INF ";
                else
                cout<<d[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl<<"Printing Matrix p"<<endl;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(p[i][j]==0)
                cout<<"NIL ";
                else
                cout<<p[i][j]<<" ";
            }
            
            cout<<endl;
        }
	return 0;
}
