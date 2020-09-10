/*
* @ author: dragon_bra
* @ email: tommy514@foxmail.com
* @ data: 2020-09-09 16:57
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

struct Node;
typedef struct Node *PNode;
struct Node {
    int constant; // 每项系数
    PNode link;
};
typedef struct Node *LinkList;
LinkList llist1, llist2, ans;

LinkList createNullList_link(void) {
    // 创建空单链表
    LinkList llist = (LinkList)malloc(sizeof(struct Node));

    if (llist != NULL) llist->link = NULL;
    else cout << "Out of space!" << endl;
    return llist;
}

bool is_NullList_link(LinkList llist) {
    // 判断是否为空
    return (llist -> link == NULL);
}

int insertAtTail_link(LinkList llist, int cons) {
    // 在单链表的结尾处插入新节点
    PNode p = llist;
    while (p->link!=NULL) {
        p = p->link;
    }

    PNode q = (PNode)malloc(sizeof(struct Node));
    if (q == NULL) {
        cout << "Out of space!" << endl;
        return 0;
    } else {
        q->constant = cons;
        q->link = p->link;
        p->link = q;
        return 1; // 插入成功
    }
}

void printList_link(LinkList llist) {
    // 输出两个多项式求和信息
    PNode p;
    p = llist->link;
    if (p == NULL) return;
    
    int times = 0;
    while (p!=NULL) {
        if (times != 0) cout << " + ";
        cout << p->constant << "x^" << times;
        p = p->link; times ++; // 指数+1
    }
    cout << endl;
    return;
}

void calAnswer(LinkList a, LinkList b, LinkList ans) {
    // 计算多项式相加结果
    a = a->link; b = b->link;
    while (a != NULL || b != NULL) {
        PNode q = (PNode)malloc(sizeof(struct Node));
        int cons = 0;
        // 如果不为0则继续相加
        if (a != NULL) {cons += a->constant; a = a->link;}
        if (b != NULL) {cons += b->constant; b = b->link;}
        q->constant = cons;
        ans->link = q;
        ans = ans->link;
    }
}

void choose() {
    int x = 0;
    while (x > 9 || x < 1) {
        cin >> x;
    }

    if (x == 1) {
        // 选择修改多项式-1的值
        cout << "多项式最高项次数是？" << endl;
        int n = 0;
        cin >> n;
        llist1 = createNullList_link();
        for (int i=0; i<=n; i++) {
            if (i == 0) cout << "请输入常数项" << endl;
            else cout << "x^" << i << "项的系数是？" << endl;
            int t; cin >> t;
            insertAtTail_link(llist1, t);
        }
    } else if (x == 2) {
        // 选择修改多项式-2的值
        cout << "多项式最高项次数是？" << endl;
        int n = 0;
        cin >> n;
        llist2 = createNullList_link();
        for (int i=0; i<=n; i++) {
            if (i == 0) cout << "请输入常数项" << endl;
            else cout << "x^" << i << "项的系数是？" << endl;
            int t; cin >> t;
            insertAtTail_link(llist2, t);
        }
    } else if (x == 3) {
        // 计算多项式的和并输出
        calAnswer(llist1, llist2, ans);
        printList_link(ans);
    } else if (x == 4) {
        exit(1);
    }
}

void printMenu() {
    printf("---------------------------------------------\n");
    printf("|       欢迎使用多项式求和工具                  \n");
    printf("|       输入以选择：                           \n");
    printf("|       1. 修改多项式-1                        \n");
    printf("|       2. 修改多项式-2                        \n");
    printf("|       3. 输出多项式之和                       \n");
    printf("|       4. 退出                              \n");
    printf("---------------------------------------------\n");

    choose();
}

void init() {
    llist1 = createNullList_link();
    llist2 = createNullList_link();
    ans = createNullList_link();
}

int main() {
    init();
    while (true) {
        printMenu();
    }
    return 0;
}