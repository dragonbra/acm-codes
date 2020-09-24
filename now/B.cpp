/*
* @ author: dragon_bra
* @ email: tommy514@foxmail.com
* @ data: 2020-09-24 23:24
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

int T, n;
ll a[N];
map<int,int>mp;
int cnt = 0;

void init() {
    mp.clear();
}

int main() {
    redirect();

    int T;
    scanf("%d",&T);
    while(T--){
        init();

        scanf("%d", &n);
        for(int i=1; i<=n; i++) {
            scanf("%lld", &a[i]);
        }
        sort(a+1,a+n+1);
        
        for(int i=1; i<=n; i++) {
            ll now = a[i];
            int res = 0;
            while(now){
                now >>= 1;
                res ++;
            }
            mp[res] ++;
        }

        ll ans = 0;
        for(auto x:mp) {
            ll res = (ll)x.second;
            ans += (res) * (res-1) / 2;
        }
        printf("%lld\n",ans);
    }

    return 0;
}