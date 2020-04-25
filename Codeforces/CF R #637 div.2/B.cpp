#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
const double eps = 1e-5;
const int N = 2e5 + 10;

void redirect() {
    #ifdef LOCAL
        freopen("1.in","r",stdin);
        freopen("1.out","w",stdout);
    #endif
}

int T, n, k;
int a[N], pre[N];
bool vis[N];

int main() {
    redirect();

    cin >> T;
    while (T--) {
        scanf("%d%d",&n,&k);
        for (int i=1; i<=n; i++) {
            scanf("%d", &a[i]);
            pre[i] = 0;
            vis[i] = 0;
        }
        for (int i=2; i<n; i++) {
            if (a[i]>a[i-1] && a[i]>a[i+1]) vis[i]=1;
        }
        for (int i=1; i<=n; i++) {
            pre[i] = pre[i-1] + vis[i];
        }

        int ans=0, L=1;
        for (int i=1; i<=n; i++) {
            int l = i, r = l + k - 1;
            if (r>n) break;
            int cmp = pre[r] - pre[l-1];

            cmp -= (vis[l] + vis[r]);

            if (cmp>ans) {
                ans = cmp;
                L = l;
            }
        }

        printf("%d %d\n",ans+1,L);
    }

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/