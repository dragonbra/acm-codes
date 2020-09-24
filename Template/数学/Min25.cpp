/*
* @ author: dragon_bra
* @ email: tommy514@foxmail.com
* @ data: 2020-09-20 13:59
*/
// n以内素数和
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

const int N = 2e5 + 10;

typedef long long ll;

void redirect() {
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
}

int T; ll n, K;

namespace Min25 {

    ll prime[N], id1[N], id2[N], flag[N], ncnt, m;

    ll g[N], sum[N], a[N], T, n;

    inline int ID(ll x) {
        return x <= T ? id1[x] : id2[n / x];
    }

    inline ll calc(ll x) {
        if (x % 2) return (x+1)/2 % K * x % K;
        else return x/2 % K * (x+1) % K;
        // return x * (x + 1) / 2 - 1;
    }

    inline ll f(ll x) {
        return x;
    }

    inline void init() {
        T = sqrt(n + 0.5);
        ncnt = 0; m = 0;
        memset(flag, 0, sizeof flag);
        memset(sum, 0, sizeof sum);
        memset(prime, 0, sizeof prime);
        memset(a, 0, sizeof a);
        for (int i = 2; i <= T; i++) {
            if (!flag[i]) prime[++ncnt] = i, sum[ncnt] = (sum[ncnt - 1] + i)%K;
            for (int j = 1; j <= ncnt && i * prime[j] <= T; j++) {
                flag[i * prime[j]] = 1;
                if (i % prime[j] == 0) break;
            }
        }
        for (ll l = 1; l <= n; l = n / (n / l) + 1) {
            a[++m] = n / l;
            if (a[m] <= T) id1[a[m]] = m; else id2[n / a[m]] = m;
            g[m] = calc(a[m]) % K;
        }
        for (int i = 1; i <= ncnt; i++) 
            for (int j = 1; j <= m && (ll)prime[i] * prime[i] <= a[j]; j++) {

                g[j] = (g[j] - (ll)prime[i] * (g[ID(a[j] / prime[i])] - sum[i - 1] + K) % K  + K) % K;
            }
    }

    inline ll solve(ll x) {
        if (x <= 1) return x;
        return n = x, init(), g[ID(n)];
    }

}

int main() {
    redirect();

    scanf("%d", &T);
    while (T--) {
        scanf("%lld %lld", &n, &K);
        n = n+1;
        ll ans = 0;
        if (n%2) {
            ans = (n+1)/2 % K * n % K;
        } else {
            ans = n/2 % K * (n+1) % K;
        }
        ans += Min25::solve(n) - 5;
        ans %= K;
        printf("%lld\n", ans);
    }
}