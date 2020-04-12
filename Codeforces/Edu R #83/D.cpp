#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 998244353;
const double eps = 1e-5;
const int N = 2e5 + 10;

void redirect() {
    #ifdef LOCAL
        freopen("1.in","r",stdin);
        freopen("1.out","w",stdout);
    #endif
}

ll f[N], p[N];

ll fast(ll a,ll n){
    if(n==0)return 1;
    if(n%2)return a*fast(a,n-1)%mod;
    ll tmp=fast(a,n/2);
    return tmp*tmp%mod;
}

ll C(ll n,ll m){
    if(n==m || m==0)return 1;
    return f[n]*fast(f[m],mod-2)%mod*fast(f[n-m],mod-2)%mod;
}

ll n,m;
ll ans = 0;

int main() {
    redirect();

    f[0]=1,p[0]=1;
    for(ll i=1;i<=N-10;i++)
        f[i]=f[i-1]*i%mod,p[i]=p[i-1]*2%mod;

    cin>>n>>m;

    /*
    ll cst = 0;
    for(ll t = n-1; t<=m; t++){
        cst += C(t-1,n-2); cst %= mod;
    }

    for(ll pos = 2; pos<=n-1; pos++){
        ll res =  cst;
        res = cst*C(n-2,pos-1); res %= mod;
        res *= (pos-1); res %= mod;
        ans += res; ans %= mod;
    }
    */

    for(ll res=n-1;res<=m;res++){
        ll t=C(res-1,n-2)%mod;
        t=t*C(n-2,1)%mod;
        t=t*p[n-3]%mod;
        ans=(ans+t)%mod;
    }

    cout<<ans<<endl;

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/