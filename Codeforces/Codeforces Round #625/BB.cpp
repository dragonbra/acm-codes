#include <bits/stdc++.h>
#include <iostream>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
const double eps = 1e-5;
const int N = 2e5 + 10;

void redirect() {
    #ifdef LOCAL
        freopen("1.in","r",stdin);
        freopen("1.out","w",stdout);
    #endif
}

int n;
ll ans;

struct node{
    ll b;
    int cmp;
} a[N];

bool cmp(node a,node b){
    return a.cmp < b.cmp;
}

int main() {
    redirect();

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].b;
        a[i].cmp = a[i].b - i;
    }
    
    sort(a+1,a+n+1,cmp);

    a[0].cmp = -INF; ll mk = 0;
    for(int i=1;i<=n;i++){
        if(a[i].cmp!=a[i-1].cmp){
            mk = a[i].b;
        } else {
            mk += a[i].b;
        }
        ans = max(ans,mk);
    }

    cout << ans << endl;

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/