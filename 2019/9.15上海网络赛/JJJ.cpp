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
const int N = 300+10;
const int M = 76000 + 10;

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

bool cmp(int a,int b){
	return a>b;
}

int n;
int a[N], dp[N][M][2];

int main() {
	redirect();
	int T; scanf("%d",&T);
	while (T--) {
		memset(dp,0,sizeof dp);
		scanf("%d",&n); int rsum=0; int ans=0;
		for(int i=1;i<=n;i++) scanf("%d",&a[i]),rsum+=a[i];
		sort(a+1,a+n+1,cmp);
		
		dp[0][0][0]=1; int sum=0;
		for(int i=1;i<=n;i++) {
			int cmp = min(M-1,sum);
			for(int j=0;j<=cmp;j++) {
				for(int k=0;k<=1;k++) {
					if(dp[i-1][j][k]) {
						dp[i][j+a[i]][1] += dp[i-1][j][k], dp[i][j+a[i]][1]%=mod;
						dp[i][j][0] += dp[i-1][j][k], dp[i][j][0]%=mod;
					}
				}
			}
			sum+=a[i]; cmp = min(M-1,sum);
			for(int j=0;j<=cmp;j++) {
				if ( j>=rsum-j && j-a[i]<=rsum-j ) ans+=dp[i][j][1], ans%=mod;
			}
		}
		printf("%d\n",ans);
	}
}

/*
---------------------
  author:dragon_bra
---------------------
*/
