#include <iostream>
using namespace std;
#define VLNUM 10000000
int m[100][100],s[100][100],p[100],i,j,n,q,k;
void genMatrices(){
    cout<<"Number of matrices: ";
    cin>>n;
    for(i=1;i<=n;i++){
        for(j=i+1;j<=n;j++)
        {
            m[i][i]=0;
            m[i][j]=VLNUM;
            s[i][j]=0;
        }
    }
}
void takeIP(){
    cout<<endl<<"Enter dimensions of matrices: "<<endl;
    for(i=0;i<=n;i++){cout<<"P"<<i<<": ";cin>>p[i];}
}
void getMSMatrices()
{
for(i=n;i>0;i--)
    {
        for(j=i;j<=n;j++)
        {
            if(i==j) m[i][j]=0;
            else
            {
                for(k=i;k<j;k++)
                {
                    q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                    if(q<m[i][j])
                    {
                        m[i][j]=q;
                        s[i][j]=k;
                    }
                }
            }
        }
    }
}
void printSMatrix(){
    // Example ordering of elements
    // 1,4
    // 1,3 
    // 2,4
    // 1,2
    // 2,3
    // 3,4
    // 1,1
    // 2,2
    // 3,3
    // 4,4
    cout<<endl<<"Matrix S:"<<endl<<endl;
    for(i=1;i<n;i++){
        for(j=1;j<i+1;j++){
            cout<<s[j][abs(j-i+n)]<<"\t\t";
        }
        cout<<endl;
    }
}
void printMMatrix(){
    cout<<endl<<"Matrix M:"<<endl<<endl;
    for(i=1;i<=n;i++){
        for(j=1;j<i+1;j++){
            cout<<m[j][abs(j-i+n)]<<"\t\t";
        }
        cout<<endl;
    }
}

int main(){
    //Generate The Matrices
    genMatrices();
    //Take Input for P array
    takeIP();
    //Multiply Matrices
    getMSMatrices();
    //Print M Matrix
    printMMatrix();
    //Print S matrix
    printSMatrix();
    //Example Inputs
    // 4 2 2 4 2 6
    // 4 7 1 5 4 2
    // 4 10 20 30 40 30
    // 6 5 10 3 12 5 50 6
    // 6 30 35 15 5 10 20 25
    
    
    return 0;
}