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
        freopen("test.txt","r",stdin);
    #endif
}
inline ll read(){
    ll f=1,x=0;char ch;
    do{ch=getchar();if(ch=='-')f=-1;}while(ch<'0'||ch>'9');
    do{x=x*10+ch-'0';ch=getchar();}while(ch>='0'&&ch<='9');
    return x*f;
}

const int MAXN=100005;
struct Point
{
    ll x,y;
    Point(){}
    Point(ll _x,ll _y):x(_x),y(_y){}
    Point operator - (const Point &t)const
    {
        return Point(x-t.x,y-t.y);
    }
    ll operator * (const Point &t)const
    {
        return x*t.y-y*t.x;
    }
}P,Q,A[MAXN];

int rp[MAXN],rq[MAXN],id[MAXN];

struct BIT
{
    pair<int,int> c[MAXN];
    int n;
    void init(int _n)
    {
        n=_n;
        for(int i=1;i<=n;i++)
            c[i]={0,0};
    }
    void update(int p,pair<int,int> v)
    {
        for(int i=p;i<=n;i+=i&-i)
            c[i]=min(c[i],v);
    }
    pair<int,int> query(int p)
    {
        pair<int,int> res={0,0};
        for(int i=p;i>0;i-=i&-i)
            res=min(res,c[i]);
        return res;
    }
}bit;

int pre[MAXN];

pair<int,vector<int> > solve(vector<int> vec,int lef)
{
    int n=(int)vec.size();
    if(!n)return {0,{}};
    for(int i=0;i<n;i++)id[i]=i;
    sort(id,id+n,[&vec,&lef](const int &x,const int &y)
    {
        if((A[vec[x]]-P)*(A[vec[y]]-P))return (A[vec[x]]-P)*(A[vec[y]]-P)*lef>0;
        else return (A[vec[x]]-Q)*(A[vec[y]]-Q)*lef>0;
    });
    for(int i=0;i<n;i++)rp[id[i]]=i;
    sort(id,id+n,[&vec,&lef](const int &x,const int &y)
    {
        if((A[vec[x]]-Q)*(A[vec[y]]-Q))return (A[vec[x]]-Q)*(A[vec[y]]-Q)*lef<0;
        else return (A[vec[x]]-P)*(A[vec[y]]-P)*lef<0;
    });
    for(int i=0;i<n;i++)rq[id[i]]=i;
    sort(id,id+n,[](const int &x,const int &y){return rp[x]<rp[y];});
    bit.init(n);
    for(int ii=0;ii<n;ii++)
    {
        int i=id[ii];
        pair<int,int> now=bit.query(rq[i]);
        pre[i+1]=now.second;
        bit.update(rq[i]+1,{now.first-1,i+1});
    }
    int cur=bit.query(n).second;
    vector<int> res;
    while(cur>0)res.push_back(vec[cur-1]),cur=pre[cur];
    return {-(int)res.size(),res};
}

int main()
{
	redirect();
    int T;
    scanf("%d",&T);
    for(int ca=1;ca<=T;ca++)
    {
        scanf("%lld%lld",&P.x,&P.y);
        scanf("%lld%lld",&Q.x,&Q.y);
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%lld%lld",&A[i].x,&A[i].y);
        vector<int> lef,rig;
        for(int i=1;i<=n;i++)
        {
            if((A[i]-P)*(Q-P)<0)lef.push_back(i);
            else rig.push_back(i);
        }
        pair<int,vector<int> > res=min(solve(lef,1),solve(rig,-1));
        printf("Case #%d: %d\n",ca,-res.first);
        for(auto &t:res.second)printf("%d\n",t);
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

