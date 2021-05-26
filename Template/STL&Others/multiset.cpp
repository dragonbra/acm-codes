/*
https://codeforces.com/contest/1487/problem/E
* @ author: dragon_bra
* @ email: tommy514@foxmail.com
* @ date: 2021-05-26 21:57
*/

#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(0);
using namespace std;

typedef long long ll;
const int N = 2e5 + 10;
const int INF = 1e9 + 10;

void redirect() {
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
}

int n[5], m[5];
int price[5][N];
vector<int> bad[5][N];
int dp[5][N];

int main() {
    redirect();

    for (int i = 1; i <= 4; i ++ ) cin >> n[i];

    for (int i = 1; i <= 4; i ++ ) {
        for (int j = 1; j <= n[i]; j ++ ) {
            cin >> price[i][j];
            if (i == 1) dp[i][j] = price[i][j];
        }
    }

    for (int i = 1; i <= 3; i ++ ) {
        cin >> m[i];
        for (int j = 1; j <= m[i]; j ++ ) {
            int u, v; cin >> u >> v;
            // bad[i][u].push_back(v);
            bad[i][v].push_back(u);
        }
    }

    for (int i = 1; i <= 3; i ++ ) {
        multiset<int> s;
        for (int j = 1; j <= n[i]; j ++ ) {
            s.insert(dp[i][j]);
        }

        for (int j = 1; j <= n[i + 1]; j ++ ) {
            for (auto k : bad[i][j]) {
                s.erase( s.find(dp[i][k]) );
            }
            if (s.empty()) {
                dp[i + 1][j] = INF;
            } else {
                dp[i + 1][j] = *s.begin() + price[i + 1][j];
            }
            for (auto k : bad[i][j]) {
                s.insert( dp[i][k] );
            }
        }
    }

    int ans = *min_element(dp[4] + 1, dp[4] + n[4] + 1);
    if (ans >= INF)
        ans = -1;

    cout << ans << endl;

    return 0;
}