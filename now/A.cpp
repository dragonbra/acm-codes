/*
* @ author: dragon_bra
* @ email: tommy514@foxmail.com
* @ date: 2021-03-10 22:31
*/

#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(0);
using namespace std;

typedef long long LL;
const int N = 20 + 10, P = 1e9 + 7;

void redirect() {
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
}

struct F {
    int s0, s1, s2;
} f[N][10][7][7];

int power7[N], power9[N];

int mod (int x, int y) { // 得到非负余数
    return (x % y + y) % y;
}

void init() {
    for (int i = 0; i <= 9; i ++ ) {
        if (i == 7) continue;
        auto &v = f[1][i][i % 7][i % 7];
        v.s0 ++;
        v.s1 += i;
        v.s2 += i * i;
    }

    LL power = 10;
    for (int i = 2; i < N; i ++, power *= 10 ) {
        for (int j = 0; j <= 9; j ++ ) {
            if ( j == 7) continue;
            for (int a = 0; a < 7; a ++ ) {
                for (int b = 0; b < 7; b ++ ) {
                    for (int k = 0; k <= 9; k ++ ) {
                        auto &v1 = f[i][j][a][b], &v2 = f[i - 1][k][mod(a - j * (power % 7), 7)][mod(b - j, 7)];
                        v1.s0 = (v1.s0 + v2.s0) % P;
                        v2.s1 = (v1.s1 + j * (power % P) * v2.s0 + v2.s1) % P;
                        v2.s2 = (v1.s2 + 
                                 j * j * (power % P) * (power % P) % P * v2.s0 % P +
                                 v2.s2) % P;
                    }
                }
            }
        }
    }

    power7[0] = power9[0] = 1;
    for (int i = 1; i <= N; i ++ ) {
        power7[i] = power7[i - 1] * 10 % 7;
        power9[i] = power9[i - 1] * 10 % P;
    }
}

F get(int i, int j, int a, int b) {
    
}

int dp(int n) {
    if (!n) return 0;

    vector<int> nums;
    while (n) nums.push_back(n % 10), n /= 10;

    int res = 0;
    LL last_a = 0, last_b = 0;
    for (int i = nums.size() - 1; i >= 0; i -- ) {
        int x = nums[i];
        for (int j = 0; j < x; j ++ ) {
            if (j == 7) continue;
            int a = mod(-last_a * power7[i + 1], 7);
            int b = mod(-last_b, 7);

            auto v = get(i + 1, j, a, b);
        }
    }

    return res;
}

int main() {
    redirect();

    init();

    int T;
    cin >> T;
    while (T -- ) {
        int l, r;
        cin >> l >> r;
        cout << dp(r) - dp(l - 1) << "\n";
    }
    

    return 0;
}