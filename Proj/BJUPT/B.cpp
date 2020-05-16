#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e17;
const int mod = 1e9+7;
const double eps = 1e-5;
const int N = 5e4 + 10;

struct node {
    int v; ll w;
    node(){}
    node(int v,int w):v(v),w(w){}
    bool operator < (const node & a) const {
		if(w==a.w) return v<a.v;
		else return w>a.w;
	}
};

vector <node> G[N];
int n,m,t;
int s,e;

ll dis_s[N], dis_e[N];

int main() {

    scanf("%d%d%d",&n,&m,&t);
    scanf("%d%d",&s,&e);

    for (int i=1; i<=m; i++) {
        int u,v; ll w;
        scanf("%d%d%lld",&u,&v,&w);
        G[u].push_back(node(v,w));
        G[v].push_back(node(u,w));
    }

    for (int i=1; i<=n; i++) dis_s[i] = dis_e[i] = INF;
    dis_s[s] = 0; dis_e[e] = 0;

    priority_queue<node> Q; 
    Q.push(node(s,0));
    while (!Q.empty()) {
        node u = Q.top(); Q.pop();
        //cout << u.v << ' ' << u.w << endl;
        for (int i=0; i<G[u.v].size(); i++) {
            node v = G[u.v][i];
            if (u.w + v.w < dis_s[v.v]) {
                dis_s[v.v] = u.w + v.w;
                Q.push(node(v.v, dis_s[v.v]));
            }
        }
    }

    Q.push(node(e,0));
    while (!Q.empty()) {
        node u = Q.top(); Q.pop();
        for (int i=0; i<G[u.v].size(); i++) {
            node v = G[u.v][i];
            if (u.w + v.w < dis_e[v.v]) {
                dis_e[v.v] = u.w + v.w;
                Q.push(node(v.v, dis_e[v.v]));
            }
        }
    }

    ll ans = INF;
    for (int i=1; i<=n; i++) {
        ll cmp1 = dis_s[i] + t*(i^e);
        ll cmp2 = dis_e[i] + t*(i^s);
        ans = min(ans, min(cmp1, cmp2) );
    }

    if (ans == INF) cout << "Imp0ssible" << endl;
    else cout << ans << endl;

    return 0;
}