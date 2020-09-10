/*
* @ author: dragon_bra
* @ email: tommy514@foxmail.com
* @ data: 2020-09-10 12:08
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

struct ThrTreeNode;
typedef struct ThrTreeNode *PThrTreeNode;
struct ThrTreeNode {
    int info;
    PThrTreeNode llink, rlink;
    int ltag, rtag;
};
typedef struct ThrTreeNode *ThrTree;
typedef ThrTree *PThrTree;

PThrTree T; int cnt = 0; // 节点数

PThrTree createEmptyTree(void) {
    PThrTree T = (PThrTree) malloc(sizeof(PThrTree));
    if (T == NULL) {
        cout << "Out of space!" << endl; // 空间不足
    }
    return T;
}

// 查找 
int search(PThrTree ptree, int key, PThrTreeNode * position){
	PThrTreeNode p, q;
	p = *ptree;
	q = p; // 记录可能的插入点 
	while(p != NULL){
		q = p;
		if(p->info == key){ // 找到key
			*position = p;
			return 1;
		}else if(p->info > key){ // 去左子树 
			p = p->llink;
		}else { // 去右子树 
			p = p->rlink;
		}
	}
	*position = q;
	return 0;
}

// 插入值为key的结点 
int insert(PThrTree ptree, int key){
	PThrTreeNode p, position;
	if(search(ptree, key, &position) == 1){ // 已经找到了key，不需插入 
		return 1;
	}
	p = (PThrTreeNode)malloc(sizeof(struct ThrTreeNode));
	if(p == NULL){
		cout<<"插入失败！"<<endl; 
		return 0;
	}
	p->info = key;
	p->llink = NULL;
	p->rlink = NULL;
	if(position == NULL){
		*ptree = p;
	}else if(key < position->info){ // 插入左边 
		position->ltag = 0; 
		position->llink = p;
	}else { // 插入右边 
		position->rtag = 0;
		position->rlink = p;
	}
	return 1;
}

void thread(ThrTree T) {
    stack<ThrTree> S;

    ThrTree p, pr;
    if (T == NULL) return;
    p = T; pr = NULL;
    do {
        while (p != NULL) { S.push(p); p = p->llink; }
                // 遇到节点推入栈中，然后进入其左子树
        p = S.top(); S.pop();
        if (pr != NULL) {
            if (pr -> rlink == NULL) { pr -> rlink = p; pr -> rtag = 1; }
                // 修改前驱节点的右指针
            if (p -> llink == NULL) { p -> llink = pr; p -> ltag = 1; }
                // 修改该节点的左指针
        }
        pr = p; p = p -> rlink; // 进入右子树
    } while (!S.empty() || p!=NULL);
}

void visit( ThrTree p ) {
    cout << p->info << ' ';
}

void nInOrder(ThrTree t) {
    cout << endl;
    cout << "二叉树的中序遍历为：" << endl;
    ThrTree p = t;
    if (t == NULL) return;
    while (p -> llink != NULL && p -> ltag == 0) { p = p -> llink; }// 顺左子树一直向下
    while (p != NULL) {
        cout << p -> info << ' ';
        if (p -> rlink != NULL && p -> rtag == 0) { // 右子树不是线索时
            p = p -> rlink;
            while (p -> llink != NULL && p -> ltag == 0) p = p -> llink; // 顺右子树的左子树一直向下
        }
        else p = p -> rlink;
    }
    cout << endl;
    cout << endl;
}

void choose() {
    int x = 0;
    while (x > 9 || x < 1) {
        cin >> x;
    }

    if (x == 1) {
        cout << "请输入要插入的新节点数据：" << endl;
        int t; cin >> t;
        insert(T, t);
    } else if (x == 2) {
        //visit(T);
        thread(*T);
        nInOrder(*T);
        cout << endl << endl;
    } else if (x == 3) {
        exit(1);
    }
}

void printMenu() {
    printf("---------------------------------------------\n");
    printf("|       欢迎使用线索二叉树实验小程序             \n");
    printf("|       输入以选择：                           \n");
    printf("|       1. 插入新节点                          \n");
    printf("|       2. 输出节点信息（中序遍历）              \n");
    printf("|       3. 退出                               \n");
    printf("---------------------------------------------\n");

    choose();
}

void init() {
    T = createEmptyTree();
}

int main() {
    init();
    while (true) {
        printMenu();
    }
}