//4_5 3-way-mergesort
#include<bits/stdc++.h>
using namespace std;

void mergesort(int a[], int start, int end);
void merge(int a[], int start, int mid, int end);


int main()
{
    int n,i;

    cout<<"Enter the number of elements :"<<endl;
    cin>>n;

    int a[n];
    cout<<"Enter the elements :"<<endl;
    for(i=0; i<n; i++)
    {
        cin>>a[i];
    }

    mergesort(a,0,n-1);

    cout<<"Sorted order :"<<endl;

    for(i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }

    return 0;

}

void mergesort(int a[], int start, int end)
{
    int mid1 = start + (end-start)/3;
    int mid2 = start + (2*(end-start))/3; 
    
    if(end-start<2)
    {
        if(a[start]>a[end])
        swap(a[start],a[end]);
    }
    

    else
    {           
        mergesort(a,start,mid1);
        mergesort(a,mid1+1,mid2);
        mergesort(a,mid2+1,end);
    }

    merge(a,start,mid1,mid2);
    merge(a,start,mid2,end);    
}

void merge(int a[], int start, int mid, int end)
{

    int p = start, q = mid+1, arr[end-start+1], k = 0,i;

    for ( i = start; i <= end; i++)
    {
        if(p > mid)
            arr[k++] = a[q++];
        
        else if(q > end)
            arr[k++] = a[p++];

        else if(a[p] < a[q])
            arr[k++] = a[p++];

        else 
            arr[k++] = a[q++];

    }

    for ( i = 0; i < k; i++)
    {
        
        a[start++] = arr[i];

    }
    
    

}


