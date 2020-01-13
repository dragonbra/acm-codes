#include<bits/stdc++.h>
//#define LOCAL
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
istream& operator>>(istream& in,P& A){
	in>>A.first>>A.second;
	return in;
}
const double pi=acos(-1.0);
const ll mod=ll(1e9+7);
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

#define LOCAL
void redirect() {
    #ifdef LOCAL
        freopen("1.in","r",stdin);
        freopen("1.out","w",stdout);
    #endif
}

ll a[100010]; ll cnt[110]; 

void cal(ll x){
    int res = 0;
    while(x){
        res++;
        if(x&1) cnt[res]++; 
        x/=2;
    }
}

int main(){
    redirect();

	int n;cin>>n;
	ll sum=0;
	for(int i=0;i<n;i++){
		a[i]=read<ll>(); cal(a[i]);
        //cout<<cal(a[i])<<endl;
		sum^=a[i]; 
        
        int dsum = 0;
        ll t = sum;
        while(t){
            dsum++; t/=2;
        }
        
        //cout<<sum<<' '<<dsum<<' ';
        
        ll ans = 0; ans = cnt[dsum];
        
        if(sum==0) puts("0");
        else printf("%lld\n",ans);
	}
}
//author:caramel_pudding
