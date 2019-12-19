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
const int N = 1e3+10;

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

struct node {
	int p; int cnt;
} Q[N*2]; int t[N*2];

int main(){
	redirect();
	int T; scanf("%d",&T); int TT=T;
	while(T--) {
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m*2;i+=2) scanf("%d%d",&t[i],&t[i+1]),t[i+1]+=1;
		sort(t+1,t+m*2+1);int cnt=0; Q[0].p=-1;
		for(int i=1;i<=m*2;i++) {
			if(t[i]!=Q[cnt].p) Q[++cnt].p=t[i],Q[cnt].cnt=1;
			else Q[cnt].cnt++;
		}
		int ans=0;int now=0;bool f=0;
		for(int i=1;i<=cnt;i++) {
			if(f) {
				ans+=(Q[i].p-now); now=Q[i].p;
			}
			if(Q[i].cnt%2) {
				f=!f; now=Q[i].p;
			}
		}
		printf("Case #%d: %d\n",TT-T,ans);
		
	}
}

/*
---linux compile---
g++ aa.cpp -o aa
./ aa
-------------------
author:dragon_bra
*/

