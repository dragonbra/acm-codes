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

int n;int a[N],c[N];

int lowbit(int x){
	return x&(-x);
}

void update(int i,int k){//µ¥µã¼Ó
	while(i<=n){
		c[i]+=k;
		i+=lowbit(i);
	}
}

int suf_sum(int i){
	int res=0;
	while(i>0){
		res+=c[i];
		i-=lowbit(i);
	}
	return res;
}

int Query(int l,int r){
	return suf_sum(r)-suf_sum(l-1);
}

int main(){
	redirect();
	int T;scanf("%d",&T);
	for (int TT=1;TT<=T;TT++) {
		memset(a,0,sizeof a); memset(c,0,sizeof c);
		printf("Case %d:\n",TT);
		scanf("%d",&n);
		for (int i=1;i<=n;i++) {
			scanf("%d",&a[i]); update(i,a[i]);
		}
		string cmd="";
		while (cin>>cmd) {
			if(cmd=="End") break;
			else if (cmd=="Add") {
				int i,j; scanf("%d%d",&i,&j);
				update(i,j);
			} else if (cmd=="Sub") {
				int i,j; scanf("%d%d",&i,&j);
				update(i,-j);
			} else if (cmd=="Query") {
				int i,j; scanf("%d%d",&i,&j);
				int ans = Query (i,j); printf("%d\n",ans);
			}
		}
	}
}

/*
---linux compile---
g++ aa.cpp -o aa
./ aa
-------------------
author:dragon_bra
*/

