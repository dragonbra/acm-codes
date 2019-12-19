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

map<int,int> g;int n;

int g_index(int x){
	if(g.count(x)==0){
		return x;
	} else {
		return g[x] = g_index(g[x]);
	}
}

int main() {
	redirect();
	int n,q; scanf("%d%d",&n,&q);
	for (int i=1;i<=q;i++) {
		int z,x; scanf("%d%d",&z,&x);
		if (z==1) {
			g[x] = g_index(x+1);
		} else {
			int ans = g_index(x);
			printf("%d\n",ans);
		}
	}
}

/*
---------------------
  author:dragon_bra
---------------------
*/

