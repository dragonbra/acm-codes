#include <bits/stdc++.h>
using namespace std;

int a[105];

bool check (int i, int j) {
	int ans = 0;
	for (int x=i; x<=j; x++) {
		ans += a[x];
	}

	if (ans % (j-i+1) != 0) return false;
	int k = ans / (j-i+1);

	for (int x=i; x<=j; x++) {
		if (a[x] == k) return true;
	}
	return false;
}

int main() {

	int n; cin >> n;

	for (int i=1; i<=n; i++){
		cin >> a[i];
	}

	int cnt = 0;
	for (int i=1; i<=n; i++) {
		for (int j = i+1; j<=n; j++) {
			if (check(i, j)) cnt++;
		}
	}

	cout << cnt + n << endl;
	
    return 0;
}
