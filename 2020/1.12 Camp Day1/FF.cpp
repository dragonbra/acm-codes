#include <bits/stdc++.h>
using namespace std;

#define LOCAL
void redirect() {
    #ifdef LOCAL
        freopen("1.in","r",stdin);
        freopen("1.out","w",stdout);
    #endif
}

long long n, m, k, a[1000001], b[1000001], l, r, mid, cnt;

long long count(long long mid) {
  long long s = 0, lb, rb, z;
  for (long long i = 0; i < n; i++) {
    if (!a[i]) {
      s += (mid < 0 ? m : 0);
      continue;
    }
    if (a[i] > 0) {
      lb = (long long)floor(mid / a[i]) + 1;
      s += m - (lower_bound(b, b + m, lb) - b);
    } else {
      rb = (long long)ceil( 1.0 * mid / a[i]);
      s += lower_bound(b, b + m, rb) - b;
    }
  }
  //cout << mid << " " << s << endl;
  return s;
}

int main(){
  redirect();
  cin >> n >> m >> k;
  long long p_a = 0, p_b = 0;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    p_a += (a[i] > 0);
  }
  for (long long i = 0; i < m; i++) cin >> b[i];
  sort(b, b + m);

  l = -1e12; r = 1e12;
  long long ans;
  while (l <= r) {
    mid = (l + r) / 2;
    cnt = count(mid);
    if (cnt > k - 1) {
      l = mid + 1;
    } else {
      r = mid - 1;
      ans = mid;
    }
  }

  cout << ans << endl;
}
