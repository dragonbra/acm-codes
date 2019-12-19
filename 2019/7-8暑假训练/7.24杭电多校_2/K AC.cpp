#include<bits/stdc++.h>
using namespace std;

const int maxn=100005;
const int maxl=45;

typedef long long ll;
struct Node
{
    int k[maxl];
    int l,r;
    int len;
} tree[maxn<<2];

int a[maxn];

int merge(int* A,int* B,int *res,int la,int lb,int l)
{
    int p=0,q=0,cur=0;
    while(cur<l&&(p<la||q<lb))
    {
        if(p>=la||(q<lb&&A[p]<B[q]))
        {
            //assert(q<lb);
            res[cur++]=B[q++];
        }
        else
        {
            //assert(p<la);
            res[cur++]=A[p++];
        }
    }
    return cur;
}

void build(int o,int l,int r)
{
    //cout<<o<<" "<<l<<" "<<r<<endl;
    if(l==r)
    {
        tree[o].l=tree[o].r=l;
        tree[o].k[0]=a[l];
        tree[o].len=1;
        return;
    }
    tree[o].l=l;
    tree[o].r=r;
    tree[o].len=min(maxl,r-l+1);
    int mid=(l+r)>>1;
    build(o<<1,l,mid);
    build(o<<1|1,mid+1,r);
    merge(tree[o<<1].k,tree[o<<1|1].k,tree[o].k,tree[o<<1].len,tree[o<<1|1].len,tree[o].len);
}

int temp[2][maxl];

int cur_len,x;
void visit(int o,int l,int r)
{
    if(tree[o].l>=l&&tree[o].r<=r)
    {
        cur_len=merge(temp[x],tree[o].k,temp[x^1],cur_len,tree[o].len,maxl);
        x^=1;

    }
    else
    {
        int mid=(tree[o].l+tree[o].r)>>1;
        if(l<=mid)
        {
            visit(o<<1,l,r);
        }
        if(mid<r)
        {
            visit(o<<1|1,l,r);
        }
    }
}
ll query(int l,int r)
{

    if(r-l+1<3)
    {
        return -1;
    }
    cur_len=0;
    x=0;
    visit(1,l,r);

    ll res=temp[x][0]+temp[x][1];
    for(int i=2; i<cur_len; i++)
    {
        res+=temp[x][i];
        if(temp[x][i]+temp[x][i-1]>temp[x][i-2])
        {
            return res;
        }
        res-=temp[x][i-2];
    }
    return -1;
}


int main()
{
    int n,q;
    while(scanf("%d%d",&n,&q)==2)
    {
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
        }
        build(1,1,n);
        int l,r;
        while(q--)
        {
            scanf("%d%d",&l,&r);
            printf("%lld\n",query(l,r));
        }
    }
    return 0;
}
