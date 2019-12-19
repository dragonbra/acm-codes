#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF = 0x7fffffff;
const int mod = 1e9+7;
const double eps = 1e-5;
const int N = 1e5+10;

void redirect() {
    #ifdef LOCAL
        //freopen("test.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
}
inline ll read() {
    ll f=1,x=0;char ch;
    do {ch=getchar(); if(ch=='-') f=-1;} while (ch<'0'||ch>'9');
    do {x=x*10+ch-'0'; ch=getchar(); } while (ch>='0'&&ch<='9');
    return x*f;
}

ll qp(ll x,ll a){
	ll res = 1;
	while(a){
		if(a&1) res*=x,res%=mod;
		x*=x; x%=mod;
		a>>=1;
	}
	return res;
}

ll x,n; int cnt = 0, ccnt = 0;
bool vis[N]; ll prime[N]; ll num[N]; 

int main() {
	redirect();
	scanf("%I64d%I64d",&x,&n); 
	
	ll cmp = sqrt(x)+0.5; ll ccmp = sqrt(cmp)+0.5;
	
	for(int i=2; i<=ccmp; i++) {
		if(!vis[i]) for(int j=i*i; j<=cmp; j+=i) vis[j]=1;
	}
	
	for(int i=2;i<=cmp;i++) if(!vis[i]) prime[++cnt] = i;
	
	ll t = x; int pt = 1;
	while( t>1 && pt<=cnt ){
		if(t%prime[pt]==0) num[++ccnt]=prime[pt];
		while(t&&t%prime[pt]==0){
			t/=prime[pt];
		}
		pt++;
	}
	if(t>1) num[++ccnt] = t;
	
	//cout<<"YES"<<endl;
	
	ll ans = 1;
	for(int i=1;i<=ccnt;i++){
		ll k = num[i]; ll cc = 0; ll t = n/k;
		while(t){
			cc++;
			t/=k;
		}
		for(ll j=1,kk=1 ; j<=cc ; j++ ) {
			kk *= k;
			ans = ans * qp(k,n/kk) % mod;
		}
	}
	
	printf("%I64d\n",ans);
	
	//for(int i=1;i<=ccnt;i++) cout<<num[i]<<' ';
}

/*
-----------------
author:dragon_bra
-----------------
*/

