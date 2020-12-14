/*
Lucas定理是用来求 C(n,m) MOD p，p为素数的值。
时间复杂度 O（logp(n)∗p)：）

卡特兰数：有一个长度为2n的01序列，其中1,0各n个，要求对于任意的整数k ∈ [ 1 , 2 n ] k \in [1,2n]k∈[1,2n]，数列的前k kk个数中，1的个数不少于0
f(n) = C(n, 2n) - C(n-1, 2n);

Lucas定理：我们令n=sp+q,m=tp+r.（q，r≤p）
那么：（在编程时你只要继续对 调用 Lucas 定理即可。代码可以递归的去完成这个过程，其中递归终点为 t=0 ；
*/

// Problem: P1641 [SCOI2010]生成字符串
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1641
// Memory Limit: 125 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)


#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
using namespace std;

typedef long long ll;
const int N = 2e5 + 10;
const int LUCAS_CON = 2e6;

long long F[LUCAS_CON + 10];

void init(long long p) {
    F[0] = 1;
    for(int i = 1;i <= LUCAS_CON;i++)
        F[i] = F[i-1]*i % (p);
}

long long inv(long long a,long long m) {
    if(a == 1)return 1;
    return inv(m%a,m)*(m-m/a)%m;
}

long long Lucas(long long m,long long n,long long p) {
	// return C(m, n) % p;
    long long ans = 1;
    while(n&&m)
    {
        long long a = n%p;
        long long b = m%p;
        if(a < b)return 0;
        ans = ans*F[a]%p*inv(F[b]*F[a-b]%p,p)%p;
        n /= p;
        m /= p;
    }
    return ans%p;
}

ll n, m, p;
int ans1 = 0, ans2 = 0;

int main() {

    cin >> n >> m; p = 20100403;
    init(p);
    ll ans = Lucas(n, m+n, p) - Lucas(m-1, m+n, p);
    ans += p*2; ans %= p;
    cout << ans << endl;

    return 0;
}
