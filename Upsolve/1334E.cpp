/*
    Edu R #85 E
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 998244353;
const double eps = 1e-5;
const int N = 1e5 + 10;

void redirect() {
    #ifdef LOCAL
        freopen("1.in","r",stdin);
        freopen("1.out","w",stdout);
    #endif
}

ll D; int q;
ll x,y;

vector<ll> primes;
vector<ll> dw, up;

ll fac[N], rfac[N];

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

ll gcd (ll a, ll b) {
    if( a>b ) swap(a,b);
    return a==0 ? b:gcd(b%a,a);
}

void init_fac() {
    fac[0] = 1, rfac[0] = 1;
    for ( int i=1; i<=100; i++ ) {
        fac[i] = fac[i-1] * i;
        fac[i] %= mod;
    }
    rfac[100] = pow(fac[100],mod-2);
    for ( int i=100; i>=2; i-- ) {
        rfac[i-1] = rfac[i] * i;
        rfac[i-1] %= mod;
    }
}

int main() {
    redirect();

    scanf("%lld",&D);

    for(ll i=2; i*i<=D; i++) {
        if( D%i==0 ) {
            while( D%i==0 ) D/=i;
            primes.push_back(i);
        }
    }
    if( D>1 ) primes.push_back(D);

    init_fac();

    scanf("%d",&q);

    for ( int i=1; i<=q; i++ ) {
        scanf( "%lld%lld", &x, &y );
        ll ans = 1;
        ll lca = gcd (x, y);
        x = x/lca, y = y/lca;

        int cnt1 = 0, cnt2 = 0;

        for(auto p:primes) {
            if( x%p == 0 ) { 
                int cnt = 0;
                while( x%p == 0 ) {
                    x /= p; cnt1++; cnt++;
                }
                ans *= rfac[cnt]; ans %= mod;
            }

            if( y%p == 0 ) { 
                int cnt = 0;
                while( y%p == 0 ) {
                    y /= p; cnt2++; cnt++;
                }
                ans *= rfac[cnt]; ans %= mod;
            }
        }

        ans *= fac[cnt1]; ans %= mod; ans *= fac[cnt2]; ans %= mod;

        printf("%lld\n",ans);
    }

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/