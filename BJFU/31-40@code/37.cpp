#include<iostream>
using namespace std;
#define  MAX  100 
#define  OK	0
#define  ERROR -1
#define  OVERFLOW -2

typedef struct
{
	char *base;
	char *top;
	int stacksize;
}Stack1;

int InitStack1(Stack1 &S)
{
	S.base=new char[MAX];
	if(!S.base) return OVERFLOW;
	S.top=S.base;
	S.stacksize=MAX;
	return OK;
}

int push1(Stack1 &S, char e)  
{
	if(S.top-S.base==S.stacksize)
		return ERROR;
	*S.top=e;
	S.top++;
	return OK;
}

int pop1(Stack1 &S)  
{
	if(S.top==S.base)
		return ERROR;
	S.top--;
	return OK;
}

char top1(Stack1 S)  
{
	if(S.top==S.base)
		return ERROR;
  	return *(S.top-1);
}

typedef struct
{
	double *base;
	double *top;
	int  stacksize;
}Stack2;

int InitStack2(Stack2 &S)
{
	S.base=new double[MAX];
	if(!S.base) return OVERFLOW;
	S.top=S.base;
	S.stacksize=MAX;
	return OK;
}

int push2(Stack2 &S,double e)  
{
	if(S.top-S.base==S.stacksize)
        return ERROR; 	
	*S.top=e;
	S.top++;
	return OK;
}

int pop2(Stack2 &S)  
{
	if(S.top==S.base)
		return ERROR;
	S.top--;	
	return OK;
}

double top2(Stack2 S)  
{	
	if(S.top==S.base)
		return ERROR;
	return *(S.top-1);
}

double Fun(double a,double b,char op)
{
	if(op=='+')
		return b+a;
	else if(op=='-')
		return b-a;
	else if(op=='*')
		return b*a;
	else if(op=='/')
		return b/a;
}

char Precede(char a,char b)
{
	if((a=='('&&b==')')||(a=='='&&b=='='))
		return '=';
	else if(a=='('||a=='='||b=='('||(a=='+'||a=='-')&&(b=='*'||b=='/'))
		return '<';
	else
		return '>';
}

int main()
{
	char s[100];
	while(cin>>s&&s[0]!='=')
	{
		Stack1 op;
		InitStack1(op);	
		Stack2 data;
		InitStack2(data);
		push1(op,'=');
		int i,x=0,e=0,flag=0;
		for(i=0;s[i]!='\0';i++)
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
				if(flag!=0)
				{
					double number=x;	
					if(e!=0)
						number=number/e;
					push2(data,number);		
					x=e=flag=0;
				}
				while(1)
				{
					if(Precede(top1(op),s[i])=='<')			
					{
						push1(op,s[i]);		
						break;
					}
					else if(Precede(top1(op),s[i])=='>')	
					{
						double a=top2(data);
						pop2(data);
						double b=top2(data);
						pop2(data);
						char oper=top1(op);
						pop1(op);
						push2(data,Fun(a,b,oper));
					}
					else
					{
						pop1(op);				
						break;
					}
				}
			}
		}
		printf("%.2f\n",top2(data));		
	}
	return 0;
}
