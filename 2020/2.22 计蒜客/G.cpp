#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
const double eps = 1e-5;
const int N = 3e5 + 10;
const int M = 2e6 + 10;

void redirect() {
    #ifdef LOCAL
        freopen("1.in","r",stdin);
        freopen("1.out","w",stdout);
    #endif
}

int n, ans = 0;
char s[N];
int c[20]; int a[N]; 
int pos[M]; bool vis[M];

int main() {
    redirect();

    c[0]=1; for(int i=1;i<=19;i++) c[i] = c[i-1] * 2;
    vis[0] = 1; pos[0] = 0;
    
    scanf("%d",&n);
    scanf("%s",s+1);
    for(int i=1;i<=n;i++) {
        a[i] = a[i-1] ^ (c[s[i]-'a']);
        if(vis[a[i]]==0) vis[a[i]]=1, pos[a[i]] = i;
    }

    for(int i=n;i>=1;i--){
        for(int j=0;j<=20;j++){
            if( vis[a[i]^c[j]] && pos[a[i]^c[j]] < i ){
                ans = max( ans, i - pos[a[i]^c[j]] );
                //cout<<i<<' '<<j<<' '<<i - pos[a[i]^c[j]]<<endl<<a[i]<<' '<<(a[i]^c[j])<<endl;
            }
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