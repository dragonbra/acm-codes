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
const ll INF = 1e14;
const int mod = 1e9+7;
const double eps = 1e-5;
const int N = 310;

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

ll f[N][N];int n,m;

void init(){
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			f[i][j]=INF;
}

int main(){
	redirect();
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		init();
		for(int i=1;i<=m;i++){
			int x,y;ll w;scanf("%d%d%lld",&x,&y,&w);
			f[x][y]=w;
		}
		
					
		for(int kk=1;kk<=6;kk++){
			for(int k=0;k<n;k++)
				for(int i=0;i<n;i++)
					for(int j=0;j<n;j++){
						f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
					}
			int s,t;scanf("%d%d",&s,&t);
			ll ans=-f[t][s];
			f[s][t]=ans;
			printf("%lld\n",ans);
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

