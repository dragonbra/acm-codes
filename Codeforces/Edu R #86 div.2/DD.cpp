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

ll n, k;
int a[N], cnt[N];
ll lmt[N], suf[N];
vector<int> G[N]; ll acc[N];

bool vis[N]; int pt[N];

int main() {
    redirect();

    //ios::sync_with_stdio(false);
    //cin.tie(0); 

    scanf("%lld%lld",&n,&k);
    for (int i=1; i<=n; i++) {
        scanf("%d",&a[i]); cnt[a[i]]++;
    }

    for (int i=1; i<=k; i++) {
        scanf("%lld",&lmt[i]);
    }

    for (int i=k; i>=1; i--) {
        suf[i] = suf[i+1] + cnt[i];
    }

    ll l = 1, r = 3e5;
    while (l<r) {
        ll mid = (l+r) >> 1;
        bool f = true;
        for (int i=k; i>=1; i--) {
            if ( suf[i] > lmt[i]*mid ) {
                f = false;
                break;
            }
        }

        if (f) r = mid;
        else l = mid+1;
    }

    int j = 0;
    for (int i=k; i>=1; i--) {
        while ( cnt[i] > 0 ) {
            G[j%l+1].push_back(i);
            j++;
            cnt[i] --;
        }
    }

    printf("%lld\n",l);
    for (int i=1; i<=l; i++) {
        printf("%d ",G[i].size());
        for (auto x:G[i]) printf("%d ",x);
        printf("\n");
    }

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/