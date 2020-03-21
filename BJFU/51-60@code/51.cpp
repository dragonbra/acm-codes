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
}SqStack;
int InitStack(SqStack &S)
{
	S.base=new char[MAX];
	if(!S.base) return OVERFLOW;
	S.top=S.base;
	S.stacksize=MAX;
	return OK;
}
int Push(SqStack &S, char e)  
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
char Top(SqStack S)  
{
	if(S.top==S.base)
		return ERROR;
  	return *(S.top-1);
}
char Precede(char a,char b)
{
	if((a=='('&&b==')')||(a=='='&&b=='='))
		return '=';
	else if(a=='='||a=='('||b=='('||((a=='+'||a=='-')&&(b=='*'||b=='/')))
		return '<';
	else
		return '>';
} 
int main()
{
	char s[100];
	while(cin>>s&&s[0]!='=')
	{
		SqStack op;
		InitStack(op);
		Push(op,'=');
		for(int i=0;s[i]!='\0';i++)
		{
			if('0'<=s[i]&&s[i]<='9')
				cout<<s[i];
			else
			{
				while(1)
				{
					if(Precede(Top(op),s[i])=='<')
					{
						Push(op,s[i]);
						break;
					}
					else if(Precede(Top(op),s[i])=='>')
					{
						cout<<Top(op);
						Pop(op);
					}
					else
					{
						Pop(op);
						break;
					}
				}
			}
		}
		cout<<endl;
	}
	return 0;
}
