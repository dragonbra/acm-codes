#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct rec{
	ll x1,y1,x2,y2;
};

bool cmp(rec a,rec b){
	if(a.x1!=b.x1) return a.x1<b.x1;
	else return a.x2>b.x2;
}

int cnt (rec a,rec b){
	int res=0;
	if(a.x1==b.x1) res++;
	if(a.x2==b.x2) res++;
	if(a.y1==b.y1) res++;
	if(a.y2==b.y2) res++;
	return res;
}

bool xinc(rec a,rec b){
	//if(a.x1>b.x1) rec T=b;b=a;a=T;
	if(a.x1<=b.x1&&a.x2>=b.x2) return true;
	else return false;
}

bool yinc(rec a,rec b){
    //if(a.y1>b.y1) rec T=b;b=a;a=T;
    if(a.y1<=b.y1&&a.y2>=b.y2) return true;
    else return false;
}

bool judge_2(rec a,rec b){
	if(cnt(a,b)==4) return true;
	return false;
}

bool judge_3(rec a,rec b){
	if(!cmp(a,b)){rec T=b;b=a;a=T;}
	if(cnt(a,b)>3) return false;
	
	if(cnt(a,b)==3) return true;
	else if(xinc(a,b)&&yinc(a,b)&&(!((a.x1==b.x1&&a.x2==b.x2)||(a.y1==b.y1&&a.y2==b.y2)))) return true;
	return false;
}

bool judge_5(rec a,rec b){
	if(!cmp(a,b)){rec T=b;b=a;a=T;}
	if(cnt(a,b)>1) return false;
	
	if(cnt(a,b)==1){
		if(xinc(a,b)&&yinc(b,a)) return true;
	}
	return false;
}

bool judge_6(rec a,rec b){
	if(!cmp(a,b)){rec T=b;b=a;a=T;}
	if(cnt(a,b)>0) return false;
	
	if(cnt(a,b)==0&&(xinc(a,b)&&yinc(b,a))) return true;
	return false;
}

int main(){
	int T;scanf("%d",&T);
	while(T--){
		rec a,b;
		scanf("%lld%lld%lld%lld",&a.x1,&a.y1,&a.x2,&a.y2);
		scanf("%lld%lld%lld%lld",&b.x1,&b.y1,&b.x2,&b.y2);
		
		bool xf=0,yf=0;
		if(a.x1>b.x1){rec T=b;b=a;a=T;}
		if(a.x2>b.x1) xf=1;
		if(a.y1>b.y1){rec T=b;b=a;a=T;}
		if(a.y2>b.y1) yf=1;
		
		if(!(xf&&yf)) printf("3\n");
		else{
			if(judge_2(a,b)) printf("2\n");
			else if(judge_6(a,b)) printf("6\n");
			else if(judge_5(a,b)) printf("5\n");
			else if(judge_3(a,b)) printf("3\n");
			else printf("4\n");
		}
	}
	return 0;
}

