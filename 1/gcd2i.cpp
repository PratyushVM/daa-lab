//gcd 2 iterative

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
{   int c;
    while(b!=0)
    {
        c=a;
        a=b;
        b=c%b;
    }
    return a;
}