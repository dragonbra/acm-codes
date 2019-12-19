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
#include <stack>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF = 0x7fffffff;
const int mod = 1e9+7;
const double eps = 1e-5;
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

pair<int,int> operator + (const pair<int,int> &lhs,const pair<int,int> &rhs)
{
    if(lhs.first<rhs.first)return lhs;
    if(lhs.first>rhs.first)return rhs;
    return {lhs.first,lhs.second+rhs.second};
}

const int MAXN=100005;

pair<int,int> s[MAXN<<2];
int lz[MAXN<<2];

void push_up(int n)
{
    s[n]=s[n<<1]+s[n<<1|1];
}

void push_down(int n)
{
    if(!lz[n])return;
    s[n<<1].first+=lz[n];
    s[n<<1|1].first+=lz[n];
    lz[n<<1]+=lz[n];
    lz[n<<1|1]+=lz[n];
    lz[n]=0;
}

void build(int l,int r,int n)
{
    lz[n]=0;
    if(l==r)
    {
        s[n]={0,1};
        return;
    }
    int m=(l+r)/2;
    build(l,m,n<<1);
    build(m+1,r,n<<1|1);
    push_up(n);
}

void update(int ql,int qr,int v,int l,int r,int n)
{
    if(ql==l && qr==r)
    {
        s[n].first+=v;
        lz[n]+=v;
        return;
    }
    push_down(n);
    int m=(l+r)/2;
    if(qr<=m)update(ql,qr,v,l,m,n<<1);
    else if(ql>m)update(ql,qr,v,m+1,r,n<<1|1);
    else
    {
        update(ql,m,v,l,m,n<<1);
        update(m+1,qr,v,m+1,r,n<<1|1);
    }
    push_up(n);
}

pair<int,int> query(int ql,int qr,int l,int r,int n)
{
    if(ql==l && qr==r)return s[n];
    push_down(n);
    int m=(l+r)/2;
    if(qr<=m)return query(ql,qr,l,m,n<<1);
    if(ql>m)return query(ql,qr,m+1,r,n<<1|1);
    return query(ql,m,l,m,n<<1)+query(m+1,qr,m+1,r,n<<1|1);
}

int main()
{
	redirect();
    int T;
    scanf("%d",&T);
    for(int ca=1;ca<=T;ca++)
    {
        map<int,int> mp;
        stack<pair<int,int> > mi,mx;
        mi.push({0,0}),mx.push({1000000001,0});
        int n;
        scanf("%d",&n);
        build(1,n,1);
        ll res=0;
        for(int i=1;i<=n;i++)
        {
            int a;
            scanf("%d",&a);
            update(mp[a]+1,i,-1,1,n,1);
            mp[a]=i;
            while(mi.top().first>=a)
            {
                int c=mi.top().first;
                int r=mi.top().second;
                mi.pop();
                int l=mi.top().second+1;
                update(l,r,c,1,n,1);
            }
            update(mi.top().second+1,i,-a,1,n,1);
            mi.push({a,i});
            while(mx.top().first<=a)
            {
                int c=mx.top().first;
                int r=mx.top().second;
                mx.pop();
                int l=mx.top().second+1;
                update(l,r,-c,1,n,1);
            }
            update(mx.top().second+1,i,a,1,n,1);
            mx.push({a,i});
            pair<int,int> now=query(1,i,1,n,1);
            res+=(now.first==-1)*now.second;
        }
        printf("Case #%d: %lld\n",ca,res);
    }
    return 0;
}

/*
---linux compile---
g++ aa.cpp -o aa
./ aa
-------------------
author:dragon_bra
*/

