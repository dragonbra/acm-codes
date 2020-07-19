/*
* @ author: dragon_bra
* @ email: tommy514@foxmail.com
* @ data: 2020-07-19 14:10
*/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <vector>

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

int T;
int total;

int arr[15] = {0, 95, 90, 85, 80, 75, 70, 67, 65, 62, 60};

double gpa(int x) {
    if (x >= 95) return 4.3;
    if (x >= 90) return 4.0;
    if (x >= 85) return 3.7;
    if (x >= 80) return 3.3;
    if (x >= 75) return 3.0;
    if (x >= 70) return 2.7;
    if (x >= 67) return 2.3;
    if (x >= 65) return 2.0;
    if (x >= 62) return 1.7;
    if (x >= 60) return 1.0;
    return 0.0;
}

int main() {
    redirect();

    cin >> T;
    while (T--) {
        cin >> total;
        double ans = 0;
        for (int i1=0; i1<=10; i1++) {
            for (int i2=0; i2<=10; i2++) {
                for (int i3=0; i3<=10; i3++) {
                    int i4 = total - arr[i1] - arr[i2] - arr[i3];
                    if (i4<0) continue;
                    //cout << arr[i1] << endl;
                    ans = max(ans, gpa(arr[i1]) + gpa(arr[i2]) + gpa(arr[i3]) + gpa(i4));
                }
            }
        }
        printf("%.1lf\n", ans);
    }

    return 0;
}