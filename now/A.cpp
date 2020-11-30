/*
* @ author: dragon_bra
* @ email: tommy514@foxmail.com
* @ data: 2020-11-30 16:26
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
const double eps = 1e-5;
const int N = 1e2 + 10;

void redirect() {
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
}

int T;
int n, x, y; int q;

double matrix[N][N];
double ans[N];

bool Gauss() {
	for (int i=1; i<=n; ++i) {   
        //枚举列（项） 
		int mx=i;
		for (int j=i+1; j<=n; ++j) {
            //选出该列最大系数 
			if ( fabs(matrix[j][i]) > fabs(matrix[mx][i]) ) {
                //fabs是取浮点数的绝对值的函数
				mx = j;
			}
		}
		for (int j=1; j<=n+1; ++j) {
		    //交换
			swap( matrix[i][j], matrix[mx][j] );
		}

		if (!matrix[i][i]) {
            //最大值等于0则说明该列都为0，肯定无解 
			// puts("No Solution");
			return false;
		}

		for(int j=1; j<=n; ++j) {
            //每一项都减去一个数（就是小学加减消元）
			if(j != i) {
				double temp = matrix[j][i] / matrix[i][i];
				for(int k=i+1;k<=n+1;++k) {
					matrix[j][k] -= matrix[i][k]*temp;
				}
			}
		}
	}
    //上述操作结束后，矩阵会变成这样
    /*
    k1*a=e1
    k2*b=e2
    k3*c=e3
    k4*d=e4
    */
    //所以输出的结果要记得除以该项系数，消去常数
	for(int i=1;i<=n;++i) {
        ans[i] = matrix[i][n+1] / matrix[i][i];
        if ( fabs(ans[i] - 0) < eps ) ans[i] = 0;
		// printf("%.2lf\n",matrix[i][n+1]/matrix[i][i]);
	}

	return true;
}

int main() {
    redirect();

    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &n, &x, &y);

        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n+1; j++) {
                matrix[i][j] = 0;
            }
        }

        matrix[1][1] = 1; matrix[1][n+1] = -x;
        matrix[n][n] = 1; matrix[n][n+1] = y;
        for (int i=2; i<n; i++) {
            matrix[i][i] = 1; matrix[i][n+1] = 0;
            for (int j=1; j<=i; j++) matrix[i][j] -= 0.5 * (1.0 / (double)i);
            for (int j=i; j<=n; j++) matrix[i][j] -= 0.5 * (1.0 / (double)(n-i+1));
        }

        bool flag = Gauss();
        scanf("%d", &q);
        while (q--) {
            int t; scanf("%d", &t);
            printf("%.6lf\n", ans[t]);
        }
    }

    return 0;
}