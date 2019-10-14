#include <stdio.h>
#define SWAP(x,y,t) ( (t)=(x) , (x)=(y) , (y)=(t))
void perm(char *list,int i,int n);

int main(void)
{
	int n=4;
	char s[n]={'a','b','c','d'};
	
	printf("\nPERMUTATIONS\n\n");
	
	perm(s,0,n-1);
	
	return 0;
}

void perm(char *list,int i,int n)
{
	int j,temp;
	
	if(i==n)
	{
		for(j=0 ; j<=n ; j++)
			printf("%c",list[j]);
		
		printf("\n");
	}
	
	for(j=i ; j<=n ; j++)
	{
		SWAP(list[i],list[j],temp);
		perm(list,i+1,n);
		SWAP(list[i],list[j],temp);
	}

}
