#include<bits/stdc++.h>
using namespace std;

void redirect() {
    #ifdef LOCAL
        freopen("1.in","r",stdin);
        freopen("1.out","w",stdout);
    #endif
}

int main()
{
    redirect();
    double dx,dy,yx,ux,uy,rx,ry,R;
    double s1,s2,s3,x1,y1,x2,y2,cosA;
        scanf("%lf%lf%lf",&rx,&ry,&R);
        scanf("%lf%lf%lf%lf",&dx,&dy,&ux,&uy);
        dx-=rx;ux-=rx;dy-=ry;uy-=ry;
        x1=dx;
        y1=-sqrt(R*R-x1*x1);
        y2=uy;
        x2=sqrt(R*R-y2*y2);
        cosA=acos((x1*x2+y1*y2)/sqrt((x1*x1+y1*y1)*(x2*x2+y2*y2)));
        s1=R*R*cosA/2;
        s2=x1*(y2-y1)/2;
        s3=y2*(x1-x2)/2;
        printf("%.4lf\n",s1-s2-s3);
}