#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;

const int N = 2e5 + 10;

int T; int n, k;

void redirect() {
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
}

int main() {
    redirect();

    int f[32]; f[0] = 1;
    for (int i=1; i<=31; i++) f[i] = f[i-1] * 2;

    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        int k = 1;
        for (int i=1; i<=31; i++) {
            k += f[i];
            if (n%k == 0) {
                printf("%d\n", n/k);
                break;
            }
        }
    }

    return 0;
}