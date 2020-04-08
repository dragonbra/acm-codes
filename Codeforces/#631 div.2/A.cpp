#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
const double eps = 1e-5;
const int N = 200 + 10;

void redirect() {
    #ifdef LOCAL
        freopen("1.in","r",stdin);
        freopen("1.out","w",stdout);
    #endif
}

int T;
int n,x;
bool vis[N];

int main() {
    redirect();

    cin>>T;
    while(T--){
        memset(vis,0,sizeof vis);
        scanf("%d%d",&n,&x);
        for(int i=1;i<=n;i++) {
            int t;
            scanf("%d",&t);
            vis[t] = true;
        }
        
        int v = x; int ans = 0;
        for(int i=1;i<=200;i++){
            if(!vis[i]){
                if(v>0){
                    v--;
                } else {
                    break;
                }
            }
            ans = max(ans, i);
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