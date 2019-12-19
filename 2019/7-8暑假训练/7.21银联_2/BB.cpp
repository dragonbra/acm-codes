#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 19940417
ll n,m;
ll s(ll l,ll r){
    if(l+r&1){
        return (l+r)*(r-l+1>>1)%MOD;
    }else{
        return (l+r>>1)*(r-l+1)%MOD;
    }
}
ll S2(ll n){
    ll t1=n,t2=n+1,t3=n*2+1;
    if(t1%2==0){
        t1/=2;
    }else if(t2%2==0){
        t2/=2;
    }else{
        t3/=2;
    }
    if(t1%3==0){
        t1/=3;
    }else if(t2%3==0){
        t2/=3;
    }else{
        t3/=3;
    }
    return t1*t2%MOD*t3%MOD;
}
ll s2(ll l,ll r){
    return (S2(r)-S2(l-1)+MOD)%MOD;
}
ll cal(ll n){
    int i;
    ll re=n*n%MOD;
    for(i=1;i<=n;i++){
        int t=n/(n/i);
        (re+=MOD-(n/i)*s(i,t)%MOD)%=MOD;
        i=t;
    }
    return re;
}
int main(){
    int i;
    scanf("%lld%lld",&n,&m);
    if(n>m){
        swap(n,m);
    }
    ll ans=cal(n)*cal(m)%MOD;
    (ans+=MOD-n*n%MOD*m%MOD)%=MOD;
    for(i=1;i<=n;i++){
        int t=min(m/(m/i),n);
        (ans+=n*(m/i)%MOD*s(i,t)%MOD)%=MOD;
        i=t;
    }
    for(i=1;i<=n;i++){
        int t=n/(n/i);
        (ans+=m*(n/i)%MOD*s(i,t)%MOD)%=MOD;
        i=t;
    }
    for(i=1;i<=n;i++){
        int t=min(m/(m/i),n/(n/i));
        (ans+=MOD-(n/i)*(m/i)%MOD*s2(i,t)%MOD)%=MOD;
        i=t;
    }
    printf("%lld\n",ans);
    return 0;
}
