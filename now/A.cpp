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

const int N = 2e5 + 10;

int n, q;
int a[N];
int pre[N][110];

int main() {
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif

    scanf("%d%d", &n, &q);
    for (int i=1; i<=n; i++) {
        scanf("%d", &a[i]);
        for (int j=0; j<=100; j++) {
            pre[i][j] = pre[i-1][j];
        }
        pre[i][a[i]] ++;
    }    

    for (int i=1; i<=q; i++) {
        int l, r; scanf("%d%d", &l, &r);
        l ++; r ++;
        int ans = 0;
        for (int j=0; j<=100; j++) {
            if (pre[r][j] - pre[l-1][j]) ans ++;
        }
        printf("%d\n", ans);
    }

    return 0;
}