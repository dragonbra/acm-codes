#include "stdio.h"
#include "string.h"
#include "string"
#include "iostream"
#include "algorithm"
#include "vector"
#include "queue"
#include "math.h"
#include "map"
#include "stack"
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
const ll mod=998244353;
const int inf=0x3f3f3f3f;
const ll INF=1e12;
const double eps=1e-6;
ll f[maxn];
ll fast(ll a,ll n){
    if(n==0)return 1;
    if(n%2)return a*fast(a,n-1)%mod;
    ll tmp=fast(a,n/2);
    return tmp*tmp%mod;
}
ll C(ll n,ll m){
    if(n==m || m==0)return 1;
    return ((f[n]*(fast(f[m],mod-2)%mod)%mod)*(fast(f[n-m],mod-2)%mod))%mod;
}
void redirect() {
    #ifdef LOCAL
        freopen("1.in","r",stdin);
        freopen("1.out","w",stdout);
    #endif
}
int main(){
    redirect();
    f[0]=1;
    for(ll i=1;i<=maxn-10;i++)
        f[i]=f[i-1]*i%mod;
    ll n,m;
    scanf("%lld%lld",&n,&m);
    ll ans=0;
    for(ll pos=2;pos<n;pos++)
        for(ll t=n-1;t<=m;t++){
            ll tt=C(t-1,n-2);
            tt=tt*C(n-2,pos-1)%mod;
            tt=tt*(pos-1)%mod;
            ans=(ans+tt)%mod;
        }
    printf("%lld\n",ans);
    return 0;
}
