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
char s1[N], s2[N];

struct node {
    int s, t;
    node(){}
    node(int s, int t) : s(s), t(t) {}
};

int main() {
    redirect();

    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        scanf("%s", s1+1);
        scanf("%s", s2+1);
        vector<node> G;
        int s = 0, t = 0;
        for (int i=1; i<=n; i++) {
            if (s==0) {
                if (s1[i] != s2[i]) {
                    s = i;
                    if (i==n) {
                        t = i;
                        G.push_back(node(s, t));
                        s = 0;
                    }
                }
            } else {
                if (s1[i] == s2[i]) {
                    t = i-1;
                    G.push_back(node(s, t));
                    s = 0;
                } else if (i==n) {
                    t = i;
                    G.push_back(node(s, t));
                    s = 0;
                }
            }
        }
        //cout << G.size() << endl;
        //for (auto x:G) { cout << x.s << ' ' << x.t << endl; }

        //cout << "ans";
        if (G.size()>0) {
            int ans = G.size() * 2;
            if (G[0].s==1) ans --;
            printf("%d ", ans);
            for (int i=0; i<G.size(); i++) {
                if (i==0 && G[i].s==1) printf("%d ", G[i].t);
                else printf("%d %d ", G[i].s-1, G[i].t);
            }
            printf("\n");
        } else {
            printf("0\n");
        }
    }

    return 0;
}