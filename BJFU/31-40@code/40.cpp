#include<iostream>
using namespace std;
#define  MAX  100 
#define  OK	0
#define  ERROR -1
#define  OVERFLOW -2

typedef struct
{
	int *base;
	int *top;
	int stacksize;
}SqStack;

int InitSqStack(SqStack &S)
{
	S.base=new int[MAX];
	if(!S.base) return OVERFLOW;
	S.top=S.base;
	S.stacksize=MAX;
	return OK;
}

int Push(SqStack &S,int e)  
{
	if(S.top-S.base==S.stacksize)
		return ERROR;
	*S.top=e;
	S.top++;
	return OK;
}

int Pop(SqStack &S)  
{
	if(S.top==S.base)
		return ERROR;
	S.top--;
	return OK;
}

int Top(SqStack S)  
{
	if(S.top==S.base)
		return ERROR;
  	return *(S.top-1);
}

int main()
{
	int n;
	while(cin>>n&&n!=0)
	{
      	SqStack S;
		InitSqStack(S);
		int a[MAX];
		for(int j=0;j<n;j++)
			cin>>a[j];
		for(int i=0;i<n;i++)
		{
			if(a[i]!=-1)
				Push(S,a[i]);
			else
			{
				if(S.top!=S.base)
				{
					cout<<Top(S)<<endl;
					Pop(S);
				}
				else
				{
                  	cout<<"POP ERROR"<<endl;
					break;
				}
			}
		}
	}
	return 0;
}
