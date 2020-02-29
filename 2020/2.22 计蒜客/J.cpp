#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
const double eps = 1e-5;
const int N = 1e3 + 10;

void redirect() {
    #ifdef LOCAL
        freopen("1.in","r",stdin);
        freopen("1.out","w",stdout);
    #endif
}

struct node {
	int x,y;
} p[N];;
int n; int ans;
unordered_map<int,unordered_map<int,bool> > mp, vis;

bool check(int x,int y) {
	int nx,ny;
	for(int i=1;i<=n;i++) {
		bool f1 = false, f2 = false;
		if(mp[p[i].x + x][p[i].y + y]) f1 = true;
		if(mp[p[i].x - x][p[i].y - y]) f2 = true;
		if(!f1 && !f2) return false;
	}
	return true;
}

int main() {
    redirect();

    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&p[i].x,&p[i].y);
        mp[p[i].x][p[i].y] = true;
    }

    for(int i=2;i<=n;i++) {
    	int x = p[1].x - p[i].x;
    	int y = p[1].y - p[i].y;
    	if(!vis[x][y]) {
    		if(check(x,y)) ans++;
			vis[x][y] = true;	
		}
    	if(!vis[-x][-y]) {
    		if(check(-x,-y)) ans++;
    		vis[-x][-y] = true;
		}
	}

	printf("%d\n",ans);

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/