#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
const double eps = 1e-5;
const int N = 3e3 + 10;

void redirect() {
    #ifdef LOCAL
        freopen("1.in","r",stdin);
        freopen("1.out","w",stdout);
    #endif
}

int T; int n,a[N],vis[N]; char s[N];

int main() {
    redirect();

    scanf("%d",&T);
    while(T--){
        int sum = 0; memset(vis,0,sizeof vis);
        scanf("%d",&n);
        scanf("%s",&s); for(int i=0;i<n;i++) a[i+1] = s[i]-'0', sum+=a[i+1];
        //for(int i=1;i<=n;i++) cout<<a[i]; cout<<endl;

        while(a[n]%2==0 && n>0) sum-=a[n], n--;
        
        if(sum%2==1){
            for(int i=1;i<n;i++){
                if(a[i]%2==1) {
                    sum-=a[i]; vis[i] = true;
                    break;
                }
            }
        }

        bool f = 0;
        for(int i=1;i<=n;i++){
            if(a[i]!=0){
                f = 1;
            } else {
                vis[i] = 1;
            }
        }

        if( n==0 || sum%2==1 ) {
            puts("-1");
        } else {
            for(int i=1;i<=n;i++){
                if(vis[i]==1) continue;
                printf("%d",a[i]);
            } 
            printf("\n");
        }
    }

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/