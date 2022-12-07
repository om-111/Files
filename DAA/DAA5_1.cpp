#include <iostream>
#include <vector>
using std::vector;
using namespace std;
int MX1=10000000;
struct wEdge{
    int cost; string src; string dest;
    wEdge(int c, string s,string d){cost=c; dest=d; src=s;}
    wEdge(){}};
struct wVertex{
    string src;int distance;
    wVertex(string s){src=s;}
    wVertex(){}};
vector<wVertex> V_tracts;
vector<wEdge> E_tracts;


void BellPrint(){ 
    for( auto item: E_tracts)
    {
      cout<<item.src <<"|----|" <<item.dest <<"|----|" <<item.cost <<endl;
    } 
    cout << endl;    
}
//Bellman Ford Function
void BellmanFord(){
    string source;
    // set the first vertex as a single source
    source=V_tracts[0].src;
    for(int i=0;i<V_tracts.size();i++){
        if(V_tracts[i].src==source){
            V_tracts[i].distance=0;//set source distance to 0
        }
        else{
            V_tracts[i].distance=MX1;//set other distances to a significantly large value
        }
        cout<<V_tracts[i].src<<": "<<V_tracts[i].distance <<endl;
    }
    cout<<"\n";
    
    /**
     Relax all edges |V| - 1 times. A simple shortest path from src
     to any other vertex can have at-most |V| - 1 edges
     **/
    for(int i=1;i<V_tracts.size()-1;i++){//go through and find initial shortest distance
        for(int j=0;j<E_tracts.size();j++){
            string src = E_tracts[j].src;
            string dest = E_tracts[j].dest;
            wVertex vsrc; wVertex vdest;
            int ksrc; int kdest;
            for(int k=0;k<V_tracts.size();k++){//find correct vertices
                if(src==V_tracts[k].src){
                    vsrc=V_tracts[k];
                    ksrc=k;
                }
                if(dest==V_tracts[k].src){
                    vdest=V_tracts[k];
                    kdest=k;
                }
            }
            int weight=E_tracts[j].cost;
            if(vsrc.distance!=MX1&&vsrc.distance+weight<vdest.distance){//finds the shortest distance
                vdest.distance=vsrc.distance+weight;
                V_tracts[ksrc]=vsrc;
                V_tracts[kdest]=vdest;
                cout<<source<<" --------> "<<V_tracts[kdest].src<<" Distance: "<<vdest.distance<<endl<<endl;
                for(int k=0;k<V_tracts.size();k++){
                    cout<<V_tracts[k].src<<": "<<V_tracts[k].distance<<endl;
                }
            }
        }
    }
    
    /**
     check for negative-weight cycles, if graph doesn't contain negative weight cycle.
     print the shortest path else: print  negative weight cycle detected
     **/ 
    bool found=false;
    for(int i=0;i<E_tracts.size();i++){
        string src = E_tracts[i].src;
        string dest = E_tracts[i].dest;
        wVertex vsrc; wVertex vdest;
        int ksrc; int kdest;
        for(int k=0;k<V_tracts.size();k++){//find correct vertices
            if(src==V_tracts[k].src){
                vsrc=V_tracts[k];
                ksrc=k;
            }
            if(dest==V_tracts[k].src){
                vdest=V_tracts[k];
                kdest=k;
            }
        }
        int weight=E_tracts[i].cost;
        if(vsrc.distance!=MX1&&vsrc.distance+weight<vdest.distance){//finds the shortest distance
            cout<<"negative weights Cycle found!"<<endl;
            found=true;
        }
    }
    if(!found){
        cout<<"No negative cycles."<<endl;
    }
    //print shortest distance 
    cout<<"Vertex  Shortest Distance" <<endl;
    for(auto is :V_tracts){
      cout<<is.src<<"|---------|"<<is.distance<<endl;
    }
  return;
}

void example1(){
    V_tracts.clear();
    E_tracts.clear();
    vector<string> vlis {"1","2","3","4","6"};
    for(auto i=vlis.begin();i<vlis.end();i++){
        V_tracts.push_back(wVertex(*i));
    }
    vector<int> dis {5,3,7,3,2,1,2};
    vector<string> src {"1","1","1","2","2","3","4"};
    vector<string> dst {"2","3","4","4","6","4","6"};
    for(int i=0;i<dis.size();i++){
        E_tracts.push_back(wEdge(dis[i],src[i],dst[i]));
    }
    BellPrint();
    BellmanFord();
    cout<<endl;
}
void example2(){
    V_tracts.clear();
    E_tracts.clear();
    vector<string> vlis {"A","B","C","D","E","F"};
    for(auto i=vlis.begin();i<vlis.end();i++){
        V_tracts.push_back(wVertex(*i));
    }
    vector<int> dis {6,4,5,-1,-2,3,-2,-1,3};
    vector<string> src {"A","A","A","B","C","C","D","D","E"};
    vector<string> dst {"B","C","D","E","B","E","C","F","F"};
    for(int i=0;i<dis.size();i++){
        E_tracts.push_back(wEdge(dis[i],src[i],dst[i]));
    }
    BellPrint();
    BellmanFord();
    cout<<endl;
}
void example3(){
    V_tracts.clear();
    E_tracts.clear();
    vector<string> vlis {"A","B","C","D"};
    for(auto i=vlis.begin();i<vlis.end();i++){
        V_tracts.push_back(wVertex(*i));
    }
    vector<int> dis {4,5,7,7,-15};
    vector<string> src {"A","A","B","C","D"};
    vector<string> dst {"B","C","D","B","C"};
    for(int i=0;i<dis.size();i++){
        E_tracts.push_back(wEdge(dis[i],src[i],dst[i]));
    }
    BellPrint();
    BellmanFord();
    cout<<endl;
}
int main(){
    example1();
    example2();    
    example3();
    return 0;
}