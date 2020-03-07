#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
using namespace std;
ll a1[1000];
void bconquer(ll out[],ll size[],ll l,ll r,ll a[][1000]){
	ll z=0;
	for(ll i=0;i<l;z+=size[i++]);
	ll i=0,j=0;
	while(i!=size[l]&&j!=size[r]){
		if(a[l][i]<a[r][j]){
			out[z]=a[l][i];
			i++;
			z++;}
		else{
			out[z]=a[r][j];
			i++;
			z++;}
	}
	while(i<size[l]){
		out[z]=a[l][i];
		z++;i++;}
	while(j<size[r]){
		out[z]=a[r][j];
		z++;j++;}
}
void conquer(ll out[],ll size[],ll l,ll r,ll m){
	ll t1[1000],t2[1000],s1=0,s2=0;
	ll z=0;
	for(ll i=0;i<l;z+=size[i++]);
	ll temp=z;
	for(ll i=l;i<=m;i++)
		s1+=size[i];
	for(ll j=m+1;j<=r;s2+=size[j++]);
	ll a=0,b=0;
	while(temp<s1){
		t1[a]=out[temp];
		a++;temp++;}
	while(temp<s1+s2){
		t2[b]=out[temp];
		b++;temp++;}
	ll i=0,j=0;
	while(i!=a&&j!=b){
		if(t1[i]<t2[j]){
			out[z]=t1[i];
			i++;
			z++;}
		else{
			out[z]=t2[j];
			j++;
			z++;}
	}
	while(i<a){
		out[z]=t1[i];
		z++;i++;}
	while(j<b){
		out[z]=t2[j];
		z++;j++;}
}
void divide(ll out[],ll size[],ll l,ll r,ll a[][1000]){
	ll m=(l+r)/2;
	if(l==r-1)
		bconquer(out,size,l,r,a);
	else{
		divide(out,size,l,m,a);
		divide(out,size,m+1,r,a);
		conquer(out,size,l,r,m);
		}
}
		
int main(){
	fastio;
	ll k;
	ll a[1000][1000];
	char temp;
	cin>>k;
	ll size[k];
	ll j,sum=0;
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
	//for(ll i=0;i<k;cout<<size[i++]<<" ");
	ll out[1000];
	divide(out,size,0,k-1,a);
	for(ll i=0;i<sum;cout<<out[i++]<<" ");
}
	
	

