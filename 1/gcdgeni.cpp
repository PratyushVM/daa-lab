//gcd fixed k integers iterative

#include<bits/stdc++.h>
using namespace std;

int gcdi(int a[], int k);
int gcd(int a, int b);

int main()
{
    int k,i,g;
    cout<<"Enter the number of integers";
    cin>>k;
    int a[k];
    cout<<"Enter the elements";
    for(i=0;i<k;i++)
    {
        cin>>a[i];
    }

    g = gcdi(a,k);
    cout<<"GCD is "<<g;
    
    return 0;

}

int gcdi(int a[], int k)
{   
    int s = gcd(a[0],a[1]);
    for(int i=2;i<k;i++)
    {
        s = gcd(a[i],s);
    }
    return s;
}

int gcd(int a,int b)
{   int k=1;
    for(int i=1;i<=min(a,b);i++)
    {
        if(a%i==0 && b%i==0)
        k=i;
    }
    return k;
}