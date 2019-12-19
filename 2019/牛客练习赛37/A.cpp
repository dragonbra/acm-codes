#include <bits/stdc++.h>
using namespace std;
bool check[10010];
int prime[100010];

int main(){
	
	memset(check, 0, sizeof(check));
	int tot = 0;
	for (int i = 2; i <= 10001; ++i)
	{
	  if (!check[i])
	  {
	    prime[tot++] = i;
	  }
	  for (int j = i+i; j <= 10001; j += i)
	  {
	    check[j] = 1;
	  }
	}
	
	int mk=0;
	for(int i=1;i<=tot;i++){
		if(prime[i]==2003){
			mk=i;break;
		}
	}
	
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		int k;scanf("%d",&k); 
		int cmp = k%6, yy = (k-1)/6; yy+=mk;
		printf("%d",prime[yy]);
		if(cmp==0) printf("-12-21\n");
		else if(cmp==1) printf("-01-10\n");
		else if(cmp==2) printf("-02-20\n");
		else if(cmp==3) printf("-03-30\n");
		else if(cmp==4) printf("-10-01\n");
		else if(cmp==5) printf("-11-11\n");
	}
	
	return 0;
}
