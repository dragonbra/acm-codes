/*
* @ author: dragon_bra
* @ email: tommy514@foxmail.com
* @ data: 2020-11-28 23:34
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
const double eps = 1e-5;
const int N = 2e5 + 10;

void redirect() {
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
}


vector<long long> p(32);

void init() {
    p[0] = 1;
    for (int i=1; i<=31; i++) p[i] = p[i-1] * 2;
}

int highbit(int x) {
    return upper_bound(p.begin(), p.end(), x) - p.begin() - 1;
}

int msb(int x) {
    union { double a; int b[2]; };
    a = x;
    return (b[1] >> 20) - 1023;
}

int highestOneBit(int i) {
    // HD, Figure 3-1
    i |= (i >>  1);
    i |= (i >>  2);
    i |= (i >>  4);
    i |= (i >>  8);
    i |= (i >> 16);
    return i - ((unsigned)i >> 1);
}

int main() {
    redirect();

    init();
    
    double t1, t2;
    const int lim = 200 * 1000 * 10;
    {
    	t1 = clock();
    	for (int i = 0; i < lim; i++) {
			int t = msb(i);
			if (t == -42) return 1;
		}
		t2 = clock();
		cout << (t2 - t1) / 1000.0 << endl;
    }
    {
    	t1 = clock();
    	for (int i = 0; i < lim; i++) {
			int t = highestOneBit(i);
			if (t == -42) return 1;
		}
		t2 = clock();
		cout << (t2 - t1) / 1000.0 << endl;
    }
    {
    	t1 = clock();
    	for (int i = 0; i < lim; i++) {
			int t = highbit(i);
			if (t == -42) return 1;
		}
		t2 = clock();
		cout << (t2 - t1) / 1000.0 << endl;
    }


    return 0;
}