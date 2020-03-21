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

int Length_L(LinkList &L)            	
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

int Delete_same_L(LinkList &L)        	
{
    LinkList p=L->next;                	
    while(p)                        	
    {
        LinkList q=p;                	
        while(q->next)                	
        {
            if(q->next->data.no==p->data.no)
            {
                LinkList s=q->next;    	
                q->next=q->next->next;
                delete s;            	
            }
            else
                q=q->next;            	
        }
        p=p->next;    			
    }
    return OK;
}

int Output_L(LinkList L)  
{
    Length_L(L);  
    cout<<L->length<<endl;
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
    Delete_same_L(L);                   
    Output_L(L);                        
    return 0;                
}