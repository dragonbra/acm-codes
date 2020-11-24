/*
* @ author: dragon_bra
* @ email: tommy514@foxmail.com
* @ data: 2020-11-20 21:51
*/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <vector>

using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
const double eps = 1e-5;
const int N = 5e5 + 10;

void redirect() {
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
}

int n;
int a[N];
struct node {
    int a;
    ll num;
} b[N];
ll f[N];

ll qpow(ll x, ll p) {
    ll res = 1;
    while (p) {
        if (p&1) {
            res *= x;
            res %= mod;
        }
        x *= x;
        x %= mod;
        p /= 2;
    }
    return res;
}

int main() {
    redirect();

    scanf("%d", &n);
    f[1] = 1;
    for (int i=2; i<=n; i++) {
        f[i] = f[i-1] * i % mod;
    }

    for (int i=1; i<=n; i++) {
        scanf("%d", &a[i]);
    }
    sort (a+1, a+n+1);
    int num = 0; int cnt = -1;
    for (int i=1; i<=n; i++) {
        if (a[i] != a[i-1]) {
            b[++cnt].a = a[i-1];
            b[cnt].num = num;
            num = 1; 
        } else {
            num ++;
        }
    }
    b[++cnt].a = a[n];
    b[cnt].num = num;

    ll ans = 1;
    
    if (cnt == 1) {
        ans = f[n];
    } else {
        for (int i=1; i<cnt; i++) {
            ans *= f[b[i].num]; ans %= mod;
            ans *= (b[i].num + 1); ans %= mod;
        }
        ans *= f[b[cnt].num]; ans %= mod;
    }
    
    printf("%lld\n", ans);

    return 0;
}