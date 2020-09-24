//埃氏筛法
#define N 10000
int flag[N+1],p[N+1],pnum;
/*
flag[n] 表示n是否是素数，1是素数，0不是
prime   中是所有的素数按从小到大排列、
pnum  表示素数的个数
*/
void CreatePrime(){
	pnum=0;//初始化没有素数
	//先将所有数看做素数，然后开始筛选
	for(int i=0; i<=N; i++){
		flag[i]=1;
	}
	//遍历筛去所有最大因数是i的合数
	for(int i=2; i<=N; i++){
		if(flag[i]==1){
		//把素数记录下来
			p[pnum++]=i;
		}
		//遍历已知素数表中比i的最小素因数小的素数，并筛去合数
		for(int j=0; j<pnum && p[j]*i<=N; j++){
		//筛去合数
			flag[p[j]*i]=0;
			if(i%p[j]==0)
			//找到i的最小素因数
				break;
		}
	}
}