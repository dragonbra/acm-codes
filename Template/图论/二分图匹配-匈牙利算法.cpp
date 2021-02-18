/*
Problem: HDU 2063 过山车 匈牙利算法-二分图匹配模板题
* @ author: dragon_bra
* @ email: tommy514@foxmail.com
* @ date: 2021-01-26 22:11
*/

#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(0);
using namespace std;

typedef long long ll;
const int N = 500 + 10;

void redirect() {
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
}

int k, m, n;
int line[N][N], used[N], nxt[N];

bool Find(int x) {
    for (int i=1; i<=m; i++) {
        if (line[x][i] && !used[i]) {
            used[i] = 1;
            if (nxt[i] == 0 || Find(nxt[i])) {
                nxt[i] = x;
                return true;
            }
        }
    }
    return false;
}

int match() {
    int sum = 0;
    for (int i=1; i<=n; i++) {
        memset(used, 0, sizeof(used));
        if (Find(i)) sum ++;
    }
    return sum;
}

int main() {
    redirect();

    while (cin >> k && k) {
        memset(line, 0, sizeof(line));
        memset(nxt, 0, sizeof(nxt));
        cin >> n >> m;
        for (int i=1; i<=k; i++) {
            int u, v;
            cin >> u >> v;
            line[u][v] = true;
        }
        cout << match() << "\n";
    }

    return 0;
}