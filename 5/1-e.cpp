#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define pll pair<ll,ll>
#define vll vector<pll>

class cmp
{
    public:
    ll operator()(pll a,pll b)
    {
        return a.f>b.f;
    }
};

void kheapsort(ll n,ll a[100][100],ll size[100],ll sum);

int main()
{
    ll n,a[100][100],size[100000],sum=0;
    cout<<"Enter the number of arrays"<<"\n";
    cin>>n;
    for(ll i=0;i<n;i++)
    {
        ll j=0;char temp;
        cout<<"Enter elements of array "<<i+1<<"\n";
        
            while(1)
            {
                scanf("%lli%c",&a[i][j],&temp);
                j++;
                if(temp=='\n')
                break;
            }
        size[i]=j;
        sum+=size[i];        
    }

    kheapsort(n,a,size,sum);
    
    return 0;
}

void kheapsort(ll n,ll a[100][100],ll size[100],ll sum)
{
    ll p[n],t;
    vector<ll> v;
    memset(p,0,sizeof(p));

    priority_queue<pll,vll,cmp> hp;
    
    for(ll i=0;i<n;i++)
    {
        hp.push(mp(a[i][p[i]],i));
    }

    ll count=0;
    //cout<<"hi";
    while(count<sum)
    {
     v.pb(hp.top().f);
     t=hp.top().s;
     hp.pop();
     if(p[t]<size[t]-1)
     {
        p[t]++;
        hp.push(mp(a[t][p[t]],t));
     }
    count++;
    }

    while(hp.empty()==false)
    {
        v.pb(hp.top().f);
        hp.pop();
    }

    for(ll i:v)
        cout<<i<<" ";
    
}

