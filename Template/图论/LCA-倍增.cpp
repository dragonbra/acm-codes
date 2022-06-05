/*
    洛谷P3379，LCA模板
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10, M = N * 2;
const int LOG = 30 + 1;

int n, m;
int h[N], e[M], ne[M], idx;
int depth[N], fa[N][LOG];
int q[N];

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

void bfs(int root) {
    memset(depth, 0x3f3f3f3f, sizeof depth);
    depth[0] = 0, depth[root] = 1;
    int hh = 0, tt = 0;
    q[0] = root;
    while (hh <= tt) {
        int t = q[hh ++ ];
        for (int i = h[t]; ~i; i = ne[i] ) {
            int j = e[i];
            if (depth[j] > depth[t] + 1) {
                depth[j] = depth[t] + 1;
                q[ ++ tt] = j;
                fa[j][0] = t;
                for (int k = 1; k < LOG; k ++ )
                    fa[j][k] = fa[fa[j][k - 1]][k - 1];
            }
        }
    }
}

int lca(int a, int b) {
    if (depth[a] < depth[b]) swap(a, b);
    for (int i = LOG - 1; i >= 0; i -- )
        if (depth[fa[a][i]] >= depth[b])
            a = fa[a][i];
    if (a == b) return a;
    for (int i = LOG - 1; i >= 0; i -- )
        if (fa[a][i] != fa[b][i])
            a = fa[a][i], b = fa[b][i];
    return fa[a][0];
}

int main() {
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    int root = 0;
    cin >> n >> m >> root;
    memset(h, -1, sizeof h);
    
    for (int i = 1; i < n; i ++ ) {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b), add(b, a);
    }
    
    bfs(root);
    
    while (m -- ) {
        int a, b;
        scanf("%d%d", &a, &b);
        int p = lca(a, b);
        printf("%d\n", p);
    }

}