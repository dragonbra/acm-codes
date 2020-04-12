#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
const double eps = 1e-5;
const int N = 3e5 + 10;
 
void redirect() {
    #ifdef LOCAL
        freopen("1.in","r",stdin);
        freopen("1.out","w",stdout);
    #endif
}
 
int T; int n, a[N];
 
int main() {
    redirect();
 
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        
        bool f1 = 1, f2 = 1; int pos1, pos2;
 
        for(int i=1;i<=n;i++){
            if( a[i] < i-1 ){
                f1 = 0, pos1 = i-1; break;
            }
        }
        if(f1){ printf("Yes\n"); continue; }
        
        int cmp = 0;
        for(int i=n;i>=1;i--){
            if( a[i] >= cmp ){ cmp++; }
            else {
                f2 = 0, pos2 = i+1; break;
            }
        }
 
        if(f2||pos2<=pos1) printf("Yes\n");
        else printf("No\n");
    }
 
    return 0;
}
 
/*
-----------------
author:dragon_bra
-----------------
*/