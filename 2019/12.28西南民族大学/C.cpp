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
const int N = 1e3 + 5;

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

int n,d;
struct node{
    int x,y;
    double l,r;
} a[N];

bool vis[N];

bool cmp(node a,node b){
    return a.l<b.l;
}

int main() {
    redirect(); 
    int T = 0;
    while(~scanf("%d%d",&n,&d)){
        if(n==0&&d==0) break;

        memset(vis,0,sizeof vis);
        bool flag = false;

        for(int i=1;i<=n;i++){
            int x,y; scanf("%d%d",&x,&y);
            if(y>d){
                flag = true;
                continue;
            }
            a[i].l = x - sqrt(d*d - y*y); 
            a[i].r = x + sqrt(d*d - y*y);
        }

        T++; cout<<"Case "<<T<<": ";
        if(flag){
            cout<<"-1"<<endl;
        } else {
            sort(a+1,a+n+1,cmp);
        
            //cout<<endl; for(int i=1;i<=n;i++) cout<<a[i].l<<' '<<a[i].r<<endl; cout<<endl;

            int ans = 0;
            for(int i=1;i<=n;i++){
                if(vis[i]) continue;
                ans++;
                for(int j=i+1;j<=n;j++)
                    if(a[j].l<=a[i].r) vis[j]=1;
            }
            cout<<ans<<endl;
        }
        
    }

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/