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
bool vis[N];
ll flag[N],prime[N],pnum;
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

    cout<<pnum<<' '<<prime[pnum-1]<<endl;

    int cnt = 0;
    for(int i=0;i<=pnum;i++){
        p[0] = 1;
        while(p[cnt]*prime[i]<n) p[cnt+1] = p[cnt] * prime[i], cnt++;
    }
    sort(p+1,p+cnt+1);

    for(int i=2;i<=pnum+1;i++){
        printf("1 ");
    }

    int ct = pnum+1; int j = 1;
    bool f = false;
    while(ct<n){
        for(int i=0;prime[i]<=j&&j<cnt;i++) {
            //cout<<p[j]<<' '<<0<<endl;
            if( prime[i]*p[j] > n ) break;
            if( vis[ prime[i]*p[j] ] ) continue;

            vis[ prime[i] * p[j] ] = true;

            //cout<<cnt<<endl;

            printf("%d ",p[j]);
            ct++;
            if(ct==n) {
                f = true; break;
            }
        }
        if(f) break;
        j++;
    }

    return 0;
}

/*
-----------------
author:dragon_bra
-----------------
*/