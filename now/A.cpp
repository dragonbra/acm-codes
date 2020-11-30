/*
* @ author: dragon_bra
* @ email: tommy514@foxmail.com
* @ data: 2020-11-30 10:03
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
const double eps = 1e-5;
const int N = 60 + 10;

void redirect() {
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
}

int n;
int a[N];
int f[N][N]; // means the xor result from i to j

int main() {
    redirect();

    cin >> n;
    if (n > 60) {
        puts("1");
        return 0;
    }

    for (int i=1; i<=n; i++) cin >> a[i];

    int ans = n;
    for (int i=1; i<=n; i++) {
        int x = 0;
        for (int j=i; j<=n; j++) {
            x ^= a[j];
            f[i][j] = x;
            for (int k=1; k<i; k++) {
                if (f[k][i-1] > x) {
                    ans = min(ans, (j-k-1));
                }
            }
        }
    }

    if (ans >= n) puts("-1");
    else cout << ans << endl;

    return 0;
}