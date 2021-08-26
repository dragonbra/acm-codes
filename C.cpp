/*
*  @ author: dragon_bra
*  @ created at: 2021-08-03 19:49:46
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

const int N = 2e5 + 10;

int n;
int a[N];
struct node {
    int idx, val;
} arr[N];
vector<int> G[N], QG[N];
int leng[N], ans[N];

void init() {
    for (int i = 1; i <= n; i ++ ) {
        G[i].clear(); QG[i].clear();
        leng[i] = 0;
        ans[i] = 0;
    }
}

bool nodecmp(node a, node b) {
    return a.val > b.val;
}

bool cmp(int x, int y) {
    return leng[x] > leng[y];
}

int main() {
    
    ios::sync_with_stdio(false); cin.tie(0);
    int T, kase = 0; cin >> T;
    while (T -- ) {
        ++ kase; cin >> n;
        init();
        for (int i = 1; i <= n; i ++ ) {
            cin >> a[i];
            arr[i].idx = i;
            arr[i].val = a[i];
        }

        sort (arr + 1, arr + n + 1, nodecmp);

        for (int i = 1; i < n; i ++ ) {
            int u, v; cin >> u >> v;
            if (a[u] >= a[v])
                G[v].push_back(u);
            if (a[v] >= a[u])
                G[u].push_back(v);
            if (a[u] == a[v]) {
                QG[u].push_back(v);
                QG[v].push_back(u);
            }
        }


        for (int i = 1; i <= n; i ++ ) {
            int idx = arr[i].idx;
            
            sort (G[idx].begin(), G[idx].end(), cmp);
            
            if (G[idx].size()) {
                // cerr << idx << ' ' << G[idx][0] << ' ' << leng[G[idx][0]] << endl;
                leng[idx] = leng[G[idx][0]] + 1;
                if (a[idx] == a[G[idx][0]]) {
                    leng[G[idx][0]] ++
                }
                if (G[idx].size() >= 2) {
                    leng[idx] = leng[G[idx][0]] + leng[G[idx][1]] + 1;
                }
            }
            else leng[idx] = 1;

            cout << idx << ' ' << leng[idx] << endl;
            // for (auto v : QG[idx]) {
            //     leng[v] = max(leng[v], leng[idx]);
            // }

            // cout << idx << ' ' << leng[idx] << endl;

            if (ans[leng[idx]] == 0) ans[leng[idx]] = arr[i].val;
        }

        for (int i = n - 1; i >= 1; i -- ) {
            if (ans[i]) continue;
            else ans[i] = ans[i + 1];
        }

        for (int i = 1; i <= n; i ++ ) {
            cout << ans[i] << char(i == n ? '\n' : ' ');
        }

    }
    
    return 0;
}