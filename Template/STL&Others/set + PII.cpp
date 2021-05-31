/*
https://codeforces.com/contest/1528/problem/C
* @ author: dragon_bra
* @ date: 2021-05-28 08:51
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 3e5 + 10;

int n;
int fa1[N], fa2[N];
vector<int> G1[N], G2[N];
PII st[N]; // stmp[i] = {start, end};
set<PII> s;

void dfs1(int u, int &step) {
    st[u].first = ++ step;
    for (auto v : G2[u]) {
        dfs1(v, step);
    }
    st[u].second = ++ step;
}

bool contains(PII a, PII b) {
    if (a.first < b.first && a.second > b.second) return true;
    return false;
}

int ans = 0;
void dfs2(int u) {
    bool insert = true;
    PII removed = {-1, -1};
    if (s.empty()) {
        s.insert(st[u]);
    } else {

        auto it = s.lower_bound(st[u]);
        if (it != s.end()) {
            if (contains(st[u], *it)) insert = false;
        }

        if (insert) {
            if (it != s.begin() ) {
                auto it2 = prev(it);
                if (contains(*it2, st[u])) {
                    s.erase( it2 );
                    removed = *it2;
                }
            }
            s.insert(st[u]);
        }
    }

    ans = max(ans, (int)s.size());

    for (auto v : G1[u]) {
        dfs2(v);
        if (insert && s.find(st[u]) == s.end()) s.insert(st[u]);
    }

    if (insert && removed.first != -1) s.insert(removed);
    s.erase( st[u] );
}

int main() {
    
    ios::sync_with_stdio(false); cin.tie(0);

    int T, kase = 0; cin >> T;
    while (T -- ) {
        ++ kase;
        cin >> n;

        s.clear(); ans = 0;
        for (int i = 1; i <= n; i ++ ) G1[i].clear(), G2[i].clear();

        for (int i = 2; i <= n; i ++ ) {
            cin >> fa1[i];
            G1[ fa1[i] ].push_back(i);
        }

        for (int i = 2; i <= n; i ++ ) {
            cin >> fa2[i];
            G2[ fa2[i] ].push_back(i);
        }

        int step = 0;
        dfs1(1, step);
        dfs2(1);

        cout << ans << endl;
    }
    
    return 0;
}