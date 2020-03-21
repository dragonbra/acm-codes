

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
void Locate(LinkList L)            	
{
    LinkList L1=L;                	
    LinkList L2=L;                	
    int k;
    cin>>k;
    while(k--)                    	
        L1=L1->next;            
    while(L1)                    	
    {
        L1=L1->next;            	
        L2=L2->next;            	
    }
    cout<<L2->data<<endl;        	
}
int main()
{
    int n;
    while(cin>>n&&n!=0)
    {
        LinkList L;                	
        InitList(L);            	
        Input(L,n);                	
        Locate(L);                	
    }
    return 0;
}