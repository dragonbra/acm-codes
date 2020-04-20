#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
const double eps = 1e-5;
const int N = 5e5 + 10;

void redirect() {
    #ifdef LOCAL
        freopen("1.in","r",stdin);
        freopen("1.out","w",stdout);
    #endif
}

ll n;
bool flag[N];
ll prime[N],pnum;
ll p[N];
/*
flag[n] 表示n是否是素数，1是素数，0不是
prime   中是所有的素数按从小到大排列、
pnum  表示素数的个数
*/
void CreatePrime(){
	pnum=0;//初始化没有素数
	//先将所有数看做素数，然后开始筛选
	for(int i=0; i<=n; i++){
		flag[i]=1;
	}
	//遍历筛去所有最大因数是i的合数
	for(int i=2; i<=n; i++){
		if(flag[i]==1){
		//把素数记录下来
			prime[pnum++]=i;
		}
		//遍历已知素数表中比i的最小素因数小的素数，并筛去合数
		for(int j=0; j<pnum && prime[j]*i<=N; j++){
		//筛去合数
			flag[prime[j]*i]=0;
			if(i%prime[j]==0)
			//找到i的最小素因数
				break;
		}
	}
}

int main() {
    redirect();

    scanf("%lld",&n);
    CreatePrime();

    priority_queue<int, vector<int>, greater<int> > Q;

    for(int i=2;i<=pnum+1;i++){
        Q.push(prime[i-2]);
        printf("1 ");
    }

    int pt=0;
    for(int i=pnum+2;i<=n;i++) {
        int t = Q.top(); Q.pop();
        while(flag[t]&&prime[pt]<t) pt++;
        for(int j=0;j<=pt&&i<=n;i++,j++) {
            Q.push(t*prime[j]);
            printf("%d ",t);
        }
    }

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/