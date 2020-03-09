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

int T; ll n,k,a[N];
int mk[N];

int main() {
    redirect();

    cin>>T;
    while(T--){
        memset(mk,0,sizeof mk);
        cin>>n>>k;
        for(int i=1;i<=n;i++) cin>>a[i];
        
        ll res = 0;
        for(int i=1;i<=n;i++){
            ll t = a[i], p = -1;
            while(t){
                p++;
                if(t%k) mk[p]+=t%k;
                t /= k; 
            }
            res = max(p,res);
        }

        bool f = true; //cout<<res<<':';
        if( res==0 && mk[0]<=1 ) { f = true; }
        else {
            for(int i=0;i<=res;i++) {
                //cout<<mk[i]<<' ';
                if(mk[i]>1){ f = false; break; }
            }
        }

        if(f) puts("YES");
        else puts("NO");
    }

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/