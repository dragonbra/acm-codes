#include<bits/stdc++.h>
//#define LOCAL
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> P;
istream& operator>>(istream& in,P& A){
	in>>A.first>>A.second;
	return in;
}
const double pi=acos(-1.0);
const int mod=1e9+7;
const int inf=0x7fffffff;
const int maxn=0x3f3f3f3f;
template <typename T>
inline T read(){
    T f=1,x=0;char ch;
    do{ch=getchar();if(ch=='-')f=-1;}while(ch<'0'||ch>'9');
    do{x=x*10+ch-'0';ch=getchar();}while(ch>='0'&&ch<='9');
    return f*x;
}
template <typename T>
inline void print(T a){
	if(a<0){a=-a;putchar('-');}
	if(a/10!=0)print(a/10);
	putchar(a%10+'0');
}
ll power2(ll a,ll b){
	ll res = 1;a%= mod;
    while (b){
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res%mod;
}
ll f[1000010];
int main()
{
	//ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	#ifdef LOCAL
        freopen("1.in","r",stdin);
        freopen("1.out","w",stdout);
    #endif
	f[0] = 1;
    for (int i=1; i<=1000005;i++) {
        f[i] = f[i-1] * i; f[i] %= mod;
    }
	int T;cin>>T;
	while(T--){
		int n=read<int>(),m=read<int>();
		ll ans=f[n];
        ans*=power2(m,mod-2); ans%=mod;
        print(ans);putchar('\n');
	}
}
