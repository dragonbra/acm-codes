#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;cin>>n;int xm=0,ym=0;
	while(n--){
		char t;int tx,ty;
		cin>>t;scanf("%d %d",&tx,&ty);if(tx<ty)swap(tx,ty);//tx>ty
		
		if(t=='+'){
			xm=max(tx,xm),ym=max(ym,ty);
		}
		else if(t=='?'){
			if(tx>=xm&&ty>=ym)printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;
}
