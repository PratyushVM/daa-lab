#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

struct node
{
    ll a;
    node *left,*right;
};

node* insert(node *ptr, ll x);
void inorder(node *ptr);

node *tptr=NULL;

int main()
{
    ll n,a[100][100],size[100000];
    cout<<"Enter the number of arrays"<<"\n";
    cin>>n;
    for(ll i=0;i<n;i++)
    {
        ll j=0;char temp;
        cout<<"Enter elements of array "<<i+1<<"\n";
        
            while(1)
            {
                scanf("%lli%c",&a[i][j],&temp);
                j++;
                if(temp=='\n')
                break;
            }
        size[i]=j;        
    }
    
    ll p=0;
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<size[i];j++)
        {
            tptr=insert(tptr,a[i][j]);
        }
    }
    
    inorder(tptr);

    return 0;
}

 node* insert(struct node *ptr, ll x)
{
    node* temp=new node;
    temp->a=x;
    if(ptr==NULL)
    ptr=temp;
    else if(ptr->a>=x)
    ptr->left=insert(ptr->left,x);
    else
    ptr->right=insert(ptr->right,x);
    return ptr;
}

void inorder(struct node *ptr)
{
    if(ptr!=NULL)
    {
        inorder(ptr->left);
        cout<<ptr->a<<" ";
        inorder(ptr->right);
    }
}