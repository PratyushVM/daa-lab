//gcd 1 recursive

#include<bits/stdc++.h>

int gcd(int a, int b);

int main()
{
    int a,b,gc=1;
    
    printf("Enter the two numbers to find gcd for :\n");
    scanf(" %d%d",&a,&b);
    gc = gcd(a,b);
    printf("The gcd is %d",gc);
    
    return(0);
}

int gcd(int a, int b)
{
    if(b==0)
    return a;
    else
    return(gcd(b,a%b));
}