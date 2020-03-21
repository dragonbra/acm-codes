#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXSIZE 1000        

typedef struct
{
    string no;                     
    string name;                  
    float price;                  
}Book;

typedef struct LNode
{
    Book data;                   
    struct LNode *next;         
}LNode,*LinkList;

int InitList_L(LinkList &L)        
{
    L=new LNode;
    L->next=NULL;
    return OK;
}

int Input_L(LinkList &L)            
{    
    int n;
    cin>>n;
    while(n--)            	 
    { 
        LinkList p=new LNode;      
           cin>>p->data.no>>p->data.name>>p->data.price;
        p->next=L->next;           
        L->next=p;                  
     } 
    return OK;
}

int Output_L(LinkList L)  
{
    LinkList p=L;                  
    while(p->next)                
    {
        cout<<p->next->data.no<<" "<<p->next->data.name<<" "<<fixed<<setprecision(2)<<p->next->data.price<<endl;     
        p=p->next;    
    }
    return OK;
}

int main()
{
    LinkList L;                    
    InitList_L(L);                  
    Input_L(L);                       
    Output_L(L);                      
    return 0;                
}
