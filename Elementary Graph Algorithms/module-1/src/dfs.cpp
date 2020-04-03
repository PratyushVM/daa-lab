#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define pf push_front
#define popf pop_front
#define popb pop_back

#include"../include/dfs.h"

ugraph::ugraph(ll v)
{
    this->v=v;
    adj = new list<ll>[v];
}

void ugraph::addedge(ll v1,ll v2)
{
    adj[v1].pb(v2);
}

void ugraph::dfs_helper(ll v,bool visit[])
{
    visit[v]=true;
    cout<<v<<" "; // to mark node as visited and print it

    for(auto i=adj[v].begin();i!=adj[v].end();i++)
    {
        if(!visit[*i])
        dfs_helper(*i,visit); // to traverse the nodes connected to v in dfs
    }
}

bool ugraph::dfs_helper1(ll v, ll v1, bool visit[])
{
    static bool flag=false;
    visit[v]=true;
    cout<<v<<" "; // to mark node as visited and print it
    if(v==v1)
    {
        flag=true;
    }

    for(auto i=adj[v].begin();i!=adj[v].end();i++)
    {
        if(!visit[*i])
        flag = dfs_helper1(*i,v1,visit); // to traverse the nodes connected to v in dfs
    }
    return flag;
}


void ugraph::dfs(ll u)
{
    bool *visit = new bool[v];
    memset(visit,false,sizeof(visit));

    dfs_helper(u,visit);
}

void ugraph::dfs(ll u, ll v)
{
    bool *visit = new bool[v];
    memset(visit,false,sizeof(visit));

    bool f=dfs_helper1(u,v,visit);
    
    if(f)
    cout<<"Path exists between "<<u<<" and "<<v<<endl;
    else
    cout<<"Path does not exist between "<<u<<" and "<<v<<endl;
}

void ugraph::dfs()
{
    dfs(0);
}

int main()
{
    //sample driver code to illustrate dfs
    ugraph g(5);
    g.addedge(0,1);
    g.addedge(0,2);
    g.addedge(2,3);
    g.addedge(1,4);

    cout<<"The DFS traversal starting from node 0 is :"<<endl;
    
    g.dfs(0,4); // Expected output is - 0 1 4 2 3

    return 0;
}
