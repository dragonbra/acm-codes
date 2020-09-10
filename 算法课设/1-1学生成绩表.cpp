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

struct Student{
    string name;
    int Chinese, Math, English;
    Student(){}//无参构造函数
    Student(string name, int c, int m, int e) {
        //带参构造函数
        this->name = name;
        this->Chinese = c;
        this->Math = m;
        this->English = e;
    }
    string outputInfo() {
        // 输出学生信息的字符串
        string res = "学生姓名：" + name + "\n";
        res += "语文：" + to_string(Chinese) + "，数学：" + to_string(Math) + "，英语：" + to_string(English) + "\n";
        return res; 
    }
};

struct Node;
typedef struct Node *PNode;
struct Node {
    Student info;
    PNode link;
};
typedef struct Node *LinkList;
LinkList llist;

LinkList createNullList_link(void) {
    // 创建空单链表
    LinkList llist = (LinkList)malloc(sizeof(struct Node));

    if (llist != NULL) llist->link = NULL;
    else cout << "Out of space!" << endl;
    return llist;
}

bool is_NullList_link(LinkList llist) {
    // 判断单链表是否为空
    return (llist -> link == NULL);
}

int insertAtTail_link(LinkList, Student stu) {
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
        q->info = stu;
        q->link = p->link;
        p->link = q;
        return 1; // 插入成功
    }
}

bool deleteV_link(LinkList llist, string name) {
    // 删除单链表中姓名为name的学生信息
    PNode p, q;
    p = llist;
    if (p == NULL) return 0;
    while (p->link!=NULL && p->link->info.name != name) {
        p = p->link;
    }

    if (p->link == NULL) {
        cout << "Not Exist!" << endl;
        return 0;
    } else {
        q = p->link;
        p->link = q->link;
        free(q);
        return 1;
    }
}

void printList_link(LinkList llist) {
    // 输出单链表内所有学生信息
    PNode p;
    p = llist->link;
    if (p == NULL) return;
    while (p!=NULL) {
        cout << p->info.outputInfo() << endl;
        p = p->link;
    }
    return;
}

void choose() {
    int x = 0;
    while (x > 9 || x < 1) {
        cin >> x;
    }

    if (x == 1) {
        // 选择插入学生信息
        cout << "请输入学生姓名：" << endl;
        string name; int c, m, e;
        cin >> name;
        cout << "请输入学生的语文、数学、英语成绩（空格分开）：" << endl;
        cin >> c >> m >> e;
        
        Student stu = Student(name, c, m, e);
        insertAtTail_link(llist, stu);

        cout << endl;
        cout << "学生信息添加成功！" << endl;
        cout << endl;
    } else if (x == 2) {
        // 选择删除学生信息
        cout << "请输入学生姓名：" << endl;
        string name;
        cin >> name;

        bool del = deleteV_link(llist, name);
        if (del) {
            cout << endl;
            cout << "删除成功！" << endl;
            cout << endl;
        }
    } else if (x == 3) {
        // 输出全部学生信息
        printList_link(llist);
    } else if (x == 4) {
        exit(1);
    }
}

void printMenu() {
    printf("---------------------------------------------\n");
    printf("|       欢迎使用单链表学生成绩表                 \n");
    printf("|       输入以选择：                           \n");
    printf("|       1. 添加学生                           \n");
    printf("|       2. 删除学生                           \n");
    printf("|       3. 输出学生信息                        \n");
    printf("|       4. 退出                              \n");
    printf("---------------------------------------------\n");

    choose();
}

void init() {
    // 初始化
    llist = createNullList_link();
}

int main() {
    init();
    while (true) {
        printMenu();
    }
    return 0;
}