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

int n,a[N];

int main() {
    redirect();
    int kase = 0;

    while(cin>>n) {
        if(n==0) break;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++){
            if(i%2) cout<<a[i]<<' ';
        }
        for(int i=1;i<=n;i++){
            if(i%2==0) {
                cout<<a[i];
                if(i/2!=n/2) cout<<' ';
            }
        } cout<<endl;
    }

    return 0;
}