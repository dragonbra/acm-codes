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

int Q;ll n,m;

int main(){
	redirect();
	scanf("%d",&Q);
	while(Q--){
		ll ans=0;
		scanf("%I64d%I64d",&n,&m);
		if(n>m*10){
			ll sum=0;ll mk=0;
			for(int i=1;i<=10;i++){
				mk+=m;sum+=(mk%10);
			}
			ans+=((n/mk)*sum);
			n-=((n/mk)*mk);
		}
		
		ll mk=m;
		while(mk<=n){
			ans+=(mk%10);mk+=m;
		}
		
		printf("%lld\n",ans);
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

