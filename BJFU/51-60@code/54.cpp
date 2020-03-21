#include<iostream>
using namespace std;	
int main()
{
	int i;
	char a[37];	
	int  b[37];
	char c[100];
	while(cin>>c&&c[0]!='0')
	{
		a[1]=48;b[1]=0;
     	a[11]=65;b[11]=0;
		for(i=2;i<=10;i++)	
		{
			a[i]=a[i-1]+1;
			b[i]=0;
		}	
		for(i=12;i<=36;i++)	
		{
			a[i]=a[i-1]+1;
			b[i]=0;	
		}
		for(i=1;i<=36;i++)
			for(int j=0;c[j]!='\0';j++)
				if(a[i]==c[j])
					b[i]++;
					for(i=1;i<=11;i++)
			if(b[i]>0)
				cout<<a[i]<<":"<<b[i]<<endl;
		for(i=12;i<=36;i++)
			if(b[i]>0)
              	cout<<a[i]<<":"<<b[i]<<endl;
	}
	return 0;
}
