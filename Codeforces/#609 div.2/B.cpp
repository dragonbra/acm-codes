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
const int N = 2e3 + 5;

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

int n,m;
int a[N], b[N];

int main() {
    redirect();
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    for(int i=0;i<n;i++) scanf("%d",&b[i]);
    sort(a,a+n); sort(b,b+n);

    int ans = 0;
    for(int i=0;i<n;i++){
        bool flag = true;
        //cout<<bb[i].num<<' '<<bb[i].cnt<<endl;
        ans = b[i] + m - a[0]; ans %= m;
        for(int j=0;j<n;j++){
            //cout<<aa[(i+j)%acnt].cnt<<' '<<bb[j].cnt<<endl;
            if( (a[j] + ans) % m != b[(i+j)%n] ){
                flag = false; break;
            }
        }
        if(flag) break;
    }

    printf("%d\n",ans);

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/