#include<iostream>
#include<string>
using namespace std;
#define  MAX  100 
#define  OK	0
#define  ERROR -1
#define  OVERFLOW -2

typedef struct
{
	double *base;
	double *top;
	int  stacksize;
}Stack;

int InitStack(Stack &S)
{
	S.base=new double[MAX];
	if(!S.base) return OVERFLOW;
	S.top=S.base;
	S.stacksize=MAX;
	return OK;
}

int push(Stack &S,double e)  
{
	if(S.top-S.base==S.stacksize)
        return ERROR; 	
	*S.top=e;
	S.top++;
	return OK;
}

int pop(Stack &S)  
{
	if(S.top==S.base)
		return ERROR;
	S.top--;	
	return OK;
}

double top(Stack S)  
{	
	if(S.top==S.base)
		return ERROR;
	return *(S.top-1);
} 

double Fun(double a,double b,char op)
{
	if(op=='+')
		return a+b;
	else if(op=='-')
		return a-b;
	else if(op=='*')
		return a*b;
	else if(op=='/')
		return a/b;
}

int main()
{
	char s[100];
	while(1)
	{
		cin.getline(s,100);
		if(s[0]=='=')
			break;
		Stack data;
		InitStack(data);
		int i,x=0,e=0,flag=0;
		for(i=0;s[i]!='=';i++)
		{
			if('0'<=s[i]&&s[i]<='9')
			{
				flag=1;
				x=x*10+(s[i]-'0');
				if(e!=0)
					e=e*10;
			}
			else if(s[i]=='.')
				e=1;
			else
			{
				if(flag==1)
				{
					double number=x;
					if(e!=0)
						number=number/e;
					push(data,number);
					x=e=flag=0;
				}
				if(s[i]==' ')
					continue;
				double b=top(data);
				pop(data);
				double a=top(data);
				pop(data);
				double oper=s[i];
				push(data,Fun(a,b,oper));
			}
		}
		printf("%.2f\n",top(data));
	}
	return 0;
}
