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

int n,k,a[N];int rcd[N][2];

int main(){
	redirect();
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	
	int ans=INF;
	for(int i=1;i<=n;i++){
		int op=0;
		while(a[i]){
			rcd[a[i]][1]++;rcd[a[i]][2]+=op;
			if(rcd[a[i]][1]==k) ans=min(ans,rcd[a[i]][2]);
			a[i]/=2;op++;
		}
		rcd[a[i]][1]++;rcd[a[i]][2]+=op;
		if(rcd[a[i]][1]==k) ans=min(ans,rcd[a[i]][2]);
	}
	printf("%d\n",ans);


	return 0;
}

/*
---linux compile---
g++ aa.cpp -o aa
./ aa
-------------------
author:dragon_bra
*/

