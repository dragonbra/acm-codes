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
const int M = 150000 + 10;

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
int a[N], dp[2][M][2];

int main() {
	redirect();
	int T; scanf("%d",&T);
	while (T--) {
		memset(dp,0,sizeof dp);
		scanf("%d",&n); int rsum=0; int ans=0;
		for(int i=1;i<=n;i++) scanf("%d",&a[i]),rsum+=a[i];
		sort(a+1,a+n+1,cmp);
		
		dp[1][a[1]][1]=1; dp[0][0][0]=dp[1][0][0]=1; int sum=a[1];
		for(int i=2;i<=n;i++) {
			bool f = i%2;
			for(int j=0;j<=sum;j++) {
				for(int k=0;k<=1;k++) {
					if(dp[!f][j][k]) {
						dp[f][j+a[i]][1] += dp[!f][j][k], dp[f][j+a[i]][1]%=mod;
						if(j) dp[f][j][0] += dp[!f][j][k] , dp[f][j][0]%=mod;
					}
				}
			}
			sum+=a[i]; 
			for(int j=0;j<=sum;j++) {
				if ( j>rsum-j && j-a[i]<=rsum-j ) ans+=dp[f][j][1], ans%=mod;
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

