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
	string s;
	bool vis; int pos;
} a[N];

bool cmp(node a,node b){
	return a.s<b.s;
}

int n, ans[N], cnt;

int main() {
	//redirect();
	int T; scanf("%d",&T);
	while(T--){
		scanf("%d",&n); cnt = 0;
		for(int i=1;i<=n;i++) cin>>a[i].s, a[i].vis=0, a[i].pos = i;
		
		sort(a+1,a+n+1,cmp);
		
		for(int i=1;i<=n;i++){
			if(a[i].s==a[i+1].s){
				if(a[i].vis){
					cnt = -1; break;
				} else {
					reverse(a[i+1].s.begin(),a[i+1].s.end());
					ans[++cnt] = a[i+1].pos;
					a[i].vis = a[i+1].vis = true;
				}
			}
		}
		
		for(int i=1;i<=n;i++){
			
		}
		
	}
}

/*
-----------------
author:dragon_bra
-----------------
*/

