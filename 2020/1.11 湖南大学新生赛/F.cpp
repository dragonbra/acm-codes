#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <vector>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
const double eps = 1e-5;
const int N = 1e5 + 5;

#define LOCAL
void redirect() {
    #ifdef LOCAL
        freopen("1.in","r",stdin);
        freopen("1.out","w",stdout);
    #endif
}

inline ll read() {
    ll f=1,x=0;char ch;
    do {ch=getchar(); if(ch=='-') f=-1;} while (ch<'0'||ch>'9');
    do {x=x*10+ch-'0'; ch=getchar(); } while (ch>='0'&&ch<='9');
    return x*f;
}

int n;
int x[N],y[N];

int main() {
    redirect();

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x[i]>>y[i];
    }

    bool flag = true, fflag = true;
    int x1=x[1],y1=y[1],x2=x1-1,y2=y1-1;
    for(int i=2;i<=n;i++){
        if(x[i]!=x1){
            fflag = false;
            x2 = x[i]; y2 = y[i];
        }
    }

    double k = (double)(y1-y2) / (double)(x1-x2), b = 1.0 * y1 - k * x1;

    //cout<<k<<' '<<b<<endl;
    
    for(int i=1;i<=n;i++){
        if( abs( k * x[i] + b - y[i] ) < eps ) continue;
        else {
            flag = false; break;
        }
   }

   if(flag||fflag) cout<<"Yes"<<endl;
   else cout<<"No"<<endl;

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/