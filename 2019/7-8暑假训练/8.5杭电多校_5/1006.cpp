#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;   //字符串长度最大值

char s[maxn];
int _next[maxn],ex[maxn]; //ex数组即为extend数组
//预处理计算__next数组

void GET_next(char *str)
{
    int i=0,j,po,len=strlen(str);
    _next[0]=len;//初始化_next[0]
    while(str[i]==str[i+1]&&i+1<len)//计算_next[1]
    i++;
    _next[1]=i;
    po=1;//初始化po的位置
    for(i=2;i<len;i++)
    {
        if(_next[i-po]+i<_next[po]+po)//第一种情况，可以直接得到_next[i]的值
        _next[i]=_next[i-po];
        else//第二种情况，要继续匹配才能得到_next[i]的值
        {
            j=_next[po]+po-i;
            if(j<0)j=0;//如果i>po+_next[po],则要从头开始匹配
            while(i+j<len&&str[j]==str[j+i])//计算_next[i]
            j++;
            _next[i]=j;
            po=i;//更新po的位置
        }
    }
}

//计算extend数组
void EXKMP(char *s1,char *s2)
{
    int i=0,j,po,len=strlen(s1),l2=strlen(s2);
    GET_next(s2);//计算子串的_next数组
    while(s1[i]==s2[i]&&i<l2&&i<len)//计算ex[0]
    i++;
    ex[0]=i;
    po=0;//初始化po的位置
    for(i=1;i<len;i++)
    {
        if(_next[i-po]+i<ex[po]+po)//第一种情况，直接可以得到ex[i]的值
        ex[i]=_next[i-po];
        else//第二种情况，要继续匹配才能得到ex[i]的值
        {
            j=ex[po]+po-i;
            if(j<0)j=0;//如果i>ex[po]+po则要从头开始匹配
            while(i+j<len&&j<l2&&s1[j+i]==s2[j])//计算ex[i]
            j++;
            ex[i]=j;
            po=i;//更新po的位置
        }
    }
}

int main(){
	int T;cin>>T;
	while(T--){
		scanf("%s",s);
		EXKMP(s,s);
		int len=strlen(s);ll cnt=len-1;
		//for(int i=1;i<len;i++) cout<<ex[i]<<' ';cout<<endl;
		for(int i=len-1;i>0;i--){
			if(ex[i]!=0&&(i+ex[i]==len)){
				cnt+=ex[i];cnt-=1;
			}
			else cnt+=ex[i];
		}
		printf("%lld\n",cnt);
	}
	return 0;
}
