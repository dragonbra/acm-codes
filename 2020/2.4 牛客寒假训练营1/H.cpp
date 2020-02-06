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

int n,k; char s[N];
int a[N], b[N];

int main() {
    redirect();

    cin>>n>>k;
    scanf("%s",s+1);

    int cnt0 = 0, cnt1 = 0;
    for(int i=1;i<=n;i++){
        if(s[i]=='0') a[++cnt0] = i;
        else b[++cnt1] = i; 
    }
    a[0] = b[0] = 0;
    a[cnt0+1] = b[cnt1+1] = n+1;

    int ans = 0;
    
    for(int i=1;i<=cnt0;i++){
        int rpos = min(cnt0+1,i+k);
        int l = a[i-1] + 1, r = a[rpos] - 1;
        ans = max(ans,r-l+1);
    }

    for(int i=1;i<=cnt1;i++){
        int rpos = min(cnt1+1,i+k);
        int l = b[i-1] + 1, r = b[rpos] - 1;
        ans = max(ans,r-l+1);
    }

    cout<<ans<<endl;

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/