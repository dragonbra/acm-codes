#include <stdio.h>
int main()
{
	int n,max,p,k;
	int c[1001];
    int T;
	while (~scanf("%d", &T)) {
        scanf("%d",&T);
        while(T--)
        {
            for(int j=0;j<26;j++)
            {
                c[j]=0;
            }
            char s[1001];
            scanf("%s",&s);
            for(int j=0;s[j]!='\0';j++)
            {
                if(s[j]>='A'&&s[j]<='Z')
                {
                    s[j]+=32;
                } 
            }
            for(int j=0;s[j]!='\0';j++)
            {
                c[s[j]-'a']+=1;
            }
            max=0;
            p=0;
            for(int j=0;j<26;j++)
            {
                if(c[j]>max)
                {
                    max=c[j];
                    p=j;
                }
            }
            printf("%c\n",p+'a');
        }
    }
	return 0;
}
