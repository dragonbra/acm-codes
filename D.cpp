/*
*  @ author: dragon_bra
*  @ created at: 2021-08-03 20:40:57
*/

#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>

using namespace std;

typedef long long LL;

const int N = 2e5 + 10;

int k;

int main() {
    
    ios::sync_with_stdio(false); cin.tie(0);
    int T, kase = 0; cin >> T;
    while (T -- ) {
        ++ kase;
        cin >> k;

        int a, b, c; bool flag = false;
        for (a = 3000; a >= 1; a -- ) {
            for (b = a; b >= 1; b -- ) {
                if (a * b == k && a + b <= 3001) flag = true;
                if (k % a == 0 && k / a + a - 1 <= 3001) flag = true;
                if (k % b == 0 && k / b + b - 1 <= 3001) flag = true;
                if ((k - a - b) % (a * b) == 0 && (k - a - b) / (a * b) + a + b <= 3000) flag = true;

                if (flag) break;
            }
        }

        if (!flag) cerr << k << endl;
    }
    
    return 0;
}