#include <bits/stdc++.h>

using namespace std;
#define maxn 1000005
int arr[maxn],l[maxn],r[maxn];
int main()
{

	int n;
	scanf("%d",&n);
	int sum1=0,sum2=0;
	for(int i=1;i<=n;i++)scanf("%d",&arr[i]);
	for(int i=1;i<=n;i++)scanf("%d",&l[i]);
	for(int i=1;i<=n;i++)scanf("%d",&r[i]);
	for(int i=1;i<=n;i++)
	{
		if(arr[i]-r[i]==0)sum1++;
		if(arr[i]-l[i]-r[i]<=0)sum2++;
	}
	if(sum1==n)printf("A\n");
	else if(sum2==n)printf("B\n");
	else printf("Draw\n");
    return 0;
}
