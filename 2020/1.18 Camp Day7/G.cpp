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
const ll mod=ll(998244353);
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

void redirect() {
    #ifdef LOCAL
        freopen("1.in","r",stdin);
        freopen("1.out","w",stdout);
    #endif
}

int main()
{
    redirect();
	//ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	#ifdef LOCAL
	freopen("1.txt","r",stdin);
	#endif
	int T;
	T=read<int>();
	while(T--){
		__int128 n,m,x,y,k;
		n=read<__int128>();m=read<__int128>();x=read<__int128>();y=read<__int128>();k=read<__int128>();
//		print(n&1);print(m&1); 
		if(!(n&1)||!(m&1)){
//			print(n);
			__int128 tot=n*m;
			__int128 ans=0;ll sum=0;
			if(k>tot){
				k-=tot;
				tot%=mod;
				ans+=(1+tot)*tot/2;
				ans+=k*tot%mod;
			}
			else
				ans+=(1+k)*k/2;
			
			print(ans%mod);putchar('\n');
		}
	}
}
//author:caramel_pudding
