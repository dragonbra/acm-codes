#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

const int MOD = 998244353;

int add(int a, int b){
	a += b;
	if (a >= MOD)
		a -= MOD;
	if (a < 0)
		a += MOD;
	return a;
}

int mul(int a, int b){
	return a * 1ll * b % MOD;
}

int binpow(int a, int b){
	int res = 1;
	while (b){
		if (b & 1)
			res = mul(res, a);
		a = mul(a, a);
		b >>= 1;
	}
	return res;
}

int main() {
	long long d;
	scanf("%lld", &d);
	int q;
	scanf("%d", &q);
	
	vector<long long> primes;
	for (long long i = 2; i * i <= d; ++i) if (d % i == 0){
		primes.push_back(i);
		while (d % i == 0) d /= i;
	}
	if (d > 1){
		primes.push_back(d);
	}
	
	vector<int> fact(100), rfact(100);
	fact[0] = 1;
	for (int i = 1; i < 100; ++i)
		fact[i] = mul(fact[i - 1], i);
	rfact[99] = binpow(fact[99], MOD - 2);
	for (int i = 98; i >= 0; --i)
		rfact[i] = mul(rfact[i + 1], i + 1);
	
	forn(i, q){
		long long x, y;
		scanf("%lld%lld", &x, &y);
		vector<int> up, dw;
		for (auto p : primes){
			int cnt = 0;
			while (x % p == 0){
				--cnt;
				x /= p;
			}
			while (y % p == 0){
				++cnt;
				y /= p;
			}
			if (cnt < 0) dw.push_back(-cnt);
			else if (cnt > 0) up.push_back(cnt);
		}
		int ans = 1;
		ans = mul(ans, fact[accumulate(up.begin(), up.end(), 0)]);
		for (auto it : up) ans = mul(ans, rfact[it]);
		ans = mul(ans, fact[accumulate(dw.begin(), dw.end(), 0)]);
		for (auto it : dw) ans = mul(ans, rfact[it]);
		printf("%d\n", ans);
	}
	
	return 0;
}