#include <cstdio>
#include <bitset>
using namespace std;

long long read() {
    long long val = 0;
    char c = getchar();
    while (c < '0' || c > '9') c = getchar();
    while (c >= '0' && c <= '9') val = val * 10 + c - '0', c = getchar();
    return val;
}

void exgcd(long long a, long long b, long long& d, long long& x, long long& y) {  // ax+by=d
    if (!b) {
        d = a;
        x = 1;
        y = 0;
        return;
    } else {
        exgcd(b, a % b, d, y, x);
        y -= x * (a / b);
    }
}

long long crt(long long a, long long m, long long b, long long n) {  // x=km+a=tn+b->km-tn=b-a
    long long d, k, t;
    exgcd(m, n, d, k, t);
    long long w = (b - a);
    // printf("m=%lld n=%lld t=%lld k=%lld w=%lld\n",m,n,t,k,w);
    long long lcm = m * n;
    return ((k * w * m + a) % lcm + lcm) % lcm;
}

const int p[10] = { 961339, 964793, 907723, 990637, 945631, 959333, 955039, 925063, 924323, 905269 };
bool can[10];
bitset<1000001> cnt[10];
int p0[501], p1[501];
long long ans[501];
int id0, id1;

int main() {
    int n = read(), k = read();
    while (n--) {
        long long x = read();
        // printf("%lld\n",x);
        for (int i = 0; i < 10; i++) cnt[i][x % p[i]].flip();
    }
    int tat = 0;
    for (int i = 0; i < 10; i++) {
        if (cnt[i].count() == k) {
            can[i] = true;
            // printf("WTF %d\n",i);
            if (!tat) {
                int cur = 0;
                id0 = i;
                for (int j = 0; j < p[i]; j++)
                    if (cnt[i][j])
                        p0[++cur] = j;
            } else if (tat == 1) {
                int cur = 0;
                id1 = i;
                for (int j = 0; j < p[i]; j++)
                    if (cnt[i][j])
                        p1[++cur] = j;
            }
            tat++;
        }
    }
    int cur = 0;
    for (int i = 1; i <= k; i++)
        for (int j = 1; j <= k; j++) {
            long long qwq = crt(p0[i], p[id0], p1[j], p[id1]);
            // printf("%lld\n",qwq);
            bool flag = true;
            for (int o = 0; o < 10; o++)
                if (can[o] && !cnt[o][qwq % p[o]]) {
                    flag = false;
                    break;
                }
            if (flag) {
                ans[++cur] = qwq;
                // printf("%d %d %lld\n",i,j,qwq);
            }
        }
    for (int i = 1; i <= k; i++)
        for (int j = i + 1; j <= k; j++)
            if (ans[j] < ans[i]) {
                long long t = ans[j];
                ans[j] = ans[i];
                ans[i] = t;
            }
    for (int i = 1; i <= k; i++) printf("%lld\n", ans[i]);
	return 0;
}