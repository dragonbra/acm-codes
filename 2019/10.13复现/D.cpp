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
ll m;int a[400],x,ans;
int main() {
	//redirect();
	while(~scanf("%lld",&m)){
		if(m==0){
			printf("2\n");
			printf("1 1\n");
			printf("2 1\n");
		}else{
			memset(a,0,sizeof(a));x=0;ans=0;
			while(m>0){
				if(m==1){
					a[x+2]=x+2;
					a[x+1]=199;
					ans+=2;
					break;
				}else{
					if(m%2){
						a[x+1]=199;
						ans++;x+=2;m--;
					}else{
						a[x+1]=x+3;a[x+2]=x+3;
						x+=3;m/=2;ans+=2;
					}
				}
			}
			printf("%d\n",ans);
			for(int i=1;i<199;i++){
				if(!a[i])continue;
				printf("%d %d\n",i,a[i]);
			}
		}
	}
	return 0;
}

/*
---------------------
  author:dragon_bra
---------------------
*/

