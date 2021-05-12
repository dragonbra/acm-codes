/*
    金明的预算方案
    https://www.acwing.com/problem/content/489/
*/
#include <iostream>
#include <algorithm>
#include <vector>

#define fastio ios::sync_with_stdio(false); cin.tie(NULL);
#define v first
#define w second

using namespace std;

typedef pair<int, int> PII;

const int N = 60 + 10;
const int M = 32000 + 10;

int n, m;
PII master[N];
vector<PII> servent[N];
int f[M];

int main() {
    fastio;
    cin >> m >> n;
    for (int i = 1; i <= n; i ++ ) {
        int v, w, q;
        cin >> v >> w >> q;
        if (!q) master[i] = {v, v * w};
        else servent[q].push_back({v, v * w});
    }
    
    for (int i = 1; i <= n; i ++ ) {
        if (master[i].v) {
            auto &sv = servent[i];
            for (int j = m; j >= 0; j -- ) {
                // 很快的二进制枚举方案
                // here !!!
                for (int k = 0; k < 1 << sv.size(); k ++ ) {
                    int v = master[i].v, w = master[i].w;
                    for (int u = 0; u < sv.size(); u ++ ) {
                        if (k >> u & 1) {
                            v += sv[u].v;
                            w += sv[u].w;
                        }
                    }
                    if (j >= v) f[j] = max(f[j], f[j - v] + w);
                }
            }
        }
    }
    
    cout << f[m] << endl;
    
    return 0;
}