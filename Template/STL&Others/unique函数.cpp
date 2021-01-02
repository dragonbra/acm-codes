/*
* @ author: dragon_bra
* @ email: tommy514@foxmail.com
* @ date: 2021-01-02 11:00
*/

// 去除的是相邻元素，所以需要先sort
// unique函数是 <= O(n)的

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e6;

void redirect() {
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
}

vector< pair<int, int> > G;

int main() {
    redirect();

    clock_t start, end;
    start = clock();

    for (int i=1; i<=N; i++) G.push_back(make_pair(rand()%10, rand()%10));
    sort(G.begin(), G.end());
    G.erase(unique(G.begin(), G.end()), G.end());
    cout << unique(G.begin(), G.end()) - G.begin() << "\n";
    cout << G.size() << "\n";

    end = clock();

    cout << (double) (end - start) / CLOCKS_PER_SEC * 1000 << "ms\n";

    for (int i=0; i<100; i++) {
        cout << G[i].first << ", " << G[i].second << "\n";
    }

    return 0;
}