#include <cstdio>
#include <iostream>
#include <utility>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <algorithm> 
#include <set>
#define mst(s,t) memset(s,t,sizeof(s)) 
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-6;
const double pi = acos(-1);
const int Max = 50010;
const int maxn = 1e5 + 10;
const int maxh = 4e6 + 10;
const double delta = 0.98;
ll qpow(ll a,ll b,ll c){ll ans=1;a=a%c;while(b>0){if(b&1)ans=(ans*a)%c;b=b>>1;a=(a*a)%c;}return ans;}
ll qmul(ll a,ll b,ll c){a=a%c;ll ans=0;while(b){if(b&1) ans=(ans+a)%c;b>>=1;a=(a+a)%c;}return ans;}
void redirect(){
    //ios::sync_with_stdio(false);
     #ifdef LOCAL
        freopen("test.txt","r",stdin);
     #endif
}

int sgn(double x) {
	if(fabs(x) < eps) return 0;
	else if(x > 0) return 1;
	else return -1;
}

int n;
double d;
struct line{
	double l,r;
	line(double s,double e):l(s),r(e) { }
};
vector<line> v;
bool cmp(const line &a,const line &b) {
	return a.l < b.l;
}

int main() {
    redirect();
    int ca = 0;
    while(scanf("%d%lf",&n,&d)) {
        bool f = true;
    	if(n == 0 && sgn(d-0) == 0) break;
    	ca++;
    	printf("Case %d: ",ca);
    	v.clear();
    	for(int i=0;i<n;i++) {
	    	double x,y;
	    	scanf("%lf%lf",&x,&y);
	    	if(sgn(y-d) > 0) {
	    		f = false;
	    		continue;
			}
			double lt = x - sqrt(d*d-y*y);
			double rt = x + sqrt(d*d-y*y);
			v.push_back(line(lt,rt));
		}
		if(!f) puts("-1");
		else {
			sort(v.begin(),v.end(),cmp);
			int cnt = 0;
			double sta = -INF,ed = -INF;
			for(int i=0;i<v.size();i++) {
				if(sgn(v[i].l - ed) > 0) {
					cnt++;
					sta = v[i].l;
					ed = v[i].r;
				}else {
					sta = v[i].l;
					ed = min(ed,v[i].r);
				}
			}
			printf("%d\n",cnt);
		}
	}
    return 0;
}
