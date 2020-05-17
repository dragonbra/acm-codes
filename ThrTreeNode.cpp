出边表：
int isend(GraphList g,int k){
    EdgeList p;
    int i;
    for(i=0;i<g.n;i++){
        p=g.vexs[i].edgelist;
        while(p!=NULL){
            if(p->endevx==k)return 1;
            p=p->nextedge;
        }
    }
    return 0;
}

邻接矩阵：
int isend(int k){
    for(int i=0;i<n;i++)
        if(g[i][k]!=0)return 1;
    return 0;
}

