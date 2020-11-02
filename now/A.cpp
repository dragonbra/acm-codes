#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 2e5 + 10;
const ll mod = 1e9 + 7;
const ll INF = 1e15;
const double eps = 1e-8;

ll n;
char s[N];
ll cnt=0,sum=0,pos=0;
ll a[N],b[N];
ll ch[30][N],c[N],p[N];
ll f[N*4];
map<char,ll>mp;
ll lowbit(ll x){
    return x&-x;
}
void add(ll x,ll k){
    for(ll i=x;i<=cnt;i+=lowbit(i))f[i]+=k;
}

ll find(ll x){
    ll ans=0;
    for(ll i=x;i>0;i-=lowbit(i))ans+=f[i];
    return ans;
}

int main(){
    int T;
    T=1;
    while(T--){
        memset(f,0,sizeof(f));
        scanf("%lld",&n);
        scanf("%s",&s);
        ll l=0,r=n-1;
        a[++cnt]=++sum;
        ch[s[0]-'a'][++c[s[0]-'a']]=sum;
        for(ll i=l+1;i<=r;i++){
            if(s[i]==s[i-1]){
                a[cnt+1]=a[cnt];
                ch[s[i]-'a'][++c[s[i]-'a']]=a[cnt];
                cnt++;
            }else{
                a[++cnt]=++sum;
                ch[s[i]-'a'][++c[s[i]-'a']]=sum;
            }
        }   
      //  for(int i=1;i<=cnt;i++)printf("%d ",a[i]);puts("");
        ll ans=0,sum=0;
        for(int i=1;i<=cnt;i++)b[i]=a[cnt-i+1];
        reverse(s,s+n);
        for(int i=1;i<=cnt;i++)
            b[i]=ch[s[i-1]-'a'][++p[s[i-1]-'a']];
        //for(int i=1;i<=cnt;i++)printf("%d ",b[i]);puts("");
        for(ll i=1;i<=cnt;i++){
            ll x=b[i];
            add(x,1);
            ans+=i-find(x);
        }
        printf("%lld\n",ans);
        // memset(f,0,sizeof(f));
        // for(ll i=1;i<=cnt;i++){
        //     ll x=a[i];
        //     add(x,1);
        //     sum+=i-find(x);
        // }
        // printf("%lld\n",abs(ans-sum));


    }
    return 0;
}