#include<iostream>
using namespace std;          
typedef struct LNode
{
    int data;
    struct LNode *next;
}LNode,*LinkList;
void InitList(LinkList &L)            
{
    L=new LNode;            
    L->next=NULL;
}
int Max(LinkList L)
{
    int max=L->next->data;		
    LinkList p=L->next->next;		
    while(p)                		
    {
        if(max<p->data)    
            max=p->data;
        p=p->next;
    }    
    return max;
}
void Input(LinkList &L)           	
{
    LinkList p=L;                    	
    int n;                        	
    while(cin>>n&&n!=0)            	
    {    
        p = L;
        while(n--)                	
        {
            LinkList q=new LNode;       
            cin>>q->data;            	
            q->next=NULL;            	
            p->next=q;            	
            p=q;            		
        }
        cout<<Max(L)<<endl;         	
    }        
}        
int main()
{
    LinkList L;           		
    InitList(L);         		
    Input(L);            		
    return 0;                
}