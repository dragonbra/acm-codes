#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXSIZE 1010     

void redirect() {
    #ifdef LOCAL
        freopen("1.in","r",stdin);
        freopen("1.out","w",stdout);
    #endif
}

typedef struct
{
    string no;                      
    string name;                    	
    float price;                    	
} Book;

typedef struct LNode
{
    int length;                          
    Book data;                        
    struct LNode *next;             
} LNode,*LinkList;

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

int Locate_L(LinkList L)            	
{
    int n;        
    cin>>n;
    int i,a[100];       
    i=1;                            	            
    while(i<=n)                        
    {
        cin>>a[i];
        LinkList p=L;             	
        if(1<=a[i]&&a[i]<=L->length)	
        {
            for(int j=1;j<=a[i];j++) p = p->next;
            cout<<p->data.no<<" "<<p->data.name<<" "<<fixed<<setprecision(2)<<p->data.price<<endl; 
        }
        else
            puts("Sorry，the book on the best position doesn't exist!");
        i++;                        	
    }
    return OK;
}

int main()
{
    redirect();
    LinkList L;                         
    InitList_L(L);                   	
    Input_L(L);      
    Length_L(L);                
    Locate_L(L);                    
    return 0;                
}