//serial C code implementing merge sort for an integer array

#include<stdio.h>

void merge_sort(int a[], int start, int end);
void merge(int a[], int start, int mid, int end);


int main()
{

    int n,i;
    
    printf("Enter the number of elements\n");
    scanf(" %d",&n);

    int a[n];

    printf("Enter the elements\n");
    for(i = 0; i < n; i++)
    {

        scanf(" %d",&a[i]);

    }

    merge_sort(a,0,n-1);

    for ( i = 0; i < n; i++)
    {
        
        printf("%d ",a[i]);
    
    }
    
     
    return(0);

}


void merge_sort(int a[], int start, int end)
{

    if(start < end)
    {

        int mid = (start + end)>>1;                                 // mid is arithmetic mean of start and end
        
        merge_sort(a, start, mid);
        merge_sort(a, mid+1, end);

        merge(a, start, mid, end);

    }

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