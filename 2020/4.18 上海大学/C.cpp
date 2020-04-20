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



int main() {
    redirect();

    string a,b;
    cin>>a>>b;
    if(a==b) puts("-1");
    else {
        printf("%d\n",max(a.length(),b.length()));
    }

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/