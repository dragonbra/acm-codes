/*
* @ author: dragon_bra
* @ email: tommy514@foxmail.com
* @ data: 2020-08-10 13:19
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
const int N = 1e6 + 10;

void redirect() {
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
}

int T; int p; int cnt = 0;
bool vis[N];
int q[N];

int main() {
    redirect();

    scanf("%d", &T);
    while (T--) {
        scanf("%d", &p);
        for (int i=1; i<p; i++) vis[i] = false;

        cnt = 1; q[1] = 1; vis[1] = true;
        for (int i=2; i<p; i++) {
            int lst = q[i-1];
            int t2 = q[i-1] * 2 % p, t3 = q[i-1] * 3 % p;
            if (!vis[t2]) {
                q[i] = t2; vis[t2] = true; cnt ++;
            } else if (!vis[t3]) {
                q[i] = t3; vis[t3] = true; cnt ++;
            } else {
                break;
            }
        }

        if (cnt != p-1) {
            puts("-1");
        } else {
            for (int i=1; i<p; i++) {
                printf("%d ", q[i]);
            } printf("\n");
        }
    }

    return 0;
}