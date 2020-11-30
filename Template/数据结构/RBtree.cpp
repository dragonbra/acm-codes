template<class T>
struct RBtree{
    #define l _M_left
    #define r _M_right
    #define p _M_parent
    #define node _Rb_tree_node_base
#if __cplusplus<=199711L
    #define key _M_value_field.first
    #define size _M_value_field.second
#else  //c++11
    #define key _M_storage._M_ptr()->first
    #define size _M_storage._M_ptr()->second
#endif
    typedef _Rb_tree_node<pair<const T,int> > Node; map<T,int> M;
    void fix_size(node *it){
        int &it_size=static_cast<Node*>(it)->size;it_size=1;
        if (it->l)it_size+=static_cast<Node*>(it->l)->size;
        if (it->r)it_size+=static_cast<Node*>(it->r)->size;
    }
    void fix_all(node *it,node *end){
        for (;;it=it->p){
            if (it->l)fix_size(it->l);if (it->r)fix_size(it->r);
            if (it->p==end){fix_size(it);break;}
        }
    }
    void insert(const T &x){
        pair<typename map<T,int>::iterator,bool> it=M.insert(make_pair(x,0));
        if (!it.second)return;
        fix_all(it.first._M_node,M.end()._M_node);
    }
    int select(int k){
        node *p=get_root();
        while (k){
            int sizel=p->l?static_cast<Node*>(p->l)->size:0;
            if (k==sizel+1)break;
            if (k<=sizel)p=p->l;
            else k-=sizel+1,p=p->r;
        }
        return static_cast<Node*>(p)->key;
    }
    int rank(int x){
        node *p=get_root(); int res=0;
        while (p){
            int y=static_cast<Node*>(p)->key;
            int s=p->l?static_cast<Node*>(p->l)->size:0;
            if (y<=x)res+=s+1,p=p->r;
            else p=p->l;
        }
        return res;
    }
    node *get_root(){
        node *it=M.begin()._M_node;
        while (it->p!=M.end()._M_node)it=it->p;
        return it;
    }
    void print(){print_node(get_root(),"");}
    void print_node(const node *it,string str){
        if (!it){cout<<str<<"nil (0)"<<endl;return;}
        cout<<str<<static_cast<const Node*>(it)->key;
        cout<<"("<<static_cast<const Node*>(it)->size<<")"<<endl;
        print_node(it->l,str+"    "); print_node(it->r,str+"    ");
    }
    #undef l
    #undef r
    #undef p
    #undef node
    #undef key
    #undef size
};
RBtree<int> a;