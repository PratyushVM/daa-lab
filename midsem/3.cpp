//To find distinct digits in a number - theta log^2n
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ll x;
    cout<<"Enter n"<<endl;
    cin>>x;
    vector<ll>v;
    set<ll>s;

    ll n,d;
    n=x;
    while(n!=0)
    {
        d=n%10;
        n=n/10;
        v.push_back(d);
    }

    for(ll i:v)
    {s.insert(i);}

    for(ll i:s)
    {cout<<i<<" ";}    
    
    return 0;
}