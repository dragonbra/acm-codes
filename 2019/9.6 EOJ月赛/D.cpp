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

ll pow_mod(ll a, ll b, ll p){//a的b次方求余p
    ll ret = 1;
    while(b){
       if(b & 1) ret = (ret * a) % p;
        a = (a * a) % p;
        b >>= 1;
    }
    return ret;
}
ll Fermat(ll a, ll p){//费马求a关于b的逆元
    return pow_mod(a, p-2, p);
}

int main() {
	redirect();
	int T;scanf("%d",&T);
	while(T--){
		ll n;scanf("%lld",&n);
		ll nn=n;ll cmp=0;
		while(nn%2==0){
			nn/=2;cmp+=1;
		}
		
		ll fm = pow_mod(2,n-1-cmp,mod);
		ll ans = nn%mod*Fermat(fm,mod)%mod;
		printf("%lld\n",ans);
		
	}
}

/*
---------------------
  author:dragon_bra
---------------------
*/

