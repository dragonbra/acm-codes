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
 
ll x,n; int num[51]; int cnt = 0;
 
int main() {
	redirect();
	scanf("%I64d%I64d",&x,&n); int cmp = sqrt(x)+1;
	for(int i=2;i<=cmp;i++){
		if(x%i==0) num[++cnt] = i;
	}
	if(cnt==0) num[++cnt] = x;
	
	ll ans = 1;
	for(int i=1;i<=cnt;i++){
		ll k = num[i]; int cc = 0;
		ll t = n/k;
		while(t){
			cc++;
			t/=k;
		}
		for(ll j=1,kk=1 ; j<=cc ; j++ ) {
			kk *= num[i];
			ans = ans * qp(num[i],n/kk) % mod;
		}
	}
	printf("%I64d\n",ans);
}
 
/*
-----------------
author:dragon_bra
-----------------
*/
