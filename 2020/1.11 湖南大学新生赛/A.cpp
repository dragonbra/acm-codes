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

int T;
ll f[51];

int gcd(int a,int b){
    if(a>b) swap(a,b);
    if(a==0) return b;
    else return gcd(b%a,a);
}

int main() {
    redirect();
    
    f[1] = f[2] = 1;
    for(int i=3;i<=45;i++) f[i] = f[i-2] + f[i-1];

    cin>>T;
    while(T--){
        int m,n;
        cin>>m>>n;
        cout<<f[gcd(m,n)]<<endl;
    }

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/