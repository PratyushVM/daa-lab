#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pll pair<ll,ll>
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define vll vector<pll>
#define v vector<ll>
using namespace std;
void merge(ll a[],ll start,ll mid,ll end){
	ll p=start,q=mid+1,arr[end-start+1],k=0;
	for(ll i=start;i<=end;i++){
		if(p>mid)
			arr[k++]=a[q++];
		else if(q>end)
			arr[k++]=a[p++];
		else if(a[p]<a[q])
			arr[k++]=a[p++];
		else
			arr[k++]=a[q++];
	}
	for(ll i=0;i<k;i++)
		a[start++]=arr[i];
}
void mergesort(ll a[],ll start,ll end){
	ll mid[100];
	for(ll i=0;i<99;i++)
		mid[i]=start-1+((i+1)*(end-start+1)/100);
	if(end-start==9)
		sort(a+start,a+end+1);
	else{
		mergesort(a,start,mid[0]);
		for(ll i=0;i<98;i++)
			mergesort(a,mid[i]+1,mid[i+1]);
		mergesort(a,mid[98]+1,end);
	}
	merge(a,start,mid[0],mid[1]);
	for(ll i=1;i<98;i++)
		merge(a,start,mid[i],mid[i+1]);
	merge(a,start,mid[98],end);
}		
int main(){
	fastio;
	ll a[1000],i,j=1;
	for(i=0;i<500;i++)
		a[i]=2*(i+1);
	for(;i<1000;i++)
		a[i]=a[i-500]-1;
	mergesort(a,0,999);
	for(ll i=0;i<1000;cout<<a[i++]<<"\n");
} 
