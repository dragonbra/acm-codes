// https://www.acwing.com/problem/content/1131/
// acwing 1129 热浪
// spfa 模板
#include <bits/stdc++.h>

using namespace std;

const int N = 2500 + 10;

int n, m, S, T;
vector<pair<int, int> > G[N];
int dist[N], q[N];
bool st[N];

void spfa() {
    memset(dist, 0x3f, sizeof dist);
    dist[S] = 0;

    int hh = 0, tt = 1;
    q[0] = S, st[S] = true;

    while (hh != tt) {
        int u = q[hh ++ ];
        if (hh == N) hh = 0;
        st[u] = false;

        for (auto p:G[u]) {
            int v = p.first;
            if (dist[v] > dist[u] + p.second) {
                dist[v] = dist[u] + p.second;
                if (!st[v]) {
                    q[tt ++ ] = v;
                    if (tt == N) tt = 0;
                    st[v] = true;
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    cin >> n >> m >> S >> T;
    for (int i = 1; i <= m; i ++ ) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }

    spfa();

    cout << dist[T] << endl;
}

作者：炽月殿
链接：https://www.acwing.com/activity/content/code/content/1620484/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。