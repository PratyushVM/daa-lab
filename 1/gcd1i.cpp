//gcd 1 iterative

#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b);

int main()
{
    int a,b,g;
    
    cout<<"Enter the two numbers to find gcd for";
    cin>>a>>b;

    g = gcd(a,b);

    cout<<"The gcd is "<<g;
    
    return 0;
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