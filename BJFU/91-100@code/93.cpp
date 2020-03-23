#include<iostream>
using namespace std;
#define MAX 100
void Input(char c[],int n)
{
	for(int i=0;i<n;i++)
		cin>>c[i];      
}
void Exchange(char &x,char &y)
{
	char t;
	t=x;
	x=y;
	y=t;
}
void Sort(char c[],int n)
{
	int i,j=0,k=n-1;
	for(i=0;i<n;i++)
	{
		if(c[i]=='R')
		{
			while(c[j]=='R'&&i>j)
				j++;
			Exchange(c[i],c[j]);
			if(c[i]=='B')
				i--;
		}
		else if(c[i]=='B')
		{
			while(c[k]=='B'&&i<k)
				k--;
			Exchange(c[i],c[k]);
			if(c[i]=='R')
				i--;
		}
	}		
}
void Output(char c[],int n)
{
	for(int i=0;i<n-1;i++)
		cout<<c[i]<<" ";
	cout<<c[n-1]<<endl;    
}
int main()
{
	int n;
	while(cin>>n&&n!=0)
	{
      	char c[MAX];
      	Input(c,n);
		Sort(c,n);
      	Output(c,n);	
	}
	return 0;
}
