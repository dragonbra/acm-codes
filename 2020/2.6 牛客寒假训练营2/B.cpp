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

int n; char s[N];
int cnt1,cnt6;

int main() {
    redirect();

    cin>>n;
    scanf("%s",s+1);
    for(int i=1;i<=n;i++){
        if(s[i]=='1') cnt1++;
        else if(s[i]=='6') cnt6++;
    }

    int ans = min(cnt1,cnt6-1);
    cout<<ans<<endl;

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/