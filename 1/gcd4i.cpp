//gcd 4 iterative

#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b);

int main()
{
    int a,b,gc;
    
    cout<<"Enter the two numbers to find gcd for";
    cin>>a>>b;

    gc = gcd(a,b);

    cout<<"The gcd is "<<gc;

    return 0;
}

int gcd(int a, int b)
{   
    if(a>b)
    swap(a,b);
    int c;
    
    while(a!=0&&b!=0)
    {
        c=a;
        a=abs(c-b);
        b=min(c,b);
    }

    if(a==0)
    return b;

    else
    {
        return a;
    }
   
}