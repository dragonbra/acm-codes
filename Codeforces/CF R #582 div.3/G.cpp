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

struct Edge{
	int u,v,w;
} E[N];

bool cmp(Edge a,Edge b){
	return a.w<b.w;
}

struct Query{
	int q,num;ll ans;
} Q[N];

bool cmp_q1(Query a,Query b){
	return a.q<b.q;
}

bool cmp_q2(Query a,Query b){
	return a.num<b.num;
}

int f[N];ll size[N];
int n,m;

int getf(int x){
    return f[x] == x ? x : f[x]=getf(f[x]);
}

int main(){
	redirect();
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++) scanf("%d%d%d",&E[i].u,&E[i].v,&E[i].w);
	for(int i=1;i<=m;i++){
		scanf("%d",&Q[i].q);
		Q[i].num=i;
	}
	sort(E+1,E+n,cmp);sort(Q+1,Q+m+1,cmp_q1);
	
	for(int i=1;i<=n;i++){
		f[i]=i;size[i]=1;
	}
	ll ans=0;int pt=1;
	for(int i=1;i<=m;i++){
		int cmp=Q[i].q;
		
		while(E[pt].w<=cmp&&pt<n){
			int u=E[pt].u,v=E[pt].v;
			int uf=getf(u),vf=getf(v);
			
			f[vf]=uf;ans+=size[uf]*size[vf];size[uf]+=size[vf];
			
			pt++;
		}
		Q[i].ans=ans;
	}
	sort(Q+1,Q+m+1,cmp_q2);
	for(int i=1;i<=m;i++) printf("%I64d ",Q[i].ans);

	return 0;
}

/*
---linux compile---
g++ aa.cpp -o aa
./ aa
-------------------
author:dragon_bra
*/

