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
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
const double eps = 1e-5;
const int N = 1e5 + 5;

#define LOCAL
void redirect() {
    #ifdef LOCAL
        freopen("1.in","r",stdin);
        freopen("1.out","w",stdout);
    #endif
}

inline ll read() {
    ll f=1,x=0;char ch;
    do {ch=getchar(); if(ch=='-') f=-1;} while (ch<'0'||ch>'9');
    do {x=x*10+ch-'0'; ch=getchar(); } while (ch>='0'&&ch<='9');
    return x*f;
}

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
}a[N];

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

int n; int f[N];

int find(int x){
    return f[x]= (f[x]==x?x:find(f[x]));
}

int main() {
    redirect();
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        f[i] = i;
        ll x1,x2,y1,y2;
        scanf("%lld%lld%lld%lld",&x1,&y1,&x2,&y2);
        a[i].s.x = x1; a[i].s.y = y1;
        a[i].e.x = x2; a[i].e.y = y2;
    }

    for(int i=1;i<=n;i++){
        for(int j = i+1;j<=n;j++){
            if(segcrossseg(a[i],a[j])){
                int fa = find(i), fb = find(j);
                if(fa!=fb) f[fb] = fa;
            }
        }
    }

    int ans = 0;
    for(int i=1;i<=n;i++){
        if(find(i)==i) ans++;
    }
    cout<<ans<<endl;

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/