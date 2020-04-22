#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

const int MAXN = 65;
long long x[MAXN];
vector<long long> f;

long long multi(long long a, long long b, long long p) {
    long long ans = 0;
    while(b) {
        if(b&1LL) ans = (ans+a)%p;
        a = (a+a)%p;
        b >>= 1;
    }
    return ans;
}

long long qpow(long long a, long long b, long long p) {
    long long ans = 1;
    while(b) {
        if(b&1LL) ans = multi(ans, a, p);
        a = multi(a, a, p);
        b >>= 1;
    }
    return ans;
}

bool Miller_Rabin(long long n) {
    if(n == 2) return true;
    int s = 20, i, t = 0;
    long long u = n-1;
    while(!(u & 1)) {
        t++;
        u >>= 1;
    }
    while(s--) {
        long long a = rand()%(n-2)+2;
        x[0] = qpow(a, u, n);
        for(i = 1; i <= t; i++) {
            x[i] = multi(x[i-1], x[i-1], n);
            if(x[i] == 1 && x[i-1] != 1 && x[i-1] != n-1) return false;
        }
        if(x[t] != 1) return false;
    }
    return true;
}

long long gcd(long long a, long long b) {
    return b ? gcd(b, a%b) : a;
}

long long Pollard_Rho(long long n, int c) {
    long long i = 1, k = 2, x = rand()%(n-1)+1, y = x;
    while(true) {
        i++;
        x = (multi(x, x, n) + c)%n;
        long long p = gcd((y-x+n)%n, n);
        if(p != 1 && p != n) return p;
        if(y == x) return n;
        if(i == k) {
            y = x;
            k <<= 1;
        }
    }
}

void find(long long n, int c) {
    if(n == 1) return;
    if(Miller_Rabin(n)) {
        f.push_back(n);
        return;
    }
    long long p = n, k = c;
    while(p >= n) p = Pollard_Rho(p, c--);
    find(p, k);
    find(n/p, k);
}
