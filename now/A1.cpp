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

        cnt = 0;
        for (int i=n; i>=1; i--) {
            if (s1[i]!=s2[i]) {
                if ((!s1[1])==s2[i]) {
                    ans[++cnt] = i;
                    for (int j=1; j<=(i+1)/2; j++) {
                        s1[j] = !s1[j];
                        if (i%2==1 && j==(i+1)/2) continue;
                        s1[i-j+1] = !s1[i-j+1];
                        swap(s1[j], s1[i-j+1]);
                    }
                } else {
                    ans[++cnt] = 1;
                    s1[1] = !s1[1];
           // cout << ":";for (int j=1; j<=n; j++) cout << s1[j]; cout << endl;

                    ans[++cnt] = i;
                    for (int j=1; j<=(i+1)/2; j++) {
                       // cout << "~~" << endl;
                        s1[j] = !s1[j];
                        if (i%2==1 && j==(i+1)/2) continue;
                        s1[i-j+1] = !s1[i-j+1];
                        swap(s1[j], s1[i-j+1]);
           // cout << ":";for (int j=1; j<=n; j++) cout << s1[j]; cout << endl;
                    }
                }
            }
           // for (int j=1; j<=n; j++) cout << s1[j]; cout << endl;
        }

        printf("%d ", cnt);
        for (int i=1; i<=cnt; i++) printf("%d ", ans[i]);
        printf("\n");
    }

    return 0;
}