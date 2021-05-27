// https://codeforces.com/gym/102055/problem/K
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,c,x,y;
ll mulit(ll x,ll y,ll mod){
	long long tmp=(x*y-(long long)((long double)x*y/mod+0.5)*mod);
	return tmp<0 ? tmp+mod : tmp;
//	ll res=0;
//	while(b){
//		if(b&1)res=(res+a)%c;
//		a=(a+a)%c;
//		b>>=1;
//	}
//	return res;
}
ll quick(ll a,ll b,ll c){
	a%=c;
	ll res=1ll%c;
	while(b){
		if(b&1)res=mulit(a,res,c);
		a=mulit(a,a,c);
		b>>=1;
	} 
	return res;
}
ll exgcd(ll a,ll b,ll& x,ll& y){
	if(b==0){
		x=1,y=0;
		return a;
	}
	ll ttt = exgcd(b,a%b,x,y);
	ll tmp=x;
	x=y;
	y=tmp-a/b*y;
	return ttt;
}
int main(){
	int T,tttt=0;
	scanf("%d",&T);
    ll d=(1<<30) + 3;
	while(T--){
		ll p,q;
		scanf("%lld%lld",&n,&c);
		for(long long i=sqrt((long long)n);i>=1;i--)
			if(n%i==0){p=i,q=n/i;break;}
		ll e=(p-1)*(q-1);
		//printf("%lld\n",d);
		assert(d > 0);
		
		ll gcd = exgcd(d,e,x,y);
		x%=e;x+=e;x%=e;
		assert(gcd == 1);
		printf("Case %d: %lld\n",++tttt,quick(c,x,n));
		
	}
	return 0;
} 