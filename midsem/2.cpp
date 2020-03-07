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

    ll min=a[0],max=a[0];
    ll i;

    for(i=0;i<n-1;i+=2)
    {
        if(a[i]>a[i+1])
        {
            swap(a[i],a[i+1]);
        }        
    }

    for(i=0;i<n;i+=2)
    {
        if(a[i]<min)
        {
            min=a[i];
        }
    }

    if(n!=1)
    {
        for(i=1;i<n;i+=2)
        {
            if(a[i]>max)
            {
                max=a[i];
            }
        }

        if(n%2!=0)
        {
            if(a[n-1]>max)
            {
                max=a[n-1];
            }
        }
    }

    cout<<"The global minimum is "<<min<<" and the global maximum is "<<max<<endl;

    return 0;
}