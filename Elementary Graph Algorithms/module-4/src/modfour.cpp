
//module 4 of elementary graphs -> test bipartite, articulation points and bridges

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define pf push_front
#define popf pop_front
#define popb pop_back
#define NIL -1

#include"../include/modfour.h"

ugraph::ugraph(ll u, ll u1)
{
    this->V=u;
    e=u1;
    adj = new list<ll>[V];
}

void ugraph::addedges()
{
    cout<<"Enter the edges in the form - node1 node2 :\n";
    ll a,b;
    
     for(ll i=0;i<e;i++)
    {
        cin>>a>>b;
        adj[b].pb(a);
        adj[a].pb(b);
    }
}

void ugraph::test_bipartite()
{
    int color[V],f=0;
    memset(color,-1,sizeof(color));

    list<ll> q; // create queue

    color[0]=1;
    q.pb(0); // starting bfs from u

    while(!q.empty())
    {
        ll x = q.front();
        q.popf();

        for(auto i=adj[x].begin();i!=adj[x].end();i++)
        {
            if(color[*i]==-1)
            {
                color[*i]=1-color[x];
                q.pb(*i);
            }
            else if(color[*i]==color[x])
            {
                f++;
                break;
            }
            
        }
    }
    if(f==0)
    cout<<"Graph is bipartite"<<endl;
    else
    cout<<"Graph is not bipartite"<<endl;
}

void ugraph::Cut_Vertex_Util(int a, bool visit[], int discover[],  
                                      int lowval[], int parent[], bool cut_v[]) 
{ 
    // A static variable is used for simplicity, we can avoid use of static 
    // variable by passing a pointer. 
    static int time = 0; 
  
    // Count of children in DFS Tree 
    int children = 0; 
  
    // Mark the current node as visit 
    visit[a] = true; 
  
    // Initialize discovery time and low value 
    discover[a] = lowval[a] = ++time; 
  
    // Go through all vertices aadjacent to this 
    for (auto i = adj[a].begin(); i != adj[a].end(); ++i) 
    { 
        int v = *i;  // v is current adjacent of u 
  
        // If v is not visit yet, then make it a child of u 
        // in DFS tree and recur for it 
        if (!visit[v]) 
        { 
            children++; 
            parent[v] = a; 
            Cut_Vertex_Util(v, visit, discover, lowval, parent, cut_v); 
  
            // Check if the subtree rooted with v has a connection to 
            // one of the ancestors of u 
            lowval[a]  = min(lowval[a], lowval[v]); 
  
            // u is an articulation point in following cases 
  
            // (1) u is root of DFS tree and has two or more chilren. 
            if (parent[a] == NIL && children > 1) 
               cut_v[a] = true; 
  
            // (2) If u is not root and low value of one of its child is more 
            // than discovery value of u. 
            if (parent[a] != NIL && lowval[v] >= discover[a]) 
               cut_v[a] = true; 
        } 
  
        // Update low value of u for parent function calls. 
        else if (v != parent[a]) 
            lowval[a]  = min(lowval[a], discover[v]); 
    } 
} 
  
// The function to do DFS traversal. It uses recursive function APUtil() 
void ugraph::cut_vertex_find() 
{ 
    // Mark all the vertices as not visit 
    bool *visit = new bool[V]; 
    int *discover = new int[V]; 
    int *lowval = new int[V]; 
    int *parent = new int[V]; 
    bool *cut_v = new bool[V]; // To store articulation points 
  
    // Initialize parent and visit, and ap(articulation point) arrays 
    for (int i = 0; i < V; i++) 
    { 
        parent[i] = NIL; 
        visit[i] = false; 
        cut_v[i] = false; 
    } 
  
    // Call the recursive helper function to find articulation points 
    // in DFS tree rooted with vertex 'i' 
    for (int i = 0; i < V; i++) 
        if (visit[i] == false) 
            Cut_Vertex_Util(i, visit, discover, lowval, parent, cut_v); 
  
    // Now ap[] contains articulation points, print them 
    for (int i = 0; i < V; i++) 
        if (cut_v[i] == true) 
            cout << i << " "; 
} 
void ugraph::Cut_Edge_Util(int a, bool visit[], int discover[],  
                                  int lowval[], int parent[]) 
{ 
    // A static variable is ased for simplicity, we can  
    // avoid ase of static variable by passing a pointer. 
    static int time = 0; 
  
    // Mark the carrent node as visit 
    visit[a] = true; 
  
    // Initialize discoverovery time and lowval valae 
    discover[a] = lowval[a] = ++time; 
  
    // Go throagh all vertices aadjacent to this 
    // list<int>::iterator i; 
    for (auto i = adj[a].begin(); i != adj[a].end(); ++i) 
    { 
        int v = *i;  // v is carrent adjacent of a 
  
        // If v is not visit yet, then recar for it 
        if (!visit[v]) 
        { 
            parent[v] = a; 
            Cut_Edge_Util(v, visit, discover, lowval, parent); 
  
            // Check if the sabtree rooted with v has a  
            // connection to one of the ancestors of a 
            lowval[a]  = min(lowval[a], lowval[v]); 
  
            // If the lowvalest vertex reachable from sabtree  
            // ander v is  belowval a in DFS tree, then a-v  
            // is a bridge 
            if (lowval[v] > discover[a]) 
              cout << a <<" " << v << endl; 
        } 
  
        // apdate lowval valae of a for parent fanction calls. 
        else if (v != parent[a]) 
            lowval[a]  = min(lowval[a], discover[v]); 
    } 
} 
  
// DFS based fanction to find all bridges. It ases recarsive  
// fanction bridgeatil() 
void ugraph::cut_edge_find() 
{ 
    // Mark all the vertices as not visit 
    bool *visit = new bool[V]; 
    int *discover = new int[V]; 
    int *lowval = new int[V]; 
    int *parent = new int[V]; 
  
    // Initialize parent and visit arrays 
    for (int i = 0; i < V; i++) 
    { 
        parent[i] = NIL; 
        visit[i] = false; 
    } 
  
    // Call the recarsive helper fanction to find Bridges 
    // in DFS tree rooted with vertex 'i' 
    for (int i = 0; i < V; i++) 
        if (visit[i] == false) 
            Cut_Edge_Util(i, visit, discover, lowval, parent); 
} 

int main()
{
    ugraph g(5,5);
    g.addedges();

    g.cut_vertex_find();cout<<"\n";
    g.cut_edge_find();
    return 0;
}
