#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
const double eps = 1e-5;
const int N = 2e5 + 10;

void redirect() {
    #ifdef LOCAL
        freopen("1.in","r",stdin);
        freopen("1.out","w",stdout);
    #endif
}

int T;
int n;
int a[N];
bool vis1[N], vis2[N];

int main() {
    redirect();

    scanf("%d",&T);
    while(T--){
        int cmp = 0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) {
            scanf("%d",&a[i]);
            cmp = max(cmp, a[i]);
        }

        int ans = 0, lft = n-cmp ;
        bool f1 = true, f2 = true;
        
        for(int i=1;i<=cmp;i++) vis1[i] = 0, vis2[i] = 0;
        for(int i=1;i<=cmp;i++){
            if(a[i]>cmp) {f1 = false; break;}
            if(!vis1[a[i]]){
                vis1[a[i]] = true;
            } else {
                f1 = false; break;
            }
        }
        for(int i=1;i<=cmp;i++) {
            if(!vis1[i]) {f1 = false; break;}
        }
        for(int i=cmp+1;i<=n;i++){
            if(a[i]>lft) {f1 = false; break;}
            if(!vis2[a[i]]){
                vis2[a[i]] = true;
            } else {
                f1 = false; break;
            }
        }
        for(int i=1;i<=lft;i++) {
            if(!vis2[i]) {f1 = false; break;}
        }

        for(int i=1;i<=cmp;i++) vis1[i] = 0, vis2[i] = 0;
        for(int i=1;i<=lft;i++){
            if(a[i]>lft) {f2 = false; break;}
            if(!vis1[a[i]]){
                vis1[a[i]] = true;
            } else {
                f2 = false; break;
            }
        }
        for(int i=1;i<=lft;i++) {
            if(!vis1[i]) {f2 = false; break;}
        }
        for(int i=lft+1;i<=n;i++){
            if(a[i]>cmp) {f2 = false; break;}
            if(!vis2[a[i]]){
                vis2[a[i]] = true;
            } else {
                f2 = false; break;
            }
        }
        for(int i=1;i<=cmp;i++) {
            if(!vis2[i]) {f2 = false; break;}
        }

        if(cmp==lft) f2 = false;

        ans = f1 + f2;
        printf("%d\n",ans);
        if(f1) printf("%d %d\n",cmp,lft);
        if(f2) printf("%d %d\n",lft,cmp);
        

    }

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/