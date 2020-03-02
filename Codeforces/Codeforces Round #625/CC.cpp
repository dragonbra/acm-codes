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

int n; char s[N];
bool vis[N]; int ans;

int main() {
    redirect();

    cin >> n;
    cin >> s;

    for(char t='z';t>='a';){
        bool f = 0;

        for(int j=0;j<n;j++){
            if( !vis[j] && s[j] == t ){
                int pre=j-1,nxt=j+1;
                for(;pre>=0;pre--){
                    if(!vis[pre]) break;
                }
                for(;nxt<n;nxt++){
                    if(!vis[nxt]) break;
                }

                if(abs(s[j]-s[pre]) == 1 || abs(s[j]-s[nxt])==1){
                    //cout<<j<<' '<<s[j]<<endl;
                    vis[j] = true; f = 1;
                    ans++; break;
                }
            }
        }

        if(!f) t--;
    }

    cout<<ans<<endl;

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/