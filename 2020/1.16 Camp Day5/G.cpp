#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 1000000000
using namespace std;

long long quick_power(long long base, long long power, long long mod){
    long long res = 1, x = base;
    while(power){
        if(power&1) res*=x, res%=mod;
        x*=x, x%=mod; power/=2;
    }
    return res;
}

long long inv(long long a, long long p) {
  if (a == 1) return 1;
  return quick_power(a, p - 2, p);
}

void redirect() {
    #ifdef LOCAL
        freopen("1.in","r",stdin);
        freopen("1.out","w",stdout);
    #endif
}

int main(){
    redirect();
  int T;
  long long p;
  long long fx = 2;
  long long minx = MAX;
  long long s = 0;
  long long split = 50000;
  long long x, delta, t, res;
  vector<pair<long long, long long> > ans;

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> T;
  while (T--) {
    s = 0;
    cin >> p;
    minx = p;
    fx = 2;
    while (true) {
      if (minx <= split) break;
      x = inv(fx, p);
      if (x < minx) {
        delta = 0;
        ans.push_back(make_pair(x, fx));
        s++;
        minx = x;
      }
      //      cout << minx << endl;
      fx++;
    }
    for (long long i = 2; i < minx; i++) {
      x = inv(i, p);
      if (i == 2 || x <= t) {
        ans.push_back(make_pair(i, x));
        s++;
        t = x;
      }
    }
    sort(ans.begin(), ans.end());
    cout << s << endl;
    for (auto res : ans) cout << res.first << " " << res.second << endl;
    ans.clear();
  }
}
