/*
* @ author: dragon_bra
* @ email: tommy514@foxmail.com
* @ date: 2021-05-26 21:04
*/

#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(0);
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
const int N = 2e5 + 10;

void redirect() {
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
}

int n = 4;

bool vis[N * 2];
vector<PII> wl;

void dfs(int x, int num) {
    for (int i = x; i <= n * 2; i++ ) {
        
    }
}

int main() {
    redirect();

    dfs(1, 1);

    return 0;
}