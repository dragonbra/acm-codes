/*
* @ author: dragon_bra
* @ email: tommy514@foxmail.com
* @ data: 2020-09-17 23:32
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

int n, q;
ll a[N];
struct node {
    int l, r;
    ll x;
} que[N];
ll dif[N];
ll change = 0;

ll cal(ll x) {
    //cout << x << ' ';
    if (x%2 == 1) x += 1;
    return x / 2;
}

void out() {
    if (n == 1) cout << cal(a[1]) << endl;
    else cout << cal(a[1] + change) << endl;
}

int main() {
    redirect();

    cin >> n;
    for (int i=1; i<=n; i++) cin >> a[i];
    cin >> q;
    for (int i=1; i<=q; i++) {
        cin >> que[i].l >> que[i].r >> que[i].x;
    }

    for (int i=2; i<=n; i++) {
        dif[i] = a[i] - a[i-1];
        if (dif[i] > 0) change += dif[i];
    }
    out();

    for (int i=1; i<=q; i++) {
        int l = que[i].l, r = que[i].r;
        ll x = que[i].x;

        if (l <= 1) a[1] += x;
        
        if (l != 1) {
            if (dif[l] > 0) change -= dif[l];
            dif[l] += x;
            if (dif[l] > 0) change += dif[l];
        }
        if (r+1 <= n) {
            if (dif[r+1] > 0) change -= dif[r+1];
            dif[r+1] -= x;
            if (dif[r+1] > 0) change += dif[r+1];
        }
        out();
    }


    return 0;
}