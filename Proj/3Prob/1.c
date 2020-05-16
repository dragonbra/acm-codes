#include <stdio.h>

const int N = 2e5 + 10;

int a[11], b[11];

void redirect() {
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
}

void bubble_sort(int arr[], int len) {
        int i, j;
        for (i = 0; i < len - 1 ; i++) {
            for (j = 0; j < len - i - 1; j++)
                    if (arr[j] > arr[j + 1]) {
                        int t = arr[j];
                        arr[j] = arr[j+1];
                        arr[j+1] = t;
                    }
        }
}

int main() {
    redirect();

    int T; scanf("%d", &T);
    while (T--) {
        for (int i=0; i<3; i++) scanf("%d", &a[i]);
        for (int i=0; i<3; i++) scanf("%d", &b[i]);
        bubble_sort(a, 3); bubble_sort(b, 3);
        int f = 1, f2 = 1;
        for (int i=0; i<3; i++) {
            if (a[i] > b[i]) {
                f = 0;
            }
            if (a[i] < b[i]) {
                f2 = 0;
            }
        }
        if (f+f2>0) puts("yes");
        else puts("no");
    }

    return 0;
}