#include <iostream> 
#include <limits.h> 
#include <list> 
#include <stack> 
#define NINF INT_MIN 
using namespace std; 
#define ll long long
#define mp make_pair
#define pb push_back
#define pf push_front
#define popf pop_front
#define popb pop_back
#define NIL -1
#include<bits/stdc++.h>

  

class AdjListNode {  
    int v;  
    int weight;  
    
public:  
    AdjListNode(int _v, int _w)  
    {  
        v = _v;  
        weight = _w;  
    }  
    int getV() { return v; }  
    int getWeight() { return weight; }  
};  
    

class Graph {  
    int V; 
    list<AdjListNode>* adj;  
    
   
    void topologicalSortUtil(int v, bool visited[],  
                             stack<int>& Stack);  
    
public:  
    Graph(int V); 
    void addEdge(int u, int v, int weight);  
    
   
    void longestPath(int s);  
};  

class ugraph
{
    ll V,e; //number of vertices and edges
    list<ll> *adj; //pointer to array of adjacency lists

    public:
    ugraph(ll u, ll u1); //constructor to create undirected graph of u nodes and u1 edges
    void addedges(); //to add the edges and their weights
    void test_bipartite(); //to test if the graph is bipartite
    void Cut_Vertex_Util(int v, bool visit[], int discover[], int lowval[], int parent[], bool cut_v[]);  //to print all articulation points in the graph
    void cut_vertex_find();
    void Cut_Edge_Util(int v, bool visited[], int disc[], int low[],  int parent[]);
    void cut_edge_find();
    void BFS_modified(int start,int end,int parent[]);
    void BFS_spath(int s,int flag);
    pair<int,int> bfs(int u);
    void longestPathLength() ;
};

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
    void kruskal_maxst(); //returns cost of MST using Kruskal's algorithm
};


