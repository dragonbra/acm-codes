/*
    LOJ 10163
    ACWing, 1081 度的数量
* @ author: dragon_bra
* @ email: tommy514@foxmail.com
* @ date: 2021-03-10 16:31
*/

#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(0);
using namespace std;

typedef long long ll;
const int N = 35 + 10;

void redirect() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
}

int B, K;
int f[N][N] = {0};

void init() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0)
                f[i][j] = 1;
            else
                f[i][j] = f[i - 1][j - 1] + f[i - 1][j];
        }
    }
}

int dp(int n) {
    if (!n)
        return 0;

    vector<int> nums;

    while (n)
        nums.push_back(n % B), n /= B;

    int res = 0;
    int last = 0; // 当前已有1的个数

    for (int i = nums.size() - 1; i >= 0; i--) {
        int x = nums[i];

        if (x) {
            res += f[i][K - last];

            if (x > 1) {
                if (K - last - 1 >= 0)
                    res += f[i][K - last - 1];

                break;
            } else {
                last ++;

                if (last > K)
                    break;
            }
        }

        if (i == 0 && last == K)
            res ++;
    }

    return res;
}

int main() {
    redirect();
    init();

    int l, r;
    cin >> l >> r >> K >> B;

    cout << dp(r) - dp(l - 1) << endl;

    return 0;
}