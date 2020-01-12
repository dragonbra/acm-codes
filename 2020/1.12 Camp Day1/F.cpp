#include <bits/stdc++.h>
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

int n,m,K;
int a[N],b[N]; int acnt = 0, bcnt = 0;

int cal(ll x){
    int l = 1, r = m, mid;
    while(l<=r){
        mid = (l+r)/2;
        if( b[mid] >= x ) r = mid - 1;
        else l = mid + 1;
    }
    return m - mid ;
}

int main() {
    redirect();

    scanf("%d%d%d",&n,&m,&K);
    for(int i=1;i<=n;i++) {
        scanf("%d",&a[i]); if(a>0) acnt++;
    }
    for(int i=1;i<=m;i++) {
        scanf("%d",&b[i]); if(b>0) bcnt++;
    }

    sort(a+1,a+n+1);
    sort(b+1,b+n+1);

    ll pos = acnt + bcnt;
    ll l,r,mid;

    l = -1e12, r = 1e12;
    while(l<=r){-
        mid = (l+r)/2; int acc1 = 0;
        for(int i=1;i<=n;i++){
            ll cmp1 = mid / a[i] , cmp2 = (mid-1) / a[i];
            acc1 += cal(cmp1);
        }
        if( acc1 > K-1 ) l = mid + 1;
        else r = mid - 1;
    }

    printf("%lld\n",mid);

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/