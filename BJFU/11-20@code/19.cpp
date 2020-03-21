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

int Delete_L(LinkList &L)               
{
    LinkList p=L;                       
    int n;                              
    cin>>n;
    if(1<=n&&n<=L->length)              
    {                      
        n--;                            
        while(n--)                      
            p=p->next;                  
        LinkList s=p->next;             
        p->next=p->next->next;        
        delete s;                      
        p=L->next;                 
        while(p)                        
        {
            cout<<p->data.no<<" "<<p->data.name<<" "<<fixed<<setprecision(2)<<p->data.price<<endl; 
            p=p->next;                 
        }
    }
    else                             
        cout<<"Sorry，the position to be deleted is invalid!"<<endl;  
    return OK;
}

int main()
{
    LinkList L;                         
    InitList_L(L);                   
    Input_L(L);                     
    Length_L(L);                      
    Delete_L(L);                       
    return 0;                
}