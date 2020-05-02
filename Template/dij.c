#include<stdio.h>
#include<string.h>
#define inf 2147483647

int heap_size;
const int maxn = 100000+10;//点的最大数量 
const int maxm = (200000  + 10) * 2;//边的最大数量 
int cnt, head[maxn],  s[maxn];// cnt 边的数量。 head【点】连接的第一条边的编号。 s集合是代表确定最短的点 
struct node{
    int to, nxt, val;// to 这条边指向的点 nxt这条边的下一条边。val权值 
}edge[maxm];
int min(int a,int b){
    return a<= b ? a : b;
}
struct node1{
    int dist;//距离 
    int idx;//点的编号 
}dist[maxm],dist1[maxm];
void shiftdown(int rt){//下放 
    int l=rt<<1;
    int r=rt<<1|1;
    int minest;
    if(l<=heap_size&&dist1[l].dist<dist1[rt].dist)
        minest=l;
    else
        minest=rt;
    if(r<=heap_size&&dist1[r].dist<dist1[minest].dist)
        minest=r;
    if(minest!= rt){
        swap(dist1[rt],dist1[minest]);
        shiftdown(minest);
    }
}
void shiftup(int rt){
    while(dist1[rt].dist<dist1[rt>>1].dist&&rt!=1){
        swap(dist1[rt],dist1[rt>>1]);
        rt=rt>>1;
    }
}
void init(){//初始化 
    cnt = 0;
    heap_size = 0;
    memset(head, -1, sizeof head);
}
void add(int u, int v, int w){
    edge[cnt].to = v;//指向V点 
    edge[cnt].val = w;//权值 
    edge[cnt].nxt = head[u];//下一条边 
    head[u] = cnt++;//第一条边 
}
void Dijkstra(int n,int st){
    int mindis, u;
    memset(s, 0, sizeof s);
    for(int i =1;i <=n;i++) dist[i].dist = inf,dist[i].idx = i;// 初始化 
//  printf("%d\n", dist[2]);
    for(int i = head[st];~i;i = edge[i].nxt){//~i  i!=-1 
        int v = edge[i].to;
        dist[v].dist = min(dist[v].dist,edge[i].val);//初始dist数组 
    }
    s[st] = 1;  //起点加入 
    dist[st].dist = 0;  // 起点的距离是0
    heap_size=0; //初始堆   没有元素 
    for(int i = 1;i <= n;i++){
        if(i==st) continue;//跳过起始点 
        heap_size++;
        dist1[heap_size] = dist[i];
        shiftup(heap_size);
    }
    //堆中有n-1个点 
    for(int i = 1; i <= n-1; i++){  
        mindis = inf;
        mindis = dist1[1].dist;// 小顶堆 z

        u = dist1[1].idx;// idx代表这个点的编号 
        while(s[u]==1){// 若选择的点已经再S数组中 ， 我们就重新再找一个 
            u = dist1[1].idx;
            swap(dist1[1],dist1[heap_size]);
            heap_size--;
            shiftdown(1);
        }

        s[u]=1;// 放到S数组中 
        for(int j = head[u];~j;j = edge[j].nxt){//遍历u点连接的所有的边 
            int v = edge[j].to;//u点所指向的点  
            if(s[v]==0 && dist[u].dist + edge[j].val < dist[v].dist && edge[j].val < inf){
                dist[v].dist = dist[u].dist + edge[j].val;
                heap_size++;
                dist1[heap_size] = dist[v];
                shiftup(heap_size);
                //重新加入到堆中 
            }
        }
    }
}
int main(){
    init();
    int N, M, S;//n个点 ， m条边 ， s代表起点 
    scanf("%d%d%d", &N ,&M, &S);
    while(M--){
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        add(u, v, w);//  加入u到v的权值为w的边 
    }
    Dijkstra(N, S);//单源最短路 
    for(int i = 1;i <= N;i++){
        printf("%d ",dist[i]);//输出所有的最短距离 
    }
}