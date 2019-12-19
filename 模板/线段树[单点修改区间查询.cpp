#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF = 0x7fffffff;
const int mod = 1e9+7;
const double eps = 1e-5;
const int N = 1e5+10;

void redirect(){
    #ifdef LOCAL
        freopen("test.txt","r",stdin);
    #endif
}
inline ll read(){
    ll f=1,x=0;char ch;
    do{ch=getchar();if(ch=='-')f=-1;}while(ch<'0'||ch>'9');
    do{x=x*10+ch-'0';ch=getchar();}while(ch>='0'&&ch<='9');
    return x*f;
}

int n,k;
int pos[N];int a[N];

struct NOOD {
    int l, r, add, Max;
}tree[N * 4 + 5];
void Build(int L, int R, int x) {
    tree[x].l = L, tree[x].r = R, tree[x].Max = 0;
    if(L == R) {
        tree[x].Max = a[L];
        return ;
    }
    int mid = (L + R) / 2;
    Build(L, mid, x * 2);
    Build(mid + 1, R, x * 2 + 1);
    tree[x].Max = max(tree[x * 2].Max, tree[x * 2 + 1].Max);
}
void PushDown(int x) {
    if(tree[x].add) {
        tree[x * 2].Max = tree[x].add;
        tree[x * 2 + 1].Max = tree[x].add;
        tree[x * 2].add = tree[x].add;
        tree[x * 2 + 1].add = tree[x].add;
        tree[x].add = 0;
    }
}
void Update(int L, int R, int add, int x) {
    if(L <= tree[x].l && tree[x].r <= R) {
        tree[x].add = add;
        tree[x].Max = add;
        return ;
    }
    PushDown(x);
    int mid = (tree[x].l + tree[x].r) / 2;
    if(L <= mid)Update(L, R, add, x * 2);
    if(R > mid)Update(L, R, add, x * 2 + 1);
    tree[x].Max = max(tree[x * 2].Max, tree[x * 2 + 1].Max);
}

int Query(int L, int R, int x) {
    if(L <= tree[x].l && tree[x].r <= R)return tree[x].Max;
    PushDown(x);
    int mid = (tree[x].l + tree[x].r) / 2;
    int res = 0;
    if(L <= mid) res = max(res, Query(L, R, x * 2));
    if(R > mid) res = max(res, Query(L, R, x * 2 + 1));
    return res;
}

int nxt[N];int ans[N];

int dfs(int i){
	if(nxt[i]==0||ans[i]!=1) return ans[i];
	else return ans[i]=dfs(nxt[i])+1;
}

int main(){
	redirect();
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&k);
		memset(nxt,0,sizeof(nxt));memset(tree, 0, sizeof(tree));
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);pos[a[i]]=i;ans[i]=1;
		}
		Build(1, n, 1);
		for(int i=n;i>=1;i--){
			Update(pos[i], pos[i] , 0, 1);
			int big = Query(max(pos[i]-k,1), min(pos[i]+k,n), 1);
			if(big!=0) nxt[i]=big;
		}

		for(int i=1;i<=n;i++){
			int ans = dfs(i);printf("%d%c",ans,i==n?'\n':' ');
		}

	}
	return 0;
}

/*
---linux compile---
g++ aa.cpp -o aa
./ aa
-------------------
author:dragon_bra
*/
