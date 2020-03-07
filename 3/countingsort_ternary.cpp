//counting sort (ternary)

#include<bits/stdc++.h>
using namespace std;

void countsort(char a[],int n);

int main()
{
    int n;
    cout<<"Enter the number of elements ";
    cin>>n;

    int i;
    char a[n];

    cout<<"Enter the elements";

    for(i=0;i<n;i++)
    cin>>a[i];

    countsort(a,n);
        
    return 0;
}

void countsort(char a[],int n)
{
    char op[n];
    int count[3]={0,0,0},i;


    //memset(count,0,sizeof(count));
    
    //for(i=0;i<3;i++)
    //cout<<count[i]<<" ";

    for(i=0;i<n;i++)
    {++count[(int)a[i]-48];
    }

    for(i=0;i<2;i++)
    count[i+1]+=count[i];

    for(i=n-1;i>=0;i--)
    {
       op[count[(int)a[i]-48]-1] = a[i];
       --count[(int)a[i]-48];
    }

    for(i=0;i<n;i++)
    cout<<op[i]<<" ";
}