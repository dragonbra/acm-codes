#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define fastio ios::sync_with_stdio(false); cin.tie(0);
const int N = 2500 + 5;

struct Point{
	int x,y;
} p[N];

bool cmp1 (Point a, Point b) {
    return a.y < b.y;
}

bool cmp2 (Point a, Point b) {
    return a.x < b.x;
}

void redirect() {
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
}

struct treap {
    int l[N], r[N], val[N], rnd[N], size[N], w[N];
    int sz, ans, rt;
    inline void pushup(int x) { size[x] = size[l[x]] + size[r[x]] + w[x]; }
    void lrotate(int &k) {
        int t = r[k];
        r[k] = l[t];
        l[t] = k;
        size[t] = size[k];
        pushup(k);
        k = t;
    }
  void rrotate(int &k) {
    int t = l[k];
    l[k] = r[t];
    r[t] = k;
    size[t] = size[k];
    pushup(k);
    k = t;
  }
  void insert(int &k, int x) {
    if (!k) {
      sz++;
      k = sz;
      size[k] = 1;
      w[k] = 1;
      val[k] = x;
      rnd[k] = rand();
      return;
    }
    size[k]++;
    if (val[k] == x) {
      w[k]++;
    } else if (val[k] < x) {
      insert(r[k], x);
      if (rnd[r[k]] < rnd[k]) lrotate(k);
    } else {
      insert(l[k], x);
      if (rnd[l[k]] < rnd[k]) rrotate(k);
    }
  }

  void del(int &k, int x) {
    if (!k) return;
    if (val[k] == x) {
      if (w[k] > 1) {
        w[k]--;
        size[k]--;
        return;
      }
      if (l[k] == 0 || r[k] == 0)
        k = l[k] + r[k];
      else if (rnd[l[k]] < rnd[r[k]]) {
        rrotate(k);
        del(k, x);
      } else {
        lrotate(k);
        del(k, x);
      }
    } else if (val[k] < x) {
      size[k]--;
      del(r[k], x);
    } else {
      size[k]--;
      del(l[k], x);
    }
  }

  int queryrank(int k, int x) {
    if (!k) return 0;
    if (val[k] == x)
      return size[l[k]] + 1;
    else if (x > val[k]) {
      return size[l[k]] + w[k] + queryrank(r[k], x);
    } else
      return queryrank(l[k], x);
  }

  int querynum(int k, int x) {
    if (!k) return 0;
    if (x <= size[l[k]])
      return querynum(l[k], x);
    else if (x > size[l[k]] + w[k])
      return querynum(r[k], x - size[l[k]] - w[k]);
    else
      return val[k];
  }

  void querypre(int k, int x) {
    if (!k) return;
    if (val[k] < x)
      ans = k, querypre(r[k], x);
    else
      querypre(l[k], x);
  }

  void querysub(int k, int x) {
    if (!k) return;
    if (val[k] > x)
      ans = k, querysub(l[k], x);
    else
      querysub(r[k], x);
  }
} T[N];

map<int, int> mpx;
map<int, int> mpy;

ll check(int i,int j){    
	int l = min(p[i].y,p[j].y), r = max(p[i].y,p[j].y);
    T[i].insert(T[i].rt, p[j].y);
    ll lcnt = T[i].queryrank(T[i].rt, l), rcnt = (j - i + 1) - T[i].queryrank(T[i].rt, r) + 1;
	return lcnt*rcnt;
}

int main(){
    fastio;
    redirect();
    srand(unsigned(time(NULL)));
	ll ans=0;
	int n; cin >> n;
	for(int i=0;i<n;i++){
		cin>>p[i].x>>p[i].y;
	}
    sort (p, p + n, cmp1);
    for (int i=0; i<n; i++) mpy[p[i].y] = i;
    
    sort (p, p + n, cmp2);
    for (int i=0; i<n; i++) mpx[p[i].x] = i;

    for (int i=0; i<n; i++) {
        p[i].x = mpx[p[i].x];
        p[i].y = mpy[p[i].y];
    }

	for(int i=0;i<n;i++){
		for(int j=i; j<n; j++){
			ans += check(i,j);
		}
	}
	cout<<ans+1<<endl;
}