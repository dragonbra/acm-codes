/*
* @ author: dragon_bra
* @ email: tommy514@foxmail.com
* @ data: 2020-09-24 23:20
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
int n, a[N];

int main() {
    redirect();
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=1; i<=n; i++) {
            scanf("%d",&a[i]);
        }

        bool flag = false;
        for(int i=2;i<=n;i++) {
            if (a[i-1] <= a[i]) {
                flag = true;
                break;
            }
        }
        if(flag) puts("YES");
        else puts("NO");
    }
    
    return 0;
}