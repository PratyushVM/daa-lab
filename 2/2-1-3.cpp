//2-1-3 
#include<bits/stdc++.h>
#define ll long long int
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int main()
{
    //fastio;

    ll i=0,a[10000],p,l;
    char temp;

    unordered_set<ll>s;

    cout<<"Enter elements of the array";
    while(1)
    {
        scanf("%lli%c",&a[i],&temp);
        if(temp=='\n')
        break;
        i++;
    }      

    cout<<"Enter p";
    cin>>p;

    for(l=0;l<=i;l++)
    {
        if(s.find(a[l])!=s.end())
        {
            cout<<"Yes they exist";
            return(0);
        }
        else
        s.insert(p-a[l]);
    }

    cout<<"NO they DNE";
    return(0);

}