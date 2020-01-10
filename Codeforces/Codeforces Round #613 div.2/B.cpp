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

int T,n;
ll pre[N]; ll a[N];

int main() {
    redirect();

    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        int mk = 0; ll r = -1e15, sum = 0;
        for(int i=1;i<=n;i++){
            scanf("%lld",&a[i]); pre[i] = pre[i-1] + a[i]; sum += a[i];
            if(pre[i]>r){
                mk = i; r = pre[i];
            }
        }
        ll l = 0;
        for(int i=1;i<=mk;i++){
            if(mk==n&&i==1){
                l = 1e15;
            }
            l = min(pre[i],l);
        }

        ll ans = r-l;
        if(sum>ans) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    
    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/