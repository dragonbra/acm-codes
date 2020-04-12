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

map<int,int> a;
int T, n;

int main() {
    redirect();

    cin>>T;
    while(T--) {
        cin>>n;
        a.clear(); int cnt = 0;
        for(int i=1;i<=n;i++) {
            int t; cin>>t;
            if(a[t]==0) a[t]=1,cnt++;
        }
        cout<<cnt<<endl;
    }

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/