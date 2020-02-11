#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;
const double eps = 1e-5;
const int maxn = 2e5 + 10;

void redirect() {
    #ifdef LOCAL
        freopen("1.in","r",stdin);
        freopen("1.out","w",stdout);
    #endif
}

int n,k;
LL mu[maxn << 2]; LL ans = 0;

void build(int l, int r, int rt) {
    if(l==r) {
        cin>>mu[rt];
        return;
    }
	int mid = (l + r) >> 1;
	build(l, mid, rt << 1);
	build(mid + 1, r, rt << 1 | 1);
	mu[rt] = (mu[rt << 1] * mu[rt << 1 | 1]) % MOD;
}

LL query(int L, int R, int l, int r, int rt) {
	if(L <= l && r <= R) {
		return mu[rt];
	}
	LL ret = 1;
	int mid = (l + r) >> 1;
	if(mid >= L) ret = (ret * query(L, R, l, mid, rt << 1)) % MOD;
	if(mid + 1 <= R) ret = (ret * query(L, R, mid + 1, r, rt << 1 | 1)) % MOD;
	return ret;
}

int main() {
    redirect();
    scanf("%d%d",&n,&k);

    build(1, n, 1);
    
    for(int i=1;i<=n-k+1;i++){
        ans = max(ans, query(i,i+k-1,1,n,1));
    }

    cout<<ans<<endl;

	return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/