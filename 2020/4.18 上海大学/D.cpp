#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    scanf("%d",&n);

    if(n==1) {
        cout<<1<<endl<<1<<endl;
    } else if(n==2) {
        cout<<2<<endl;
        cout<<1<<endl<<"00"<<endl;
    } else {
        printf("%d\n",n-1);
        for(int i=2;i<=n;i++) {
            printf("0");
            for(int j=2;j<=i-1;j++) printf("1");
            printf("0\n");
        }
    }

    return 0;
}