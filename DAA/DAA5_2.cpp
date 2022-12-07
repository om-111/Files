#include <iostream>
using namespace std;
int M1=1000000;
int miniDist(int distance[], bool visited[]) // finding mnm distance
{
    int mnm=M1,ind;
              
    for(int k=0;k<6;k++) 
    {
        if(visited[k]==false && distance[k]<=mnm)      
        {
            mnm=distance[k];
            ind=k;
        }
    }
    return ind;
}

void DijkstraAlgo(int graph[6][6],int src,int sz) // adjacency matrix 
{
    int distance[6]; // array to calculate the minimum distance for each node                             
    bool visited[6];// boolean array to mark visited and unvisited for each node
    
     
    for(int k = 0; k<6; k++)
    {
        distance[k] = M1;
        visited[k] = false;    
    }
    
    distance[src] = 0;   // Source vertex distance is set to 0
    
    for(int k = 0; k<6; k++)                           
    {
        int m=miniDist(distance,visited); 
        visited[m]=true;
        for(int k = 0; k<6; k++)                  
        {
            // updating the distance w.r.t to the neighbouring vertex
            if(!visited[k] && graph[m][k] && distance[m]!=M1 && distance[m]+graph[m][k]<distance[k])
                distance[k]=distance[m]+graph[m][k];
        }
    }
    cout<<"Vertex\t\tDistance from source vertex"<<endl;
    for(int k = 0; k<sz; k++)                      
    { 
        char str=65+k; 
        cout<<str<<"\t\t\t"<<distance[k]<<endl;
    }
}

int main()
{
    int graph[6][6]={
        {0, 1, 2, 0, 0, 0},
        {1, 0, 0, 5, 1, 0},
        {2, 0, 0, 2, 3, 0},
        {0, 5, 2, 0, 2, 2},
        {0, 1, 3, 2, 0, 1},
        {0, 0, 0, 2, 1, 0}};
    DijkstraAlgo(graph,0,6);
    int graph2[6][6]={
        {0,7,3,0,0},
        {7,0,1,2,6},
        {3,1,0,2,0},
        {0,2,2,0,4},
        {0,6,0,4,0},
    };
    DijkstraAlgo(graph2,0,5);
    int graph3[6][6]={
        {0,7,12,0,0,0},
        {0,0,2,9,0,0},
        {0,0,0,0,10,0},
        {0,0,0,0,0,1},
        {0,0,0,4,0,5},
        {0,0,0,0,0,0}
    };
    DijkstraAlgo(graph3,0,6);

    return 0;                           
}