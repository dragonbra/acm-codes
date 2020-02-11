#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int INF = 0x3f3f3f3f;
const ull mod = 5e12+7;
const double eps = 1e-5;
const int N = 1e5 + 10;

void redirect() {
    #ifdef LOCAL
        freopen("1.in","r",stdin);
        freopen("1.out","w",stdout);
    #endif
}

ull qp(ull x, ull p){
    ull res = 1;
    while(p){
        if(p&1) res*=x;
        x*=x; p>>=1;
    }
    return res;
}

int T;
ll aa,bb,cc,gg;
int fa,fb,fc,fg;
ull a,b,c,d,e,f,g;

int main() {
    redirect();
    cin>>T;
    while(T--){
        cin>>a>>b>>c>>d>>e>>f>>g;

        /*
        if(aa<0&&d%2) fa=-1; a = abs(aa);
        if(bb<0&&e%2) fb=-1; b = abs(bb);
        if(cc<0&&f%2) fc=-1; c = abs(cc);
        if(gg<0) fg=-1; g = abs(gg);
        */

        //cout<<fg*g<<endl;

        if( qp(a,d) + qp(b,e) + qp(c,f) == g ) puts("Yes");
        else puts("No");
    }
    

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/