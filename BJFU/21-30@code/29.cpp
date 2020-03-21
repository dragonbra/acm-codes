#include<iostream>
#include<string>
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
void Input(LinkList &L,int n)    	
{
    LinkList p=L;                	
    while(n--)                    	
    {
        LinkList q=new LNode;    	
        cin>>q->data;            	
        q->next=NULL;            	
        p->next=q;                	
        p=q;                    	
    }
}
void Delete(LinkList &L)        	
{
    int min,max;
    cin>>min>>max;                	
    LinkList p=L;                	
    while(p->next)                	
    {
        if(min<=p->next->data&&p->next->data<=max)
        {
            LinkList q=p->next;        	
            p->next=p->next->next;    	
            delete(q);                	
        }
        else
            p=p->next;                	
    }
}
void Output(LinkList L)                
{
    LinkList p=L->next;                	
    while(p->next)                    	
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<p->data<<endl;            	
}
int main()
{
    int n;
    while(cin>>n&&n!=0)
    {
        LinkList L;                	
        InitList(L);            	
        Input(L,n);                	
        Delete(L);                	
        Output(L);                	
    }
    return 0;
}