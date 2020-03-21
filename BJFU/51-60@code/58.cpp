#include<iostream>
using namespace std;
int main()
{
	int n;
	while(cin>>n&&n!=0)
	{	
      	int i,count=0,a[100];
		for(i=0;i<n;i++)
			cin>>a[i];
		for(i=n-1;i>=0;i--)
		{
			if(a[i]<0)
			{
              	count++;
				for(int j=i;j<n-count;j++)
				{
                  	int t;
					t=a[j+1];
					a[j+1]=a[j];
					a[j]=t;
				}
			}
		}
		for(i=0;i<n-1;i++)
			cout<<a[i]<<" ";
		cout<<a[n-1]<<endl;
	}
	return 0;
}
