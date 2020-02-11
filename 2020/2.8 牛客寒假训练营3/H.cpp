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

int n,m,k;
bool is_[N];
int cnt[N];

int main() {
    redirect();

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=2;j*j<=i;j++){
            if(i%j==0){
                is_[i]=true; break;
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(is_[i]){
            int res=0;
            for(int j=1;j*j<=i;j++){
                if(i%j==0){
                    int x = j, y = i/j;
                    if(x==y) y=1;
                    res+=(is_[x]+is_[y]);
                }
            }
            //cout<<i<<' '<<res<<endl;
            cnt[res]++;
        }
    }

    for(int i=1;i<=m;i++){
        int k; cin>>k; cout<<cnt[k]<<endl;
    }

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/