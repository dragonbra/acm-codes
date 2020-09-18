/*
* @ author: dragon_bra
* @ email: tommy514@foxmail.com
* @ data: 2020-09-17 22:37
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
int n, a[N], b[N];

bool cmp (int a, int b) {
    return a > b;
}

int main() {
    redirect();

    cin >> T;
    while (T--) {
        cin >> n;
        int acnt = 0, bcnt = 0;
        ll res = 1;
        for (int i=1; i<=n; i++) {
            int t; cin >> t; res *= t;
            if (t > 0) a[++acnt] = t;
            else b[++bcnt] = t;
        }

        sort(a+1, a+acnt+1, cmp);
        sort(b+1, b+bcnt+1);

        ll ans = -1e18;
        for (int i=0; i<=5; i++) {
            ll res = 1;
            if (bcnt >= i && acnt >= 5 - i) {
                ll ares = res, bres = res;
                for (int j=1; j<=i; j++) ares *= b[j];
                for (int j=bcnt; j>=bcnt-i+1; j--) bres *= b[j];
                
                res = max(ares, bres);
                ll resa = res, resb = res;
                //cout << i << ' ' << resa << ' ' << resb << endl;
                for (int j=1; j<=5 - i; j++) resa *= a[j];
                for (int j=acnt; j>=acnt-4+i; j--) resb *= a[j];
                ans = max(ans, max(resa, resb));
                //cout << i << ' ' << resa << ' ' << resb << endl;
            }
        }
        cout << ans << endl;
    }

    return 0;
}