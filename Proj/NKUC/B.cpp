#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
const double eps = 1e-5;
const int N = 2e5 + 10;

void redirect() {
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
}

int T; ll n, k; ll sum[N];

int main() {
    redirect();

    for (int i=1; i<N; i++) sum[i] = sum[i-1] + i;

    scanf("%d", &T);
    while (T--) {
        scanf("%lld%lld", &n, &k);
        int idx = upper_bound(sum+1, sum+n+1, k) - sum - 1;
        int lft = k - sum[idx];
        
        int pos1, pos2;
        if (lft) {
            pos1 = n-idx-1;
            pos2 = n-lft+1;
        } else {
            pos1 = n-idx;
            pos2 = n-idx+1;
        }
        
        //cout << idx << ' ' << lft << '|' << pos1 << ' ' << pos2 << endl;

        for (int i=1; i<=n; i++) {
            if (i==pos1 || i==pos2) {
                printf("b");
            } else {
                printf("a");
            }
        }
        printf("\n");
    }

    return 0;
}
