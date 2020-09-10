/*
* @ author: dragon_bra
* @ email: tommy514@foxmail.com
* @ data: 2020-09-10 11:30
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

#define N 10

int sx = 0, sy = 0, ex = 9, ey = 9;
char mp[15][15] = {
    "....###..#",
    "###.##..##",
    "#.#....###",
    "#...##.###",
    "####...###",
    "#....#####",
    "#.#.####.#",
    "#.#....###",
    "#..###.###",
    "##.###....",
    ""
};
char ans[15][15];
// 起点是左上角，终点是右下角，#代表障碍物，.代表路，10*10

int dir[4][2] = {
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0}
};

struct Point {
    int x, y, step;
    Point(){}
    Point(int x, int y, int s):x(x), y(y), step(s){}
} path[110]; // 将搜索到的路径存储在path数组中
int ansStep;
bool flag = false; // 是否找到终点的路
bool vis[15][15] = {0};

void printAns(bool flag) {
    // 输出答案的结果
    if (flag) {
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                // 更新地图后输出
                ans[i][j] = mp[i][j];
            }
        }
        for (int i=0; i<=ansStep; i++) {
            ans[path[i].x][path[i].y] = '-';
        }
        for (int i=0; i<N; i++) {
            cout << ans[i] << endl;
        }
    } else {
        cout << "Didn't find a path!" << endl;
    }
}

void stackSearch() {
    // 使用栈搜索的走迷宫路线
    stack<Point> S;
    memset(vis, 0, sizeof vis); flag = false;

    S.push(Point(sx, sy, 0)); vis[sx][sy] = true;
    while (!S.empty()) {
        Point now = S.top(); S.pop(); path[now.step] = now;
        if (now.x == ex && now.y == ey) {
            flag = true;
            ansStep = now.step;
            break;
        }
        int x = now.x, y = now.y, s = now.step;

        for (int i=0; i<4; i++) {
            int tx = x + dir[i][0], ty = y + dir[i][1];
            if (tx >= 0 && tx < N && ty >= 0 && ty < N && !vis[tx][ty] && mp[tx][ty] != '#') {
                S.push(Point(tx, ty, s + 1));
                vis[tx][ty] = true;
            }
        }
    }

    printAns(flag);
}

void queueSearch() {
    // 使用队列搜索的走迷宫路线
    queue<Point> Q;
    memset(vis, 0, sizeof vis); flag = false;

    Q.push(Point(sx, sy, 0)); vis[sx][sy] = true;
    while (!Q.empty()) {
        Point now = Q.front(); Q.pop(); path[now.step] = now;
        if (now.x == ex && now.y == ey) {
            flag = true;
            ansStep = now.step;
            break;
        }
        int x = now.x, y = now.y, s = now.step;

        for (int i=0; i<4; i++) {
            int tx = x + dir[i][0], ty = y + dir[i][1];
            if (tx >= 0 && tx < N && ty >= 0 && ty < N && !vis[tx][ty] && mp[tx][ty] != '#') {
                Q.push(Point(tx, ty, s + 1));
                vis[tx][ty] = true;
            }
        }
    }

    printAns(flag);
}

void choose() {
    int x = 0;
    while (x > 9 || x < 1) {
        cin >> x;
    }

    if (x == 1) {
        // 选择了输出迷宫地图
        cout << endl;
        for (int i=0; i<N; i++) {
            cout << mp[i] << endl;
        } cout << endl;
    } else if (x == 2) {
        // 使用栈搜索迷宫路线
        stackSearch();
    } else if (x == 3) {
        // 使用队列搜索迷宫路线
        queueSearch();
    } else if (x == 4) {
        exit(1);
    }
}

void printMenu() {
    printf("---------------------------------------------\n");
    printf("|       欢迎使用走迷宫（栈/队列）小程序           \n");
    printf("|       输入以选择：                           \n");
    printf("|       1. 输出迷宫地图                        \n");
    printf("|       2. 使用栈走迷宫                        \n");
    printf("|       3. 使用队列走迷宫                      \n");
    printf("|       4. 退出                               \n");
    printf("---------------------------------------------\n");

    choose();
}

int main() {
    while (true) {
        printMenu();
    }
}