#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const double eps = 1e-5;
const int mod = 1e9+7;
const int N = 1e4 + 10;

void redirect() {
    freopen("exercise.in","r",stdin);
    freopen("exercise.out","w",stdout);
}

ll prime[N]; bool flag[N];
ll n,m=mod; int cnt;
map<ll,bool> mp;
ll ans = 0;

void init(){
    cnt = 0;
	
    for(int i=1; i<=n; i++){
        flag[i]=1;
    }
    for(int i=2; i<=n; i++){
        if(flag[i]==1){
            prime[++cnt]=i;
        }
        for(int j=1; j<=cnt && prime[j]*i<=n; j++){
            flag[prime[j]*i]=0;
            if(i%prime[j]==0)
                break;
        }
    }

    //for(int i=1;i<=cnt;i++) cout<<prime[i]<<' '; cout<<endl;

    for(int i=1;i<=n;i++){
        ans += i; ans %= m;
        mp[i] = true;
    }
}

int log(int x,int p){
    int res = 1;int cmp = x;
    while(cmp<=p){
        cmp*=x; res++;
    }
    //cout<<"log:"<<x<<' '<<p<<' '<<res-1<<endl;
    return res-1;
}

ll qp(ll x,ll p) {
    if(p==0) return 0;
    ll res = 1;
    while(p){
        if(p&1) res*=x,res%=m;
        x*=x; x%=m; p>>=1;
    }
    return res;
}

void dfs(int pos,int lft,ll val){
    //cout<<pos<<' '<<lft<<' '<<val<<endl;
    if( prime[pos] > lft || pos > cnt ) {
        if(!mp[val]){
            mp[val] = true;
            ans += val;
            ans %= m;
            //cout<<"------val:"<<val<<' '<<"sum:"<<ans<<endl;
        }
        return;
    }

    ll cmp = log(prime[pos],lft); ll t = 1;
    for(ll j = 0; j <= cmp; j++,t*=prime[pos],t%=m ){
        if(t==1) t = 0;

        //cout<<"j:"<<j<<" t:"<<t<<" cmp:"<<cmp<<endl;

        dfs( pos+1, lft-t, ( val * max(1ll,t) ) % m );
    }
}

int main() {
    //redirect();
    #ifdef LOCAL
        freopen("1.in","r",stdin);
        freopen("1.out","w",stdout);
    #endif

    scanf("%lld%lld",&n,&m);
    init();

    dfs(1,n,1);
    cout<<ans<<endl;

    return 0;
}
