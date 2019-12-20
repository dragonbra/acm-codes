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
const int N = 3e5 + 5;

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

int a[N], pos[N];

int main() {
    redirect();
    int T; scanf("%d",&T);
    
    while(T--){
        int n; scanf("%d",&n);
        int cnt1=0, cnt2=0;
        for(int i=1;i<=2*n;i++){
            scanf("%d",&a[i]);
            if(a[i]==1) cnt1++;
            else cnt2++;
        }

        const int cg = 1e5+10; 
        int need = cnt1 - cnt2;
        memset(pos,0,sizeof pos);

        cnt1=0, cnt2=0;
        for(int i=n;i>=1;i--){
            if(a[i]==1) cnt1++;
            if(a[i]==2) cnt2++;

            int cmp = cg + cnt1 - cnt2;

            pos[cmp] = max(pos[cmp], i); 
        }

        int ans = INF;
        if(need == 0) ans = 0;
        pos[cg] = n+1;

        if(pos[cg + need]!=0) ans = min(ans, n - pos[cg + need] + 1);

        cnt1=0, cnt2=0;
        for(int i=n+1;i<=2*n;i++){
            if(a[i]==1) cnt1++;
            if(a[i]==2) cnt2++;

            int cmp = cnt1 - cnt2;

            //cout<<need<<' '<<cmp<<' '; cout<<need-cmp<<' '<<pos[need-cmp+cg]<<' '<<i<<endl; 
            cmp = need - cmp + cg;

            if(pos[cmp]!=0) ans = min(ans, i-pos[cmp]+1);
        }

        printf("%d\n",ans);
    }

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/