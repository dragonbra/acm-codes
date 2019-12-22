#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
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
const int N = 2e5 + 5;

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

char a[N], b[N];
int n,m,k;

int main() {
    redirect();
    scanf("%d%d",&n,&k);
    scanf("%s",a);
    for(int i=0;i<n;i++){
        b[i] = a[i];
    }

    bool flag = true;
    for(int i=0;i<n-k;i++){
        if(a[i+k]!=a[i]) {
            flag = false; break;
        }
    }

    if(!flag){
        for(int i=0;i<n-k;i++) a[i+k] = a[i];
        if( strcmp(a,b) < 0 ) {
            a[k-1]++; 
            int t = k-1;
            while(a[t]=='9'+1){
                a[t]='0'; a[t-1]++; t--;
            }
            for(int i=0;i<n-k;i++) a[i+k] = a[i];
        }
    }

    cout<<n<<endl;
    cout<<a<<endl;

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/