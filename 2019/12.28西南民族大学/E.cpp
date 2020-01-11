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

int n,m,k;

int main() {
    redirect();
    cin>>n>>m>>k; if(n>m) swap(n,m);
    if( k>=5 || (k>=1&&m==1&&n==1) || (n==1&&m==2 && k>=2) ||( min(n,m)==1 && k>=2 ) || ( m==2&&n==2 && k>=3 ) || ( min(n,m) == 2 && k>=4) ) {
        cout<<"Beautiful flowers!"<<endl;
    } else {
        cout<<"Oh! My poor HJ!"<<endl;
    }

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/