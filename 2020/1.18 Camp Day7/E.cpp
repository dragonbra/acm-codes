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

int a[6] = {0,1,2,3,4,5};
bool vis[5]={0};
int b[6],aa[6];
int n = 5;

bool check(){
    int cnt = 0;
    for(int i=1;i<=n;i++){
        if(!vis[i]) b[++cnt] = i;
    }
    for(int i=2;i<=cnt;i++){
        if(a[i]>a[i-1]) return false;
    }
    return true;
}

int cmp = 0;
bool make_a(int cnt){
    if(cnt==cmp+1) {
        return check();
    }
    for(int i=1;i<=n;i++){
        if( !vis[i] && a[i]>aa[cnt-1] ){
            vis[i] = 1;
            aa[cnt] = a[i];
            vis[i] = 0;
            return make_a(cnt+1);
        }
    }
}

int main() {
    //redirect();
    int ans = 0; int cnt = 0;
    do{
        for(int i=0;i<5;i++) cout<<a[i]<<' ';cout<<endl;
        
        bool flag = true;

        for(int i=1;i<=4;i++){
            cmp = i, flag = make_a(1);
            if(!flag) break;
        }
        if(flag) ans ++; 
        
    } while( next_permutation(a+1,a+6) );

    cout<<ans<<endl;

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/