#include <bits/stdc++.h>
typedef long long LL;
using namespace std;
const int maxn = 2e5+7;
const LL inf = 1e18+7;
const int N = 2e6+7;
int n,b,a[maxn],h[maxn];
LL tree[4*N],ans;

void build(int l,int r,int rt)
{
    if(l==r)
    {
        tree[rt]=-inf;
        return;
    }
    int mid=(l+r)/2;
    build(l,mid,2*rt);
    build(mid+1,r,2*rt+1);
    tree[rt]=max(tree[2*rt],tree[2*rt+1]);
}
void update(int p,LL c,int l,int r,int rt)
{
    if(l==r)
    {
        tree[rt]=max(tree[rt],c);
        return;
    }
    int mid=(l+r)/2;
    if(p<=mid) update(p,c,l,mid,2*rt);
    else update(p,c,mid+1,r,2*rt+1);
    tree[rt]=max(tree[2*rt],tree[2*rt+1]);
}
LL query(int L,int R,int l,int r,int rt)
{
    if(L<=l && R>=r)
        return tree[rt];
    int mid=(l+r)/2;
    LL res=-inf;
    if(L<=mid) res=max(res,query(L,R,l,mid,2*rt));
    if(R>mid) res=max(res,query(L,R,mid+1,r,2*rt+1));
    return res;
}
int main()
{
    scanf("%d %d",&n,&b);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        scanf("%d",&h[i]);
    build(1,N,1);
    update(h[1],0,1,N,1);
    for(int i=2;i<=n;i++)
    {
        LL temp=query(max(1,h[i]-b),N,1,N,1);
        ans=max(ans,temp+a[i]);
        update(h[i],temp+a[i],1,N,1);
    }
    printf("%lld\n",ans);
    return 0;
}
