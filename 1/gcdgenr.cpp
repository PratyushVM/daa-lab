//gcd fixed k integers recursive

#include<bits/stdc++.h>
using namespace std;

int gcdr(int a[], int i, int k, int m);
int gcd(int a, int b,int i);

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

    g = gcdr(a,2,k,gcd(a[0],a[1],min(a[0],a[1])));
    cout<<"GCD is "<<g;
    
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

int gcdr(int a[], int i, int k, int m)
{
   if(i==k)
   return m;
   else
   { 
     m = gcd(a[i],m,min(a[i],m));  
   } 
   return gcdr(a,++i,k,m);
}