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
const int INF = 1e6;
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

struct mat {
    int val[5][5];
    mat () {
        for (int i=0;i<5;i++) {
            for(int j=0;j<5;j++) val[i][j] = INF;
            val[i][i] = 0;
        }
    }
    mat operator + (mat a) const {
        int i,j,k;
        mat t;
        for (i=0;i<5;i++) {
            for (j=0;j<5;j++) {
                t.val[i][j] = INF;
                for(k=i;k<=j;k++) {
                    t.val[i][j] = min(t.val[i][j],val[i][k]+a.val[k][j]);
                }
            }
        }
        return t;
    }
};

mat mul (mat a,mat b) {
	mat ans;int i,j,k;
	for(i=1;i<=3;i++)
        for(j=1;j<=3;j++)
            ans.val[i][j]=0;
    for(i=1;i<=3;i++)
        for(j=1;j<=3;j++)
            for(k=1;k<=3;k++)
                ans.val[i][j]=(ans.val[i][j]+a.val[i][k]*b.val[k][j])%mod;
    return ans;
}

mat matqp(mat t,long long p) {
    mat ans;
    int i,j;
    for(i=1;i<=3;i++)
        for(j=1;j<=3;j++)
            if(i==j)ans.val[i][j]=1;
            else ans.val[i][j]=0;
    while(p)
    {
        if(p&1)
            ans=mul(ans,t);
        t=mul(t,t);
        p=p>>1;
    }
    return ans;
}

int n,q;
char s[N],ss[N];
mat tree[N*4];

void build (int now,int l,int r) {
    if (l==r) {
        if(s[l]=='2'){ tree[now].val[0][0] = 1; tree[now].val[0][1] = 0; }
        else if(s[l]=='0'){ tree[now].val[1][1] = 1; tree[now].val[1][2] = 0; }
        else if(s[l]=='1'){ tree[now].val[2][2] = 1; tree[now].val[2][3] = 0; }
        else if(s[l]=='9'){ tree[now].val[3][3] = 1; tree[now].val[3][4] = 0; }
        else if(s[l]=='8'){ tree[now].val[3][3] = 1; tree[now].val[4][4] = 1; }
        return;
    }
    int mid = (l+r)/2;
    build(now<<1,l,mid); build(now<<1|1,mid+1,r);
    tree[now] = tree[now<<1]+tree[now<<1|1];
}

mat query(int now,int l,int r,int x,int y) {
    if(l==x && r==y) return tree[now];
    int mid = (l+r)/2;
    mat a,b;
    if(x<=mid) a = query(now<<1,l,mid,x,min(mid,y));
    if(y>mid) b = query(now<<1|1,mid+1,r,max(mid+1,x),y);
    return a+b;
}

int main() {
	redirect();
    scanf("%d%d",&n,&q); scanf("%s",ss);
    for(int i=0;i<n;i++) s[i]=ss[n-1-i];
    build(1,0,n-1);
    while (q--) {
    	int l,r; scanf("%d%d",&l,&r);
		int tl=l,tr=r; l=n-tr; r=n-tl;
		
        int ans = query(1,0,n-1,l,r).val[0][4];
        
        if(ans>=INF) printf("-1\n");
        else printf("%d\n",ans);
    }
}

/*
---------------------
  author:dragon_bra
---------------------
*/
