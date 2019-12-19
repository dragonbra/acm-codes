#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=1e5+10;
int a[maxn],b[maxn],n;LL ans=0;

LL cal(int a[],int le,int mid,int ri,int tmp[]){
    int i=le,j=mid+1;
    LL sum=0;
    while(i<=mid && j<=ri){
        if(a[i]>a[j])sum+=ri-j+1,i++;
        else j++;
    }
    return sum;
}
void merge(int a[],int le,int mid,int ri,int tmp[]){
    int p=0,p1=le,p2=mid+1;
    while(p1<=mid && p2<=ri){
        if(a[p1]>a[p2])tmp[p++]=a[p1++];
        else tmp[p++]=a[p2++];
    }
    while(p1<=mid)tmp[p++]=a[p1++];
    while(p2<=mid)tmp[p++]=a[p2++];
    for(int i=0;i<p;i++)a[i+le]=tmp[i];
}
LL merge_sort(int a[],int le,int ri,int tmp[]){
    LL cnt=0;
    if(ri>le){
        int mid=le+(ri-le)/2;
        cnt+=merge_sort(a,le,mid,tmp);
        cnt+=merge_sort(a,mid+1,ri,tmp);
        cnt+=cal(a,le,mid,ri,tmp);
        merge(a,le,mid,ri,tmp);
    }
    return cnt;
}


int main(){
	int T;scanf("%d",&T);
	int row=0;
	while(T--){
		int cur=0;
		for(int i=0;i<16;i++){
			scanf("%d",&a[cur+1]);
			if(a[cur+1]==0){
				row=i/4;continue;
			}
			cur++;
		}
		int cnt=merge_sort(a,1,15,b);
		//cout<<cnt<<' '<<row<<endl;
		bool is = (cnt&1)==((3-row)&1) ? 1:0;
		if(is) printf("Yes\n");
		else printf("No\n");
	}
    return 0;
}
