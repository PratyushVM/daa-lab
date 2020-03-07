///incomplete code

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back

int main()
{
    ll n;
    cout<<"Enter the number in base 10(decimal) :"<<endl;
    cin>>n;
    
    vector<ll> v;
    //vector<ll> ::iterator it=s.begin();
    //s.resize(v.size()*2);
    
    while(n>0)
    {
        v.pb(n%2);
        n/=2;  
    }


    ll s[2*v.size()],k=0;
    memset(s,0,sizeof(s));

    for(ll i=0;i<v.size();i++)
    {
        k=i;
        for(ll j=0;j<v.size();j++)
        {
            s[k]+=v[i]*v[j];
            k++;            
        }
    }

    for(ll i=0;i<2*v.size();i++)
    {
        while(s[i]>=1)
        {
            s[i]-=1;
            s[i+1]+=1;
        }
    }

    for(ll i=k;i>=0;i--)
    {
        cout<<s[i]<<" ";
    }


}