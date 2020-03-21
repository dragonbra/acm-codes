#include<iostream>
using namespace std;
#define  MAX 100 
#define  OK	0
#define  ERROR -1
#define  OVERFLOW -2

typedef struct 
{
	char *top;
	char *base;
	int stacksize;
}SqStack;

int	InitStack(SqStack &S)
{
	S.base=new char[MAX];
	if(!S.base)
		return OVERFLOW;
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
	return *S.top;
}

int IsHuiwen(char t[])
{
	SqStack S;
	InitStack(S);
	int i,len=0;
  	for(i=0;t[i]!='\0';i++)
	len++;
	for(i=0;i<len/2;i++)
		Push(S,t[i]);
	if(len%2!=0)
		i++;
	for(;t[i]!='\0';i++)
	{  
		if(Pop(S)!=t[i])	
			return 0;
	}
	return 1; 
}

int main()
{
  	char t[100];
	while(cin>>t&&t[0]!='0')
	{
		if(IsHuiwen(t)==1)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}