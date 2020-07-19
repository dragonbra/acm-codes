/*
* @ author: dragon_bra
* @ email: tommy514@foxmail.com
* @ data: 2020-07-19 15:27
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
const int N = 2e5 + 10;

void redirect() {
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
}

int T;
int n, a[N];

ll qpow(ll x, ll p) {
    ll res = 1;
    while (p) {
        if (p&1) {
            res *= x;
            res %= mod;
        }
        x *= x;
        x %= mod;
        p >>= 1;
    }
    return res;
}

int main() {
    redirect();

    cin >> T;
    while (T--) {
        cin >> n;
        ll cnt = 0, ecnt = 0;
        for (int i=1; i<=n; i++) {
            scanf("%d", &a[i]);
            if (i>=2) {
                if (a[i]==a[i-1]) {
                    cnt += a[i]/2;
                } else {
                    cnt += ( a[i]/2 + 1 ) / 2;
                    if ((a[i]/2) % 2 == 0) {
                        ecnt += 1;
                    }
                }
            }
        }
        if (ecnt %2 ==0) {
            cnt += ecnt / 2;
            cnt %= mod;
        } else {
            cnt *= 2; cnt += ecnt;
            cout << cnt << endl;
            cnt = cnt * qpow(2, mod-2) % mod;
        }
        printf("%lld\n", cnt);
    }

    return 0;
}