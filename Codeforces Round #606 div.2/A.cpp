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

int n;int ans;

int main() {
	//redirect();
	int T; scanf("%d",&T);
	while(T--){
		scanf("%d",&n); ans = 0;
		int t = n, dgt = 0;
		while(t>0) dgt++,t/=10;
		//cout<<"dgt "<<dgt<<endl<<endl;
		
		int cmp = 0;
		for(int i=1;i<=9;i++){
			cmp = 0;
			for(int j=1;j<=dgt;j++){
				cmp*=10; cmp+=i; 
			}
			//cout<<n<<' '<<cmp<<endl<<endl;
			if(n<cmp){
				ans = (dgt-1)*9 + i - 1;
				break; 
			}
			if(i==9&&n==cmp){
				ans = dgt*9;
				break;
			}
		}
		
		printf("%d\n",ans);
	}
}

/*
-----------------
author:dragon_bra
-----------------
*/

