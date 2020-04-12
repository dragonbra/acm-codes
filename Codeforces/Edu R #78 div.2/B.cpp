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

ll a,b;

int main() {
    redirect();

    int T; scanf("%d",&T);
    
    while(T--){
        scanf("%lld%lld",&a,&b);
        ll cmp = max(a,b) - min(a,b);

        ll l=0,r=1e6+1;
        while(l<r){
            ll mid = (l+r)/2;
            if(mid*(mid+1)/2 >= cmp) r = mid;
            else l = mid+1;
        }

        while(cmp%2!=((l+1)*l/2)%2) l++;

        printf("%lld\n",l);
    }
    
    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/