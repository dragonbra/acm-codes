/*
*  @ author: dragon_bra
*  @ created at: 2021-11-11 16:48:31
*/

#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>

using namespace std;

typedef long long LL;

const LL N = 200 + 10;

LL n, m;
LL c[N], w[N];
int G[N][N];
LL ans[N];
vector<LL> st[N];
unordered_map<LL, bool> arr[N];
unordered_map<LL, LL> rem;

void dfs(LL u, LL status) {
    if (arr[u][status]) {
        return;
    }

    arr[u][status] = true;
    st[u].push_back(status);

    for (int v = 1; v <= n; v ++ ) {
        if (!G[u][v]) continue;
        dfs(v, status | (1ll << c[v]) );
    }
}

LL getAns(LL status) {
    if (rem[status]) return rem[status];
    LL res = 0;
    for (LL i = 1; i <= n; i ++ ) {
        // cout << ((status >> i) & 1);
        if ((status >> i) & 1ll) res += w[i];
    }
    // cout << endl;
    rem[status] = res;
    return res;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    cin >> n >> m;
    for (LL i = 1; i <= n; i ++ ) cin >> c[i];
    for (LL i = 1; i <= n; i ++ ) cin >> w[i];

    for (LL i = 1; i <= m; i ++ ) {
        LL u, v; cin >> u >> v;
        G[u][v] = true;
    }

    for (int i = 1; i <= n; i ++ ) {
        for (int j = i + 1; j <= n; j ++ ) {
            for (int k = j + 1; k <= n; k ++ ) {
                if (G[i][j] && G[j][k] && G[i][k]) {
                    G[i][k] = false;
                }
            }
        }
    }

    dfs(1, 0 | (1ll << c[1]) );

    for (LL i = 1; i <= n; i ++ ) {
        // cout << i << ": " << endl;
        for (auto s:st[i]) {
            ans[i] = max(ans[i], getAns(s));
        }
        cout << ans[i] << endl;
    }
}