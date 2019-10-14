/*Non-Recursive implementation of Binary Search*/
#include <stdio.h>
#include <stdlib.h>
#define COMPARE(x,y) ( (x)>(y) ? 1 : ( (x)==(y) ? 0 : -1 ) )
int binsearch(int[],int,int,int);

int main(void)
{
	int n;
	printf("\nHow many integers you wanna enter : ");
	scanf("%d",&n);
	
	int *p = (int*)malloc(n*sizeof(int));
	if(NULL==p)
	{
		puts("Insufficient Memory");
		fprintf(stderr,"Insufficient Memory");
		exit(EXIT_FAILURE);
	}
	
	int i;
	for(i=0 ; i<n ; i++)
	{
		printf("\nEnter integer %d : ",i+1);
		scanf("%d",(p+i));
	}
	
	printf("\nThe entered array is : \n");
	for(i=0 ; i<n ; i++)
		printf("%d ",*(p+i));
	
	int searchnum;
	printf("\n\nEnter the no. to be searched for : ");
	scanf("%d",&searchnum);
	
	int x = binsearch(p,searchnum,0,n-1);
	
	if(x==-1)
		printf("\nNumber %d not present in array\n",searchnum);
	else
		printf("\nNumber %d is present at index : %d\n",searchnum,x);
	
	free(p);
		
	return 0;	
}


int binsearch(int list[],int searchnum,int left,int right)
{
	int middle;
	while(left<=right)
	{
		middle=(left+right)/2;
		
		switch(COMPARE(list[middle],searchnum))
		{
			case 1:
				right=middle-1;
				break;
				
			case 0:
				return middle;
				break;
				
			case -1:
				left=middle+1;
				break;
		}
	}
	
	return -1;
}








