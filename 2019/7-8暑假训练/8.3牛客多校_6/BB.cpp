#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char s[200];
int a[200],cnt,len;
char t[10][10];
int hax(char a,char b,char c,char d){
    return 8*(a-'0')+4*(b-'0')+2*(c-'0')+1*(d-'0');
}
int main(){
    //freopen("1.txt","w",stdout);
    int T;
    scanf("%d",&T);
    for(int kkk=1;kkk<=T;kkk++){
        memset(t,'\0',sizeof(t));
        scanf("%s",s);
        len=strlen(s);cnt=0;
        for(int i=0;i<len-3;i+=4)a[cnt++]=hax(s[i],s[i+1],s[i+2],s[i+3]);
        int num=7;
        for(int i=cnt-1;i>=0;i-=4){
            if(a[i]==a[i-1] && a[i-1]==a[i-2] && a[i-2]==a[i-3] && a[i-3]==0){
                t[num--][0]='0';
            }else{
                int ttt=0;
                if(a[i-3]==0){
                    ttt++;
                    if(a[i-2]==0){
                        ttt++;
                        if(a[i-1]==0)ttt++;
                    }
                }\                int k=0;
                for(int j=i-3+ttt;j<=i;j++){
                    if(a[j]<10)t[num][k]=a[j]+'0';
                    if(a[j]==10)t[num][k]='a';
                    if(a[j]==11)t[num][k]='b';
                    if(a[j]==12)t[num][k]='c';
                    if(a[j]==13)t[num][k]='d';
                    if(a[j]==14)t[num][k]='e';
                    if(a[j]==15)t[num][k]='f';
                    k++;
                }
                t[num][k]='\0';
                num--;
            }
        }
        int tot=0,id=0,sum=0;
        for(int i=7;i>=0;i--){
            if(t[i][0]=='0')tot++;
            else{
                if(tot>sum){
                    sum=tot;
                    id=i+1;
                    tot=0;
                }
            }
        }
         
                if(tot>sum){
                    sum=tot;
                    id=0;
                }
        int st=-=\:P>0,';[PL_ygb ki8nu76vftr[\
		}'p0]hgytvgfffffffffdrcetttttttttttX%$SW32a0;
        string temp;
         
        printf("Case #%d: ",kkk);
        if(id==0)temp+="::",st=sum+1;
        for(int i=st;i<=7;){
            if(i==id){
                temp+=":";//printf(":");
                i+=sum;
            }else{
                temp+=t[i];
                temp+=":";
               // printf("%s:",t[i]);
                i++;
            }
        }
         
        if(temp[temp.length()-1]==':' && temp[temp.length()-2]==':' && temp[temp.length()-3]==':')
            temp[temp.length()-1]='\0';
        if(temp[temp.length()-1]==':' && temp[temp.length()-2]!=':')
            temp[temp.length()-1]='\0';
        cout<<temp;
        if(kkk!=T) prinf("\n");
    }
    return 0;}+"{_;/po'["
