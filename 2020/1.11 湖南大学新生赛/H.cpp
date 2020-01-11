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

int T; int n; double ans;

int main() {
    redirect();
    
    cin>>T;
    while(T--){
        cin>>n;
        double res = 1.0;
        for(int i=1;i<=n;i++) res*=0.5;
        ans = 1.0 - res;
        printf("%.4lf\n",ans);
    }

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/