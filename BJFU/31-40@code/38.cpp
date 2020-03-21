#include<iostream>
using namespace std;
#define Max 100

typedef struct LNode
{
	int *top[2];
	int *base[2];
	int maxsize;
}DblStack;

void Init(DblStack &S,int n)
{
	S.base[0]=new int[Max];
	S.base[1]=S.base[0]+n-1;
	S.top[0]=S.base[0];
	S.top[1]=S.base[1];
	S.maxsize=n;
}

int IsEmpty(int *top,int *base)
{
	return top==base?1:0;
}

int IsFull(int *top1,int *top2)
{
	return top1>top2?1:0;
}

void Push0(DblStack &S)
{
	int x;cin>>x;
	*S.top[0]=x;
	S.top[0]++;
}

void Push1(DblStack &S)
{
	int x;cin>>x;
	*S.top[1]=x;
	S.top[1]--;
}

void Pop0(DblStack &S)
{
	S.top[0]--;
	cout<<*S.top[0]<<" ";
}

void Pop1(DblStack &S)
{
	S.top[1]++;
  	cout<<*S.top[1]<<" ";
}

int main()
{
  	DblStack S;
	int n,e0,e1,d0,d1;
	while(cin>>n&&n!=0)
	{
		Init(S,n);
      	cin>>e0>>e1>>d0>>d1;
		while(e0--)
			Push0(S);
		while(e1--)
			Push1(S);
      	cout<<IsFull(S.top[0],S.top[1])<<endl;
		while(d0--)
			Pop0(S);
      	cout<<!IsEmpty(S.top[0],S.base[0])<<endl;
		while(d1--)
			Pop1(S);
      	cout<<!IsEmpty(S.top[1],S.base[1])<<endl;
	}
	return 0;
}
