/*
* @ author: dragon_bra
* @ email: tommy514@foxmail.com
* @ data: 2020-07-19 18:09
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
const int N = 1e5 + 10;

void redirect() {
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
}

struct node {
    ll a, b;
} f[N];

bool cmp(node a, node b) {
    if(a.a!=b.a) return a.a > b.a;
    return a.b > b.b;
}

int T;
int n, m;
ll pre[N];

int main() {
    redirect();

    cin >> T;
    while (T--) {
        scanf("%d %d", &n, &m);
        for (int i=1; i<=m; i++) {
            scanf("%lld %lld", &f[i].a, &f[i].b);
        }

        ll ans = 0;

        sort(f+1, f+m+1, cmp); 
        for (int i=1; i<=m; i++) pre[i] = pre[i-1] + f[i].a;
        //for (int i=1; i<=m; i++) cout << f[i].a << ' '; cout << endl;

        for (int i=1; i<=m; i++) {
            ll res = f[i].a; ll add = f[i].b;
            ll l = 1, r = m;

            ll mid;
            while (l<r) {
                mid = (l+r) / 2;
                if (f[mid].a < add) r = mid;
                else l = mid+1;
            }
            if (f[l].a <= add) l = l - 1;
            if (l>=n) {
                res = pre[n];
            } else {
                //cout << add << ' ' << l << endl;
                res += pre[l];
                ll cnt = n - l - 1;
                if (l>=i) res -= f[i].a, cnt ++;
                //cout << res << ' ' << l << ' ' << add << '*' << cnt << endl;
                res += add * cnt;
                //cout << "res: " << res << endl;
            }
            ans = max(ans, res);
        }

        printf("%lld\n", ans);
    }

    return 0;
}