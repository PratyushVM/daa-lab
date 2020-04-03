#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front

class graph
{
    ll v; // number of vertices
    list<ll> *adj; // pointer to array of adjacency lists

    public:
    graph(ll v); //constructor
    void addedge(ll v1,ll v2); // adds edge between v1 and v2
    void bfs(); // bfs from arbitrary node
    void bfs(ll u); // bfs from vertex u
    void bfs(ll u, ll v); // using bfs to check if v is reachable from u 
};