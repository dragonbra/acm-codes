/*
* @ author: dragon_bra
* @ email: tommy514@foxmail.com
* @ data: 2020-09-09 19:31
*/

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

const int N = 2e5 + 10;
int nxt[N];
string p, t;
// 模式串pattern，文本串text

int pos, mx=-1; // 最长公共子串开始位置和最大长度

void makeNext(string s) {
    // 计算pattern串的next数组
    int i = 0, k = -1;
    nxt[0] = -1;
    int len = s.length();
    while (i < len-1) {
        while (k >= 0 && s[i] != s[k]) k = nxt[k];
        i ++; k ++;
        if (s[i] == s[k]) nxt[i] = nxt[k];
        else nxt[i] = k;
    }
}

void kmpMatch(string t, string p) {
    // 运行kmp算法，并同时记录下最长的匹配长度和起始位置（最长公共子串）
    int i = 0, j = 0;
    int len1 = t.length(), len2 = p.length();
    while (i < len1 && j < len2) {
        if (i == -1 || p[i] == t[j]) {
            i ++; j ++;
        } else {
            if (i-1 > mx) {
                // 大于已有长度，更新
                mx = i;
                pos = j - mx;
            }
            i = nxt[i];
        }
    }
    if (i >= len2-1) {
        mx = len2;
        pos = j - mx + 1;
    }
}

void choose() {
    int x = 0;
    while (x > 9 || x < 1) {
        cin >> x;
    }

    if (x == 1) {
        // 选择输入字符串-1
        cout << "请输入字符串-1：" << endl;
        cin >> t;

        cout << endl;
        cout << "输入成功！" << endl;
        cout << endl;
    } else if (x == 2) {
        // 选择输入字符串-2
        cout << "请输入字符串-2：" << endl;
        cin >> p;

        cout << endl;
        cout << "输入成功！" << endl;
        cout << endl;
    } else if (x == 3) {
        // 运行匹配算法，并输出结果
        makeNext(p);
        kmpMatch(t,p);
        cout << "最长公共子串为：" << t.substr(pos, mx) << endl;
        pos = 0; mx = -1;
    } else if (x == 4) {
        exit(1);
    }
}

void printMenu() {
    printf("---------------------------------------------\n");
    printf("|       欢迎使用求最长公共子串工具                \n");
    printf("|       输入以选择：                           \n");
    printf("|       1. 输入字符串-1                        \n");
    printf("|       2. 输入字符串-2                        \n");
    printf("|       3. 输出最长公共子串                     \n");
    printf("|       4. 退出                              \n");
    printf("---------------------------------------------\n");

    choose();
}

int main() {
    while (true) {
        printMenu();
    }
}