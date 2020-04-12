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
const int N = 1e3 + 5;

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

char p[N], h[N]; int pre[N][31], cmp[31];

int main() {
    redirect();
    
    int T; scanf("%d",&T);
    
    while(T--){
        scanf("%s",p);
        scanf("%s",h);

        memset(cmp,0,sizeof cmp);
        int plen = strlen(p);
        for(int i=0;i<plen;i++) cmp[p[i]-'a'+1]++;

        for(int i=1;i<=26;i++) pre[0][i]=0;

        int len = strlen(h);
        pre[0][h[0]-'a'+1] = 1;
        for(int i=1;i<len;i++){
            for(int j=1;j<=26;j++) pre[i][j] = pre[i-1][j];
            pre[i][h[i]-'a'+1]++;
        }

        bool flag=false;
        for(int i=0;i<len;i++){
            if( i+plen-1 >= len ) break;
            flag = true;
            for(int j=1;j<=26;j++){
                if(i==0){
                    if(pre[i+plen-1][j]!=cmp[j]){
                        flag = false; break; 
                    }
                } else {
                    //cout<<1<<endl;
                    if(pre[i+plen-1][j] - pre[i-1][j] != cmp[j]){
                        //cout<<2<<endl;
                        //cout<<pre[i+plen-1][j]<<' '<<pre[i-1][j]<<' '<<cmp[j]<<' '<<j<<endl;
                        flag = false; break;
                    } 
                }
            }
            if(flag) break;
        }

        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/