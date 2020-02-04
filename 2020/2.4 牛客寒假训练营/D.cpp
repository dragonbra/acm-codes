#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
const double eps = 1e-5;
const int N = 1e5 + 10;

void redirect() {
    #ifdef LOCAL
        freopen("1.in","r",stdin);
        freopen("1.out","w",stdout);
    #endif
}

int n; bool vis[N];

int main() {
    redirect();

    scanf("%d",&n);
    for(int i=1;i<n;i++){
        int t; scanf("%d",&t); vis[t] = 1;
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            ans = i; break;
        }
    }

    printf("%d\n",ans);

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/