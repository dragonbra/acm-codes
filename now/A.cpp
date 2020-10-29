<<<<<<< Updated upstream
=======
/*
* @ author: dragon_bra
* @ email: tommy514@foxmail.com
* @ data: 2020-10-28 20:33
*/

>>>>>>> Stashed changes
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
#include <stack>
#include <vector>

using namespace std;

const int N = 2e5 + 10;

<<<<<<< Updated upstream
int main() {

    cout << "Hello world" << endl;
=======
void redirect() {
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
}

int n;
bool vis[N];
bool out[N];
int mi;
int a[N];
int Q[N];
struct node {
    int val, s;
    node (int val, int s):s(s), val(val){}
};
stack<node> S;
priority_queue<int,vector<int>,greater<int> > PQ;
int cnt = 0, in = 0;

char s[N][10]; int b[N];

int main() {
    redirect();

    scanf("%d", &n);
    bool flag = true;
    mi = n+1;
    for (int i=1; i<=2*n; i++) {
        scanf("%s", s[i]);
        if (s[i][0] == '+') {
            while(vis[mi-1]) mi--;
            mi --; vis[mi] = true;
            Q[++in] = mi;
            S.push(node(mi, in));
        } else {
            scanf("%d", &b[i]); int x = b[i];
            if (S.empty() || S.top().val < x) {
                flag = false; break;
            }
            node now = S.top(); S.pop();
            vis[now.val] = false; vis[x] = true;
            Q[now.s] = x;
            if (S.empty()) mi = n+1;
            else mi = S.top().val;
        }
    }

    in = 0;
    for (int i=1; i<=2*n; i++) {
        if (s[i][0] == '+') {
            PQ.push(Q[++in]);
        } else {
            if (PQ.empty() || PQ.top() != b[i]) {
                flag = false; break;
            }
            PQ.pop();
        }
    }

    if (flag) {
        puts("YES");
        for (int i=1; i<=n; i++) printf("%d ", Q[i]);
    } else {
        puts("NO");
    }
>>>>>>> Stashed changes

    return 0;
}