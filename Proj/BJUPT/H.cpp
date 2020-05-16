#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
const double eps = 1e-5;
const int N = 1e6 + 10;

int T;
ll n,m;
ll f[N];

ll pow(ll x, int p) {
    ll res = 1;
    while( p ) {
        if ( p & 1 ) {
            res *= x; res %= mod;
        }
        x*=x; x%=mod; p>>=1;
    }
    return res;
}

int main() {
    
    f[0] = 1;
    for (int i=1; i<=1e6; i++) {
        f[i] = f[i-1] * i; f[i] %= mod;
    }

    cin >> T;
    while (T--) {
        scanf("%lld%lld",&n,&m);
        ll ans = f[n];
        ans *= pow(m,mod-2); ans %=mod;

        printf("%lld\n",ans);
    }

    return 0;
}
