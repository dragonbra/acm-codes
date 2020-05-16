#include <stdio.h>

const int N = 2e5 + 10;

int T, n; 

int main() {

    scanf("%d", &T);
    while (T--) {
        int ans = 0;
        for (int i=1; i<=10; i++) {
            int t; scanf("%d", &t);
            if (t < 0) ans ++;
        }
        printf("%d\n", ans);
    }

    return 0;
}