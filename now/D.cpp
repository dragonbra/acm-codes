/*
* @ author: dragon_bra
* @ email: tommy514@foxmail.com
* @ data: 2020-09-24 22:39
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
const ll mod = 998244353;
const double eps = 1e-5;
const int N = 3e5 + 10;

void redirect() {
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
}

int n, k;
struct node {
    int pos, val;
} a[N*2];

bool cmp (node a, node b) {
    if (a.pos == b.pos) return a.val > b.val;
    return a.pos < b.pos;
}

ll C[N];
ll Inv(ll a, int m) {
    ll d, x, y, t = (ll)m;	
	d = Ext_gcd(a, t, x, y);	
	if (d == 1) return (x%t + t) % t;	
	return -1;
} 

int main() {
    redirect();

    cin >> n >> k;
    int cnt = 0;
    for (int i=1; i<=n; i++) {
        int l, r;
        scanf("%d %d", &l, &r);
        a[++cnt].pos = l; a[cnt].val = 1;
        a[++cnt].pos = r; a[cnt].val = -1;
    }
    sort (a+1, a+cnt+1, cmp);


    C[k-1] = 1;
    // cout << C[k-1] << ' ';
    for (int i=k; i<=n; i++) {
        ll div = i - k + 1;
        div = Inv(div, mod);
        C[i] = C[i-1] * div % mod * i % mod;
        // cout << C[i] << ' ';
    }
    // cout << endl;
    ll in = 0, ans = 0;
    for (int i=1; i<=cnt; i++) {
        if (a[i].val == 1) {
            if (in >= k-1) {
                ans += C[in];
                ans %= mod;
            }
        }
        in += a[i].val;
    }
    cout << ans << endl;

    return 0;
}