/*
* @ author: dragon_bra
* @ email: tommy514@foxmail.com
* @ data: 2020-09-24 23:33
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
const int N = 3e5 + 10;

void redirect() {
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
}

int T, n, q;
ll a[N];
int mk[N];

ll ans = 0;

void modi(int x) {
    if (x<1 || x>n) return;
    if (mk[x] == 1) {
        ans -= a[x]; mk[x] = 0;
    }
    if (mk[x] == -1) {
        ans += a[x]; mk[x] = 0;
    }
}

void check(int x) {
    if (x<1 || x>n) return;
    if (mk[x] == 0 && a[x] > a[x-1] && a[x] > a[x+1]) {
        ans += a[x]; mk[x] = 1;
    }
    if (mk[x] == 0 && a[x] < a[x-1] && a[x] < a[x+1]) {
        ans -= a[x]; mk[x] = -1;
    }
}

int main() {
    redirect();

    scanf("%d",&T);
    while (T--) {
        scanf("%d %d", &n, &q);
        for (int i=1; i<=n; i++) {
            scanf("%lld", &a[i]);
            mk[i] = 0;
        } a[0] = 0; a[n+1] = 0;

        ans = 0; bool flag = true;
        for (int i=1; i<=n; i++) {
            if (a[i] > a[i-1] && a[i] > a[i+1]) {
                ans += a[i]; mk[i] = 1;
            }
            else if (a[i] < a[i-1] && a[i] < a[i+1]) {
                ans -= a[i]; mk[i] = -1;
            }
        }

        //for (int i=1; i<=n; i++) cout << mk[i] << ' '; cout << endl;
        
        printf("%lld\n", ans);

        for (int i=1; i<=q; i++) {
            int l, r;
            scanf("%d%d", &l, &r);

            modi(l); modi(r); modi(l-1); modi(l+1); modi(r-1); modi(r+1);
            swap(a[l], a[r]);
            check(l); check(r); check(l-1); check(l+1); check(r-1); check(r+1);

            printf("%lld\n", ans);
        }
    }

    return 0;
}