#include<iostream>
using namespace std;
#define MAX 100
#define OK 0
#define OVERFLOW -1
#define ERROR -2

typedef struct
{
	int *base;
	int front;
  	int rear;
  	int tag;
}SqQueue;

int InitQueue(SqQueue &Q)
{
	Q.base=new int[MAX];
	if(!Q.base) return OVERFLOW;
	Q.front=Q.rear=Q.tag=0;
	return OK;
}	

int EnQueue(SqQueue& Q,int e)
{
	if(Q.tag==1&&Q.front==Q.rear)
		return ERROR;
	Q.base[Q.rear]=e;
	Q.rear=(Q.rear+1)%MAX;
	if(Q.tag==0)
		Q.tag=1;
	return OK;
}

int DeQueue(SqQueue &Q)
{
	if(Q.tag==0&&Q.front==Q.rear)
		return ERROR;
	int e=Q.base[Q.front];
	Q.front=(Q.front+1)%MAX;
	if(Q.tag==1)
		Q.tag=0;
	return e;
}

int main()
{
	int n;
	while(cin>>n&&n!=0)
	{
		SqQueue Q;
		InitQueue(Q);
		for(int i=0;i<n;i++)
		{
			int x;cin>>x;
			EnQueue(Q,x);
		}
		for(int j=0;j<n-1;j++)
			cout<<DeQueue(Q)<<" ";
		cout<<DeQueue(Q)<<endl;
	}
	return 0;			
}
