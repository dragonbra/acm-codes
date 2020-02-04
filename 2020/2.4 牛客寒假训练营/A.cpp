#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
const double eps = 1e-5;
const int N = 1e5 + 10;

void redirect() {
    #ifdef LOCAL
        freopen("1.in","r",stdin);
        freopen("1.out","w",stdout);
    #endif
}

ll n,m;

int main() {
    redirect();

    cin>>n>>m;
    ll ans = 0;

    ll res = ( (n-2)*(m-1) + (n-1)*(m-2) ) % mod * 6 % mod;
    ans += res; ans %= mod;
    
    res = (n-2) * (n-3) % mod * (m-1) * 2 % mod;
    ans += res; ans %= mod;

    res = (m-2) * (m-3) % mod * (n-1) * 2 % mod;
    ans += res; ans %= mod;

    res = (n-1) * (n-2) % mod * (m-2) * 2 % mod;
    ans += res; ans %= mod;

    swap(n,m);
    res = (n-1) * (n-2) % mod * (m-2) * 2 % mod;
    ans += res; ans %= mod;

    cout<<ans<<endl;

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/