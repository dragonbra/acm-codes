#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
const int E = 1e5 + 10;
const int INF = 1e9+10;

int s, t;
int n, m;
int a[N][8]={0};

int c[N], sum=0;
int cnt = 1, first[N], nxt[E<<1], to[E<<1], val[E<<1];

inline void addE(int u, int v, int w) {
    to[++cnt] = v;
    val[cnt] = w;
    nxt[cnt] = first[u];
    first[u] = cnt;
}

int dep[N], q[N];

bool bfs() {//顺着残量网络，方法是 bfs；这是个bool型函数，返回是否搜到了汇点 
    memset(dep, 0, (n + 10) * sizeof(int));//记得开局先初始化 
    int l,r;

    q[l = r = 1] = s;

    dep[s] = 1;
    while(l <= r) {
        int u = q[l++];
        for(int p = first[u]; p; p = nxt[p]) {
            int v = to[p];
            if(val[p] and !dep[v]) {//按照有残量的边搜过去 
                dep[v] = dep[u] + 1;
                q[++r] = v;
            }
        }
    }
    return dep[t];//dep[t] != 0，就是搜到了汇点 
}

int dfs(int u, int in/*u收到的支持（不一定能真正用掉）*/) {
//注意，return 的是真正输出的流量
    if(u == t)
        return in;//到达汇点是第一个有效return 
    int out = 0;
    for(int p = first[u]; p and in; p = nxt[p]) {
        int v = to[p];
        if(val[p] and dep[v] == dep[u] + 1) {//仅允许流向下一层 
            int res = dfs(v, min(val[p], in)/*受一路上最小流量限制*/);
            //res是v真正输出到汇点的流量
            val[p] -= res;
            val[p ^ 1] += res;
            in -= res;
            out += res;
        }
    }
    if(out == 0)//我与终点（顺着残量网络）不连通 
        dep[u] = 0;//上一层的点请别再信任我，别试着给我流量
    return out;
}

int dinic() {
    int res = 0;
    while (bfs()) {
        res += dfs(s, 2e9);
    }
    return res;
}

bool check(int x) {
    if (x*m < sum) return false;

    memset(first, 0, (n + 10) * sizeof(int));
    cnt = 1; s = n+8, t = n+9;

    for (int i=1; i<=7; i++) { // 从s往星期一~星期天连边
        addE(s, n+i, ( x/7 + (x%7>=i)) * m );
        addE(n+i, s, 0);
    }

    for (int i=1; i<=n; i++) { // 从1-n个任务往t连边

        addE(i, t, c[i]);
        addE(t, i, 0);

        for (int j=1; j<=7; j++) {
            if (a[i][j]) { // 如果第j天可以执行第i个任务，那么第j天向第i个任务连边
                addE(n+j, i, INF);
                addE(i, n+j, 0);
            }
        }
    }

    int res = dinic();

    //cout << x << ' ' << ' ' << res << ' ' << sum << endl;
    if(res == sum) return true;
    return false;
}

int main() {

    #ifdef LOCAL
        freopen("1.in","r",stdin);
        freopen("1.out","w",stdout);
    #endif

    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        int cmp, t;

        cin >> c[i] >> cmp;
        sum += c[i];

        for (int j=1; j<=cmp; j++) {
            cin >> t; a[i][t]=1;
        }
    }

    int l = 0, r = 1e9/m, res;
    while (l<=r) {
        int mid = (l+r) >> 1;
        if (check(mid)) {
            r = mid-1; res = mid; 
        } else {
            l = mid+1;
        }
    }

    //for (int i=1;i<=50;i++) check(i);

    cout << res << endl;

    return 0;
}