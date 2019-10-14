/*Quick Sort*/
#include <stdio.h>
#include <stdlib.h>
#define SWAP(x,y,t) ((t)=(x) , (x)=(y), (y)=(t))
void quickSort(int arr[],int left,int right);

int main(void){
	int a[11] = {26,5,37,1,61,11,59,15,48,19,__INT_MAX__};
	//We have to ensure that last element is greater than or
	//equal to all other elements.
	printf("\nInitial array : \n");
	int i;
	for(i=0;i<10;i++)
		printf("%d ",a[i]);
	printf("\n");
	
	quickSort(a,0,9);

	printf("\nSorted array : \n");
	for(i=0;i<10;i++)
		printf("%d ",a[i]);
	printf("\n");
	
	return 0;
}

void quickSort(int arr[],int left,int right){
	int i,j,pivot,tmp;

	if(left < right){
		i = left; j=right+1;
		pivot = arr[left]; //Selecting leftmost as pivot(can select any)
		do{
			//Reordering the array such that elements
			//less than or equal to pivot and greater than or equal
			//to pivot are segregated
			do{i++;}while(arr[i]<pivot);
			do{j--;}while(arr[j]>pivot);
			if(i<j)
				SWAP(arr[i],arr[j],tmp);
		}while(i<j);
		SWAP(arr[left],arr[j],tmp);
		quickSort(arr,left,j-1);
		quickSort(arr,j+1,right);
	}

}
