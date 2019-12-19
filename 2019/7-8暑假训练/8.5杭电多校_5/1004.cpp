#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+10;

int T,n,c;
int gcd(int a,int b) {if(a<b)swap(a,b);return b?gcd(b,a%b):a;}

struct node{
	int a,b;// =b/a;
	node operator + (const node t) const{
		int na=a*t.b+b*t.a,nb=b*t.b;
		node res;int g=gcd(abs(na),abs(nb));
		res.a=na/g;res.b=nb/g;
		if(res.a<0){
			res.a=-res.a;
			res.b=-res.b;
		}
		return res;
	}
	node operator - (const node t) const{
		int na=a*t.b-b*t.a,nb=b*t.b;
		node res;int g=gcd(abs(na),abs(nb));
		res.a=na/g;res.b=nb/g;
		if(res.a<0){
			res.a=-res.a;
			res.b=-res.b;
		}
		return res;
	}
	void print(){
		if(a<0){
			a=-a;
			b=-b;
		}
		if(a==0&&b==0){
			printf("0/1\n");
		}
		else printf("%d/%d\n",b,a);
	}
} equa[N];int prea[N],preb[N];
bool cmp(node a,node b){
	double ans1=-1.0*a.b/a.a,ans2=-1.0*b.b/b.a;
	return ans1<ans2;
}

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&c);
		for(int i=1;i<=n;i++) scanf("%d%d",&equa[i].a,&equa[i].b);
		sort(equa+1,equa+n+1,cmp);
		prea[0]=preb[0]=0;
		for(int i=1;i<=n;i++){
			prea[i]=prea[i-1]+equa[i].a;
			preb[i]=preb[i-1]-equa[i].b;
		}
		
		int cnt=0;node ans[11];
		//left-right
		if(preb[n]-prea[n]*equa[1].a<=c){
			node t;t.b=c-(preb[n]-prea[n]*equa[1].a);t.a=prea[n];
			
			node tt;tt.a=1,tt.b=0;
			ans[++cnt]=tt-equa[1]-t;
			ans[cnt].print();
		}//left
		if(prea[n]*equa[n].a-preb[n]<=c){
			node t;t.b=c-(prea[n]*equa[n].a-preb[n]);t.a=prea[n];
			ans[++cnt]=t-equa[n];
			ans[cnt].print();
		}
	}
	return 0;
}
