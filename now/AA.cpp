#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 1e2 + 10;

void redirect() {
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
}

int n, m;
int sx, sy;
char mp[N][N];
int stp[N][N]; bool vis[N][N];
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

struct node {
    int x, y, s;
    node (int x, int y) : x(x), y(y) {}
    node (int x, int y, int s) : x(x), y(y), s(s) {}
};

bool cmp(node a, node b) {
    if (a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}

int main() {
    redirect();

    cin >> n >> m;
    for (int i=0; i<n; i++) {
        cin >> mp[i];
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (mp[i][j] == 'T') {
                sx = i, sy = j; break;
            }
        }
    }

    queue<node> Q;
    Q.push(node(sx, sy, 0)); vis[sx][sy] = true;
    while (!Q.empty()) {
        node now = Q.front(); Q.pop();
        int x = now.x, y = now.y, s = now.s;
        stp[x][y] = s;
        for (int i=0; i<4; i++) {
            int tx = x + dir[i][0];
            int ty = y + dir[i][1];
            int ts = s + 1;
            if (tx < 0 || tx >= n || ty < 0 || ty >= m) continue;
            if (!vis[tx][ty] && mp[tx][ty] != '1') {
                vis[tx][ty] = true;
                Q.push(node(tx, ty, ts));
            }
        }
    }

    int res = 1e5;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (mp[i][j] == 'X') {
                res = min(res, stp[i][j]);
            }
        }
    }

    queue<node> ans;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (stp[i][j] == res && mp[i][j] == 'X') {
                ans.push(node(i, j));
            }
        }
    }

    cout << res << endl;
    while (!ans.empty()) {
        node now = ans.front(); ans.pop();
        cout << now.x << ' ' << now.y << ' ';
    } cout << endl;

    return 0;
}