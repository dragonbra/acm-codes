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
const int N = 1e6+10;

void redirect(){
    #ifdef lCAL
        //freopen("test.txt","r",stdin);
    #endif
}
inline ll read(){
    ll f=1,x=0;char ch;
    do{ch=getchar();if(ch=='-')f=-1;}while(ch<'0'||ch>'9');
    do{x=x*10+ch-'0';ch=getchar();}while(ch>='0'&&ch<='9');
    return x*f;
}

int n,m;
int c[N*4]; bool f[N*4];

void flip(int x,int l,int r,int st,int ed ) {
	if (l>ed||r<st||l>r) return;

	if (l>=st&&r<=ed) {
		c[x] = (r-l+1)-c[x];
		f[x] ^= true;
		return;
	}

	int mid = (l+r)/2;

	if (f[x]) {
		flip(2*x+1,l,mid,l,mid);
		flip(2*x+2,mid+1,r,mid+1,r);
		f[x] = false;
	}

	flip(2*x+1,l,mid,st,ed);
	flip(2*x+2,mid+1,r,st,ed);

	if (l<r) c[x] = c[2*x+1] + c[2*x+2];
}

int query(int x,int l,int r,int st,int ed) {
	if (l>ed||r<st||l>r )
	      return 0;

	if (l>=st&&r<=ed)
		return c[x];

	int mid = (l+r)/2;
	if (f[x]) {
		flip(2*x+1,l,mid,l,mid);
		flip(2*x+2,mid+1,r,mid+1,r);
		f[x] = false;
	}

	return query(2*x+1,l,mid,st,ed) + query(2*x+2,mid+1,r,st,ed);
}

int main(){
	redirect();int T; 
	scanf("%d",&T);int TT=T;
	while (T--) {
		memset(f, 0, sizeof f); memset(c, 0, sizeof c);
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;i++) {
			int l,r;
			scanf("%d%d",&l,&r);
			flip(0,1,n,l+1,r+1);
		}
		int ans = query(0,1,n,1,n);
		printf("Case #%d: %d\n",TT-T,ans);
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

