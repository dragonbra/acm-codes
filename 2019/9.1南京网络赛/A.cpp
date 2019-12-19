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
const int N = 1e6+10;

void redirect(){
    #ifdef LOCAL
        freopen("out.txt","r",stdin);
        freopen("cmp.txt","w",stdout);
    #endif
}
inline ll read(){
    ll f=1,x=0;char ch;
    do{ch=getchar();if(ch=='-')f=-1;}while(ch<'0'||ch>'9');
    do{x=x*10+ch-'0';ch=getchar();}while(ch>='0'&&ch<='9');
    return x*f;
}

struct PT{
	ll x,y;ll v;
} plc[N];
struct Qrr{
	int x1,y1,x2,y2;int num;ll lans,rans;
} Q[N];
bool cmp_pt(PT a,PT b){
	return a.x<b.x;
}
bool cmp_qrr_1(Qrr a,Qrr b){
	return a.x1<b.x1;
}
bool cmp_qrr_2(Qrr a,Qrr b){
	return a.x2<b.x2;
}
bool cmp_qrr_end(Qrr a,Qrr b){
	return a.num<b.num;
}

int n,m,p;ll c[N];

int lowbit(int x){
	return x&(-x);
}
void update(int i,int k){
	while(i<=n){
		c[i]+=k;
		i+=lowbit(i);
	}
}
ll suf_sum(int i){
	ll res=0;
	while(i>0){
		res+=c[i];
		i-=lowbit(i);
	}
	return res;
}
ll Query(int l,int r){
	return suf_sum(r)-suf_sum(l-1);
}

ll QV(ll x,ll y){//求美丽值
	ll mi,ans=0;
	x=n-x+1;y=n-y+1;
    mi=min(x,min(y,min(n-x+1,n-y+1)));

    if(x<=y)
		ans=mi*(4*(n-1)-4*mi)+10*mi-4*n-3+x+y;
    else
		ans=mi*(4*n-4*mi)+2*mi+1-x-y;//模拟过程
		
	ll res=0;
	while(ans){
		res+=(ans%10);ans/=10;
	}
	return res;
}

int main(){
	redirect();
    int T;scanf("%d",&T);
    while(T--){
    	scanf("%d%d%d",&n,&m,&p);
    	for(int i=1;i<=m;i++){
    		int x,y;scanf("%lld%lld",&plc[i].x,&plc[i].y);
			plc[i].v=QV(plc[i].x,plc[i].y);
		}
		
		sort(plc+1,plc+m+1,cmp_pt);
		for(int i=1;i<=p;i++){
			int x1,y1,x2,y2;Q[i].num=i;
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			Q[i].x1=x1;Q[i].y1=y1;Q[i].x2=x2;Q[i].y2=y2;
		}
		
		//处理左端点
		memset(c,0,sizeof(c));
		sort(Q+1,Q+p+1,cmp_qrr_1);
		int pt=1;
		for(int i=1;i<=p;i++){
			while( plc[pt].x < Q[i].x1 && pt<=m ){
				update(plc[pt].y,plc[pt].v);pt++;
			}
			Q[i].lans=Query(Q[i].y1,Q[i].y2);
		}
		
		//处理右端点
		memset(c,0,sizeof(c));
		sort(Q+1,Q+p+1,cmp_qrr_2);
		pt=1;
		for(int i=1;i<=p;i++){
			while( plc[pt].x <= Q[i].x2 && pt<=m ){
				update(plc[pt].y,plc[pt].v);pt++;
			}
			Q[i].rans=Query(Q[i].y1,Q[i].y2);
		}
		
		sort(Q+1,Q+p+1,cmp_qrr_end);
		for(int i=1;i<=p;i++){
			printf("%lld\n",Q[i].rans-Q[i].lans);
		}

	}
	return 0;
}

/*
author:dragon_bra
*/
