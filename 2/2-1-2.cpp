//2-1-2 
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main()
{
    ///fastio;

    ll i=0,a[10000],*x,*y,p;
    char temp;

    cout<<"Enter elements of the array";
    while(1)
    {
        scanf("%lli%c",&a[i],&temp);
        if(temp=='\n')
        break;
        i++;
    }

    cout<<"Enter p";
    cin>>p;

    x=a;
    y=&a[i];

    sort(a,a+i+1);

    for(;;x>=y)
    {
        if(*x+*y==p)
        {
        cout<<*x<<" and "<<*y<<" are present in the array whose sum is "<<p;
        return(0);
        }
    

        else if(*x+*y>p)
        y--;

        else
        x++;
    }

    cout<<"q and r DNE in array a ";
     
    return(0);
}