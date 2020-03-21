#include<iostream>
#include<cstring>
using namespace std;
#define MAX 100
int m,n; 
int BF(char s[],char p[])
{
	int i=1,j=1,t=1;
	while(i<=m&&j<=n)
	{
		if(s[i]==p[j])
		{
			i++;
			j++;
		}
		else
		{
			i=++t;
			j=1;
		}
	}
	if(j>n)
		return 1;
	else
		return 0;
}
int main()
{
	char a[MAX],b[MAX],s[MAX],p[MAX];
	while(cin>>b>>a&&a[0]!='0'&&b[0]!='0')
	{
		int i,j,flag=0;
		m=strlen(a);
		n=strlen(b);
		for(i=1;i<=m;i++)
			s[i]=a[i-1];
		s[m+1]='\0';
		for(i=n;i<2*n;i++)
			b[i]=b[i-n];
		b[2*n]='\0';
		for(i=0;i<n;i++)
		{
			for(j=1;j<=n;j++)
				p[j]=b[i+j-1];
			p[n+1]='\0';
			if(BF(s,p))
			{
				flag=1;
				break;
			}
		}
		if(flag)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}

