//2.1 logic 1 bf
#include<bits/stdc++.h>
#define ll long long int
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int a[1000];
int main()
{
    //fastio;

    int p,i=0,j,k,flag=0,n;

    cout<<"Enter n";
    cin>>n;
    
    cout<<"Enter the elements of the array";
    while(i<n)
    {cin>>a[i++];}
    
    cout<<"Enter p";
    cin>>p;

    for(j=0;j<i;j++)
    {
        for(k=j+1;k<i;k++)
        {
            if(a[j]+a[k]==p)
            {
                flag=1;
                cout<<"The numbers are "<<a[j]<<" and "<<a[k]<<" at "<<j<<"and "<<k<<" respectively";
            }
        }
    }

    if(flag==0)
    cout<<"q and r DNE in array a";
    
    
    return(0);
}