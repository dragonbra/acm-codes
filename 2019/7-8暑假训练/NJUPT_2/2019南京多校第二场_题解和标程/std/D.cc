#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair <LL, LL> PII;

const int P = int(1E9) + 7;
const int MAX_T = 20000 + 5;
const int MAX_N = 100000 + 5;

struct BIT {
    LL c[MAX_N];
    inline int lowbit(int x) {
        return x & (-x);
    }
    void add(int pos, LL k) {
        while (pos < MAX_N) {
            c[pos] += k;
            pos += lowbit(pos);
        }
    }
    LL pre(int pos) {
        LL ret = 0;
        while (pos >= 1) {
            ret += c[pos];
            pos -= lowbit(pos);
        }
        return ret;
    }
} bit;

bool vis[MAX_N];
LL low[MAX_N], mu[MAX_N], d[MAX_N], p[MAX_N], tot;
PII va[MAX_N];

void linearSieve() {
    vis[0] = vis[1] = 1;
    mu[1] = d[1] = low[1] = 1;
    for (int i = 2; i < MAX_N; ++i) {
        if (!vis[i]) {
            low[i] = p[++tot] = i;
            mu[i] = -1;
            d[i] = i + 1;
        }
        for (int j = 1; j <= tot && LL(i) * p[j] < MAX_N; ++j) {
            vis[i * p[j]] = 1;
            if (i % p[j] == 0) {
                low[i * p[j]] = low[i] * p[j];
                if (low[i] == i) d[i * p[j]] = d[i] + i * p[j];
                else d[i * p[j]] = d[i / low[i]] * d[p[j] * low[i]];
                break;
            } else {
                low[i * p[j]] = p[j];
                mu[i * p[j]] -= mu[i];
                d[i * p[j]] = d[i] * d[p[j]];
            }
        }
    }
    for (LL i = 1; i < MAX_N; ++i) va[i] = {d[i], i};
    sort(va + 1, va + MAX_N, [](const PII &px, const PII &py) { return px.first > py.first; });
}

int T;
LL ans[MAX_N];

void contribute(LL val, LL id) {
    // f(id) * mu(i / id)
    for (LL i = id; i < MAX_N; i += id) {
        bit.add(i, d[id] * mu[i / id]);
    }
}

struct Query {
    LL qn, qu, id;
    friend bool operator < (const Query &qx, const Query &qy) {
        return qx.qu > qy.qu;
    }
} q[MAX_N];

int main() {
    scanf("%d", &T);
    for (int i = 1; i <= T; ++i) scanf("%lld%lld", &q[i].qn, &q[i].qu), q[i].id = i;
    sort(q + 1, q + T + 1);
    linearSieve();
    int vPtr = 1;
    for (int i = 1; i <= T; ++i) {
        while (vPtr < MAX_N && va[vPtr].first >= q[i].qu) {
            contribute(va[vPtr].first, va[vPtr].second);
            ++vPtr;
        }
        LL ret = 0, l = 1, r, n = q[i].qn;
        for (l = 1; l <= n; l = r + 1) {
            r = n / (n / l);
            ret += ((bit.pre(r) - bit.pre(l - 1)) * ((n / l) * (n / l) * (n / l) % P) % P);
            ret %= P;
        }
        ans[q[i].id] = ret;
    }
    for (int i = 1; i <= T; ++i) printf("%lld\n", ans[i]);
    return 0;
}