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
    int length;         
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
    LinkList p=L;                   
    int n;
    cin>>n;                    
    while(n--)             	     
    {
        LinkList q=new LNode;        
        cin>>q->data.no>>q->data.name>>q->data.price;
        q->next=NULL;                                 
        p->next=q;                  
        p=q;                        
    }
    return OK;                   
}    

int Max_L(LinkList L)               
{
    LinkList p=L->next;              
    int max=p->data.price;          
    int count=0;		   
    while(p->next)                
    {
        if(max<p->next->data.price)    
            max=p->next->data.price; 
        p=p->next;                  
    }
    p=L->next;                    
    while(p)                         
    {
        if(p->data.price==max)      
            count++;                
        p=p->next;                 
    }
    cout<<count<<endl;               
    p=L->next;                     
    while(p)                         
    {
        if(p->data.price==max)     
            cout<<p->data.no<<" "<<p->data.name<<" "<<fixed<<setprecision(2)<<p->data.price<<endl;     
        p=p->next;                  
    }
    return OK;
}

int main()
{
    LinkList L;                    
    InitList_L(L);                   
    Input_L(L);                     
    Max_L(L);                       
    return 0;                
}