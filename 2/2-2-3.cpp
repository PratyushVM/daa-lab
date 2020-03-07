//2-2-3
#include<bits/stdc++.h>
using namespace std;

int main()
{
    char temp;
    int a[10000],i=0;
    while(1)
    {
        scanf("%d%c",&a[i++],&temp);
        if(temp=='\n')
        break;
    }

    for(i=0;;i++)
    {
        if(a[i]>a[i+1])
        break;
    }

    cout<<i+1;

    return(0);
}