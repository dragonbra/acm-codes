#include <stdio.h>

int T, n; int a[51];

void bubble_sort(int arr[], int len) {
        int i, j;
        for (i = 0; i < len - 1 ; i++) {
            for (j = 0; j < len - i - 1; j++)
                    if (arr[j] > arr[j + 1]) {
                        int t = arr[j];
                        arr[j] = arr[j+1];
                        arr[j+1] = t;
                    }
            for (int j=0; j<len; j++) {
                printf("%d", a[j]);
                if (j!=len-1) printf(" ");
            }
            printf("\n");
        }
}

int main() {

    #ifdef LOCAL
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif

    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i=0; i<n; i++) {
            scanf("%d", &a[i]);
        }
        bubble_sort(a, n);
    }

    return 0;
}