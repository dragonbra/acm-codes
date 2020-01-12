#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 998244353;
const double eps = 1e-5;
const int N = 1e5 + 5;

#define LOCAL
void redirect() {
    #ifdef LOCAL
        freopen("1.in","r",stdin);
        freopen("1.out","w",stdout);
    #endif
}

inline ll read() {
    ll f=1,x=0;char ch;
    do {ch=getchar(); if(ch=='-') f=-1;} while (ch<'0'||ch>'9');
    do {x=x*10+ch-'0'; ch=getchar(); } while (ch>='0'&&ch<='9');
    return x*f;
}

int T; 
ll n,l,r; ll ans;
ll a[N]; int cnt;

ll cal(ll x){
    if(x==0) return 0;
    
    ll res = 0;
    for(int pt = 2; pt <= cnt; pt++) {
        if(a[pt]>x) a[pt] = x + 1;
        //cout<<a[pt]<<' ';

        ll N = n / a[pt-1]; //cout<<N<<' '<<M<<endl;
        ll len = ( a[pt] - a[pt-1] ) % mod; ll sum = ( ( a[pt-1] + a[pt] - 1 ) * ( a[pt] - a[pt-1] ) / 2 ) % mod;
        
        res += n * n % mod * len % mod; res %= mod;
        res -= 2 * N % mod * (n * len - N * sum); res %= mod; res = (res+mod) % mod;
        res -= (n * len - N * sum) * len % mod; res %= mod; res = (res+mod) % mod;
        res -= N * N % mod * sum % mod; res %= mod; res = (res+mod) % mod;

        if(a[pt]==x+1) break;
    }

    return res;
}

int main() {
    redirect();

    scanf("%d",&T);
    while(T--){
        scanf("%lld%lld%lld",&n,&l,&r);
        cnt = 0; ll cmp = sqrt(n);
        for(ll i=1;i<=cmp;i++){
            if(n%i==0) {
                a[++cnt] = i;
                if(n/i!=i) a[++cnt] = n/i;
            }
        }

        sort(a+1,a+cnt+1);

        //cout<<cal(r)<<' ';
        ll ans = cal(r) - cal(l-1);
        //cout<<cal(l-1)<<endl;
        ans /= 2;

        printf("%lld\n",ans);
    }

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/