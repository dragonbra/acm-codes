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


int n; int ans;
int a[10],vis[10];
void dfs(int x){
    if(x>n){
        //for(int i=1;i<x;i++)printf("%d",a[i]); printf("\n");
        for(int l=1;l<=n;l++)
            for(int r=l;r<=n;r++){
                int m1=INF,m2=0;
                for(int k=l;k<=r;k++) m1=min(m1,a[k]),m2=max(m2,a[k]); 
                //cout<<minnum<<' '<<maxnum<<' '<<l<<' '<<r<<endl;
                if( (m2-m1) == (r-l) && r-l==4 ) ans++;
            }
        return;
    }
    for(int i=1;i<=n;i++)
        if(!vis[i]){
            vis[i]=1;
            a[x]=i;
            dfs(x+1);
            vis[i]=0;
        }
}
int main() {
    redirect();

    while(~scanf("%d",&n)){
        ans=0;
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=n;i++){
            vis[i]=1;
            a[1]=i;
            dfs(2);
            vis[i]=0;
        }
        printf("%d\n",ans);
    }
    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/