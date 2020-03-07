//2-2-2
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

    int k=0;
    if(a[k]==-1)
    cout<<0;
    else
    k++;

    for(;;k*=4)
    {
        if(a[k]==-1)
        {
            cout<<k;
            break;
        }

        else if(a[k]>a[k+1])
        {
            k/=4;
            int x;
            for( x=k;x<=k*4;x++)
            {
                if(a[x]==-1)
                break;
            }
            cout<<x-1+k;
            break;
        }

    }



    return(0);
}