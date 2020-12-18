#include <bits/stdc++.h>
using namespace std;

const int INF = 2e9;
const int N = 50 + 5;

int n;
struct pt {
    string to;
    int x, y, ans;
} a[N];

struct node{
    int x, y, time, idx;
    node (int x, int y, int time, int idx) : x(x), y(y), time(time), idx(idx) {}

    friend bool operator < (node a, node b) {
        return a.time > b.time;
    }
};

priority_queue<node> PQ;
map<pair<int, int>, int> mp;
bool vis[55];

int main() {

    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> a[i].to >> a[i].x >> a[i].y;
        a[i].ans = INF;
    }

    for (int i=1; i<=n; i++) {
        for (int j=i+1; j<=n; j++) {
            int u = i, v = j;
            if (a[u].to == a[v].to) continue;
            if (a[u].to == "E") swap(u, v);

            int cx = a[u].x, cy = a[v].y;
            if (cx >= a[v].x && cy >= a[u].y) {
                PQ.push(node(cx, cy, cy - a[u].y, u));
                PQ.push(node(cx, cy, cx - a[v].x, v));
            }
            
        }
    }

    while (!PQ.empty()) {
        node now = PQ.top(); PQ.pop();
        int x = now.x, y = now.y, time = now.time, idx = now.idx;

        if (vis[idx]) continue;

        if (!mp[make_pair(x, y)]) {
            mp[make_pair(x, y)] = time;
        } else {
            if (mp[make_pair(x, y)] == time) continue;
            else {
                a[idx].ans = time;
                vis[idx] = true;
            }
        }
    }

    for (int i=1; i<=n; i++) {
        if (a[i].ans == INF) puts("Infinity");
        else cout << a[i].ans << endl;
    }

    return 0;
}