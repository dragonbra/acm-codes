
// Problem: P3805 【模板】manacher算法
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3805
// Memory Limit: 512 MB
// Time Limit: 500 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

/*
  @ author: dragon_bra
  @ QQ: 1277037638
  @ email: tommy514@foxmail.com
*/

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
using namespace std;

typedef long long ll;
const int N = 1e7 + 1e6 + 10;

int n, len = 0, ans = 0;
int f[N << 1];
char tmp[N], s[N << 1];

void init() { // 倍长原字符串 
	scanf("%s", tmp + 1), n = strlen(tmp + 1);
	s[0] = '%' /*防止超出边界*/;
	for(int i = 1; i <= n; ++i) {
		s[++len] = '#';
		s[++len] = tmp[i];
	}
        s[++len] = '#', s[len + 1] = '$' /*防止超出边界*/ ;
	/* %#l#g#y#o#r#z#$ */
	return;
}

void manacher() {
	int r = 0, mid = 0;
	for(int i = 1; i <= len; ++i) {
		// 得到当前位置回文半径 
		if(i <= r) 	f[i] = min(f[(mid << 1) - i], r - i);
		// 扩大回文半径 
		while(s[i + f[i] + 1] == s[i - f[i] - 1]) ++f[i];
		// 更新右端点 
		if(f[i] + i > r) r = i + f[i], mid = i;
		// 更新答案...  倍长后发现答案就是回文半径 感性理解 
		if(f[i] > ans) ans = f[i];
	}
	return;
}

int main() {
	
	init();
	manacher();
	
	cout << ans << endl;

    return 0;
}
