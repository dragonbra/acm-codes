/*
* @ author: dragon_bra
* @ email: tommy514@foxmail.com
* @ data: 2020-07-25 12:12
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
const int N = 1e3 + 10;

void redirect() {
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
}

int n, a[N];
int f[N];

int lis(int x) {
    f[0]=-INF;
    int s=0, t;
    for(int i=1;i<=n;i++) {
        t = a[i+x-1];
        if(t > f[s]) f[++s]=t;
        else {
            int l=1, r=s, m;
            while(l<=r) {
                m=(l+r)/2;
                if(t>f[m]) l=m+1;
                else r=m-1;
            }
            f[l]=t;
        }
    }
    return s;
}

int main() {
    redirect();

    cin>>n;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        a[i+n] = a[i];
    }

    int mx = 0;
    for (int i=1; i<=n; i++) {
        mx = max(mx, lis(i));
    }
    
    cout << n - mx << endl;
}