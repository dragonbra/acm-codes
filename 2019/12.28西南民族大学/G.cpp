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

int n;
struct node{
    int a; string b;
} a[N];
string b[10];

int main() {
    redirect();
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i].a);
    }
    for(int i=1;i<=n;i++){
        cin>>a[i].b;
    }
    b[1] = "do";
    b[2] = "re";
    b[3] = "mi";
    b[4] = "fa";
    b[5] = "sol";
    b[6] = "la";
    b[7] = "si";

    int ans = 0;
    for(int i=1;i<=n;i++){
        if(a[i].b!=b[a[i].a]) ans++;
    }
    cout<<ans<<endl;

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/