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

int l,r; int ans;

int main() {
    redirect();
    
    cin>>l>>r; ans = 0;
    for(int i=l;i<=r;i++){
        if(i==1) ans++;
        else{
            bool flag = true;
            for(int j=2;j<=sqrt(i)+1;j++){
                if(i%j==0) {
                    flag = false; break;
                }
            }
            if(flag) ans++;
        }
    }

    cout<<ans<<endl;

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/