/*
* @ author: dragon_bra
* @ email: tommy514@foxmail.com
* @ data: 2020-09-19 23:09
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

int T, n, x;
int a[N];

int main() {
    redirect();

    scanf("%d",&T);
    while (T--) {
        cin >> n >> x;

        int sum = 0; bool flag = false; bool f2 = true;
        for (int i=1; i<=n; i++) {
            scanf("%d", &a[i]);
            sum += a[i];
            if (a[i] == x) flag = true;
            if (a[i] != x) f2 = false;
        }

        if (sum / n == x) flag = true;

        if (f2) puts("0");
        else {
            if (flag) puts("1");
            else puts("2");
        }
    }

    return 0;
}