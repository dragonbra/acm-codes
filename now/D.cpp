/*
* @ author: dragon_bra
* @ email: tommy514@foxmail.com
* @ data: 2020-09-19 23:14
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

int n;
int a[N], b[N];
int b1[N], b2[N];

void easySolve() {
    sort(a+1,a+n+1);

    int cnt = 1;
    cout << (n-1)/2 << endl;
    
    for(int i=2; i<=n; i+=2) {
        b[i] = a[cnt++];
    }
    for(int i=1; i<=n; i++) {
        if(!b[i]) b[i] = a[cnt++];
    }
    for(int i=1; i<=n; i++) {
        cout << b[i] << ' ';
    }
}

void hardSolve() {
    sort(a+1,a+n+1);

    int cnt1 = 1, cnt2 = 1;

    for(int i=2; i<=n; i+=2) {
        b1[i] = a[cnt1++];
    }

    for (int i=n%2 == 0 ? n:n-1; i>=2; i-=2) {
        b2[i] = a[cnt2++];
    } 

    for(int i=1; i<=n; i++) {
        if(!b1[i]) b1[i] = a[cnt1++];
    }

    for(int i=1; i<=n; i++) {
        if(!b2[i]) b2[i] = a[cnt2++];
    }

    int ans1 = 0, ans2 = 0;
    for (int i=2; i<=n-1; i++) {
        if (b1[i] < b1[i-1] && b1[i] < b1[i+1]) ans1 ++;
        if (b2[i] < b2[i-1] && b2[i] < b2[i+1]) ans2 ++;
    }

    if (ans1 > ans2) {
        cout << ans1 << endl;
        for (int i=1; i<=n; i++) cout << b1[i] << ' ';
    } else {
        cout << ans2 << endl;
        for (int i=1; i<=n; i++) cout << b2[i] << ' ';
    }
}

int main() {
    redirect();

    ios::sync_with_stdio(false);
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> a[i];
    }

    hardSolve();

    return 0;
}