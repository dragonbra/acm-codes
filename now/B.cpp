/*
* @ author: dragon_bra
* @ email: tommy514@foxmail.com
* @ data: 2020-07-19 17:56
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
ll l, r, m;

int main() {
    redirect();

    cin >> T;
    while (T--) {
        scanf("%lld %lld %lld", &l, &r, &m);
        ll len = r - l;
        ll dif, a, b, c;
        for (ll i=l; i<=r; i++) {
            if (m/i>0) {
                dif = min (m - m/i * i, (m/i+1) * i - m);
                if (dif <= len) {
                    a = i;
                    break;
                }
            } else {
                dif = (m/i+1) * i - m;
                if (dif <= len) {
                    a = i;
                    break;
                }
            }
        }
        if ((m/a+1) * a - m == dif) {
            b = l;
            c = l + dif;
        } else {
            c = l;
            b = l + dif;
        }
        printf("%lld %lld %lld\n", a, b, c);
    }

    return 0;
}