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
const int N = 5e5 + 5;

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

int n;
struct node{
    int l,r; int idx;
} a[N], b[N];

bool vis[N]; int ans=0; int pos[N], f[N]; bool flag = true;

bool cmp(node a,node b){
    return a.l<b.l;
}

bool cmp2(node a,node b){
    return a.r<b.r;
}

void dfs(int x){
    //cout<<x<<' '<<a[x].l<<' '<<a[x].r<<endl;
    for(int i=x-1;i>=1;i--){
        if(a[i].l<a[x].l && a[i].r>a[x].l && a[i].r<a[x].r){
            if(f[x]==i) continue;
            if(vis[i]) {
                flag = false; return;
            } else {
                ans++; f[i] = x; vis[i] = true; dfs(i); if(!flag) return;
            }
        }
    }

    for(int i=x+1;i<=n;i++){
        if(a[i].l>a[x].l && a[i].l<a[x].r && a[i].r>a[x].r){
            if(f[x]==i) continue;
            if(vis[i]) {
                flag = false; return;
            } else {
                ans++; f[i] = x; vis[i] = true; dfs(i); if(!flag) return;
            }
        }
    }

    int l = x+1, r = n;
    while(l<r){
        int mid = (l+r)/2;
        if(a[mid].l < a[x].l) l = mid+1;
        else if(a[mid].l > a[x].r) r = mid;
    }
    if(f[x]==l) l++;

    if(vis[l]) {
        flag = false; return;
    } else {
        ans++; f[l] = x; vis[l] = true; dfs(l); if(!flag) return;
    }

    return;
}

int main() {
    redirect();
    
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d%d",&a[i].l,&a[i].r);

    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++) a[i].idx = i, b[i]=a[i];
    sort(b+1,b+n+1,cmp2);
    for(int i=1;i<=n;i++) pos[b[i].idx]=i;

    ans++; vis[(n+1)/2] = 1; dfs((n+1)/2);

    if(flag && ans == n){
        cout<<"YES"<<endl;
    } else cout<<"NO"<<endl;

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/