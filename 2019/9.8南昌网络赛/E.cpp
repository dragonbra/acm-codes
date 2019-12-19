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
const int N = 4e7+10;

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

int n,m,q;
int nxt[N],frt[N];int ans[N];

int main() {
	redirect();
	int T;scanf("%d",&T);
	while (T--) {
		scanf("%d%d%d",&n,&m,&q);
		for(int i=1;i<=n;i++) {
			nxt[i]=i+1;frt[i]=i-1;
		}nxt[n]=1;frt[1]=n;
		
		ans[1]=1;int pos=1;nxt[n]=2;frt[2]=n;
		for(int i=2;i<=n;i++){
			for(int j=1;j<=m+1;j++) {
				pos=nxt[pos];
			}
			ans[pos]=i;
			nxt[ frt[pos] ] = nxt[pos];
			frt[ nxt[pos] ] = frt[pos];
		}
		
		//for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
		//cout<<endl;
		
		for(int i=1;i<=q;i++) {
			int k; scanf("%d",&k); printf("%d\n",ans[k]);
		}
	}
}

/*
---------------------
  author:dragon_bra
---------------------
*/

