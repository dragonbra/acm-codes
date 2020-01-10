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

int n; int ans = 0;
string a[N]; 
bool vis[N];//0-29

void find(int ll,int rr,int pos){
    if(pos==30) return;
    int l=ll, r=rr;
    while(l<r){
        int mid = (l+r)/2;
        if(a[mid][pos] == a[mid+1][pos]){
            if(a[mid][pos] == '0') l = mid+1;
            else r = mid;
        } else{
            l = mid; r = mid+1; break;
        }
    }

    cout<<l<<' '<<r<<endl;

    if(a[l][pos] == a[r][pos]){
        vis[pos] = 1;
    }
    find(ll,l,pos+1);
    find(r,rr,pos+1);
}

int main() {
    redirect();

    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int t; scanf("%d",&t);
        string s="000000000000000000000000000000";
        int pos = 29;
        while(t){
            if(t%2==1) s[pos] = '1';
            pos--; t/=2;
        }
    }

    sort(a+1,a+n+1);

    find(1,n,0);

    int res = 1;
    for(int i=29;i>=0;i--){
        cout<<vis[i];
        if(!vis[i]) ans += res;
        res*=2;
    }

    cout<<ans<<endl;
    
    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/