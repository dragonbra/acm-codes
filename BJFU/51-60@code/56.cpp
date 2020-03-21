#include<iostream>
using namespace std;
#define MAX 100
void Insert(char a[],char b[],int pos)
{
	int m=0,n=0,len1=0,len2=0;
	for(int i=0;a[i]!='\0';i++)
		len1++;
	for(int i=0;b[i]!='\0';i++)
		len2++;
	for(int j=0;j<len1;j++)
	{
		m++;n++;
		if(m==pos)
			for(int i=0;i<len2;i++)
            {
				cout<<b[i];
              	n++;
			}
		cout<<a[j];
		if(n==len1+len2)
			cout<<endl;
	}
}
int main()
{
	int pos;
	while(cin>>pos&&pos!=0)
	{
		char a[2*MAX],b[MAX];
		cin>>a>>b;
		Insert(a,b,pos);
	}
	return 0;
}
