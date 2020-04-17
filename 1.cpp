struct BinTreeNode;
typedef struct BinTreeNode *PBinTreeNode;

const int MAXSIZE=20;

struct BinTreeNode{
	char info;
	PBinTreeNode llink;
	PBinTreeNode rlink; 
}; 

typedef struct BinTreeNode *BinTree;
typdef BinTree *PBinTree;

PBinTree Build(char *pre,char *ops,int n){
	PBinTree p;
	char *rpre;
	int k;
	if(n<=0)return NULL;
	p=(PBinTree)malloc(sizeof(BinNode));
	p->data=*pre;
	for(rpre=ops;(*rpre)==(*pre);rpre++)break;
	int k=rops-ops;
	p->llink=Build(pre+1,ops,k);
	p->rlink=BUild(pre+k+1,ops+1,n-k+1);
}
