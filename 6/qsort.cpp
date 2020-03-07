#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll partition(ll a[], ll low, ll high);
void quicksort(ll a[], ll low, ll high);

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

    quicksort(a,0,n-1);

    for(ll i=0;i<n;cout<<a[i++]<<" ");

    return 0;
}

void quicksort(ll a[], ll low, ll high)
{
    if(low<high)
    {
        ll pi=partition(a,low,high);

        quicksort(a,low,pi-1);
        quicksort(a,pi+1,high);
    }
}

ll partition(ll a[], ll low, ll high)
{
    ll pivot=a[high];
    ll i=low-1;
    
    for(ll j=low;j<high;j++)
    {
        if(a[j]<pivot)
        {
            i++;
            swap(a[i],a[j]);
        }
    }

    swap(a[i+1],a[high]);
    
    return i+1;
}

