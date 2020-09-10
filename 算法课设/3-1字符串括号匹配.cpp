/*
* @ author: dragon_bra
* @ email: tommy514@foxmail.com
* @ data: 2020-09-09 20:02
*/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <stack>
#include <map>
#include <set>
#include <queue>
#include <vector>

using namespace std;

string leftparenthese = "([{<";//保存左括号列表
string rightparenthese = ")]}>";//保存右括号列表
stack<char> parenthese;
string str;

void doBracketMatch() {
    int flag = -1;
    for (int i = 0; i < str.length(); i++) {
        if (leftparenthese.find(str[i]) != string::npos)//左括号直接入栈
            parenthese.push(str[i]);
        else if (rightparenthese.find(str[i]) != string::npos) { //如果遇到右括号
            //检查是否与栈顶栈顶符号匹配
            if (!parenthese.empty() && leftparenthese.find(parenthese.top()) == rightparenthese.find(str[i]))
                parenthese.pop();//如果匹配则删除栈顶符号
            else { //不匹配则标记并退出循序 
                flag = i;
                break;
            }
        }
    }
    //根据比较结果判定是否匹配
    cout << endl;
    if (!parenthese.empty() || flag >= 0) cout << "括号序列不匹配！" << endl;
    else cout << "括号序列完成匹配！" << endl;
    cout << endl;
}

void choose() {
    int x = 0;
    while (x > 9 || x < 1) {
        cin >> x;
    }

    if (x == 1) {
        cout << "请输入字符串：" << endl;
        cin >> str;
    } else if (x == 2) {
        doBracketMatch();
    } else if (x == 3) {
        exit(1);
    }
}

void printMenu() {
    printf("---------------------------------------------\n");
    printf("|       欢迎使用检查括号匹配（栈）工具            \n");
    printf("|       输入以选择：                           \n");
    printf("|       1. 输入字符串                          \n");
    printf("|       2. 检查括号是否匹配                      \n");
    printf("|       3. 退出                               \n");
    printf("---------------------------------------------\n");

    choose();
}

int main() {
    while (true) {
        printMenu();
    }
}