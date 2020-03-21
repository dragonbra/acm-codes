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

int Favorite_book_L(LinkList &L1)    	
{
    int n;
    cin>>n;                           
    LinkList L2=new LNode;            	
    LinkList p,q=L2;                	
    for(int i=0;i<n;i++)            	
    {
        LinkList s=new LNode;        	
        cin>>s->data.name;            	
        s->next=NULL;                
        q->next=s;                   
        q=s;                        
    }
    q=L2->next;                       
    while(q)                        
    {
        int count=0;                
        int flag=0;                     
        p=L1->next;                    
        while(p)                 
        {
            if(q->data.name==p->data.name)
            {    
                flag=1;                
                count++;            
            }
            p=p->next;                
        }
        if(flag==0)                 
            cout<<"Sorry，there is no your favourite!"<<endl;    
        else                        	
        {
            cout<<count<<endl;        	
            p=L1->next;                	
            while(p)                	
            {
                if(q->data.name==p->data.name)
                    cout<<p->data.no<<" "<<p->data.name<<" "<<fixed<<setprecision(2)<<p->data.price<<endl;     
                p=p->next;            	
            }
        }
        q=q->next;                    	
    }
    return OK;
}

int main()
{
    LinkList L;                         
    InitList_L(L);                    
    Input_L(L);                        	
    Favorite_book_L(L);                
    return 0;                
}