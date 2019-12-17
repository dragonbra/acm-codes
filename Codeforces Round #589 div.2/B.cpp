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
const int N = 1e3+10;

void redirect() {
    #ifdef LOCAL
        //freopen("test.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
}
inline ll read() {
    ll f=1,x=0;char ch;
    do {ch=getchar(); if(ch=='-') f=-1;} while (ch<'0'||ch>'9');
    do {x=x*10+ch-'0'; ch=getchar(); } while (ch>='0'&&ch<='9');
    return x*f;
}

bool a[N][N]={0}; int h,w; bool af=0;
int r[N],c[N];

ll qp(ll x,ll a){
	ll res = 1;
	while(a){
		if(a&1) res*=x,res%=mod;
		x*=x; x%=mod;
		a/=2; 
	}
	return res;
}

int main() {
	redirect();
	scanf("%d%d",&h,&w);
	for(int i=1;i<=h;i++) scanf("%d",&r[i]);
	for(int i=1;i<=w;i++) scanf("%d",&c[i]);
	
	for(int i=1;i<=h;i++){
		for(int j=1;j<=r[i];j++) a[i][j]=1;
		r[i]++;
	}
	
	for(int j=1;j<=w;j++){
		for(int i=1;i<=c[j];i++) a[i][j]=1;
		c[j]++; 
	}
	
	for(int i=1;i<=h;i++){
		int mk=0;
		for(int j=1;a[i][j];j++) mk++;
		if(mk+1!=r[i]) af=1;
	}
	
	for(int j=1;j<=w;j++){
		int mk=0;
		for(int i=1;a[i][j];i++) mk++;
		if(mk+1!=c[j]) af=1;
	}
	
	int cnt = 0;
	for(int i=2;i<=h;i++){
		for(int j=2;j<=w;j++){
			if(i>c[j]&&j>r[i]) cnt++;
		}
	}
	
	if(af) printf("0\n");
	else {
		ll ans = qp(2,cnt);
		printf("%I64d\n",ans);
	}
	
}

/*
-----------------
author:dragon_bra
-----------------
*/

