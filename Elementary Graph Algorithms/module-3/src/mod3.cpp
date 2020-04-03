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

#include"../include/mod3.h"
    
    
Graph::Graph(int V){
    this->V = V;  
    adj = new list<AdjListNode>[V];  
}  
    
  
  
void Graph::addEdge(int u, int v, int weight)  
{  
    AdjListNode node(v, weight);  
    adj[u].push_back(node); }
void Graph::topologicalSortUtil(int v, bool visited[],  
                                stack<int>& Stack)  
{  
    
    visited[v] = true;  
    
   
    list<AdjListNode>::iterator i;  
    for (i = adj[v].begin(); i != adj[v].end(); ++i) {  
        AdjListNode node = *i;  
        if (!visited[node.getV()])  
            topologicalSortUtil(node.getV(), visited, Stack);  
    }  
    
   
    Stack.push(v);  
}  
    

void Graph::longestPath(int s)  
{  
    stack<int> Stack;  
    int dist[V];  
    
   
    bool* visited = new bool[V];  
    for (int i = 0; i < V; i++)  
        visited[i] = false;  
    
   
    for (int i = 0; i < V; i++)  
        if (visited[i] == false)  
            topologicalSortUtil(i, visited, Stack);  
   
    for (int i = 0; i < V; i++)  
        dist[i] = NINF;  
    dist[s] = 0;  
    
   
    while (Stack.empty() == false) {  
        
        int u = Stack.top();  
        Stack.pop();  
    
        
        list<AdjListNode>::iterator i;  
        if (dist[u] != NINF) {  
            for (i = adj[u].begin(); i != adj[u].end(); ++i)  
                if (dist[i->getV()] < dist[u] + i->getWeight())  
                    dist[i->getV()] = dist[u] + i->getWeight();  
        }  
    }  
    
    
    for (int i = 0; i < V; i++)  
        (dist[i] == NINF) ? cout << "INF " : cout << dist[i] << " "; 
      
    delete [] visited; 
}  


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
void ugraph::BFS_modified(int start,int end,int parent[]){
    int visit[V]={0},flag=0;
    queue<int> q;
    q.push(start);
    visit[start]=1;
    while(!q.empty()){
        int y=q.front();
        q.pop();
        for(auto i=adj[y].begin();i!=adj[y].end();i++){
            if(!visit[*i]){
                visit[*i]=1;
                q.push(*i);
                parent[*i]=y;
            }
        }
        if(y==end) flag=1;
    }
    if(flag){
        int x=end;
        cout<<end<<" ";
        while(parent[x]!=-1){
            cout<<"<-"<<parent[x];
            x=parent[x];
        }
    }
    else cout<<"NO PATH";
}
void ugraph::BFS_spath(int s,int flag){
    if(!flag){
        int parent[V];
        for(int i=0;i<V;i++){
            memset(parent,-1,sizeof(parent));
            BFS_modified(s,i,parent);
        }

    }
}
pair<int, int> ugraph::bfs(int u) 
{ 
    //  mark all distance with -1 
    int dis[V]; 
    memset(dis, -1, sizeof(dis)); 
  
    queue<int> q; 
    q.push(u);  
    dis[u] = 0; 
    while (!q.empty()) 
    { 
        int t = q.front();      
         q.pop();  
        for (auto it = adj[t].begin(); it != adj[t].end(); it++) 
        { 
            int v = *it;  
            if (dis[v] == -1) 
            { 
                q.push(v);  
                dis[v] = dis[t] + 1; 
            } 
        } 
    } 
  
    int maxDis = 0; 
    int nodeIdx; 
    for (int i = 0; i < V; i++) 
    { 
        if (dis[i] > maxDis) 
        { 
            maxDis = dis[i]; 
            nodeIdx = i; 
        } 
    } 
    return make_pair(nodeIdx, maxDis); 
} 
void ugraph::longestPathLength() 
{ 
    pair<int, int> t1, t2; 
    t1 = bfs(0); 
    t2 = bfs(t1.first); 
  
    cout << "Longest path is from " << t1.first << " to "
         << t2.first << " of length " << t2.second; 
} 
int main()
{
    ugraph g(4,3);
    g.addedges();

    g.cut_vertex_find();cout<<"\n";
    g.cut_edge_find();
    g.BFS_spath(0,0);
    // g.Lpath_Tree(0);
    g.longestPathLength(); 
    return 0;
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

void dsu::kruskal_maxst()
{
    initialize();
    ll cost=0;

    sort(p,p+e,greater<pair<ll,pair<ll,ll>>>()); //sorting edges with respect to their weights

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

