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
bool vis[35];//0-29
bool avis[35];

void find(int ll,int rr,int pos){
    if(pos==30){
        for(int i=0;i<30;i++){
            if(avis[i]==1 && vis[i]==0) break;
            avis[i] = vis[i];
        } 
        return;
    } 

    int l=ll, r=rr;
    if(a[l][pos] == a[r][pos]) {
        vis[pos] = 1; find(l,r,pos+1); vis[pos] = 0;
    } else {
        while(l<r){
            int mid = (l+r)/2;
            if(a[mid][pos] == '0') l = mid+1;
            else r = mid;
        }
        //cout<<l<<r<<endl;
        find(ll,l-1,pos+1);
        find(r,rr,pos+1);
    }
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
        a[i] = s;
    }

    sort(a+1,a+n+1);

    find(1,n,0);

    int res = 1;
    for(int i=29;i>=0;i--){
        //cout<<avis[i];
        if(!avis[i]) ans += res;
        res*=2;
    } //cout<<endl;

    printf("%d\n",ans);
    
    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/