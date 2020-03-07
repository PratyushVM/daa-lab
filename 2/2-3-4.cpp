//2-3-4
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    for(int i=n;i>0;i--)
    {
        for(int x=i;x>0;x--)
        cout<<"  ";

        for(int j=i;j<=n;j++)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    
    }

    return(0);
}