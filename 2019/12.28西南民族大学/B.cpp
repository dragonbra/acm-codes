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

int n; char s[N]; int cnt[53]; bool vis[53];//a-z 1-26 A-Z 27-52

int cal(int i){
        if(s[i]>='a'&&s[i]<='z') return s[i]-'a'+1;
        if(s[i]>='A'&&s[i]<='Z') return s[i]-'A'+27;
}

int main() {
    redirect();
    cin>>n;
    cin>>s;

    for(int i=0;i<n;i++){
        if(s[i]>='a'&&s[i]<='z') vis[s[i]-'a'+1] = true;
        if(s[i]>='A'&&s[i]<='Z') vis[s[i]-'A'+27] = true;
    }

    int ans = n; int l = 0; int r = 0;
    for(int i=0;i<n;i++ ) {
        if(s[i]>='a'&&s[i]<='z') cnt[s[i]-'a'+1]++;
        if(s[i]>='A'&&s[i]<='Z') cnt[s[i]-'A'+27]++;

        bool flag = true;
        for(int j=1;j<=52;j++){
            if(vis[j]&&cnt[j]==0){
                flag = 0;
                break;
            }
        }

        if(flag){
            r = i; ans = min(ans,r-l+1); break;
        }
    }
    
    for(;r<n;){
        while( l<r && cnt[cal(l)] >= 2 ){
            cnt[cal(l)]--; l++;
        }
        ans = min(ans,r-l+1);
        r++;
        cnt[cal(r)]++;
    }

    cout<<ans<<endl;

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/