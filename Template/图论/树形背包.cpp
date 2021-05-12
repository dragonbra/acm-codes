/*
EOJ https://acm.ecnu.edu.cn/contest/405/problem/G/
* @ author: dragon_bra
* @ email: tommy514@foxmail.com
* @ date: 2021-05-09 13:58
*/

#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(0);
using namespace std;

typedef long long ll;
const int N = 5e3 + 10;
const ll mod = 998244353;

void redirect() {
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
}

ll qp(ll x, ll p) {
    ll res = 1;
    while (p) {
        if (p & 1) res *= x, res %= mod;
        x *= x, x %= mod;
        p >>= 1;
    }
    return res;
}

int n;
int f[N]; int sz[N];
vector<int> G[N];
ll dp[N][N];
ll cnt[N];

void dfs(int x) {
    // cout << x << endl;
    dp[x][1] = 1; sz[x] = 1;
    for (auto v : G[x]) {
        dfs(v);
        for (int i = sz[x]; i >= 1; i -- ) {
            for (int j = sz[v]; j >= 1; j -- ) {
                dp[x][i + j] += dp[x][i] * dp[v][j];
                dp[x][i + j] %= mod;
            }
        }
        sz[x] += sz[v];
    }

    for (int i = 1; i <= sz[x]; i ++ ) {
        cnt[i] += dp[x][i];
    }
    // cout << x << endl;
}

int main() {
    redirect();
    fastio;

    while(cin >> n) {
        for (int i = 1; i <= n; i ++ ) G[i].clear();
        for (int i = 1; i <= n; i++ ) {
            for (int j = 1; j <= n; j ++ ) dp[i][j] = 0;
            cnt[i] = 0;
        }

        for (int i = 2; i <= n; i ++ ) {
            cin >> f[i];
            G[f[i]].push_back(i);
        }


        dfs(1);

        ll sum = 0, num = 0;
        for (int i = 1; i <= n; i ++ ) {
            // cout << cnt[i] << ' ';
            sum += cnt[i] * i;
            num += cnt[i];
        }
        // cout << endl;

        sum %= mod, num %= mod;
        cout << sum * qp(num, mod - 2) % mod << "\n";
    }

    return 0;
}