//insertion sort
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,i,j,t;
    
    cout<<"Enter the number of elements";
    cin>>n;

    int a[n];

    cout<<"Enter the elements";
 
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }

    for(i=1;i<n;i++)
    {
       t=a[i];
       j=i-1;

        while(a[j]>t && j>=0)
        {
            a[j+1]=a[j];
            j--;
        }

        a[j+1]=t;      
        
    }

    for(i=0;i<n;i++)
    cout<<a[i]<<" ";

    return 0;
}