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
typedef long double db;
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
const int MAXN=55;
const db PI=acos(-1.0);
struct Point{
    db x,y;
    Point(){}
    Point(db _x,db _y):x(_x),y(_y){}
    Point operator - (const Point &t)const
    {
        return Point(x-t.x,y-t.y);
    }
    db operator ^ (const Point &t)const
    {
        return x*t.x+y*t.y;
    }
    db len()const
    {
        return sqrt(x*x+y*y);
    }
}p[MAXN];
db ang(Point a,Point b,Point c)
{
    db t=((b-a)^(c-a))/(b-a).len()/(c-a).len();
    return acos(max(-1.0L,min(1.0L,t)));
}
int main()
{
	redirect();
    int T;scanf("%d",&T);
    for(int ca=1;ca<=T;ca++)
    {
        int n;
        scanf("%d",&n);
        for(int i=0;i<=n;i++)
        {
            double x,y;
            scanf("%lf%lf",&x,&y);
            p[i]=Point(x,y);
        }
        db res=0;
        for(int i=0;i<n;i++)
            res+=(p[n]-p[i]).len()*(PI-ang(p[i],p[(i-1+n)%n],p[(i+1)%n]));
        printf("Case #%d: %.3f\n",ca,(double)res);
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
