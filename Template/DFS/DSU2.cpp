/*
    https://codeforces.com/gym/102431/problem/K
* @ author: dragon_bra
* @ email: tommy514@foxmail.com
* @ date: 2021-05-24 15:58
*/

#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(0);
using namespace std;

typedef long long ll;
const int N = 2e5 + 10;

void redirect() {
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
}

int T;
int n;
vector<int> G[N];
int fa[N], son[N], size[N];

bool vis[N]; vector<int> used;
int ans[N];

void dfs1(int u) {
    size[u] = 1; son[u] = 0;
    for (auto v : G[u]) {
        if (v == fa[u]) continue;

        fa[v] = u; dfs1(v);
        size[u] += size[v];

        if (size[v] > size[ son[u] ]) son[u] = v;
    }
}

void clear() {
    for (auto i : used) {
        vis[i] = false;
    }
    used.clear();
}

int add(int u) {
    int res = 0;
    used.push_back(u); vis[u] = true;

    res ++ ;
    if (vis[u + 1]) res -- ;
    if (vis[u - 1]) res -- ;

    for (auto v : G[u]) {
        if (v == fa[u]) continue;
        res += add(v);
    }
    
    return res;
}

void dfs2(int u) {
    clear();
    for (auto v : G[u]) {
        if (v == fa[u]) continue;
        if (v == son[u]) continue;
        dfs2(v);
    }

    if (son[u]) {
        dfs2(son[u]);
        ans[u] = ans[ son[u] ];
    }

    used.push_back(u); vis[u] = true;
    ans[u] ++ ;
    if (vis[u + 1]) ans[u] -- ;
    if (vis[u - 1]) ans[u] -- ;
    
    for (auto v : G[u]) {
        if (v == fa[u]) continue;
        if (v == son[u]) continue;
        ans[u] += add(v);
    }
}

int main() {
    redirect();
    fastio;

    cin >> T;
    int kase = 0;
    while (T -- ) {
        cin >> n;

        for (int i = 1; i <= n; i ++ ) {
            vis[i] = false;
            ans[i] = 0;
            G[i].clear();
        }

        for (int i = 1; i < n; i ++ ) {
            int u, v; cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }

        dfs1(1);
        dfs2(1);

        cout << "Case #" << ++ kase << ": ";
        for (int i = 1; i <= n; i ++ ) cout << ans[i] << (i == n ? '\n' : ' ');
    }
    

    return 0;
}