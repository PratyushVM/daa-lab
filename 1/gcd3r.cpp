//gcd 3 recursive

#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b, int i);

int main()
{
    int a,b,gc;
    
    cout<<"Enter the two numbers to find gcd for";
    cin>>a>>b;

    gc = gcd(a,b,min(a,b));

    cout<<"The gcd is "<<gc;

    return 0;
}

int gcd(int a, int b, int i)
{
    if(a%i==0 && b%i==0)
    return i;

    else
    {
        return(gcd(a,b,--i));
    }
    
}