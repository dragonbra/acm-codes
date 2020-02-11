#include <bits/stdc++.h>
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
int a[N]; int aa[N]; ll ans = 0;
map<int,int> mmp;

int main() {
    redirect();

    cin>>n; mmp[0]=1;
    for(int i=1;i<=n;i++) {
        scanf("%d",&a[i]), aa[i] = aa[i-1]^a[i];
        ans += mmp[aa[i]];
        mmp[aa[i]]++;
    }
    //for(int i=1;i<=n;i++) cout<<aa[i]<<' '; cout<<endl;
    
    cout<<ans<<endl;
    
    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/