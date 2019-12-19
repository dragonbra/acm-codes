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
const double eps = 1e-5;
const int INF = 0x7fffffff;
const int MOD = 1e9+7;
const int N = 1e5+10;

void redirect(){
    #ifdef LOCAL
        freopen("test.txt","r",stdin);
    #endif
}
inline ll read(){
    ll f=1,x=0;char ch;
    do{ch=getchar();if(ch=='-')f=-1;}while(ch<'0'||ch>'9');
    do{x=x*10+ch-'0';ch=getchar();}while(ch>='0'&&ch<='9');
    return x*f;
}

struct node{
	double l,r;
} a[N];

bool cmp(node a,node b){
    return a.r<b.r;
}

int n,d;

int main(){

	//redirect();

	int T=0;
	while(~scanf("%d%d",&n,&d)){
		if(n==0&&d==0) break;
		memset(a,0,sizeof(a));

		bool f=0;
		for(int i=1;i<=n;i++){
			int x,y;scanf("%d%d",&x,&y);
			if(y>d) { f=1; }
			double ee = sqrt(1.0*d*d-1.0*y*y);
			a[i].l=(double)x-ee;a[i].r=(double)x+ee;
		}
		printf("Case %d: ",++T);
		if(f) { printf("-1\n");continue; }
		
		sort(a+1,a+n+1,cmp);
		int ans=0;
		for(int i=1;i<=n;){
		    double r = a[i].r;
			while(a[i].l<=r && r<=a[i].r) i++;
			ans++;
		}
		printf("%d\n",ans);
	}

	return 0;
}

/*
---linux compile---
g++ aa.cpp -o aa
./ aa
-------------------
*/
