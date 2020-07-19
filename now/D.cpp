/*
* @ author: dragon_bra
* @ email: tommy514@foxmail.com
* @ data: 2020-07-19 14:52
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
const int N = 5e2 + 10;

void redirect() {
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
}

int T;
int n, sx, sy;
int mp[N][N];

bool cmp (int a, int b) {
    return a > b;
}

int check(int x, int y) {
    int res = 0;
    res += (abs(x-sx) + abs(y-sy) + 1) / 2;

    int arr[N]; int cnt = 0;
    for (int i=-3; i<=3; i++) {
        for(int jj=1; jj<=3; jj++) {
            if (jj<abs(i)) continue;
            int jmov = jj - abs(i);
            int j = jmov;
            if ((i+x) >= 1 && (i+x) <=n && (j+y) >= 1 && (j+y) <=n) {
                arr[++cnt] = mp[i+x][j+y];
            }
            if (jmov==0) continue;
            j = -jmov;
            if ((i+x) >= 1 && (i+x) <=n && (j+y) >= 1 && (j+y) <=n) {
                arr[++cnt] = mp[i+x][j+y];
            }
        }
    }

    sort(arr+1, arr+1+cnt, cmp);

    int acc = 0; int spd = mp[x][y];
    for (int i=1; i<=8; i++) {
        int goal = 8 * i * i;
        int t = (goal - acc - 1) / spd + 1;
        res += t;
        acc += t*spd;
        spd += arr[i];
    }

    /*
    cout << "x, y: " << x << ' ' << y << endl;
    cout << cnt << endl;
    for (int i=1; i<=cnt; i++) cout << arr[i] << ' '; cout << endl;
    cout << "res: " << res << endl;
    cout << endl;
    */

    return res;
}

int main() {
    redirect();

    cin >> T;
    while (T--) {
        scanf("%d %d %d", &n, &sx, &sy);
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                scanf("%d", &mp[i][j]);
            }
        }

        int ans = INF;
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                ans = min(ans, check(i, j));
            }
        }

        printf("%d\n", ans);
    }

    return 0;
}