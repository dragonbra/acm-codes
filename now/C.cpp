/*
* @ author: dragon_bra
* @ email: tommy514@foxmail.com
* @ data: 2020-09-17 22:58
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

int T;
int n;
vector<int> G[N];
int fa[N], dep[N];
int size[N]; int ans[N];
int ra, rb;

void make_tree(int x, int dp) {
    dep[x] = dp;
    for (auto v:G[x]) {
        if (dep[v] == 0) {
            fa[v] = x;
            make_tree(v, dp+1);
            ans[x] = max(ans[x], size[v]);
            size[x] += size[v];
        }
    }
    ans[x] = max(ans[x], n - size[x]);
}

int main() {
    redirect();

    cin >> T;
    while (T--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            G[i].clear(); size[i] = 1; ans[i] = 1; dep[i] = 0;
        }
        for (int i=1; i<n; i++) {
            int u, v; cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }

        make_tree(1, 1);

        ra = rb = 0; int mx = n;
        for (int i=1; i<=n; i++) mx = min(mx, ans[i]);
        for (int i=1; i<=n; i++) {
            if (ans[i] == mx) {
                if (!ra) ra = i;
                else if (!rb) rb = i;
            }
        }

        // cout << "hh" << ' ' << ra << ' ' << rb << endl;
        // for (int i=1; i<=n; i++) cout << ans[i] << ' '; cout << endl;
        if (rb == 0) {
            cout << ra << ' ' << G[ra][0] << endl;
            cout << ra << ' ' << G[ra][0] << endl;
            continue;
        }
        if (dep[ra] < dep[rb]) swap(ra, rb);
        int cut = 0;
        for (auto v:G[ra]) {
            if (v != fa[ra] && v != rb) {
                cut = v;
                break;
            }
        }
        cout << cut << ' ' << ra << endl;
        cout << cut << ' ' << rb << endl;
    }

    return 0;
}