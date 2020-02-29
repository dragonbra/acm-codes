int main(){
    redirect();
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
    	scanf("%d%d",&p[i].x,&p[i].y);
    	mp[p[i].x][p[i].y] = true;
	}
	int cnt = 0;
    for(int i=2;i<=n;i++) {
    	int dx = p[i].x - p[1].x;
    	int dy = p[i].y - p[1].y;
    	if(!vis[dx][dy]) {
    		if(judge(dx,dy)) cnt++;
			vis[dx][dy] = true;	
		}
    	if(!vis[-dx][-dy]) {
    		if(judge(-dx,-dy)) cnt++;
    		vis[-dx][-dy] = true;
		}
	}
	printf("%d\n",cnt);
    return 0;
}