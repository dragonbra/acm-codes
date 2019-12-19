#include <bits/stdc++.h>
#define INF -0x3f3f3f3f
using namespace std;
typedef long long ll;
const int N = 2e3+10;
struct pt{
	int x,y;ll w;
	int rx,ry;
} s[N];

bool cmp1(pt a,pt b){
	return a.y<b.y;
} 

bool cmp2(pt a,pt b){
	if(a.x!=b.x) return a.x<b.x;
	return a.y<b.y;
}

int T,n;int xcnt,ycnt;

ll a[N]={0};

struct SegmentTree{
    int l, r;
    ll dat, sum, lmax, rmax;
}t[N<<2];

void init(SegmentTree &tree, ll x){
    tree.dat=tree.lmax=tree.rmax=tree.sum=x;
}

void push_up(int p){
    t[p].sum = t[2*p].sum + t[2*p+1].sum;
    t[p].lmax = max(t[2*p].lmax, t[2*p].sum+t[2*p+1].lmax);
    t[p].rmax = max(t[2*p+1].rmax, t[2*p+1].sum+t[2*p].rmax);
    t[p].dat = max(t[2*p].dat, max(t[2*p+1].dat, t[2*p].rmax+t[2*p+1].lmax));
}

void build(int p, int l, int r){
    t[p].l = l, t[p].r = r;
    if(l == r){
        init(t[p], a[l]);
        return;
    }
    int mid = (l+r)/2;
    build(2*p, l, mid);
    build(2*p+1, mid+1, r);
    push_up(p);
}

void change(int p, int x, ll val){
    if(t[p].l == t[p].r){
        init(t[p], t[p].dat + val);
        return;
    }
    int mid = (t[p].l+t[p].r)/2;
    if(x <= mid) change(2*p, x, val);
    else change(2*p+1, x, val);
    push_up(p);
}

SegmentTree ask(int p, int l, int r){
    if(l <= t[p].l && r >= t[p].r){
        return t[p];
    }
    int mid = (t[p].l+t[p].r)/2;
    SegmentTree a, b, c;
    init(a, INF), init(b, INF);
    c.sum = 0;
    if(l <= mid) {
        a = ask(2*p, l, r);
        c.sum += a.sum;
    }
    if(r > mid) {
        b = ask(2*p+1, l, r);
        c.sum += b.sum;
    }
    c.dat = max(max(a.dat, b.dat), a.rmax+b.lmax);
    c.lmax = max(a.lmax, b.lmax+a.sum);
    c.rmax = max(b.rmax, a.rmax+b.sum);
    return c;
}

int main(){
	//freopen("1005.in","r",stdin);
	//freopen("me.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			int x,y,w;scanf("%d%d%lld",&s[i].x,&s[i].y,&s[i].w);
		}
		
		xcnt=0;ycnt=0;
		
		sort(s+1,s+n+1,cmp1);
		s[1].ry=++ycnt;
		for(int i=2;i<=n;i++){
			if(s[i].y==s[i-1].y) s[i].ry=ycnt;
			else s[i].ry=++ycnt;
		}
		
		sort(s+1,s+n+1,cmp2);
		s[1].rx=++xcnt;
		for(int i=2;i<=n;i++){
			if(s[i].x==s[i-1].x) s[i].rx=xcnt;
			else s[i].rx=++xcnt;
		}
		
		ll ans=0;
		
		for(int i=1;i<=xcnt;i++){
			build(1,1,ycnt);
			int ls=1;
			while(s[ls].rx!=i) ls++;
			for(int j=i;j<=xcnt;j++){
				while(s[ls].rx==j){
					change(1,s[ls].ry,s[ls].w);
					ls++;
				}
				ll t = ask(1,1,ycnt).dat;
				if(ans<t) ans=t;
			}
		}
		
		printf("%lld\n",ans);
	}
	return 0;
}

