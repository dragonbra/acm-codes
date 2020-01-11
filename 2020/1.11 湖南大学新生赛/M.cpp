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

ll l,r;
ll a[N],b[N],ans[N];

int main() {
    redirect();

    cin>>l>>r;
    l = l; r = r+1;
    
    ll res = 1; int pt = 0;
    while(res<=l){
        a[pt] += (l/(res*2)*res);
        if(l%(res*2) > res) a[pt] += (l%(res*2) - res);
        pt++; res*=2;
    }

    res = 1; pt = 0;
    while(res<=r){
        b[pt] += (r/(res*2)*res);
        if(r%(res*2) > res) b[pt] += (r%(res*2) - res);
        pt++; res*=2;
    }

    ll cnt = 0; res = 1;
    for(int i=0;i<=pt;i++){
        ans[i] = b[i] - a[i]; //cout<<i<<' '<<b[i]<<' '<<a[i]<<endl;;
        if(ans[i]%2) cnt += res;
        res*=2;
    }

    cout<<cnt<<endl;
    
    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/