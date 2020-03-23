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

int a[11];

int main() {
    redirect();

    while(cin>>a[1]&&a[1]!=0){
        int ans = 0;
        for(int i=2;i<=7;i++) cin>>a[i];
        if(a[2]==0&&a[5]==0) ans = 0;
        else {
            if(a[2]!=0) {
                if(a[3]==0&&a[4]==0) ans += a[2];
                else {
                    if(a[3]!=0) ans += a[3]*2;
                    if(a[4]!=0) ans += a[4]*2;
                } 
            }

            if(a[5]!=0) {
                if(a[6]==0&&a[7]==0) ans += a[5];
                else {
                    if(a[6]!=0) ans += a[6]*2;
                    if(a[7]!=0) ans += a[7]*2;
                } 
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/