#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
const double eps = 1e-5;
const int N = 1e2 + 10;

void redirect() {
    #ifdef LOCAL
        freopen("1.in","r",stdin);
        freopen("1.out","w",stdout);
    #endif
}

int n;
int a[N],b[N];

int main() {
    redirect();

    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&b[i]);
    }

    bool f = 0; int cnt = 0, sum = 0;
    for(int i=1;i<=n;i++){
        if(a[i]==1 && b[i]==0) { f=1; cnt++; }
        if(a[i]==0 && b[i]==1) { sum++; }
    }

    if(!f){
        puts("-1");
    } else {
        int ans = (sum+cnt) / cnt ;
        printf("%d\n",ans);
    }

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/