/*
* @ author: dragon_bra
* @ email: tommy514@foxmail.com
* @ data: 2020-07-21 22:42
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
int n;
char ts1[N], ts2[N];
bool s1[N], s2[N];
int ans[N*2], cnt;

int main() {
    redirect();

    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        scanf("%s", ts1+1);
        scanf("%s", ts2+1);

        for (int i=1; i<=n; i++) {
            s1[i] = (ts1[i]=='1');
            s2[i] = (ts2[i]=='1');
        }

        int cnt = 0;
        int change = 0;
        int l=1, r=n;
        for (int i=n; i>=1; i--) {
            //cout << "i,l,r: " << i << ' ' << l << ' ' << r << endl;
            //cout << change << endl;
            if (change % 2 == 0) {
                if (s1[r] != s2[i]) {
                    change ++;
                    if (s1[r] == s1[l]) {
                        ans[++cnt] = i;
                    } else {
                        ans[++cnt] = 1;
                        ans[++cnt] = i;
                    }
                }
            } else {
                if (s1[l] == s2[i]) {
                    change ++;
                    //cout << "2i,l,r: " << i << ' ' << l << ' ' << r << endl;
                    if (s1[l] == s1[r]) {
                        ans[++cnt] = i;
                    } else {
                        ans[++cnt] = 1;
                        ans[++cnt] = i;
                    }
                }
            }
            if (change % 2 == 0) {
                r--;
            } else {
                l++;
            }
        }

        printf("%d ", cnt);
        for (int i=1; i<=cnt; i++) printf("%d ", ans[i]);
        printf("\n");
    }

    return 0;
}