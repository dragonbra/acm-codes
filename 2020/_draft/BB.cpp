#include <string>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string.h>
#include <utility>
#include <queue>
#include <stack>
#include <iomanip>
#include <ctype.h>
#include <map>
#include <set>
#include <stdio.h>
#include <assert.h>
#include <ctype.h>
#include <sstream>
#include <math.h>
#include <time.h>
#include <iostream>
#include <iomanip>
#include <unordered_set>
#include <unordered_map>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <tuple>
#include <cmath>
#include <stdio.h>      /* printf, fgets */
#include <stdlib.h>
#include <fstream>

using namespace std;

typedef long long LL;

#define FOR(i,n) for(int i = 0;i < n;i++)
#define MP make_pair
#define PB push_back
#define ALL(a) (a).begin(),(a).end()
#define PII pair<int, int>
#define PLL pair<long long, long long>
#define CLEAR(a) memset(a, 0, sizeof(a))
#define INF 2000000007
#define y1 uu1
#define y2 uu2
#define hash mash
const double EPS = 1E-12;
const double PI = acos(-1.0);
const LL mod = 1000000007;

using namespace std;

LL k,n,m;
set<LL> sol;

bool isq(LL x) {
  LL sq = sqrt(x);
  for (LL i = sq-1; i <= sq+1; i++) {
    if (i*i == x) return true;
  }
  return false;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0);
  cin >> k;

  for (LL i = 1; i <= (LL)sqrt(k); i++) {
    if (k % i == 0 && ((i + k / i) % 2) == 0) {
      m = (i + k / i) / 2;
      n = k / i - m;
      if (n != 0 && (n*n+k != 0)) sol.insert(n*n);
      n = (i + k / i) / 2;
      if (n != 0 && (n*n-k > 0)) sol.insert(-n*n);
    }
  }

  for (LL i = 1; i <= (LL)sqrt(k); i++) {
    LL sq = (LL)sqrt(k - i*i);
    for (LL j = max((LL)1, sq - 1); j <= sq+1; j++) {
      if (i*i + sq*sq == k && abs(-i*i+k) != 0) {
        sol.insert(-i*i);
      }
    }
  }

  // Double check correctness
  for (auto z : sol) {
    if (!isq(abs(z)) || !isq(abs(z + k))) assert(0);
  }

  cout << sol.size() << endl;
  for (auto z : sol) {
    cout << z << ' ';
  }
  if (sol.size() > 0) cout << endl;

  return 0;
}
