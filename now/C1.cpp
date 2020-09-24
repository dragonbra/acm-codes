/*
* @ author: dragon_bra
* @ email: tommy514@foxmail.com
* @ data: 2020-09-24 23:39
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
const int N = 3e5 + 10;

void redirect() {
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
}

int T;
int n, q;
int a[N];

void input() {
    scanf("%d%d", &n, &q);
    for (int i=1; i<=n; i++) {
        scanf("%d", &a[i]);
    }
}

int main() {
    redirect();

    scanf("%d",&T);
    while(T--){
        input();
        a[n+1] = 0;

        int pos=1, tmp=0, now=0; 
        bool flag = false; ll ans=0;
        while(pos <= n){
            if(now%2==0){
                tmp = a[pos];
                while(a[pos] < a[pos+1]){
                    tmp = a[pos+1];
                    pos++;
                    if(pos>n) break;
                }
                ans = ans + 1ll*tmp;
                now++;
            } else {
                tmp = a[pos];
                while(a[pos] > a[pos+1]){
                    tmp = a[pos+1];
                    pos++;
                    if(pos>n) {
                        flag = true; break;
                    }
                }
                if(flag) break;
                ans = ans - 1ll * tmp;
                now++;
            }
            pos++;
        }
        printf("%lld\n",ans);
        for (int i=1; i<=q; i++) {
            int l, r;
            scanf("%d %d", &l, &r);
            swap(a[l], a[r]);
            
        }
    }

    return 0;
}