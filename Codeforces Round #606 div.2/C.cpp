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

char s[N]; int ans[N], cnt;

int main() {
	//redirect();
	int T; scanf("%d",&T);
	while(T--){
		scanf("%s",s);
		
		int len = strlen(s); cnt = 0;
		for(int i=0;i<len;i++){
			if(s[i]=='t'){
				if(i+4<len && s[i+1]=='w' && s[i+2] == 'o' && s[i+3] == 'n' && s[i+4] == 'e'){
					ans[++cnt] = i+1 + 2;
				} else if( i+2<len && s[i+1]=='w' &&s[i+2] == 'o' ){
					ans[++cnt] = i+1 + 1;
				}
			} else if(s[i]=='o'){
				if( i+2<len && s[i+1]=='n' &&s[i+2]=='e' ){
					if( i-2>=0 && s[i-2]=='t' && s[i-1]=='w' ) continue;
					ans[++cnt] = i+1 + 1;
				}
			}
		}
		
		printf("%d\n",cnt);
		for(int i=1;i<=cnt;i++){
			printf("%d ",ans[i]);
		}
		printf("\n");
	}
	
}

/*
-----------------
author:dragon_bra
-----------------
*/

