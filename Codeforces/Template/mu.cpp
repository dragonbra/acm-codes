#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <vector>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
const double eps = 1e-5;
const int N = 1e5 + 5;

#define LOCAL
void redirect() {
    #ifdef LOCAL
        freopen("1.in","r",stdin);
        freopen("1.out","w",stdout);
    #endif
}

inline ll read() {
    ll f=1,x=0;char ch;
    do {ch=getchar(); if(ch=='-') f=-1;} while (ch<'0'||ch>'9');
    do {x=x*10+ch-'0'; ch=getchar(); } while (ch>='0'&&ch<='9');
    return x*f;
}

struct Car{
    char color[30], type[30], plateNumber[30], driverName[30];
    struct Car * next;
};

struct Car *add( struct Car *head, struct Car *p ){
    p->next = head;
    head = p;
    return head;
}

struct Car *search(struct Car *head, char *p){
    while(head!=NULL){
        if(strcmp(head->driverName,p)==0||strcmp(head->plateNumber,p)==0) return head;
        head = head->next;
    }
    return head;
}

void f(float* , float);

int main() {
    redirect();
    
    float a[10],b=1;
    f(a,b);

    return 0;
}

void f(float a[],float b){
    
}

/*
-----------------
author:dragon_bra
-----------------
*/