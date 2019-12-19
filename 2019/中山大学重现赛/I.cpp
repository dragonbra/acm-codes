#include<bits/stdc++.h>
using namespace std;
const int maxn=10010;
char s[maxn],ans[maxn];
int main(){
	int n,m,k,cnt;
    while(scanf("%d %d %d\n",&n,&m,&k)!=EOF){
        for(int i=0;i<n;i++){
            scanf("%s",&s);
            memset(ans,'\0',sizeof(ans));
            cnt=-1;
            for(int i=0;i<m;i++)
                for(int j=0;j<k;j++) ans[++cnt]=s[i];
            for(int i=0;i<k;i++) printf("%s\n",ans);
        }
    }
    return 0;
}

