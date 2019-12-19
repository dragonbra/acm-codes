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
const int M = 1e4+10;

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

ll p[N],c[N];
ll dp[M];
int n,m; ll ansa=1e9,ansb=1;

int main() {
	redirect();
	while (~scanf("%d%d",&n,&m)) {
		ansa=1e16;
		for(int i=1;i<M;i++) dp[i]=INF; dp[0]=0;
		for (int i=1;i<=n;i++) scanf("%lld%lld",&p[i],&c[i]);
		
		for (int i=1;i<=n;i++) {
			for (int j=0; j+c[i]<M; j++) {
				dp[j+c[i]] = min(dp[j+c[i]], dp[j]+p[i]);
			}
		}

		//for(int i=0;i<=10;i++) cout<<dp[i]<<' ';cout<<endl;
		
		for (int i=m;i<=M-10;i++) {
			if (dp[i]<ansa) {
				ansa=dp[i]; ansb=i;
			} else if (dp[i]==ansa) {
				ansb=i;
			}
 		}
		
		printf("%lld %lld\n",ansa,ansb);
	}
}

/*
---------------------
  author:dragon_bra
---------------------
*/
