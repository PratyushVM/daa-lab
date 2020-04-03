#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define pf push_front
#define popf pop_front
#define popb pop_back
#define NIL -1


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
};