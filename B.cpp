#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
using namespace std;
const double eps = 1e-8;
const double pi = acos(-1.0);
const int maxn = 1e6+10;
struct Round {
	double x, y, r, r2;
}R[5];
double d;
double cal(Round a, Round b) {
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
double solve(Round a, Round b) {
	double d = cal(a, b);
	if(d >= a.r + b.r) return 0;
	if(d <= fabs(a.r - b.r)) {
		double r = a.r < b.r ? a.r : b.r;
		return pi * r * r;
	}
	double ang1 = acos((a.r * a.r + d * d - b.r * b.r) / (2 * a.r * d));
	double ang2 = acos((b.r * b.r + d * d - a.r * a.r) / (2 * b.r * d));
	double res = ang1 * a.r * a.r + ang2 * b.r * b.r - d * a.r * sin(ang1);
	return res;
}
int main(){
	int T;
	scanf("%d", &T);
	while(T--) {
		scanf("%lf %lf %lf", &R[0].r, &R[0].x, &R[0].y);
		scanf("%lf %lf %lf", &R[1].r, &R[1].x, &R[1].y);
		scanf("%lf", &d);
		// R[2].r = R[0].r - sqrt(2 * (d/2) * (d/2));
		R[2].r = sqrt(R[0].r * R[0].r - (d / 2) * (d / 2)) - d / 2;
        R[2].x = R[0].x; R[2].y = R[0].y;
		// R[3].r = R[1].r - sqrt(2 * (d/2) * (d/2));
		R[3].r = sqrt(R[1].r * R[1].r - (d / 2) * (d / 2)) - d / 2;
        R[3].x = R[1].x; R[3].y = R[1].y;
		//double ans = pi * R[2].r * R[2].r + pi * R[3].r * R[3].r - solve(R[2], R[3]);
        
        if (R[3].r < 0) {
            printf("0.000000\n");
            continue;
        }
		double ret = pi * R[2].r * R[2].r;
		printf("%.6lf\n", solve(R[2], R[3]) / ret);
	}
}