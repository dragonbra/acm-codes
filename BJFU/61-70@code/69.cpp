#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
char s[N];

bool judge(char c){        
	return c>='0'&&c<='9';
}

struct node{
	char c;
	int num;
	node* left;
	node* right;
};

typedef node* tree;

tree build(int l,int r){          
	tree p=new node;
	p->c='#';
	p->left=NULL;
	p->right=NULL;
	int a=0;
	int i;
	bool flag=false;
	while(l<r&&s[l]=='('&&s[r]==')') l++,r--;
	vector<int> v;
	for(i=l;i<=r;i++){
		if(!judge(s[i])&&s[i]!='('&&s[i]!=')'&&a==0){  
			if(s[i]=='+'||s[i]=='-'){      
				flag=true;
				p->c=s[i];
				p->left=build(l,i-1);
				p->right=build(i+1,r);
				break;
			}
			else{
				v.push_back(i); 
			}	
		}
		else if(s[i]=='(') a++;
		else if(s[i]==')') a--;
	}	
	if(!flag&&v.size()>0){ 
	    int m=v.size()-1;  
		p->c=s[v[m]];
		p->left=build(l,v[m]-1);
		p->right=build(v[m]+1,r);
	}
	if(l==r) {     
	   p->c=s[l];
	   p->num=s[l]-'0';
	};
	return p;
} 

void print(tree t){     
	if(t->left!=NULL) print(t->left);
	if(t->right!=NULL) print(t->right);
	if(t->left==NULL&&t->right==NULL) printf("%c",t->c);
}

int js(tree t){   
	if(t->left!=NULL&&t->right!=NULL){    
		if(t->c=='*') t->num=js(t->left)*js(t->right);
		else if(t->c=='/') t->num=js(t->left)/js(t->right);
		else if(t->c=='+') t->num=js(t->left)+js(t->right);
		else if(t->c=='-') t->num=js(t->left)-js(t->right);
	}
    return t->num;
}

int main(){
	while(~scanf("%s",s)){
		if(s[0]=='=') break;
		int len=strlen(s);
		int l=0,r=len-2; 
	    tree T=build(l,r);
	    int t=js(T);
	    cout<<t<<endl;
	}
}