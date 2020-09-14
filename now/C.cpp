/*
* @ author: dragon_bra
* @ email: tommy514@foxmail.com
* @ data: 2020-09-14 23:00
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
int n, a[N];
int dp[N][3]; // friend - 0, me - 1

int main() {
    redirect();

    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i=1; i<=n; i++) {
            scanf("%d", &a[i]);
        }

        for (int i=n+1; i>=0; i--) {
            dp[i][0] = dp[i][1] = INF;
        }

        dp[0][1] = 0; dp[0][0] = INF;
        for (int i=0; i<=n; i++) {
            if (dp[i][1] != INF) {
                int pos1 = a[i+1] == 1 ? 1 : 0;
                int pos2 = a[i+2] == 1 ? 1 : 0;
                dp[i+1][0] = min(dp[i+1][0], dp[i][1] + pos1);
                dp[i+2][0] = min(dp[i+2][0], dp[i][1] + pos1 + pos2);
            }
            if (dp[i][0] != INF) {
                dp[i+1][1] = min(dp[i+1][1], dp[i][0]);
                dp[i+2][1] = min(dp[i+2][1], dp[i][0]);
            }
        }

        // for (int j=0; j<=1; j++) {
        //     for (int i=1; i<=n+1; i++) {
        //         if (dp[i][j] == INF) cout << "X" << ' ';
        //         else cout << dp[i][j] << ' ';
        //     } cout << endl;
        // }

        int ans = INF;
        if (dp[n][1] != INF) ans = min(dp[n][1], ans);
        if (dp[n][0] != INF) ans = min(dp[n][0], ans);
        cout << ans << endl;
    }

    return 0;
}