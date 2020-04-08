#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
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
const int N = 1e2 + 5;

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

int n; int a[N];
struct node{
    int s, len, yx;
} b[N];

bool cmp(node a,node b){
    return a.yx < b.yx;
}

int main() {
    redirect();
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);

    int cnt = 0, len = 0, yx = 0; int acc = 0;
    for(int i=1;i<=n;i++){
        if(a[i]%2==0) {
            len++;
            if(a[i]==0) yx++;
            if(i==n){
                b[++cnt].s = i-len + 1; b[cnt].len = len; b[cnt].yx = yx;
                len = 0; yx = 0;
            }
        }
        else {
            acc++;
            b[++cnt].s = i-len; b[cnt].len = len; b[cnt].yx = yx;
            len = 0; yx = 0;
        }
    }

    sort(b+1,b+cnt+1,cmp);
    int pt = 0;
    while( acc < (n+1)/2 ){
        pt++;
        for(int i=b[pt].s;i<b[pt].s+b[pt].len;i++){
            if(i==0) continue;
            if(a[i]==0){
                a[i] = 3; acc++; 
            }
            if(acc==(n+1)/2) break;
        }
    }

    for(int i=1;i<=n;i++){
        if(a[i]==0) a[i]=2;
    }

    int ans = 0; bool f = a[1]%2;
    for(int i=2;i<=n;i++){
        if(a[i]%2!=f){
            f=!f; ans++;
        }
    }

    for(int i=1;i<=n;i++) cout<<a[i]<<' '; cout<<endl;

    printf("%d\n",ans);
    
    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/