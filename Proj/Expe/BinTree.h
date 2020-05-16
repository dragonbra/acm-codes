#include<iostream>
#include<assert.h>
#include<stack>
#include<queue>
using namespace std;
 
template<class Type>
class BinTree;
 
template<class Type>
class BinTreeNode    // 树中的节点类
{
	friend class BinTree<Type>;
public:
	/* 树节点的构造函数*/
	BinTreeNode():value(Type()), leftChild(NULL), rightChild(NULL)
	{}               
	BinTreeNode(Type data):value(data), leftChild(NULL), rightChild(NULL)
	{}
	~BinTreeNode()
	{}
private:					// 树中节点的结构 
	Type value;                       //值类型
	BinTreeNode<Type> *leftChild;     // 指向左孩子
	BinTreeNode<Type> *rightChild;	  // 指向右孩子
};
 
/////////////////////////////////////////////////////
typedef enum{L,R}Tag_Type;
 
/* 这个结构用来实现树的非递归后序遍历，后面再讲*/
template<class Type>
struct stkNode        
{
	BinTreeNode<Type> *str;
	Tag_Type           Tag;
};
/////////////////////////////////////////////////////
 
/* 二叉树类*/
template<class Type>
class BinTree
{
public:
	/* '#'是自定义的一个标记，表示该节点为空*/
	BinTree():root(NULL), refvalue('#')
	{}
	
        /* 第一种构造树的方法，直接按先序遍历写出树中所有节点,
	包括叶子节点的两个空左右孩子【用'#'代替，例如 ABC##DE##F##G#H##】*/
	void CreateBinTree_w()
	{
		CreateBinTree(root);  // CreateBinTree_w为树对外的接口，CreateBinTree为具体实现，为私有方法
	}
	
	/* 第二种构造方法，把先序遍历的字符串以参数形式穿进去*/
	void CreateBinTree_str(const char *str)
	{
		CreateBinTree(root, str);
	}
	
	/* 根据先序遍历和中序遍历的结果唯一构造二叉树，
	三个参数分别为先序遍历字符串、中序遍历字符串、树的节点个数*/
	void CreateBinTree_Pre(char *VLR, char *LVR, int n)    
	{           
		CreateBinTree_Pre(root, VLR, LVR, n); 
	}
	
	/* 根据后序遍历和中序遍历的结果唯一构造二叉树，
	三个参数分别为后序遍历字符串、中序遍历字符串、树的节点个数*/
	void CreateBinTree_Post(char *LRV, char *LVR, int n)
	{
		CreateBinTree_Post(root, LRV, LVR, n);
	}
	
	/* 求树中的节点个数*/
	int Size()const
	{		
		return Size(root);
	}
	
	/* 求树的高度*/
	int Height()const
	{
		return Height(root);
	}
	
	/* 求树的根节点*/
	BinTreeNode<Type>* Root()const
	{
		return root;
	}
	
	/* 求指针p所指节点的左孩子*/
	BinTreeNode<Type>* LeftChild(BinTreeNode<Type>* p)const
	{
		if(NULL == p)
			return p;
		return p->leftChild;
	}
	
	/* 求指针p所指节点的右孩子*/
	BinTreeNode<Type>* RightChild(BinTreeNode<Type>* p)const
	{	
		if(NULL == p)
			return p;
		return p->rightChild;
	}	
	
	/* 求指针p所指节点的双亲节点*/
	BinTreeNode<Type>* Parent(BinTreeNode<Type>* p)
	{
		return Parent(root, p);
	}
	
	/* 求值为key的节点的双亲节点*/
	BinTreeNode<Type>* Parent(const Type &key)
	{
		return Parent(Search(key));
	}
	
	/* 查找值为key的节点，返回其地址*/
	BinTreeNode<Type>* Search(const Type &key)
	{
		return Search(root, key);
	}
	
	/* 按层遍历二叉树*/
	void LevelOrder()
	{
		LevelOrder(root);
	}
	
	/* 判断二叉树是否为空*/
	bool Empty()const
	{
		return (root == NULL);
	}
	
	/* 判断两个二叉树是否相等*/
	bool Equal(BinTree<Type> &bt)
	{
		return Equal(root, bt.root);
	}
	
	/* 把一个树拷贝到另一个非空树中，（首先释放要拷贝的树）*/
	void Copy(const BinTree<Type> &bt)const
	{
		DistroyBinTree();
		Copy(root, (BinTreeNode<Type>*)bt.root);
	}
	
	/* 摧毁二叉树*/
	void DistroyBinTree()
	{
		DistroyBinTree(root);
	}
	///////////////////////////////////////////
	/* 递归形式 先序遍历二叉树*/
	void PreOrder()      
	{
		PreOrder(root);
	}
	
	/* 中序遍历*/
	void InOrder()   
	{
		InOrder(root);
	}
	
	/* 后序遍历*/
	void PostOrder()
	{
		PostOrder(root);
	}
	///////////////////////////////////////////
	/* 非递归形式 先序遍历二叉树（以‘_’结束） */
	void PreOrder_()   //
	{
		PreOrder_(root);
	}	
	
	void InOrder_()
	{
		InOrder_(root);
	}	
	
	void PostOrder_()
	{
		PostOrder_(root);
	}
	////////////////////////////////////////////
	
	/* 下面是各类函数的具体实现*/
private:
	
	/* 手写先序遍历字符串构造二叉树*/
	void CreateBinTree(BinTreeNode<Type> *&t)
	{
		Type Item;
		cin>>Item;
		if(Item == refvalue)
			t = NULL;
		else
		{
			t = new BinTreeNode<Type>(Item);  // 首先构造根节点
			CreateBinTree(t->leftChild);      // 构造左孩子
			CreateBinTree(t->rightChild);     // 构造右孩子
		}
	}
	
	/* 以参数形式传入先序遍历字符串，构造二叉树*/
	void CreateBinTree(BinTreeNode<Type> *&t, const char *&str)
	{
		 if(*str=='#' || *str=='\0')
			t = NULL;
		else
		{
			t = new BinTreeNode<Type>(*str);
			CreateBinTree(t->leftChild, ++str);
			CreateBinTree(t->rightChild,++str);
		}
	}
	
	/* 根据先序遍历和中序遍历的结果唯一构造二叉树，
	三个参数分别为先序遍历字符串、中序遍历字符串、树的节点个数*/
	void CreateBinTree_Pre(BinTreeNode<Type> *&t, char *VLR, char *LVR, int n)
	{
		if(0 == n)
			return ;
		else
		{
			int k = 0;
			while(VLR[0] != LVR[k])
			{
				k++;
			}
			
			t = new BinTreeNode<Type>(LVR[k]);
			CreateBinTree_Pre(t->leftChild,VLR+1,LVR,k);
			CreateBinTree_Pre(t->rightChild,VLR+k+1,LVR+k+1,n-k-1);
		}
	}
	
	/* 根据后序遍历和中序遍历的结果唯一构造二叉树，
	三个参数分别为后序遍历字符串、中序遍历字符串、树的节点个数*/
	void CreateBinTree_Post(BinTreeNode<Type> *&t, char *LRV, char *LVR, int n)
	{
		if(0 == n)
			return ;
		else
		{
			int k = n-1;
			while(LRV[n-1] != LVR[k])
				k--;
			t = new BinTreeNode<Type>(LVR[k]);
			CreateBinTree_Post(t->leftChild, LRV, LVR, k);
			CreateBinTree_Post(t->rightChild, LRV+k,LVR+k+1,n-k-1); 
		}
	}
	/* 递归形式遍历*/
	void PreOrder(BinTreeNode<Type> *t)
	{
		if(NULL != t)
		{
			cout<<t->value<<" ";
			PreOrder(t->leftChild);
			PreOrder(t->rightChild);
		}
	}
	
	void InOrder(BinTreeNode<Type> *t)
	{
		if(NULL != t)
		{
			InOrder(t->leftChild);
			cout<<t->value<<" ";
			InOrder(t->rightChild);
		}
	}
	
	void PostOrder(BinTreeNode<Type> *t)
	{
		if(NULL != t)
		{
			PostOrder(t->leftChild);
			PostOrder(t->rightChild);
			cout<<t->value<<" ";
		}
	}
	
	/* 求树中节点个数*/
	int Size(BinTreeNode<Type> *t)const
	{
		if(NULL == t)
			return 0;
		else
			return Size(t->leftChild) + Size(t->rightChild) + 1;
	}	
	
	/* 求树的高度*/
	int Height(BinTreeNode<Type> *t)const
	{
		int Height = 0;
		int lcHeight = 0;
		int rcHeight = 0;
		if(NULL != t)
		{
			lcHeight = Height(t->leftChild);
			rcHeight = Height(t->rightChild);
			Height = lcHeight>rcHeight ? lcHeight+1 : rcHeight+1;
		}
		return Height;
	}
	
	
	BinTreeNode<Type> *Parent(BinTreeNode<Type> *t, BinTreeNode<Type> *pkey)
	{
		assert(NULL != pkey);
		
		if(NULL == t)
			return NULL;
		if(t->leftChild==pkey || t->rightChild==pkey)
			return t;
		BinTreeNode<Type> *p = Parent(t->leftChild, pkey);
		if(NULL != p)
			return p;
		else 
			return Parent(t->rightChild, pkey);
	}
	
	/* 查找节点key,返回该节点的指针*/
	BinTreeNode<Type> *Search(BinTreeNode<Type> *t, const Type &key)
	{
		if(NULL == t)
			return NULL;
		else
		{
			if(t->value == key)
				return t;
			BinTreeNode<Type> *p = Search(t->leftChild, key);
			if(NULL != p)
				return p;
			return Search(t->rightChild, key);
		}		
	}	
	
	/* 判断两棵树是否相等*/
	bool Equal(const BinTreeNode<Type> *t, const BinTreeNode<Type> *p)
	{
		if(NULL==t && NULL==p)
			return true;
		if(t!=NULL && p!=NULL && t->value==p->value && Equal(t->leftChild, p->leftChild) && Equal(t->rightChild, p->rightChild))
			return true;
		return false;
	}	
	
	/* 拷贝一棵树到另一颗非空树中*/
	void Copy(BinTreeNode<Type> *&t, BinTreeNode<Type> *&p)
	{
		if(NULL == p)
			return ;
		t = new BinTreeNode<Type>(p->value);
		Copy(t->leftChild, p->leftChild);
		Copy(t->rightChild, p->rightChild);
	}
	
	/* 摧毁二叉树*/
	void DistroyBinTree(BinTreeNode<Type> *&t)
	{
		if(NULL != t)
		{
			DistroyBinTree(t->leftChild);
			DistroyBinTree(t->rightChild);
			delete t;
			t = NULL;
		}
	}
	
	/* 按层遍历二叉树，借助一个队列*/
	void LevelOrder(BinTreeNode<Type> *t)
	{
		if(NULL != t)
		{
			queue<BinTreeNode<Type>* > que;
			BinTreeNode<Type> *p;
			que.push(t);          // 根节点压入队列
			while(!que.empty())
			{
				p = que.front();
				que.pop();
				cout<<p->value<<" ";      // 出栈访问
				if(NULL != p->leftChild)
					que.push(p->leftChild);   //左孩子 先进先出【保证了左在右之前】
				if(NULL != p->rightChild)
					 que.push(p->rightChild);
			 }
		}
	}	
	
	/* 二叉树的先序遍历【非递归】，需要借助一个栈结构*/
	void PreOrder_(BinTreeNode<Type> *t)
	{
		if(NULL != t)
		{
			stack<BinTreeNode<Type>* > st;
			BinTreeNode<Type> *p;
			st.push(t);       // 把根节点入栈
			while(!st.empty())
			{
				p = st.top();   // p指向栈顶元素 
				st.pop(); 
				cout<<p->value<<" ";      // 出栈访问该节点
				if(NULL != p->rightChild)     // 该节点的右孩子压栈，保证左孩子先出栈
					st.push(p->rightChild);
				if(NULL != p->leftChild)      // 左孩子入栈
					st.push(p->leftChild);
			}
		}                       // 循环结束，栈空，二叉树访问完
		cout<<endl;
	}	
	
	/* 二叉树的中序遍历【非递归】，需要借助一个栈结构*/
	void InOrder_(BinTreeNode<Type> *t)  
	{  
		if(t==NULL)  
			return;  
		stack<BinTreeNode<Type>* > st;  
		BinTreeNode<Type>*p = t;  
		
		while (p!=NULL||!st.empty())
		{  
			while(p!=NULL)  
			{  
				st.push(p);        // 首先一直左孩子压栈
				p = p->leftChild;
			}
			p=st.top();            // p 接收栈顶元素
			st.pop();              // 出栈访问
			cout<<p->value<<" "; 
			p=p->rightChild;  	   // 指向右孩子，下一个循环 右孩子压栈
		}   
	}  
	
	/* 二叉树的后序遍历【非递归】，需要借助一个栈结构和一个结构sn（把一个节点指针和一个标记封装）*/
	void PostOrder_(BinTreeNode<Type> *t)
	{
		if(NULL != t)
		{
			stkNode<Type> sn;
			stack< stkNode<Type> > st;
			do
			{
				while(NULL != t)    // 把节点指针和标记封装
				{
					sn.str = t;
					sn.Tag = L;     // 标记为L 表示是第一次访问该节点，出栈的时候先不能访问
					st.push(sn);
					t = t->leftChild;
				}
				
				while(!st.empty())    
				{
					sn = st.top();       // sn接收栈顶元素
					t = sn.str->rightChild;    // 先记下栈顶元素的右孩子，下一个do while循环要把右孩子压栈
					st.pop();
					if(sn.Tag == L)      // 为L 表示是第一次访问该节点，出栈的时候先不能访问 
					{
						sn.Tag = R;  
						st.push(sn);     // 把标记改为R后继续把sn压栈
						break;           // 结束本次循环
					}
					else
					{
						cout<<sn.str->value<<" "; // 为R 表示是第二次访问该节点，可以访问
					}
				}
			}while(!st.empty());
		}
	}
	
private:
	BinTreeNode<Type> *root;   // 树的根
	Type refvalue;             // 根据refvalue判断一个节点是否为空
};