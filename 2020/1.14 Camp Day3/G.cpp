#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 998244353;
const double eps = 1e-5;
const int N = 1e5 + 5;

#define LOCAL
void redirect() {
#ifdef LOCAL
  freopen("1.in","r",stdin);
  freopen("1.out","w",stdout);
#endif
}

inline ll read() {
  ll f=1,x=0;char ch;
  do {ch=getchar(); if(ch=='-') f=-1;} while (ch<'0'||ch>'9');
  do {x=x*10+ch-'0'; ch=getchar(); } while (ch>='0'&&ch<='9');
  return x*f;
}

int T;
ll n,l,r; ll ans;
ll a[N]; int cnt;

inline ll cal(ll l, ll x){
  if(x==1) return 0;
  //cout << cnt << '@' << endl;
  ll res = 0;
  int pt;
  for (pt = 1; pt <= cnt && a[pt] < l; pt++);
  a[pt - 1] = l - 1;
  for(; pt <= cnt; pt++) {
    if(a[pt]>x) {
      a[pt] = x;
    }
    ll N = n / a[pt]; //cout<<N<<' '<<M<<endl;
    ll len = ( a[pt] - a[pt-1]) % mod; ll sum = ( ( a[pt-1] + a[pt] + 1 ) * ( a[pt] - a[pt-1] ) / 2 ) % mod;
    res += n * n  * len ;
    res -= 2 * N  * (n * len - N * sum);
    res -= (n * len - N * sum);
    res -= N * N  * sum;  res = (res % mod + mod) % mod;
    if(a[pt]==x) break;
  }

  return res;
}

int main() {
  //  redirect();

  T = read();
  while(T--){
    n = read();
    l = read();
    r = read();
    cnt = 0;
    for (ll _l = 1, _r = 0; _l <= n; _l = _r + 1) a[++cnt] = _r = n / (n / _l);
    //cout<<cal(r)<<' ';
    ll ans = cal(l, r);
    //cout<<cal(l-1)<<endl;
    ans /= 2;

    printf("%lld\n",ans);
  }

  return 0;
}
