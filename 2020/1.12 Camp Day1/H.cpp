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

inline __int128 read() {
    __int128 f=1,x=0;char ch;
    do {ch=getchar(); if(ch=='-') f=-1;} while (ch<'0'||ch>'9');
    do {x=x*10+ch-'0'; ch=getchar(); } while (ch>='0'&&ch<='9');
    return x*f;
}

void myitoa(__int128_t v, char* s)
{
    char temp;
    int i=0, j;
 
    while(v >0) {
        s[i++] = v % 10 + '0';
        v /= 10;
    }
    s[i] = '\0';
 
    j=0;
    i--;
    while(j < i) {
        temp = s[j];
        s[j] = s[i];
        s[i] = temp;
        j++;
        i--;
    }
}

ll gcd(ll a,ll b){
    if(a>b) swap(a,b);
    if(a==0) return b;
    else return gcd(b%a,a);
}

ll prime[510]; int cnt;

int main() {
    redirect();

    __int128_t ans = 1;

    for(int i=2;i<=500;i++){
        bool flag = true;
        for(int j=2;j*j<=i;j++){
            if(i%j==0){
                flag = false; break;
            }
        }
        if(flag){
            prime[++cnt] = i;
        }
    }

    int T; scanf("%d",&T);
    while(T--){
        int n,k; scanf("%d%d",&n,&k);

        ll ans = 1; ans *= k; n /= k;
        for(int i=1;i<=cnt;i++){
            if(prime[i]>n) break;
            ans = ans * prime[i];
        }
        char s[51];
        myitoa(ans,s);
        cout<<s<<endl;
    }

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/