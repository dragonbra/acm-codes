/*
* @ author: dragon_bra
* @ email: tommy514@foxmail.com
* @ data: 2020-07-19 14:29
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
const int N = 1e3 + 10;

void redirect() {
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
}

int T;
int a, b;
int f[N][N];

int gcd(int a, int b) {
    return a == 0 ? b : gcd(b%a, a);
}

int main() {
    redirect();

    f[1][1] = 1;
    for (int i=1; i<=1000; i++) {
        for (int j=1; j<=1000; j++) {
            if (f[i-1][j]) f[i][j] = max(f[i][j], f[i-1][j] + (gcd(i, j)==1 ? 1:0) );
            if (f[i][j-1]) f[i][j] = max(f[i][j], f[i][j-1] + (gcd(i, j)==1 ? 1:0) );
        }
    }

    cin >> T;
    while (T--) {
        scanf("%d%d", &a, &b);
        printf("%d\n", f[a][b]);
    }

    return 0;
}