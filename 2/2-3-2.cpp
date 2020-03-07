//2-3-2
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    for(int i=1;i<=n;i++)
    {


        for(int j=i;j<=n;j++)
        {
            cout<<j<<" ";
        }
        cout<<endl;
        
        for(int x=0;x<i;x++)
        cout<<"  ";
    }

    return(0);
}