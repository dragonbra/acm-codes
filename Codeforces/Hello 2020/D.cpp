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

int n; bool ans = true; int cnt,cnt2;
struct node{
    int s,e; int idx,rk1,rk2;
} a[N],b[N];

int as[N*4],at[N*4];

bool cmp(node a,node b){
    return a.s<b.s;
}

bool cmp2(node a,node b){
    return a.e<b.e;
}

bool cmp3(node a,node b){
    return a.idx<b.idx;
}

int main() {
    redirect();
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d%d%d",&a[i].s,&a[i].e,&b[i].s,&b[i].e); 
        a[i].idx = b[i].idx = i;
        as[++cnt] = a[i].s; as[++cnt] = a[i].e; at[++cnt2] = b[i].s; at[++cnt2] = b[i].e; 
    }

    sort(as+1,as+cnt+1);
    sort(at+1,at+cnt2+1);
    //for(int i=1;i<=cnt;i++) cout<<as[i]<<' '; cout<<endl;
    
    sort(a+1,a+n+1,cmp);
    int pt = 1;
    for(int i=1;i<=n;i++){
        while(as[pt]<a[i].s && pt<cnt ) pt++;
        if(a[i].s==as[pt]) a[i].rk1 = pt;
    }

    sort(b+1,b+n+1,cmp);
    pt = 1;
    for(int i=1;i<=n;i++){
        while(at[pt]<b[i].s && pt<cnt ) pt++;
        if(b[i].s==at[pt]) b[i].rk1 = pt;
    }

    sort(a+1,a+n+1,cmp2);
    pt = 1;
    for(int i=1;i<=n;i++){
        while(as[pt]<a[i].e && pt<cnt ) pt++;
        if(a[i].e==as[pt]) a[i].rk2 = pt;
    }
    
    sort(b+1,b+n+1,cmp2);
    pt = 1;
    for(int i=1;i<=n;i++){
        while(at[pt]<b[i].e && pt<cnt ) pt++;
        if(b[i].e==at[pt]) b[i].rk2 = pt;
    }

    sort(a+1,a+n+1,cmp3);
    sort(b+1,b+n+1,cmp3);

    for(int i=1;i<=n;i++){
        //cout<<a[i].rk1<<' '<<a[i].rk2<<' '<<b[i].rk1<<' '<<b[i].rk2<<endl;
        if(a[i].rk1!=b[i].rk1 || a[i].rk2!=b[i].rk2){
            ans = false;
        }
    }

    if(ans) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/