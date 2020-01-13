#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
const long double eps = 1e-6;
const int N = 1e6 + 5;

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

ll n;
char s[N]; ll nn;
ll acc[N]; ll pre[N]; ll cnt[N];
ll sum; long double ans=0;

int main() {
    redirect();
    
    scanf("%s",s+1); s[0]='0';
    n = strlen(s) -1;

    sum = n*(n+1)/2;

    for(ll i=1;i<=n;i++){
        ll pos = min(i,n-i+1);
        if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='y')
            nn++, cnt[pos]++, pre[pos]+=pos;
    }

    for(int i=1;i<=n;i++) pre[i] += pre[i-1], cnt[i] += cnt[i-1];

    long double cmp = 0;

    for(ll i=1;i<=n;i++){
        ll pos = min(i,n-i+1);
        acc[i] += pre[pos] + (nn-cnt[pos])*pos; 
        //cout<<i<<' '<<pos<<' '<<pre[pos]<<' '<<cnt[pos]<<' '<<acc[i]<<endl;

        cmp += 1.0/(long double)i/(long double)sum * acc[i]; //cout<<cmp<<endl;
    }

    ans = cmp;

    if(abs(ans-0)<=eps) ans = 0;
    cout << fixed << setprecision(9) << ans << endl;

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/