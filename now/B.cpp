/*
* @ author: dragon_bra
* @ email: tommy514@foxmail.com
* @ data: 2020-07-21 23:52
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
int n; int cnt;
vector<int> G; // 记录块的大小

bool vis[N];

int main() {
    redirect();

    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        G.clear();

        int mx = 0, res = 0;
        for (int i=1; i<=n*2; i++) {
            int t; scanf("%d", &t);
            if (t > mx) {
                mx = t;
                G.push_back(res);
                res = 1;
            } else {
                res ++;
            }
        }

        for (int i=0; i<=n; i++) vis[i] = false;
        cnt = G.size(); vis[0] = true;
        for (int i=0; i<cnt; i++) {
            for (int j=n; j>=0; j--) {
                if (vis[j]) vis[j+G[i]] = true;
            }
        }
        //for (int i=1; i<=n; i++) cout << vis[i] << ' '; cout << endl;

        if (vis[n]) puts("YES");
        else puts("NO");
    }

    return 0;
}