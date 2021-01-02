/*
* @ author: dragon_bra
* @ email: tommy514@foxmail.com
* @ date: 2021-01-02 11:30
*/

#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(0);
using namespace std;

typedef long long ll;
const int INF = 1e9 + 7;
const int N = 3e4 + 10;

void redirect() {
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
}

int n, x, y, s;
vector< pair<int, int> > G1[N], G2[N];
vector< int > comp[N]; // 每个连通块内的成员
bool vis[N];
int belong[N], in[N], dis[N];

void make_belong(int x, int num) {
    belong[x] = num;
    comp[num].push_back(x);

    for (pair<int, int> p : G1[x]) {
        int v = p.first;
        if (!belong[v]) dfs(v, num);
    }
}

int main() {
    redirect();

    fastio;
    cin >> n >> x >> y >> s;

    for (int i=1, u, v, w; i<=x; i++) {
        cin >> u >> v >> w;
        G1[u].push_back(make_pair(v, w));
        G1[v].push_back(make_pair(u, w));
    }

    for (int i=1, u, v, w; i<=y; i++) {
        cin >> u >> v >> w;
        G2[u].push_back(make_pair(v, w));
        in[v] ++;
    }

    int c = 0;
    for (int i=1; i<=n; i++) {
        if (!belong[i]) {
            make_belong(i, ++c);
        }
    }

    return 0;
}