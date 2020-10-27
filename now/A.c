#include <stdio.h>

int z;
int g(int a,int z)
{
int e;
e=5;
        do{
	z=a+z;
	e=e-1;
	}while(e>0);
return z;
}
void f(void)
{
int a,k;
for(a=0;a<10;a=a+1)
	{
	k=0;
	while(k<5)
		{
		z=[g(a,z)];
		k=k+1;
		}
	}
}
void main(void)
{
[f()];
}