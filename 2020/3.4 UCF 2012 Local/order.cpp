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

int T;int a[N];

int main() {
    redirect();

    cin>>T; int C=0;
    while(T--){
        C++;
        for(int i=1;i<=3;i++) cin>>a[i];
        cout << "Data set #" << C << ":" << endl;
        cout << "   Original order: ";
        cout<<1[a]<<' '<<2[a]<<' '<<3[a]<<endl;

        sort(a+1,a+4);

        cout << "   Smallest to largest: ";
        cout<<a[1]<<' '<<a[2]<<' '<<a[3];
        cout<<endl<<endl;
    }

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/