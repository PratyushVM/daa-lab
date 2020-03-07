#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ll a[1000000],n=0;
    char temp;

    cout<<"Enter elements of the array :"<<endl;
 
    while(1)
    {
        scanf("%lli%c",&a[n],&temp);
        n++;
        if(temp=='\n')
        break;
    }

    ll min=a[0],max=a[0],minind=0,maxind=0;
    ll i,j;
    
    for(i=1;i<n;i++)
    {
        if(a[i]<min)
        {
            min=a[i];
            minind=i;
        }
    }

    for(j=minind;j<n-1;j++)
    {
        a[j]=a[j+1];
    }

    
    for(i=1;i<n-1;i++)
    {
        if(a[i]>max)
        {
            max=a[i];
            maxind=i;
        }
    }

    cout<<"The global minimum is "<<min<<" at position "<<minind<<" and the global maximum is "<<max<<" at position "<<maxind<<endl;

    return 0;
}