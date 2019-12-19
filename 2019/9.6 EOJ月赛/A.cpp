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

int main() {
	redirect();
	int T;scanf("%d",&T);
	while(T--){
		ll n;scanf("%lld",&n);
		int res = 0;ll nn=n;
		while(n%2==0&&n!=2){
			n/=4;if(n==2||n%2) break;
		}
		if(n==2) printf("Cuber QQ Win\n");
		else printf("Little Fang Win\n");
	}
}

/*
---------------------
  author:dragon_bra
---------------------
*/

