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

void redirect(){
    #ifdef LOCAL
        //freopen("test.txt","r",stdin);
    #endif
}
inline ll read(){
    ll f=1,x=0;char ch;
    do{ch=getchar();if(ch=='-')f=-1;}while(ch<'0'||ch>'9');
    do{x=x*10+ch-'0';ch=getchar();}while(ch>='0'&&ch<='9');
    return x*f;
}

bool is(int x){
	int cnt[10]={0};
	while(x){
		if(cnt[x%10]) return false;
		cnt[x%10]++; x/=10;
	}
	return true;
}

int main(){
	redirect();
	int l,r;bool f=0;
	scanf("%d%d",&l,&r);
	for(int i=l;i<=r;i++){
		if(is(i)) {
			printf("%d\n",i);
			f=1;
			break;
		}
	}
	if(!f) printf("-1\n");

	return 0;
}

/*
---linux compile---
g++ aa.cpp -o aa
./ aa
-------------------
author:dragon_bra
*/

