//2-2-1
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

    for(i=0;a[i]!=-1;i++);

    cout<<i;

    return(0);
}