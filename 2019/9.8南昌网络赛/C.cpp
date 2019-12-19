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
const int N = 2e5+10;

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

struct Node {
	int l,r; int idx,ans;
} Q[N];

bool cmp_1 (Node a, Node b) {
	return a.l<b.l;
}

bool cmp_2 (Node a, Node b) {
	return a.idx<b.idx;
}

int n,q;
int a[N];char s[N];
queue<int> p[10];//201
int c8[N],c9[N],c2[N],c0[N],c1[N];

int lowbit (int x) { return x&(-x); }

void update8(int i,int k){//单点加
	while(i<=n){
		c8[i]+=k;
		i+=lowbit(i);
	}
}

void update9(int i,int k){//单点加
	while(i<=n){
		c9[i]+=k;
		i+=lowbit(i);
	}
}

void update2(int i,int k){//单点加
	while(i<=n){
		c2[i]+=k;
		i+=lowbit(i);
	}
}

void update0(int i,int k){//单点加
	while(i<=n){
		c0[i]+=k;
		i+=lowbit(i);
	}
}

void update1(int i,int k){//单点加
	while(i<=n){
		c1[i]+=k;
		i+=lowbit(i);
	}
}

int suf_sum8(int i){
	int res=0;
	while(i>0){
		res+=c8[i];
		i-=lowbit(i);
	}
	return res;
}

int suf_sum9(int i){
	int res=0;
	while(i>0){
		res+=c9[i];
		i-=lowbit(i);
	}
	return res;
}

int suf_sum2(int i){
	int res=0;
	while(i>0){
		res+=c2[i];
		i-=lowbit(i);
	}
	return res;
}

int suf_sum1(int i){
	int res=0;
	while(i>0){
		res+=c1[i];
		i-=lowbit(i);
	}
	return res;
}

int suf_sum0(int i){
	int res=0;
	while(i>0){
		res+=c0[i];
		i-=lowbit(i);
	}
	return res;
}

int Query8(int l,int r){
	if(r<l) return 0;
	return suf_sum8(r)-suf_sum8(l-1);
}

int Query9(int l,int r){
	if(r<l) return 0;
	return suf_sum9(r)-suf_sum9(l-1);
}

int Query1(int l,int r){
	if(r<l) return 0;
	return suf_sum1(r)-suf_sum1(l-1);
}

int Query2(int l,int r){
	if(r<l) return 0;
	return suf_sum2(r)-suf_sum2(l-1);
}

int Query0(int l,int r){
	if(r<l) return 0;
	return suf_sum0(r)-suf_sum0(l-1);
}

int main() {
	redirect();
	scanf("%d%d",&n,&q); scanf("%s",s+1);
	
	for (int i=1;i<=n;i++) {
		a[i]=s[i]-'0';
		if(a[i]==8) update8(i,1);
		else if(a[i]==9) update9(i,1);
		else if(a[i]==1) update9(i,1);
		else if(a[i]==2) update9(i,1);
		else if(a[i]==0) update9(i,1);
	}
	for (int i=n;i>=1;i--) { //9102-8
		if(a[i]==9) p[1].push(i);
		else if(a[i]==1) p[2].push(i);
		else if(a[i]==0) p[3].push(i);
		else if(a[i]==2) p[4].push(i);
		else if(a[i]==8) p[5].push(i);
	}
	
	for (int i=1;i<=q;i++) {
		scanf("%d%d",&Q[i].l,&Q[i].r); Q[i].idx=i;
	}
	sort( Q+1, Q+q+1, cmp_1 );
	
	int pt=n;
	for( int i=1;i<=q;i++) {
		int last[10]; int ll[10];//9102-8
		while ( p[1].front() > Q[i].l  ) { ll[1]=last[1]; last[1]=p[1].front(); p[1].pop(); }
		while ( p[2].front() > last[1] ) { ll[2]=last[2]; last[2]=p[2].front(); p[2].pop(); }
		while ( p[3].front() > last[2] ) { ll[3]=last[3]; last[3]=p[3].front(); p[3].pop(); }
		while ( p[4].front() > last[3] ) { ll[4]=last[4]; last[4]=p[4].front(); p[4].pop(); }
		while ( p[5].front() > last[4] ) { ll[5]=last[5]; last[5]=p[5].front(); p[5].pop(); }
		
		int l = Q[i].l, r = last[2];
		if ( last[4] <= Q[i].r ) {
			Q[i].ans += Query8(l,r);
			int res = min ( Query1(last[4],ll[3]), min ( Query0(ll[3]), Query2() ) );
		} else {
			Q[i].ans=-1;
		}
	}
	
	sort ( Q+1, Q+q+1, cmp_2 );
	for ( int i=1;i<=q;i++ ) {
		printf("%d\n",Q[i].ans);
	}
}

/*
---------------------
  author:dragon_bra
---------------------
*/

