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

struct node{
    char c;
    int pre,nxt;
} a[N];

int main() {
    redirect();

    cin >> n;
    cin >> s;

    for(int i=1;i<=n;i++){
        a[i].c = s[i-1];
        if(i!=1) a[i].pre = i-1;
        if(i!=n) a[i].nxt = i+1;
    }

    for(int i=1;i<=n;i++){
        char t = 'a';
        for(int j=1;j<=n;j++){
            if( !vis[j] ) t = max ( t, a[j].c );
        }

        for(int j=1;j<=n;j++){
            if( a[j].c == t ){
                int pre = a[j].pre, nxt = a[j].nxt;
                if( abs(a[j].c - a[pre].c) == 1 || abs(a[j].c - a[nxt].c) == 1 ){
                    cout<<j<<endl;
                    vis[j] = true; ans++;
                    a[pre].nxt = nxt; a[nxt].pre = pre;
                    break;
                }
            }
        }
    }

    cout<<ans<<endl;

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/