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

int n,p;int a[10];int rm[10];
int ans[N];ll rr[N];
char s[N];

int main() {
	redirect();
	memset(rm,0,sizeof rm);
	scanf("%d%d",&n,&p);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++){
		a[s[i]-'0']++;rm[s[i]-'0']++;
	}
	
	while (p--) {
		for(int i=1;i<=9;i++) a[i]=rm[i];
		
		int k; scanf("%d",&k);
		
		if(rr[k]){
			printf("%d\n",rr[k]);
		} else {
			int dgt = n/k;
			int pt = 9; int cnt = k - n%k;
			for(int i=1;i<=dgt;i++){
				if ( a[pt] >= cnt ) {
					ans[i]=pt; a[pt] -= cnt;
				} else {
					cnt -= a[pt]; pt--;
					while ( a[pt] < cnt ) {
						cnt -= a[pt]; pt--;
					}
					a[pt] -= cnt;
					ans[i] = pt;
				}
			}

			ll res=0;
			for(int i=1;i<=dgt;i++){
				res *= 10;
				res += ans[i];
				res %= mod;
			}
			rr[k]=res;
			printf("%lld\n",res);
		}
	}
}

/*
---------------------
  author:dragon_bra
---------------------
*/

