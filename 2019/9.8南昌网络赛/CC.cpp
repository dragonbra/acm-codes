#include <vector>
#include<cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <deque>
#include <set>
#ifdef __GXX_EXPERIMENTAL_CXX0X__
#include <unordered_map>
#include <cassert>
#endif
#include <ctime>
#include <queue>
#include <stack>
#include<iomanip>
#include <sstream>
#include <cmath>
using namespace std;
typedef pair<int, int> PII;
typedef pair<string, string> PSS;
typedef pair<int, PII> PIP;
typedef long long ll;

const int N = 200100;
const int S = 5;
const int inf = 0x3f3f3f3f;

struct Info {
    int state[S][S];
    Info() {
        memset(state, 0x3f, sizeof(state));
    }
    void show() {
        for(int i = 0; i < S; i++) {
            for(int j = 0; j < S; j++) {
                printf("%13d", state[i][j]);
            }
            puts("");
        }
    }
    void updateLeaf(char c) {
        if (c == '2') state[0][0] = 1, state[0][1] = 0; else state[0][0] = 0;
        if (c == '0') state[1][1] = 1, state[1][2] = 0; else state[1][1] = 0;
        if (c == '1') state[2][2] = 1, state[2][3] = 0; else state[2][2] = 0;
        if (c == '9') state[3][3] = 1, state[3][4] = 0; else state[3][3] = 0;
        if (c == '8') state[3][3] = 1, state[4][4] = 1; else state[4][4] = 0;
    }
};

int n, q;
char s[N];char ss[N];

struct TreeNode {
    TreeNode(): lson(NULL), rson(NULL) {}
    TreeNode *lson, *rson;
    Info info;
}seg[N << 2];
int nextSeg;

Info operator+(const Info& info1, const Info& info2) {
    Info info;
    for(int i = 0; i < S; i++) {
        for(int j = 0; j < S; j++) {
            for(int k = 0; k < S; k++) {
                info.state[i][j] = min(info.state[i][j], info1.state[i][k] + info2.state[k][j]);
            }
        }
    }
    return info;
}


TreeNode* build(int l, int r) {
    TreeNode* node = &seg[nextSeg++];
    if (l == r) {
        node->info.updateLeaf(s[l]);
        return node;
    }
    int m = (l + r) / 2;
    node->lson = build(l, m);
    node->rson = build(m + 1, r);
    node->info = node->lson->info + node->rson->info;
    return node;
}

Info query(int L, int R, TreeNode* root, int l, int r) {
    if (l <=L && R <= r) {
        return root->info;
    }
    int m = (L + R) / 2;
    if (r <= m) return query(L, m, root->lson, l, r);
    if (m + 1 <= l) return query(m + 1, R, root->rson, l, r);
    return query(L, m, root->lson, l, r) + query(m + 1, R, root->rson, l, r);
}

void solve(int ncase) {
    scanf("%d%d%s", &n, &q, ss + 1);
    for(int i=n;i>=1;i--) s[i]=ss[i];
    TreeNode* root = build(1, n);
    while(q--) {
        int l, r;
        scanf("%d%d", &l, &r);
        Info info = query(1, n, root, l, r);
        printf("%d\n", info.state[0][4] == inf ? -1 : info.state[0][4]);
    }
}


int main() {
    //ios::sync_with_stdio(false);
    int T = 1;
    //scanf("%d", &T);
    //cin >> T;
    int ncase = 0;
    while(T --) {
        solve(++ ncase);
    }
}
