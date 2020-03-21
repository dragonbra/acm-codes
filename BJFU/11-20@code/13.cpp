#include <bits/stdc++.h>
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
    string no0;
    string name0;
    float price0;
    while(cin>>no0>>name0>>price0)
    {
        if(no0=="0"&&name0=="0"&&price0==0.0)
            break;                  
        else
        {
            LinkList q=new LNode; 
            q->data.no=no0;        
            q->data.name=name0;   
            q->data.price=price0; 
            q->next=NULL;         
            p->next=q;           
            p=q;            
        }
    }
    return OK;                      
}

int  Length_L(LinkList &L)      
{    
    LinkList p=L;               
    L->length=0;                    
    while(p->next)                
    {
        L->length++;              
        p=p->next;                
    }
    return OK;                             
}

int Avg_Revise_L(LinkList &L) 
{
    LinkList p=L->next;   
    float sum=0;   		
    float avg_price;    	
    while(p)      		
    {
        sum+=p->data.price; 
        p=p->next;     		
    }
    avg_price=sum/L->length;  	
    cout<<fixed<<setprecision(2)<<avg_price<<endl; 
    p=L->next;     		
    while(p)      		
    {
        if(p->data.price<avg_price) 
            p->data.price=p->data.price*1.2;
        else
            p->data.price=p->data.price*1.1;
        p=p->next;     		
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
    Length_L(L);              
    Avg_Revise_L(L);        
    Output_L(L);              
    return 0;                
}