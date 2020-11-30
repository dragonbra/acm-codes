/*
* @ author: dragon_bra
* @ email: tommy514@foxmail.com
* @ data: 2020-11-28 21:38
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
const int N = 1e5 + 10;

void redirect() {
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
}

struct node {
    int idx;
    int val; // 差多少满足一个整除
    node(int idx, int val):idx(idx), val(val) {}
    friend bool operator < (node a, node b) {
        return a.val > b.val;
    }
};

struct op {
    int i, j, x;
    op(int i, int j, int x):i(i), j(j), x(x) {}
};

int T, n;
int a[N]; bool vis[N]; int cnt = 0;

int main() {
    redirect();

    scanf("%d",&T);
    while (T--) {
        scanf("%d", &n);

        for (int i=1; i<=n; i++) vis[i] = false; cnt = 1;

        int sum = 0;
        for (int i=1; i<=n; i++) {
            scanf("%d", &a[i]);
            sum += a[i];
        }

        if (sum % n != 0) {
            printf("-1\n"); continue;
        }

        int ave = sum / n;
        priority_queue<node> wl; // waitingList of undividable
        queue<op> ans;
        for (int i=2; i<=n; i++) {
            wl.push(node(i, a[i] % i == 0 ? 0 : i - a[i] % i));
        }

        bool flag = true;
        while (!wl.empty()) {
            node now = wl.top(); wl.pop();
            if (a[1] < now.val) {
                // cout << "H: " << a[1] << ' ' << now.idx << ' ' << now.val << endl;
                flag = false; break;
            }

            // cout << now.idx << ' ' << now.val << endl;

            ans.push(op(1, now.idx, now.val));
            // cout << 1 << ' ' << now.idx << ' ' << now.val << endl;
            a[1] -= now.val;
            a[now.idx] += now.val;


            ans.push(op(now.idx, 1, a[now.idx] / now.idx));
            // cout << now.idx << ' ' << 1 << ' ' << a[now.idx] / now.idx << endl;
            a[1] += a[now.idx];
            a[now.idx] = 0;
            // cout << 1 << ' ' << now.idx << ' ' << ave << endl;
        }

        if (flag) {
            for (int i=2; i<=n; i++) {
                if (!vis[i]) {
                    ans.push(op(1, i, ave - a[i]));
                    a[1] -= ave - a[i];
                    a[i] = ave;
                    vis[i] = true; cnt ++;
                }
            }
        }

        // cout << cnt << ' ' << n << endl;
        if (!flag || cnt != n) {
            puts("-1");
        } else {
            int k = ans.size();
            printf("%d\n", k);
            while (!ans.empty()) {
                op now = ans.front(); ans.pop();
                printf("%d %d %d\n", now.i, now.j, now.x);
            }
        }
    }

    return 0;
}