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
const int N = 5e5+10;

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

int n,m;

struct Node {
	int v,idx;int ans;
} w[N],a[N];

bool cmp_1 (Node a,Node b) {
	return a.v>b.v;
}

bool cmp_2 ( Node a,Node b) {
	return a.idx<b.idx;
}

int main() {
	redirect();
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) {
		scanf("%d",&w[i].v); w[i].idx=i;
	}
	sort ( w+1, w+n+1, cmp_1 );
	
	int r=0; int pt=0; int now=0;
	for (int i=1;i<=n;i++) {
		now = w[i].v;
		while ( w[pt+1].v >= now + m ) {
			pt++; r = max( w[pt].idx, r );
		}
		if(r<=w[i].idx) w[i].ans = -1;
		else w[i].ans = r-w[i].idx-1;
	}
	
	sort( w+1, w+n+1, cmp_2);
	for (int i=1;i<=n;i++) {
		printf("%d%c",w[i].ans, i==n ? '\n' : ' ' );
	}
}

/*
---------------------
  author:dragon_bra
---------------------
*/

