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
const int N = 2e5+10;

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

struct node{
	int x; int p;
	bool operator < (const node &a) const {
		return p > a.p;
	}
}a[N];

priority_queue<node> Q; int n;

bool cmp(node a,node b){
	if(a.x==b.x) return a.p<b.p;
	return a.x<b.x;
}

int main() {
	//redirect();
	int T; scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i].x);
			a[i].p=0;
			while(a[i].x%2==0) a[i].p++,a[i].x/=2;
		}
		
		sort(a+1,a+n+1,cmp);
		
		ll ans = 0;
		for(int i=1;i<=n;i++){
			if(a[i+1].x==a[i].x&&i!=n) continue;
			ans += a[i].p;
		}
		
		printf("%lld\n",ans);
	}
	
}

/*
-----------------
author:dragon_bra
-----------------
*/

