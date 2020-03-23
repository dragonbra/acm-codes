#include<iostream>
using namespace std;

int IsEqual(int a[20][20],int m,int n)
{
	int i,j,p,k;
	for(i=0;i<m;i++)
		for(j=0;j<n-1;j++)
		{
			for(p=j+1;p<n;p++)
				if(a[i][j]==a[i][p])
				{
					cout<<"YES"<<endl;
					return 1;
				}
          	for(k=i+1;k<m;k++)
            	for(p=0;p<n;p++)
             		if(a[i][j]==a[k][p])
					{
              			cout<<"YES"<<endl;
					  	return 1;
					}
		}
  	cout<<"NO"<<endl;
	return 0;
} 

int main()
{
	int m,n,i,j;
	while(cin>>m>>n&&m!=0&&n!=0)
	{
		int a[20][20];
		for(i=0;i<m;i++)
			for(j=0;j<n;j++)
				cin>>a[i][j];
		IsEqual(a,m,n);
	}
	return 0;
}
