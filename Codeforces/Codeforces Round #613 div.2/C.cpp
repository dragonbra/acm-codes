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

ll x, ans;

ll gcd(ll a,ll b){
    if(a>b) swap(a,b);
    if(a==0) return b;
    else return gcd(b%a,a);
}

int main() {
    redirect();
    
    scanf("%lld",&x); ans = x+1;
    ll cmp = sqrt(x) + 1;
    for(ll i=1;i<=cmp;i++){
        if(x%i!=0) continue;
        else {
            if(gcd(i,x/i)==1) ans = min( ans, max(i,x/i) );
        }
    }

    cout<<x/ans<<' '<<ans<<endl;

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/