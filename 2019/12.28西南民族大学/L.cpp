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
const int N = 2e3 + 10;

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

int n; ll k; ll a[N][N],pre[N][N];

int main() {
    redirect();
    scanf("%d%lld",&n,&k);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%lld",&a[i][j]);
        }
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            pre[i][j] = a[i][j] + pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1];
        }
        //(x,y,u,v) = pre[u][v] + pre[u-1][v-1] - pre[u][y-1] - pre[x-1][v];
    }

    int l = 1, r = n;
    while(l<r){
        int mid = (l+r-1)/2;
        ll t = 0, cmp = 0;
        for(int i=mid;i<=n;i++){
            for(int j=mid;j<=n;j++){
                int x = i-mid+1, y = j-mid+1, u = i, v = j;

                t = pre[u][v] + pre[x-1][y-1] - pre[u][y-1] - pre[x-1][v];
                //cout<<i<<' '<<j<<' '<<pre[u][v]<<endl;
                //cout<<mid<<' '<<t<<endl;
                cmp = max(cmp,t);
            }
        }
        //cout<<cmp<<endl;
        if(cmp>=k) r = mid;
        else l = mid+1;
    }

    if(pre[n][n]<k){
        cout<<"I'm a Gold Chef!"<<endl;
    } else {
        cout<<l<<endl;
    }

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/