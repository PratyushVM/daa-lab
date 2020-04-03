#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define pf push_front
#define popf pop_front
#define popb pop_back

class ugraph
{
    ll v; //number of vertices
    list<ll> *adj; //pointer to array of adjacency list

    void dfs_helper(ll v, bool visit[]);
    bool dfs_helper1(ll v, ll v1, bool visit[]);

    public:
    ugraph(ll v); //constructor
    void addedge(ll v1, ll v2); //adds edge between v1 and v2
    void dfs(ll u); // to print dfs traversal of ugraph starting from vertex u
    void dfs(); // to print dfs traversal of ugraph from arbitrary node
    void dfs(ll u, ll v); // to find if v is reachable from u using dfs traversal
};