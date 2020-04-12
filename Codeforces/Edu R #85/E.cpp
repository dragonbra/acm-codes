#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 998244353;
const double eps = 1e-5;
const int N = 1e5 + 10;

void redirect() {
    #ifdef LOCAL
        freopen("1.in","r",stdin);
        freopen("1.out","w",stdout);
    #endif
}

ll d; int q;

int main() {
    redirect();

    scanf("%lld", &d);
    scanf("%d", &q);

    vector<long long> primes;
	for (long long i = 2; i * i <= d; ++i) if (d % i == 0){
		primes.push_back(i);
		while (d % i == 0) d /= i;
	}
	if (d > 1){
		primes.push_back(d);
	}

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/