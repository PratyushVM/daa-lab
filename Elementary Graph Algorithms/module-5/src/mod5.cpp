//cpp code implementing kruskal's MST and Prim's MST algorithms

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front

#include"../include/mod5.h"

ugraph::ugraph(ll u, ll u1)
{
    this->v=u;
    e=u1;
    adj = new list<pair<ll,ll> >[v];
}

void ugraph::addedges()
{
    cout<<"Enter the edges in the form - weight node1 node2 :\n";
    ll a,b,c;
    
     for(ll i=0;i<e;i++)
    {
        cin>>a>>b>>c;
        adj[b].pb(mp(a,c));
        adj[c].pb(mp(a,b));
    }
}

void ugraph::prim_mst()
{
    bool visit[v];
    memset(visit,false,sizeof(visit));

    priority_queue< pair<ll,ll>, vector<pair<ll,ll> >, greater<pair<ll,ll> > > q;

    ll x,y,c=0;
    pair<ll,ll> p;

    q.push(mp(0,0));
    while(!q.empty())
    {
        p=q.top();
        q.pop();
        x=p.second;
        if(visit[x]==true)
        continue;
        else
        {
            c+=p.first;
            visit[x]=true;
            for(auto i=adj[x].begin();i!=adj[x].end();i++)
            {
                y=(*i).second;
                if(visit[y]==false)
                q.push(*i);
            }
        }

    }

    cout<<"The cost of MST derived from Prim's algorithm is "<<c<<endl;

}

dsu::dsu(ll u, ll u1)
{
    this->v=u;
    e=u1;
    arr = new ll[v];
    p = new pair<ll, pair<ll,ll> >[u1];
}

void dsu::addedges()
{
    cout<<"Enter edges of the form cost node1 node2 :\n";
    ll a,b,c;
    for(ll i=0;i<e;i++)
    {
        cin>>a>>b>>c;
        p[i]=mp(a,mp(b,c));
    }
}

void dsu::initialize()
{
    for(ll i=0;i<v;i++)
    {
        arr[i]=i;
    }
}

ll dsu::root(ll u)
{
    while(u!=arr[u])
    {
        u=arr[u];
    }
    return u;
}


void dsu::uniondsu(ll u, ll v)
{
    ll ru=root(u);
    ll rv=root(v);

    arr[ru]=rv; //setting parent of root of u as root of v 

}

void dsu::kruskal_mst()
{
    initialize();
    ll cost=0;

    sort(p,p+e); //sorting edges with respect to their weights

    ll q,w,c=0;
    
    for(ll i=0;i<e;i++)
    {
        q=root(p[i].second.first);
        w=root(p[i].second.second);

        if(q!=w)
        {
            c+=p[i].first;
            uniondsu(p[i].second.first,p[i].second.second);
        }
    }
        
    cout<<"The cost of the MST derived from Kruskal's MST Algorithm is "<<c<<endl;
}


int main()
{
    ugraph g(5,5);
    g.addedges();
    g.prim_mst();
}

dsu2::dsu2(int V,int e) 
{ 
    this->V = V; 
    this->e=e;
    adj = new list<int>[V]; 
} 
  
void dsu2::addEdge() 
{ 
    cout<<"Enter the edges of the form-node1 node2 weight\n";
    int u,v,w;
    for(int i=0;i<e;i++){
        cin>>u>>v>>w;
        adj[u].push_back(v); 
        adj[v].push_back(u); 
        p.push_back({w, {u, v}});
    } 
} 
  
void dsu2::DFS(int v, bool visit[]) 
{ 
    visit[v] = true; 
    list<int>::iterator i; 
    for (i = adj[v].begin(); i != adj[v].end(); ++i) 
        if (!visit[*i]) 
            DFS(*i, visit); 
} 
bool dsu2::DFS_Connectedness() 
{ 
    bool visit[V]; 
    memset(visit, false, sizeof(visit)); 
    DFS(0, visit); 
    for (int i=1; i<V; i++) 
        if (visit[i] == false) 
            return false; 
  
    return true; 
} 
void dsu2::Reverse_Delete_Algo_MST() 
{ 
    sort(p.begin(), p.end()); 
    int minCost = 0;  
    for (int i=p.size()-1; i>=0; i--) 
    { 
        int u = p[i].second.first; 
        int v = p[i].second.second; 
        adj[u].remove(v); 
        adj[v].remove(u); 
        if (DFS_Connectedness() == false) 
        { 
            adj[u].push_back(v); 
            adj[v].push_back(u); 
            minCost += p[i].first; 
        } 
    } 
  
    cout << "Total weight of MST is " << minCost; 
} 