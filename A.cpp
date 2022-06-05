#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

int n, m;
int sorted[N], a[N];
bool vis[N];

int main() {

    unordered_map<int, int> idx; 
    // 存储排序后的数字和其在数组中的位置
    // idx[x] 表示 x 这个数字在排序后的数组中的位置
    vector<int> ans; // 存储答案

    cin >> n ;

    for (int i = 1; i <= n; i++) {
        cin >> sorted[i];
        idx[sorted[i]] = i;
    }

    cin >> m ;

    for (int i = 1; i <= m; i++) {
        cin >> a[i];
        // idx[a[i]]可以找到a[i]在排序后的数组中的位置，把对应位置标记为存在，后续存入结果数组
        vis[idx[a[i]]] = true;
    }

    for (int i = 1; i <= n; i ++ ) {
        if (vis[i]) {
            // 如果该位置标记为存在，则把该数字存入结果数组
            ans.push_back(sorted[i]);
        }
    }

    for (auto x : ans) {
        // 输出结果
        cout << x << ' ';
    }

    return 0;
}