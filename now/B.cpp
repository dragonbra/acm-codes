#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <vector>

using namespace std;

const int N = 1e5 + 10;

int n, k;
// int dp[N][N];
map<int, int> dp[N];

int dfs(int n, int k) {
    if(n < 1 || k < 1) return 0;
    if(n == 1 || k == 1){
		dp[n][k]=1;
        return 1;
    } if(n < k) {
		dp[n][n]=dp[n][n]? dp[n][n] : dfs(n, n);
		return dp[n][n];
    } if(n == k) {
		dp[n][k]=dp[n][n-1]?1+dp[n][n-1]:1 + dfs(n, n - 1);
		return dp[n][k];
    } else {
		dp[n][k]=dp[n - k][k]? (dp[n - k][k]) : dfs(n - k, k);
		dp[n][k]+=dp[n][k-1]? (dp[n][k-1]): dfs(n, k - 1);	
        return dp[n][k];
    }
}

int main() {

    cin >> n >> k;
    dp[n][n] = dfs(n, n);
    cout << dp[n][k] << endl;

    return 0;
}