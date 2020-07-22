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
string a,b;
vector<int>ans;

int main()
{
	//ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	#ifdef LOCAL
	freopen("1.txt","r",stdin);
	#endif
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		cin>>a>>b;
		ans.clear();
		int base=0,l=0,r=n-1,charge=0;
		for(int i=n-1;i>=0;i--){
			if(charge%2==0){
				if(base&1){
					char tmp=a[r]=='1'?'0':'1';
					if(tmp==b[i]){
						r--;
						continue;
					}
					char tmp2=a[l]=='1'?'0':'1';
//					cout<<tmp<<" "<<tmp2<<endl;
					if(tmp==tmp2){
						ans.push_back(i+1);
						base++;charge++;l++;
					}else{
						ans.push_back(1);
						ans.push_back(i+1);
						base++;charge++;l++;
					}
				}else{
					char tmp=a[r]=='1'?'1':'0';
					if(tmp==b[i]){
						r--;
						continue;
					}
					char tmp2=a[l]=='1'?'1':'0';
//						cout<<tmp<<" "<<tmp2<<endl;
					if(tmp==tmp2){
						ans.push_back(i+1);
						base++;charge++;l++;
					}else{
						ans.push_back(1);
						ans.push_back(i+1);
						base++;charge++;l++;
					}
				}
			}else{
				if(base&1){
					char tmp=a[l]=='1'?'0':'1';
					if(tmp==b[i]){
						l++;
						continue;
					}
					char tmp2=a[r]=='1'?'0':'1';
//						cout<<tmp<<" "<<tmp2<<endl;
					if(tmp==tmp2){
						ans.push_back(i+1);
						base++;charge++;r--;
					}else{
						ans.push_back(1);
						ans.push_back(i+1);
						base++;charge++;r--;
					}
				}else{
					char tmp=a[l]=='1'?'1':'0';
					if(tmp==b[i]){
						l++;
						continue;
					}
					char tmp2=a[r]=='1'?'1':'0';
//						cout<<tmp<<" "<<tmp2<<endl;
					if(tmp==tmp2){
						ans.push_back(i+1);
						base++;charge++;r--;
					}else{
						ans.push_back(1);
						ans.push_back(i+1);
						base++;charge++;r--;
					}
				}
			}
		}
		cout<<ans.size()<<' ';
		for(auto i:ans)cout<<i<<' ';
		cout<<endl;
	}
}
//author:caramel_pudding