#include<iostream>
using namespace std;
#define MAX 100
int sum;
int flag;
int p[MAX];
int m[MAX][3];

void DFS(int n)
{
	if(n==sum)
	{
		flag=1;
		return ;
	}
	for(int i=0;i<3;i++)
	{
		if(m[n][i]&&!p[m[n][i]])
		{
			p[m[n][i]]=1;
			DFS(m[n][i]);
			p[m[n][i]]=0;
		}
	}
}

int main()
{
	int n;
	while(cin>>n&&n!=0)
	{
		flag=0;
		for(int i=1;i<=n;i++)
			p[i]=0;
		for(int i=1;i<=n;i++)
			for(int j=0;j<3;j++)
				cin>>m[i][j];
		cin>>sum;	
		p[1]=1;
		DFS(1);
		if(flag)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}
