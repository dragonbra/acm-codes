//以下是网络流模板
struct Edge{
    int to,nxt,w;
}e[M<<1];
int head[N],ecnt;
void AddEdge(int u,int v,int w) {
    e[ecnt]=(Edge){v,head[u],w};
    head[u]=ecnt++;
}
void Link(int u,int v,int w){ AddEdge(u,v,w),AddEdge(v,u,0); }
#define erep(u,i) for(int i=head[u];~i;i=e[i].nxt)
 
int dis[N];
int Bfs(){
    static queue <int> que;
    rep(i,1,vc) dis[i]=INF;
    que.push(S),dis[S]=0;
    while(!que.empty()) {
        int u=que.front(); que.pop();
        erep(u,i) {
            int v=e[i].to,w=e[i].w;
            if(!w || dis[v]<=dis[u]+1) continue;
            dis[v]=dis[u]+1,que.push(v);
        }
    }
    return dis[T]<INF;
}
 
int Dfs(int u,int flowin) {
    if(u==T) return flowin;
    int flowout=0;
    erep(u,i) {
        int v=e[i].to,w=e[i].w;
        if(dis[v]!=dis[u]+1 || !w) continue;
        int t=Dfs(v,min(flowin-flowout,w));
        flowout+=t,e[i].w-=t,e[i^1].w+=t;
        if(flowin==flowout) break;
    }
    if(!flowout) dis[u]=0;
    return flowout;
}
 
int Dinic(){
    int ans=0;
    while(Bfs()) ans+=Dfs(S,INF);
    return ans;
}