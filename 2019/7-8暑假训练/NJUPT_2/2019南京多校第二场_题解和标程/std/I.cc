#include <bits/stdc++.h>
typedef long long LL;
using namespace std;
const int maxn = 1e6+7;
LL k,q,a[maxn];
int main()
{
    for(LL i=1;i<maxn;i++) a[i]=i*i*i-i;
    scanf("%lld",&q);
    while(q--)
    {
        scanf("%lld",&k);
        int pos = lower_bound(a+1,a+maxn,k) - a - 1;
        printf("%lld\n",k+pos);
    }
    return 0;
}
