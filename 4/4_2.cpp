//4_2
#include<bits/stdc++.h>
using namespace std;

int fn(int a[], int start, int end);

int main()
{
    int n,i;
    cout<<"Enter n";
    cin>>n;
    cout<<"Enter the numbers";
    int a[n];
    for(i=0;i<n;i++)
    cin>>a[i];
    int g = fn(a,0,n-1);
    cout<<"The number of ones are "<<g;
    return 0;
}

int fn(int a[], int start, int end)
{
    int mid=(start+end)/2;
    if(start<end)
    {
        return fn(a,start,mid) + fn(a,mid+1,end);
    }
    return a[mid];
}