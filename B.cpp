/*
*  @ author: dragon_bra
*  @ created at: 2021-11-11 17:46:53
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

int n = 60;

int main() {
    
    cout << n << ' ' << n * (n - 1) / 2 << endl;
    for (int i = 1; i <= n; i ++ ) cout << i << ' '; cout << endl;
    for (int i = 1; i <= n; i ++ ) cout << i << ' '; cout << endl;

    for (int i = 1; i <= n; i ++ ) {
        for (int j = i + 1; j <= n; j ++ ) {
            cout << i << ' ' << j << endl;
        }
    }
    
    return 0;
}