#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("1.txt","w",stdout);
	srand((unsigned)time(NULL));
	int n=rand()%10+1;
	printf("%d\n",n);
	for(int i=1;i<=n;i++){
		int flag=rand()%2;
		if(flag)printf("-");
		printf("%d ",rand()%10+1); 
	}
	return 0;
}
