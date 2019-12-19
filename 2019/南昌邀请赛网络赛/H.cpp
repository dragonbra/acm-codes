#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1000000007;
ll qp(ll x,ll n){
	ll res = 1;
	while(n){
		if(n&1) res*=x,res%=mod;
		x*=x;x%=mod;
		n>>=1;
	}
	return res;
}

int main(){
	ll n;
	while(~scanf("%lld",&n)){
		ll ans;
		if(n==1) ans = 1;
		else ans = qp(3,n-2)*2*2%mod;
		printf("%lld\n",ans);
	}
	return 0;
}
