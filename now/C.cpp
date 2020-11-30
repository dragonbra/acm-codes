/*
* @ author: dragon_bra
* @ email: tommy514@foxmail.com
* @ data: 2020-11-29 01:18
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
const double eps = 1e-5;
const int N = 5e6 + 10;

const int power = 30;

void redirect() {
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
}

int n; 
int a[N]; 

int t[N][2]; int id = 0; // Trie;
ll dp[31][2];
vector<int> g[N];

void add(int val, int pos) {
    int u = 0;
    for (int i=power; i>=0; i--) {
        int bit = ( (val >> i) & 1 );
        if (!t[u][bit]) t[u][bit] = ++id;
        u = t[u][bit];
        g[u].push_back(pos);
    }
}

void cal(int u, int b = power) {
    int l = t[u][0], r = t[u][1];
    if (l) cal(l, b-1);
    if (r) cal(r, b-1);
    if (!l || !r) return;

    ll res = 0; int ptr = 0;
    for (auto x:g[l]) {
        while (ptr < g[r].size() && g[r][ptr] < x) ptr ++;
        res += ptr;
    }
    dp[b][0] += res;
    dp[b][1] += 1ll * g[l].size() * g[r].size() - res;
}

int main() {
    redirect();

    scanf("%d", &n);
    for (int i=1; i<=n; i++) {
        scanf("%d", &a[i]);
        add(a[i], i);
    }

    cal(0);

    ll ans = 0, x = 0;
    for (int i=0; i<=power; i++) {
        if (dp[i][0] <= dp[i][1]) {
            ans += dp[i][0];
        } else {
            ans += dp[i][1];
            x += (1 << i);
        }
    }

    printf("%lld %lld\n", ans, x);

    return 0;
}