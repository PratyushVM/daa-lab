//4_1
#include<bits/stdc++.h>
using namespace std;

int gcddc(int a[], int start, int end);

int main()
{
    int n,i;
    cout<<"Enter n";
    cin>>n;
    cout<<"Enter the numbers";
    int a[n];
    for(i=0;i<n;i++)
    cin>>a[i];
    int g = gcddc(a,0,n-1);
    cout<<"The gcd is "<<g;
    return 0;
}

int gcddc(int a[], int start, int end)
{
    int mid=(start+end)/2;
    if(start<end)
    {
        return __gcd(gcddc(a,start,mid),gcddc(a,mid+1,end));
    }
    return a[mid];
}