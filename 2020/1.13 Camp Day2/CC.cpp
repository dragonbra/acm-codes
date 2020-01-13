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
ll a[100010];
multiset<ll>mst;
int main()
{
	//ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);

	int n;cin>>n;
	ll ans=0;//cout<<0<<endl;
	for(int i=0;i<n;i++){
		a[i]=read<ll>();
		ans^=a[i]; cout<<ans<<' ';
		if(ans==0)puts("0");
		else {
			ll tot=0;
			for(int j=0;j<=i;j++){
				if(a[j]>(ans^a[j]))tot++;
			}
			print(tot);putchar('\n');
		}
	}
}
//author:caramel_pudding
