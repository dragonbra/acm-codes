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

ll u,v;

int main() {
    redirect();

    cin>>u>>v;

    if(u==0 && v==0){
        cout<<0<<endl;
    } else if(u==v) {
        cout<<1<<endl;
        cout<<u<<endl;
    } else {
        if(v<u||(v-u)%2==1) {
            cout<<-1<<endl;
        } else {
            ll h = (v-u) / 2;
            if( ( (u+h) ^ h ) == u ){
                cout<<2<<endl;
                cout<<u+h<<' '<<h<<endl;
            } else {
                cout<<3<<endl;
                cout<<u<<' '<<h<<' '<<h<<endl;
            }
        }
    }

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/