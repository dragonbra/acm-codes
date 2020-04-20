#include <bits/stdc++.h>
using namespace std;

struct node {
    string date, no;
    double temp;
} a[100005];

bool cmp(node a, node b) {
    if(a.date!=b.date) return a.date>b.date;
    if(a.temp!=b.temp) return a.temp>b.temp;
    return a.no<b.no;
}

int n;

int main() {
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i].date>>a[i].no>>a[i].temp;

    sort(a+1,a+n+1,cmp);

    int m =0;
    for(int i=1;i<=n;i++) {
        if(a[i].temp>=38) m++;
    }

    cout<<m<<endl;
    for(int i=1;i<=n;i++) {
        if(a[i].temp>=38) {
            cout<<a[i].date<<' '<<a[i].no<<' ';
            printf("%.1lf\n",a[i].temp);
        }
    }

    return 0;
}
