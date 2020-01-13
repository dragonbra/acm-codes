#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

long long ans[100005];
vector<vector<long long> > children;

void redirect() {
    #ifdef LOCAL
        freopen("1.in","r",stdin);
        freopen("1.out","w",stdout);
    #endif
}

set<long long> dfs(long long root) {
  set<long long> tmp;
  set<long long> nodes;
  long long res = 0;
  nodes.insert(root);
  for (auto child : children[root]) {
    tmp = dfs(child);
    for (auto node : tmp) nodes.insert(node);
  }
  long long last = 0;
  for (auto node : nodes) {
    if (!last) {
      last = node;
      continue;
    }
    res += (node - last) * (node - last);
    last = node;
  }
  ans[root] = res;
  return nodes;
}

int main()
{
    redirect();
  long long n, x;
  cin >> n;
  children.resize(n + 1);
  for (long long i = 0; i < n - 1; i++) {
    cin >> x;
    children[x].push_back(i + 2);
  }

  dfs(1);

  for (long long i = 1; i <= n; i++) cout << ans[i] << endl;
}
