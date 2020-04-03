#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front

class dsu
{
    ll v,e; //number of vertices
    ll *arr; //pointer to array   
    pair< ll,pair<ll,ll> > *p; //array with each edge of the form cost,node1,node2  

    public:
    dsu(ll u, ll u1); //constructor initializing a graph with u nodes and u1 edges
    void addedges(); // enter edge values
    void initialize(); //initializes the array
    ll root(ll u); //returns root of u
    void uniondsu(ll u, ll v); //connects u to v
    void kruskal_mst(); //returns cost of MST using Kruskal's algorithm
};

class ugraph
{
    ll v,e; //number of vertices and edges
    list< pair<ll,ll> > *adj; //pointer to array of adjacency lists

    public:
    ugraph(ll u, ll u1); //constructor to create undirected graph of u nodes and u1 edges
    void addedges(); //to add the edges and their weights
    void prim_mst(); //to print the cost of MST using Prim's MST algorithm
    void youralgo();
};

class dsu2 
{ 
    int V,e;    
    list<int> *adj; 
    vector< pair<int,pair<int,int>> > p; 
    void DFS(int v, bool visit[]); 
  
public: 
    dsu2(int V,int e);   
    void addEdge(); 
    bool DFS_Connectedness(); 
    void Reverse_Delete_Algo_MST(); 
}; 