/*
2020 南京 Mhttps://ac.nowcoder.com/acm/contest/10272/M
* @ author: dragon_bra
* @ email: tommy514@foxmail.com
* @ date: 2021-03-26 12:33
*/

#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(0);
using namespace std;

typedef long long ll;
const int N = 2e3 + 10;
const ll INF = 1e15 + 10;

void redirect() {
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
}

int T;
int n, f[N], sz[N];
vector<int> G[N];
ll val[N];
ll dp[N][N][2], tmp[N][N][2];

void dfs(int x) {
    sz[x] = 1;
    
    for (int v: G[x]) {
        dfs(v);
        
        for (int i = 0; i <= sz[x] + sz[v]; i ++ ) {
            tmp[x][i][0] = tmp[x][i][1] = INF;
        }

        for (int i = 0; i <= sz[x]; i ++ ) {
            for (int j = 0; j <= sz[v]; j ++ ) {
                tmp[x][i + j][0] = min(tmp[x][i + j][0], dp[x][i][0] + dp[v][j][0] + val[v]);
                if (j > 0)
                    tmp[x][i + j][0] = min(tmp[x][i + j][0], dp[x][i][0] + dp[v][j][1]);
                if (i > 0) 
                    tmp[x][i + j][1] = min(tmp[x][i + j][1], dp[x][i][1] + dp[v][j][0]);
                if (i > 0 && j > 0) 
                    tmp[x][i + j][1] = min(tmp[x][i + j][1], dp[x][i][1] + dp[v][j][1]);
            }
        }
        
        sz[x] += sz[v];
        for (int i = 0; i <= sz[x]; i ++ ) {
            dp[x][i][0] = tmp[x][i][0];
            dp[x][i][1] = tmp[x][i][1];
        }
    }

    for (int i = 0; i <= sz[x]; i ++ ) {
        dp[x][i][0] += val[x];
    }
}

void debug() {
    for (int i = 1; i <= n; i ++ ) {
        cout << i << ": " << "\n";
        for (int j = 0; j <= n; j ++ ) cout << dp[i][j][0] << ' '; cout << endl;
        for (int j = 0; j <= n; j ++ ) cout << dp[i][j][1] << ' '; cout << endl;
        cout << "---------------------------------------------" << endl;
    }
}

int main() {
    redirect();

    cin >> T;
    while (T -- ) {
        cin >> n;
        for (int i = 1; i <= n; i ++ ) {
            G[i].clear();
            for (int j = 0; j <= n; j ++ ) {
                dp[i][j][0] = dp[i][j][1] = 0;
            }
            // dp[i][1][1] = 0;
        }

        for (int i = 2; i <= n; i ++ ) {
            cin >> f[i];
            G[f[i]].push_back(i);
        }
        for (int i = 1; i <= n; i ++ ) cin >> val[i];

        dfs(1);

        // debug();

        for (int i = 0; i <= n; i ++ ) {
            cout << min(dp[1][i][0], dp[1][i][1]) << (i == n ? "\n" : " ");
        }
    }

    return 0;
}