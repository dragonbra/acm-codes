#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
const int mod=1e9+7;
const int INF=0x3f3f3f3f;
ll read(){
    ll f=1,x=0;char ch;
    do{ch=getchar();if(ch=='-')f=-1;}while(ch<'0'||ch>'9');
    do{x=x*10+ch-'0';ch=getchar();}while(ch>='0'&&ch<='9');
    return f*x;
}
int n,fa[maxn];
struct Point{
    ll x,y;
};

ll operator^(const Point&a,const Point&b){
    return a.x*b.y-a.y*b.x;
}

ll operator*(const Point&a,const Point&b){
    return a.x*b.x+a.y*b.y;
}

Point operator-(const Point&a,const Point&b){
    return Point{a.x-b.x,a.y-b.y};
}

struct Line{
    Point s,e;  
}a[maxn];

int sgn(ll x){
    if(x > 0)return 1;
    else if(x < 0)return -1;
    return 0;
}

int segcrossseg(Line u,Line v){
    int d1 = sgn((u.e-u.s)^(v.s-u.s));
    int d2 = sgn((u.e-u.s)^(v.e-u.s));
    int d3 = sgn((v.e-v.s)^(u.s-v.s));
    int d4 = sgn((v.e-v.s)^(u.e-v.s));
    if((d1^d2) == -2 && (d3^d4) == -2)return 2;
    return (d1==0 && sgn((v.s-u.s)*(v.s-u.e)) <= 0) ||
           (d2==0 && sgn((v.e-u.s)*(v.e-u.e)) <= 0) ||
           (d3==0 && sgn((u.s-v.s)*(u.s-v.e)) <= 0) ||
           (d4==0 && sgn((u.e-v.s)*(u.e-v.e)) <= 0);
}
int find(int x){
	if(x==fa[x])return x;
	return fa[x]=find(fa[x]);
}
void combine(int a,int b){
	int ffa=find(a),ffb=find(b);
	if(ffa!=ffb)fa[ffa]=ffb;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		ll xx1,yy1,xx2,yy2;
		scanf("%lld%lld%lld%lld",&xx1,&yy1,&xx2,&yy2);
		a[i].s.x=xx1,a[i].s.y=yy1;
		a[i].e.x=xx2,a[i].e.y=yy2;
	}
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if(segcrossseg(a[i],a[j]))combine(i,j);
	int cnt=0;
	for(int i=1;i<=n;i++)
		if(fa[i]==i)cnt++;
	printf("%d\n",cnt);
	return 0;
}
