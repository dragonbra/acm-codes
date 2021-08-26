/*
*  https://acm.hdu.edu.cn/contests/contest_showproblem.php?pid=1003&cid=992
*  Prim算法，复杂度O(N^2 + M)
*  @ author: dragon_bra
*  @ created at: 2021-08-12 12:03:39
*/

#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>

using namespace std;

typedef long long LL;

const int N = 5e3 + 10;

int n;
vector<pair<int, LL> > G[N];
int f[N]; LL x[N], y[N], dis[N]; bool vis[N];

LL prim() {
    int tot = 0;
	//先把dis数组附为极大值
	for(int i=2;i<=n;++i) {
		dis[i]=__LONG_LONG_MAX__;
	}
    //这里要注意重边，所以要用到min
    for (pair<int, LL> p : G[1]) {
        dis[p.first] = min(dis[p.first], p.second);
    }

    int now = 1; LL res = 0;
    while(++tot<n)//最小生成树边数等于点数-1
    {
        LL minn=__LONG_LONG_MAX__;//把minn置为极大值
        vis[now]=1;//标记点已经走过

        //枚举每一个没有使用的点
        //找出最小值作为新边
        //注意这里不是枚举now点的所有连边，而是1~n
        for(int i=1;i<=n;++i)
        {
            if(!vis[i]&&minn>dis[i])
            {
                minn=dis[i];
				now=i;
            }
        }

        res = max(res, minn);

        //枚举now的所有连边，更新dis数组
        for (pair<int, LL> p : G[now]) {
            if (!vis[p.first]) {
                dis[p.first] = min(dis[p.first], p.second);
            }
        }
    }
    return res;
}

int main() {
    
    ios::sync_with_stdio(false); cin.tie(0);
    int T, kase = 0; cin >> T;
    while (T -- ) {
        ++ kase;
        cin >> n;
        for (int i = 1; i <= n; i ++ ) {
            cin >> x[i] >> y[i];
            f[i] = i;
            vis[i] = false;
            G[i].clear();
        }

        for (int i = 1; i <= n; i ++ ) {
            for (int j = i + 1; j <= n; j ++ ) {
                LL res = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
                G[i].push_back({j, res});
                G[j].push_back({i, res});
            }
        }

        LL ans = prim();
        cout << ans << endl;
    }
    
    return 0;
}