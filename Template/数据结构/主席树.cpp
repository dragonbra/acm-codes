#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int N = 200500;

void redirect() {
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
}

struct node{
	int l, r, sum;
	#define l(x) tree[x].l
	#define r(x) tree[x].r
	#define sum(x) tree[x].sum
}tree[N<<5];

int n, m, a[N], b[N];
int q, cnt, t[N];
int build(int l, int r) {
	int rt = ++cnt;
	sum(rt) = 0;
	int mid = (l + r) >> 1;
	if (l < r) {
		l(rt) = build(l, mid);
		r(rt) = build(mid + 1, r);
	}
	return rt;
}
inline int update(int pre,int l,int r,int x) {
	int rt = ++cnt;
	l(rt) = l(pre), r(rt) = r(pre);
	sum(rt) = sum(pre) + 1;
	int mid = (l + r) >> 1;
	if (l < r) {
		if (x <= mid) l(rt) = update(l(pre), l, mid, x);
		else r(rt) = update(r(pre), mid + 1, r, x);
	}
	return rt;
}
inline int query(int u,int v,int l,int r,int k) {
	if (l >= r) return l;
	int x = sum(l(v)) - sum(l(u));
	int mid = (l + r) >> 1;
	if (x >= k) return query(l(u), l(v), l, mid, k);
	else return query(r(u), r(v), mid + 1, r, k - x);
}
int main() {
    redirect();
	cin >> n >> q;
	for (int i = 1;i <= n; i++) {
        cin >> a[i]; b[i] = a[i];
    }
	sort(b + 1,b + n + 1);
	m = unique(b + 1,b + n + 1) - b - 1;

	t[0] = build(1, m);
	for (int i = 1;i <= n; i++) {
		int T = lower_bound(b + 1,b + m + 1, a[i]) - b;
		t[i] = update(t[i-1], 1, m, T);
	}

	while (q--) {
        int l, r, k;
		cin >> l >> r >> k;
		printf ("%d\n", b[query(t[l-1], t[r], 1, m, k)]);
	}
	return 0;
}