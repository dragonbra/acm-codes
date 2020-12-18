#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a[10];

int main() {
    
    for (int i=1; i<=7; i++) {
        cin >> a[i];
    }
    
    sort (a+1, a+1+7);

    printf("%lld %lld %lld\n",a[1],a[2],a[7]-a[1]-a[2]);

    return 0;
}
