#include <bits/stdc++.h>
using namespace std;
struct bread{
	long long x1,y1,x2,y2,x3,y3;long long area;//S=(1/2)*(x1y2+x2y3+x3y1-x1y3-x2y1-x3y2)//ÐÐÁÐÊ½ 
} br[100010];
int n,num[100010];
long long cal(bread a){
	long long ans = abs(a.x1*a.y2 + a.x2*a.y3 + a.x3*a.y1 - a.x1*a.y3 - a.x2*a.y1 - a.x3*a.y2);
	return ans;
}
bool cmp(bread a,bread b){
	return a.area<b.area;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>num[i]>>br[i].x1>>br[i].y1>>br[i].x2>>br[i].y2>>br[i].x3>>br[i].y3;
		br[i].area=cal(br[i]);
	}
	int mk = num[1];
	sort(num+1,num+n+1);
	sort(br+1,br+n+1,cmp);
	
	int i=1;
	while(1){
		if(num[i]==mk) break;
		else{
			//cout<<i<<' '<<num[i]<<' '<<br[i].area<<endl; 
			i++;
		}
	}
	cout<<br[i].area<<endl;
	
	return 0;
}
