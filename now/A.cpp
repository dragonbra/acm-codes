/*
* @ author: dragon_bra
* @ email: tommy514@foxmail.com
* @ data: 2020-11-22 18:29
*/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <vector>

using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
const double eps = 1e-5;
const int N = 1e5 + 5;

void redirect() {
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
}

inline int read() {
    int f=1,x=0;char ch;
    do {ch=getchar(); if(ch=='-') f=-1;} while (ch<'0'||ch>'9');
    do {x=x*10+ch-'0'; ch=getchar(); } while (ch>='0'&&ch<='9');
    return x*f;
}

int n, m;
int vis[1030]; // 1024 - cnt
bool in[N][12]; int val[N];
int a[N][12];
vector<int> checkList[1030];

struct node {
    int val;
    int i, j;
} que[N*10];
int cnt = 0;

bool cmp (node a, node b) {
    return a.val > b.val;
}

int cal(int x) {
    int res = 0; int cnt = 0;
    for (int i=1; i<=m; i++) {
        res *= 2;
        res += in[x][i];
        cnt += in[x][i];
    }
    val[x] = res;
    return cnt;
}

int update(int x) {
    vis[val[x]] --;
    int cnt = cal(x);
    vis[val[x]] ++;
    return cnt;
}

bool check(int x) {
    // cout << x << ": ";
    for (int v: checkList[x]) {
        // cout << v << ' ';
        if (vis[v]) {
            return true;
        }
    }
    // cout << endl;
    return false;
}

void init() {
    int cmp = pow(2, m) - 1;
    for (int i=0; i<=cmp; i++) {
        for (int j=0; j<=cmp; j++) {
            if ((i|j) == cmp) {
                checkList[i].push_back(j);
            }
        }
    }
}

int main() {
    redirect();

    scanf("%d %d", &n, &m);
    init();
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            scanf("%d", &a[i][j]);
            que[++cnt].val = a[i][j];
            que[cnt].i = i, que[cnt].j = j;
        }
    }

    sort(que+1, que+cnt+1, cmp);

    int ans;
    for (int i=1; i<=cnt; i++) {
        in[que[i].i][que[i].j] = true;
        int num = update(que[i].i);
        if (num == m) {
            ans = que[i].val; break;
        } else if (num >= m/2) {
            if (check(val[que[i].i])) {
                ans = que[i].val; break;
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}