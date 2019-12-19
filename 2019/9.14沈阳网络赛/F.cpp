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
const int N = 5e5+10;

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

int n,k;int t[N];

struct Node{
	int num,cnt;
} a[N],b[N];

int main() {
	redirect();
	while ( ~scanf("%d%d",&n,&k) ) {
		ll sum=0;
		for(int i=1;i<=n;i++) scanf("%d",&t[i]),sum+=t[i];
		ll cmp=sum/n;
		
		sort(t+1,t+n+1);int acnt=0,bcnt=0;
		for (int i=1;i<=n;i++) {
			if(t[i]<=cmp) {
				if(acnt==0||a[acnt].num!=t[i]) a[++acnt].num=t[i],a[acnt].cnt=1;
				else a[acnt].cnt++;
			}
		}
		for (int i=n;i>acnt;i--) {
			if(bcnt==0||b[bcnt].num!=t[i]) b[++bcnt].num=t[i],b[bcnt].cnt=1;
			else b[bcnt].cnt++;
		}
		a[acnt+1].num=cmp; b[bcnt+1].num=cmp;
		
		int pt=1,cnt=a[1].cnt; int kk=k; int ansa=a[1].num, ansb=b[1].num;
		while(kk&&pt<=acnt) {
			if ( cnt*(a[pt+1].num-a[pt].num) <= kk ) {
				kk -= ( cnt*(a[pt+1].num-a[pt].num) );
				ansa = a[pt+1].num; cnt += a[pt+1].cnt; pt++; continue;
			} else {
				int ex = kk / cnt; ansa += ex; break;
			}
		}
		
		pt=1,cnt=b[1].cnt; kk=k;
		while(kk&&pt<=bcnt) {
			if ( cnt*(b[pt].num-b[pt+1].num) <= kk ) {
				kk -= ( cnt*(b[pt].num-b[pt+1].num) );
				ansb = b[pt+1].num; cnt += b[pt+1].cnt; pt++; continue;
			} else {
				int ex = kk / cnt; ansb -= ex; break;
			}
		}
		
		//for(int i=1;i<=acnt+1;i++) cout<<a[i].num<<' ';cout<<endl;
		//cout<<ansa<<' '<<ansb<<endl;
		
		if(ansa==ansb) {
			if(cmp*n==sum) printf("0\n");
			else printf("1\n");
		} else printf("%d\n",ansb-ansa);
	}
}

/*
---------------------
  author:dragon_bra
---------------------
*/

