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
const int INF = 0x3f3f3f3f;
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
ll f[1111],num=0;

int main() {
	//redirect();
	for(int i=1;i<=9;i++){
		f[++num]=i;
		ll x=1ll*i;
		while(x<1000000000){
			x=x*10+i;
			if(x<1000000000)f[++num]=x;
		}
	}
	sort(f+1,f+1+num);
	f[++num]=1000000000000;
	int T;
	scanf("%d",&T);
	while(T--){
		ll n,ans=0;
		scanf("%lld",&n);
		for(int i=1;i<=num;i++){
			if(n>=f[i])continue;
			else{
				ans=i;
				break;
			}
		}
		printf("%lld\n",ans-1);
	}
}

/*
-----------------
author:dragon_bra
-----------------
*/

