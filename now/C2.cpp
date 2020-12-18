#include <bits/stdc++.h>
using namespace std;

const int INF = 2e9;
struct ts {
    char to;
    int x, y, time;
} a[105];
struct node{
    int a,b,time;
}nod[105*105];
bool cmp(node a,node b){
    return a.time<b.time;
}
int n;
int cnt=0;
int main() {

    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> a[i].to >> a[i].x >> a[i].y;
        a[i].ans = INF;
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            int u = i, v = j;
            if (a[u].to == a[v].to) continue;
            if(a[u].to=='N'&&a[u].y>a[v].y)continue;
            if(a[u],to=='E'&&a[v].x>a[u].x)continue;
            nod[cnt].a=u;
            nod[cnt].b=v;
            if(a[u].to=='N'){
                nod[cnt]=min(a[u].)
            }
        }
    }

    for (int i=1; i<=n; i++) {
        if (a[i].ans == INF) puts("Infinity");
        else cout << a[i].ans << endl;
    }

    return 0;
}