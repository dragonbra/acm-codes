#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
const double eps = 1e-5;
const int N = 1e2 + 10;

void redirect() {
    #ifdef LOCAL
        freopen("1.in","r",stdin);
        freopen("1.out","w",stdout);
    #endif
}

int T;
int n,m;
char a[N][N];

int main() {
    redirect();

    cin>>T;
    while(T--){
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                a[i][j] = 'B';
            }
        }

        a[1][1] = 'W';

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cout<<a[i][j];
            }
            cout<<endl;
        }
    }

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/