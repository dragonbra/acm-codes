#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 100050;
LL a[MAXN], sum[MAXN];
LL L[MAXN], R[MAXN];
int n;
int main ()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
        sum[i] = sum[i - 1] + a[i];
        L[i] = R[i] = i;
    }
    a[0] = a[n + 1] = -1;//保证不会访问或者访问无效。
    for(int i = 1; i <= n; i++)
    {
        while(a[i] <= a[L[i] - 1])
            L[i] = L[L[i] - 1];
    }
    for(int i = n; i >= 1; i--)
    {
        while(a[i] <= a[R[i] + 1])
            R[i] = R[R[i] + 1];
    }
    LL ans = -1e10, l, r;
    for(int i = 1; i <= n; i++)
    {
        LL T = a[i] * (sum[R[i]] - sum[L[i] - 1]);
        if(ans < T)
            ans = T, l = L[i], r = R[i];
    }
    printf("%lld\n%lld %lld\n", ans, l, r);
}
