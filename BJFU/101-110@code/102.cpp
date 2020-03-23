#include <iostream>
#include <cstring>
using namespace std;
const int N = 1e5+10;

void redirect() {
    #ifdef LOCAL
        freopen("1.in","r",stdin);
        freopen("1.out","w",stdout);
    #endif
}

int f[N],n,m;

int getf(int x){ return f[x]==x ? x : f[x] = getf(f[x]); }

int main(){
    redirect();
    while(cin >> n && n!=0){
        cin>>m;
        int cnt = 0;
        for(int i=1;i<=n;i++) f[i] = i, cnt++;
        for(int i=1;i<=m;i++) {
            int u,v;
            cin>>u>>v;
            if(getf(u)!=getf(v)){
                f[getf(v)] = getf(u); cnt--;
            }
        }
        cout<<cnt-1<<endl;
    }
    return 0;
}