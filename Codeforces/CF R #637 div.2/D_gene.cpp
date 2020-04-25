#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
const double eps = 1e-5;
const int N = 1e5 + 10;

void redirect() {
    #ifdef LOCAL
        //freopen("1.in","r",stdin);
        freopen("1.in","w",stdout);
    #endif
}



int main() {
    redirect();

    srand(unsigned(time(NULL)));

    cout << 2000 <<' ' << 2000 << endl;
    for (int i=1; i<=2000; i++) {
        for (int j=0; j<7; j++) {
            cout << rand()%2;
        } cout << endl;
    }

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/