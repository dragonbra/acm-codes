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

int T; int x;

int main() {
    redirect();

    cin>>T;
    while(T--){
        cin>>x;
        if(x%2==0) cout<<x/2<<' '<<x/2<<endl;
        else {
            cout<<"1 "<<x-1<<endl;
        }
    }

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/