#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
const double eps = 1e-5;
const int N = 20 + 10;

void redirect() {
    #ifdef LOCAL
        freopen("1.in","r",stdin);
        freopen("1.out","w",stdout);
    #endif
}

struct node{
    int x,y;
    string p;
} a[N];
unordered_map< string, int > mp;
string idx[N];

int n; int D;
ll f [ N ] [ 1<<20 + 10] ;

int main() {
    redirect();

    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int x,y; string p;
        cin>>x>>y>>p;
        a[i].x = x, a[i].y = y, a[i].p = p;
        if(mp[p]==0){
            D++; idx[D] = p;
        } mp[p]++;
    }

    for(int i=1;i<=D;i++){
        for(int j=1;j<=N;j++){
            string p = a[j].p;
            for(int k=1;k<=1<<D;k++){
                if( k & (1<<j) == 0 ){
                    f [i] [ k + (1<<j) ] = min ( f [i] [ k + (1<<j) ], f [i] [k] +  )
                }
            }
        }
    }

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/