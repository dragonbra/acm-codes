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

void redirect() {
    #ifdef LOCAL
        freopen("test.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
}
inline ll read() {
    ll f=1,x=0;char ch;
    do {ch=getchar(); if(ch=='-') f=-1;} while (ch<'0'||ch>'9');
    do {x=x*10+ch-'0'; ch=getchar(); } while (ch>='0'&&ch<='9');
    return x*f;
}

struct Node{
	int l,r;int idx;ll ans;
} Q[N];

bool cmp_1 (Node a, Node b) {
	return a.r<b.r;
}

bool cmp_2 (Node a, Node b) {
	return a.idx<b.idx;
}

vector<int> G[N];
int n,m;int vis[N];int a[N],pos[N],nxt[N];ll c[N];

int lowbit (int x) {
    return x&(-x);
}

void update (int i,ll k) {
    while(i <= n){
        c[i] += k;
        i += lowbit(i);
    }
}

ll sufsum (int i) {//A[1-i]µÄºÍ
    ll res = 0;
    while (i) {
        res += c[i];
        i -= lowbit(i);
    }
    return res;
}

ll query(int l,int r){
	return sufsum(r)-sufsum(l-1);
}

int main() {
	redirect();
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) {
		scanf("%lld",&a[i]); pos[a[i]]=i;
	}
	for (int i=1;i<=n;i++) {
		int t = a[i]*2;
		while ( t <= n ) {
			G[t].push_back(i);
			G[a[i]].push_back(pos[t]);
			t+=a[i];
		}
	}
	
	for(int i=1;i<=n;i++) sort(G[i].begin(),G[i].end());
	
	for ( int i=1;i<=m;i++ ) {
		scanf("%d%d", &Q[i].l, &Q[i].r); Q[i].idx = i;
	}
	sort ( Q+1, Q+m+1, cmp_1 );
	
	int pt=1;
	for(int i=1;i<=m;i++){
		while( pt<=Q[i].r && pt<=n ) {
			int k=0; int x=a[pt];
			for ( k = nxt[x]; k < G[x].size(); k++ ) {
				if ( G[x][k] < pt ) update(G[x][k],1);
				else break;
			}
			nxt[x] = k;
			pt++;
		}
		Q[i].ans = query(Q[i].l,Q[i].r);
	}
	
	sort( Q+1, Q+m+1, cmp_2 );
	
	for(int i=1;i<=m;i++) printf("%lld\n",Q[i].ans);
}

/*
---------------------
  author:dragon_bra
---------------------
*/

