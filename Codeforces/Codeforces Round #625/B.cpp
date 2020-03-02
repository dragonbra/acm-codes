#include <bits/stdc++.h>
#include <iostream>
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

int n;
ll ans;

struct node{
    ll b;
    bool vis;
    int pre, nxt;
} a[N];

int main() {
    redirect();

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].b;
        if( i!=1 ) a[i].pre = i-1;
        if( i!=n ) a[i].nxt = i+1;
    }

    int head = 1; int cnt = 0;

    while(cnt<n){
        bool f = 0; int pt = head; ll cmp = 0; cnt++; a[head].vis = true;
        cout << head << ' ';
        while( a[pt].nxt != 0 ){
            pt = a[pt].nxt;
            if( pt-head == a[pt].b - a[head].b ){
                cout << pt << ' ';
                //cut link
                a[pt].vis = true; cmp += a[pt].b; cnt++;
                int pre = a[pt].pre, nxt = a[pt].nxt;
                a[pre].nxt = nxt, a[nxt].pre = pre;
            } else if ( f==0 ) {
                f = 1; head = pt;
            }
        }

        ans = max ( ans, cmp );

        cout << endl;
    }

    cout << ans << endl;

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/