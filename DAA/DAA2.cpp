#include<bits/stdc++.h>
using namespace std;
//Declare variables
//To Keep track of a nodes parent and mark visited nodes
vector<int>d,parent,mark;
//To store the edges src,dest
vector< pair<int,int> >edges;
//To store the overall weighted graph
vector< vector< pair<int,int> > >graph;
//To Map the edges to their respective weights
map< pair<int,int> ,int>weight;

//A function to find the runtime of functions
auto timing = [](auto && F, auto && ... params)
{
    auto start = std::chrono::steady_clock::now();
    std::forward<decltype(F)>(F)
    (std::forward<decltype(params)>(params)...);
    return std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::steady_clock::now() - start).count()*0.0000001;
};
//Functions for prims algorithm
void prim(int s,int n){
    //int s for start vertex and n for final
    //create set of pairs
    set< pair<int,int> >st;
    pair<int,int>p;
    int u;
    d[s]=0;
    //insert all the pairs of edges
    for(int i=1;i<=n;i++)
    st.insert(make_pair(d[i],i));
    while(!st.empty()){
        //find connected nodes and mark as true when visiting
        u=st.begin()->second;
        mark[u]=true;
        st.erase(st.begin());
        for(int i=0;i<graph[u].size();i++){
            p=graph[u][i];
            if(p.second<d[p.first] && mark[p.first]==false){
                st.erase(make_pair(d[p.first],p.first));
                d[p.first]=p.second;
                parent[p.first]=u;
                st.insert(make_pair(d[p.first],p.first));
            }
        }
    }
    
}
//compare weights
bool cmp(pair<int,int>a,pair<int,int>b){
    if(weight[a]<weight[b])return true;
    else return false;
}
//findset function
int findset(int s){
    if(parent[s]==s)return s;
    parent[s]=findset(parent[s]);
    return parent[s];
}
//uninset function
void unionset(int x,int y){
    int a,b;
    a=findset(x);
    b=findset(y);
    parent[a]=b;
}
//answer variable
int ansvar=0;
//kruskal implementation
void krus(int n,int m){
    //sort the edges
    sort(edges.begin(),edges.end(),cmp);
    int i,u,v,w;
    int c=0,ans=0;
    for(i=0;i<m;i++){
        u=edges[i].first;
        v=edges[i].second;
        w=weight[edges[i]];
        if(findset(u)!=findset(v)){
            unionset(u,v);
            ans+=w;
            c++;
        }
        if(c==n-1)break;
    }
    ansvar=ans;
}
//Sets size of the graph, marked and parent vectors
void setsize(int n,int m){
    
    graph.resize(n+1);
    d.resize(n+1);
    mark.resize(n+1);
    parent.resize(n+1);
}
//fill the vectors with INT_MAX
void fill_for_prim(int n){
    fill_n(d.begin(),n+1,INT_MAX);
    fill_n(parent.begin(),n+1,0);
    fill_n(mark.begin(),n+1,false);
}
//Get answer for prims
void get_answer_prim(int n){
    int ans=0;
    for(int i=1;i<=n;i++){
        ans+=d[i];
    }
    cout<<"\nThe MST of the graph (Using Prim's) is..."<<ans<<endl;
}
//Fill the vector with INT_MAX and set marked as false
void fill_for_krus(int n){
    fill_n(d.begin(),n+1,INT_MAX);
    for(int i=1;i<=n;i++){
        parent[i]=i;
    }
    fill_n(mark.begin(),n+1,false);
}
//Get Answer for Kruskals
void get_answer_krus(){
    cout<<"\nThe MST of the graph (Using Kruskal's) is..."<<ansvar<<endl;
}
//Create Graph
void creategraph(int m){
    int u,v,w,i;
    for(i=1;i<=m;i++){
        cin>>u>>v>>w;
        edges.push_back(make_pair(u,v));
        weight[make_pair(u,v)]=w;
        graph[u].push_back(make_pair(v,w));
        graph[v].push_back(make_pair(u,w));
    }
}
int main()
{
    int v,e;
    //Enter total number of V, E to set size
    cin>>v>>e;
    setsize(v,e);
    //Create Graph with M Edges
    creategraph(e);
    // Using Prims Algorithm...
    cout<<timing(fill_for_prim,v)+timing(prim,1,v)+timing(get_answer_prim,v)<<endl;
    // Using Kruskals Algorithm
    cout<<timing(fill_for_krus,v)+timing(krus,v,e)+timing(get_answer_krus);
    return 0;
}