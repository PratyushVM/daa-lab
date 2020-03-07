//gcd 4 recursive

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
       
    if( a == 0 )
    return b;
    else if( b == 0 )
    return a;
    else
    {
        return gcd(abs(a-b),min(a,b));
    }
}