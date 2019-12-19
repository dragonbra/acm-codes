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
const int N = 200+10;
const int M = 3610;

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

int f[N][M]; int tf[N][M]; int t1[N],t2[N];

int main(){
	//redirect();
	int n,K;
	while(~scanf("%d%d",&n,&K)){
		if(n<0) n=0; if(K>n) K=n;
		memset(f,-1,sizeof(f));
		for(int i=0;i<=n;i++) f[0][0]=0;
		for(int i=1;i<=n;i++){
			ll t; scanf("%lld",&t);
			
			ll tt = t; int cnt = 0;
			while(tt%2==0){
				tt/=2; cnt++;
			} t1[i]=cnt;
			
			tt = t; cnt = 0;
			while(tt%5==0){
				tt/=5; cnt++;
			} t2[i]=cnt;
		}
		
		for(int i=1;i<=n;i++){
			for(int j=min(i,K);j>=1;j--){
				for(int k=t2[i];k<=M-10;k++){
					if( f[j-1][k-t2[i]] != -1 ){
						f[j][k] = max( f[j][k] , f[j-1][k-t2[i]] + t1[i] );
						//cout<< i <<' '<< j <<' '<< k << ' '<< f[i][j][k]<<endl;
					}
				}
			}
		}

		int ans = 0;
		for(int i=1;i<=M-10;i++){
			int cmp = min(f[K][i],i);
			if(cmp>ans){
				ans = cmp;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

/*
---------------------
  author:dragon_bra
---------------------
*/

