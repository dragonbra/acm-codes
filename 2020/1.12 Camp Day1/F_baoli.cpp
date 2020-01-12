#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
const double eps = 1e-5;
const int N = 1e7 + 5;

#define LOCAL
void redirect() {
    #ifdef LOCAL
        freopen("1.in","r",stdin);
        freopen("1.out","w",stdout);
    #endif
}

int n,m,k;
ll a[N],b[N], c[N];

int main() {
    redirect();
    
    cin>>n>>m>>k; int cnt = 0;
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(int i=1;i<=m;i++) scanf("%lld",&b[i]);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            c[++cnt] = a[i]*b[j];
        }
    }
    sort(c+1,c+cnt+1);

    cout<<c[cnt-k+1]<<endl;

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/