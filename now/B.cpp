/*
* @ author: dragon_bra
* @ email: tommy514@foxmail.com
* @ data: 2020-09-19 22:54
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
typedef unsigned long long ull;
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

int T, n;
ull x;

int main() {
    redirect();

    scanf("%d",&T);
    while (T--) {
        cin >> x;
        int ans = 0;
        ull acc = 0, cnt = 1;
        ull lst = INF;
        ull res = 1;
        for (int i=1; i<=63; i++) {
            res *= 2;
            cnt = res - 1;
            acc = (cnt+1)/2 * cnt;
            if (acc < lst) cout << acc << endl;
            if (acc <= x) {
                //cout << acc << ' ';
                x -= acc;
                ans ++;
            }
        }
        cout << ans << endl;
    }

    return 0;
}