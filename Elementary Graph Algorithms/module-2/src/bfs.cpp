#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front

#include"../include/bfs.h"

graph::graph(ll v)
{
    this->v=v;
    adj = new list<ll>[v];
}

void graph::addedge(ll v1,ll v2)
{
    adj[v1].pb(v2);
}

void graph::bfs()
{
    bfs(0);
}

void graph::bfs(ll u)
{
    bool *visit = new bool[v];
    memset(visit,false,sizeof(visit)); // initializing visit array

    list<ll> q; // create queue

    visit[u]=true;
    q.pb(u); // starting bfs from u

    while(!q.empty())
    {
        ll x = q.front();
        cout<<x<<" "; // printing the node visited
        q.popf();

        for(auto i=adj[x].begin();i!=adj[x].end();i++)
        {
            if(!visit[*i])
            {
                visit[*i]=true;
                q.pb(*i);
            }
        }
    }
}

void graph::bfs(ll u, ll v)
{
    ll flag=0;
    bool *visit = new bool[v];
    memset(visit,false,sizeof(visit)); // initializing visit array

    list<ll> q; // create queue

    visit[u]=true;
    q.pb(u); // starting bfs from u

    while(!q.empty())
    {
        ll x = q.front();
        cout<<x<<" "; // printing the node visited
        if(x==v)
        {
            cout<<"Path exists between "<<v<<" and "<<u<<endl;
            flag++;
        }
        q.popf();

        for(auto i=adj[x].begin();i!=adj[x].end();i++)
        {
            if(!visit[*i])
            {
                visit[*i]=true;
                q.pb(*i);
            }
        }
    }

    if(flag==0)
    cout<<"Path does not exist between "<<v<<" and "<<u<<endl;

}

int main()
{
    ///sample driver code to illustrate bfs
    graph g(5);
    g.addedge(0,1);
    g.addedge(1,3);
    g.addedge(0,2);
    g.addedge(2,4);

    g.bfs(0,4); // Expected output - 0 1 2 3 4

    return 0;
}