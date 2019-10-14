/*Implementing Merge Sort(Iterative)*/
#include <stdio.h>
#include <stdlib.h>

void merge(int initList[], int mergedList[], int i, int m, int n);
void mergePass(int initList[], int mergedList[], int n, int s);
void mergeSort(int a[], int n);

int main(void)
{
	int n;
	printf("\nHow many elements you want in array : ");
	scanf("%d",&n);
	
	int arr[100];
	int i,j,k;
	
	for(i=0 ; i<n ; i++){
		printf("\nEnter element %d : ",i+1);
		scanf("%d",&arr[i]);
	}
	
	printf("\nThe entered array is : \n");
	for(i=0 ; i<n ; i++)
		printf("%d ",arr[i]);
		
	printf("\n\n");
	mergeSort(arr,n);
	
	printf("\nThe sortrd array is : \n");
	for(i=0 ; i<n ; i++)
		printf("%d ",arr[i]);
		
	printf("\n\n");
	return 0;
}


void merge(int initList[], int mergedList[], int i, int m, int n)
{
	int k=i;
	int j=m+1;
	
	while(i<=m && j<=n)
	{
		if(initList[i]<initList[j])
		{
			mergedList[k] = initList[i];
			k++;
			i++;
		}else if(initList[i]>initList[j])
		{
			mergedList[k] = initList[j];
			k++;
			j++;
		}else{
			mergedList[k] = initList[i];
			i++;
			j++;
			k = k+2;
		}
	}
	
	while(i<=m)
	{
		mergedList[k] = initList[i];
		i++;
		k++;
	}
	
	while(j<=n)
	{
		mergedList[k] = initList[j];
		j++;
		k++;
	}
}

void mergePass(int initList[], int mergedList[], int n, int s)
{
	int i,j;
	for(i=0 ; i<=n-2*s ; i+=2*s)
	{
		merge(initList,mergedList,i,i+s-1,i+2*s-1);
	}
	if(i+s-1 < n-1)
		merge(initList,mergedList,i,i+s-1,n-1);
	else{
		for(j=i ; j<=n-1 ; j++)
			mergedList[j]=initList[j];
	}
	
	for(i=0 ; i<n ; i++)
		printf("%d ",mergedList[i]);
	
	printf("\n");
}

void mergeSort(int a[],int n)
{
	int s=1;
	int extra[n];
	
	while(s<n)
	{
		mergePass(a,extra,n,s);
		s = s*2;
		
		mergePass(extra,a,n,s);
		s = s*2;		
	}
}








