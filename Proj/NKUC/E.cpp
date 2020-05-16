#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
const double eps = 1e-5;
const int N = 2e5 + 10;

void redirect() {
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
}

vector<int> v[N];
int n,m,a,b,c;
ll f[N];
int s[N],dis1[N],dis2[N],dis3[N];

void bfs(int s,int dis[]) {
	dis[s]=0;
    queue<int>Q;
	Q.push(s);
	while(!Q.empty()) {
		int u = Q.front(); Q.pop();
		for(int i=0; i<v[u].size(); i++) {
			if(dis[v[u][i]] == INF) {
				dis[v[u][i]] = dis[u]+1;
				Q.push(v[u][i]);
			}
		}
	}
}

int main() {
    redirect();

	int T;cin>>T;
	while(T--) {
        for(int i=1;i<=n;i++) v[i].clear();

		scanf("%d%d%d%d%d", &n, &m, &a, &b, &c);

		for(int i=1;i<=m;i++) scanf("%d",&s[i]);

		for(int i=1;i<=m;i++) {
			int x,y;
            scanf("%d%d",&x,&y);
			v[x].push_back(y); v[y].push_back(x);
		}

		sort(s+1,s+1+m);
        for(int i=1;i<=m;i++) f[i] = f[i-1] + s[i];
		for(int i=1;i<=n;i++) dis1[i]=INF, dis2[i]=INF, dis3[i]=INF;

		bfs(a,dis1);bfs(b,dis2);bfs(c,dis3);
		//for(int i=1;i<=n;i++) cout<<dis1[i]<<endl;
		ll ans = 1e18;
		for(int x=1;x<=n;x++) {
			if (dis1[x] + dis2[x] + dis3[x] <= m)
			    ans = min( f[ dis1[x] + dis2[x] + dis3[x] ] + f[dis2[x]], ans);
        }
        cout<<ans<<endl;
	}
	return 0;
} 