//2-3-5
#include<bits/stdc++.h>
#include<math.h>
using namespace std;

int main()
{
    float n;
    cin>>n;

for(int i=1;i<=ceil(n/2);i++)
{
    for(int x=1;x<i;x++)
    cout<<"  ";

    for(int j=i;j<=n-i+1;j++)
    cout<<j<<" ";
    
    cout<<endl;
}

for(int i=ceil(n/2);i>=1;i--)
{
    for(int x=1;x<i;x++)
    cout<<"  ";

    for(int j=i;j<=n+1-i;j++)
    cout<<j<<" ";

    cout<<endl;
}
    return(0);
}