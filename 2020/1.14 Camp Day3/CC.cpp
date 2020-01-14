#include <bits/stdc++.h>
using namespace std;

vector<long long> downh_max_pos;
vector<long long> downh_smax_pos;
vector<long long> down_heights;
vector<long long> down_heights_smax;
vector<long long> up_heights;
vector<long long> down_cnt;
vector<long long> up_cnt;

struct ed {
  long long v;
  long long w;
  ed() {}
  ed(long long _v, long long _w) {
    v = _v;
    w = _w;
  }
};
vector<vector<ed> > edges;
vector<bool> is_country;

void get_down(long long root, long long from)
{
  downh_max_pos[root] = -1;
  downh_smax_pos[root] = -1;
  down_heights[root] = -1;
  down_heights_smax[root] = -1;
  down_cnt[root] = -1;
  for (auto edge : edges[root]) {
    if (edge.v == from) continue;
    get_down(edge.v, root);
    if (down_heights[edge.v] != -1) {
      if (down_heights[edge.v] + edge.w > down_heights[root]) {
        down_heights[root] = down_heights[edge.v] + edge.w;
        downh_max_pos[root] = edge.v;
      } else if (down_heights[edge.v] + edge.w > down_heights_smax[root]) {
        down_heights_smax[root] = down_heights[edge.v] + edge.w;
        downh_smax_pos[root] = edge.v;
      }
    }
    if (down_cnt[edge.v] != -1) {
      if (down_cnt[root] == -1) down_cnt[root] = 0;
      down_cnt[root] += 2 * edge.w + down_cnt[edge.v];
    }
  }
  if (down_heights[root] == -1 && is_country[root]) down_heights[root] = 0;
  if (down_cnt[root] == -1 && is_country[root]) down_cnt[root] = 0;
  // cout << "node:" << root + 1 << " down_height_max:" << down_heights[root] << "[child=" << downh_max_pos[root] + 1 << "] down_height_secondmax:" << down_heights_smax[root] << "[child=" << downh_smax_pos[root] << "]" << endl;
  // cout << root + 1 << " dt: " << down_cnt[root] << endl;
}

void get_up(long long root, long long from, long long w, long long s)
{
  if (from != -1) {
    long long len = 0;
    if (downh_max_pos[from] != root) len = down_heights[from];
    else if (downh_smax_pos[from] != -1) len = down_heights_smax[from];
    len = max(len, up_heights[from]);
    up_heights[root] = len + w;
    if (up_cnt[from] != -1) up_cnt[root] = s + 2 * w + up_cnt[from];
    else up_cnt[root] = s + 2 * w;
  } else {
    up_heights[root] = 0;
    up_cnt[root] = is_country[root] ? 0 : -1;
  }
  long long tot = 0;
  for (auto edge : edges[from]) {
    if (edge.v == root) continue;
    if (down_cnt[edge.v] == -1) continue;
    tot += down_cnt[edge.v] + 2 * edge.w;
  }
  for (auto edge : edges[root]) {
    if (edge.v == from) continue;
    get_up(edge.v, root, edge.w, tot);
  }
}

int main(){
    #ifdef LOCAL
        freopen("1.in","r",stdin);
        freopen("1.out","w",stdout);
    #endif
  long long n, k, u, v, w, x;

  cin >> n >> k;
  edges.resize(n);
  down_heights.resize(n);
  down_heights_smax.resize(n);
  downh_max_pos.resize(n);
  downh_smax_pos.resize(n);
  down_cnt.resize(n);
  up_cnt.resize(n);
  is_country.resize(n);
  up_heights.resize(n);

  for (long long i = 0; i < n - 1; i++) {
    cin >> u >> v >> w;
    u--; v--;
    edges[u].push_back(ed(v, w));
    edges[v].push_back(ed(u, w));
  }


  for (long long i = 0; i < n; i++) {
    down_cnt[i] = 0;
    is_country[i] = false;
  }
  for (long long i = 0; i < k; i++) {
    cin >> x;
    is_country[x - 1] = true;
    down_cnt[x - 1] = 1;
  }

  get_down(0, -1);
  get_up(0, -1, 0, 0);

  for (long long i = 0; i < n; i++) {
    if (up_cnt[i] == -1) up_cnt[i] = 0;
    if (down_cnt[i] == -1) down_cnt[i] = 0;
    if (down_heights[i] == -1) down_heights[i] = 0;
    if (up_heights[i] == -1) up_heights[i] = 0;
    cout << "id:" << i + 1 << " down_cnt:" << down_cnt[i] << " up_cnt:" << up_cnt[i] << endl;
    //cout << down_cnt[i] + up_cnt[i] - max(down_heights[i], up_heights[i]) << endl;
  }
}
