#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ll t[10000],t1[10000],n,k=2;
    cout<<"Enter the number of elements"<<endl;
    cin>>n;
    cout<<"Enter the elements :"<<endl;
    for(ll i=0;i<n;cin>>t[i++]);
    copy(begin(t),end(t),begin(t1));

    while(k<=2*n)
    {
        for(ll i=0;i<n;i+=k)
        {
            if(t[i+(k/2)]>t[i])
            {
                swap(t[i+(k/2)],t[i]);
            }
        }
        k*=2;
    }

    ll j=2,smax=t[2];
    while(j<=n)
    { 
        if(t[j]>smax)
        {
            smax=t[j];
        }
        j*=2;
    }
    ll i;

    for(i=0;i<n;i++)
    {
        if(t1[i]==t[0])
        break;
    }
    //if(i%2==0)
    {
        if(t1[i+1]>smax)
        smax=t1[i+1];
    }
    //else
    {
        if(t1[i-1]>smax)
        smax=t1[i-1];
    }
    
    cout<<"The max is "<<t[0]<<" and second max is "<<smax<<endl;

    return 0;
}