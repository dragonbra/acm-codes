#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
const double eps = 1e-5;
const int N = 500 + 10;

void redirect() {
    #ifdef LOCAL
        freopen("1.in","r",stdin);
        freopen("1.out","w",stdout);
    #endif
}

int n;
struct node{
    int pre, nxt;
    int a;
} a[N];

int main() {
    redirect();

    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i].a;
    for(int i=1;i<=n;i++){
        if(i!=1) a[i].pre = i-1;
        if(i!=n) a[i].nxt = i+1;
    }

    int T = 500; int head = 1;
    while(T--){
        bool f = 0;
        int t = head;
        while(a[t].nxt!=0){
            int nxt = a[t].nxt;
            if(a[t].a-1 == a[nxt].a) continue;
            
        }
    }

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/