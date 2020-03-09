#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
const double eps = 1e-5;
const int N = 1e4 + 10;

void redirect() {
    #ifdef LOCAL
        freopen("1.in","r",stdin);
        freopen("1.out","w",stdout);
    #endif
}

int T; int a,b;

int main() {
    //redirect();

    cin>>T;
    while(T--){
        cin>>a>>b;
        if(a%b==0) puts("YES");
        else puts("NO");
    }

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/