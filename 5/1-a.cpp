#include<bits/stdc++.h>
#define ll long long
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;


void arrsort1(ll n, ll a[][100], ll size[]);

ll x[10000];

int main()
{
    ll n,a[100][100],size[100000];
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
    }

    arrsort1(n,a,size);

    return 0;
}


void arrsort1(ll n, ll a[][100], ll size[])
{
    ll i=0,k;

    for(ll j=0;j<n;j++)
    {
        k=0;
        for(;k<size[j];k++)
        {
            x[i+k]=a[j][k];
        }
        i+=k;
        sort(x,x+i);

    }

    for(ll j=0;j<i;j++)
    {
        cout<<x[j]<<" ";
    }

}


