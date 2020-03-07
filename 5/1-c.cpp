#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
using namespace std;
ll minarr(ll b[],ll n){
	ll x=b[0];
	ll imin=0;
	for(ll i=1;i<n;i++)
		if(b[i]<x){
			x=b[i];
			imin=i;}
	return imin;
}
int main(){
	fastio;
	ll a[1000][1000],k,j;
	cin>>k;
	ll size[1000],sum=0;
	char temp;
	for(ll i=0;i<k;i++){
		j=0;
		while(1){
			scanf("%lld%c",&a[i][j],&temp);
			j++;
			if(temp=='\n')
				break;
		}
		size[i]=j;
		sum+=size[i];
	}
	ll po[1000];
	memset(po,0,sizeof(po));
	ll tem[k];
	ll out[sum];
	ll count=0,ans=0;
	while(count<sum){
		if(po[ans]==size[ans])
			a[ans][po[ans]]=(ll)1e5;
		for(ll i=0;i<k;i++)
			tem[i]=a[i][po[i]];
		 ans=minarr(tem,k);
		out[count]=a[ans][po[ans]];
		if(po[ans]<size[ans])
			po[ans]++;
		count++;
	}
	//for(ll i=0;i<k;i++){
		//for(ll j=0;j<size[i];j++){
			//cout<<a[i][j]<<" "
	for(ll i=0;i<sum;cout<<out[i++]<<" ");
}
