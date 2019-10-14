//Implementing Selection Sort
#include <iostream>
#include <stdio.h>
using namespace std;

int main(void)
{
	int n;
	cout<<"\nHow many elements you want in array : ";
	cin>>n;
	
	int a[100];
	int i,j,k;
	
	for(i=0 ; i<n ; i++){
		cout<<"\nEnter element "<<i+1<<" : ";
		cin>>a[i];
	}
	
	cout<<"\nThe entered array is : \n";
	for(i=0 ; i<n ; i++)
		cout<<a[i]<<" ";
	
	cout<<endl<<endl;
	
	printf("%5s","Pass");

		printf("%s","     ");
		
	printf("%s","Output");
	printf("%25s %10s\n","Comparisons", "Swaps");
	
	//In one iteration min comes to correct place
	
	int min,temp,comp,swap;
	for(i=0 ; i<n-1 ; i++)
	{
		comp=0;
		swap=0;
		printf("%5d",i+1);
		printf("%s","     ");
		min=a[i];
		for(j=i+1 ; j<n ; j++)
		{
			comp++;
			if(a[j]<min)
			{
				min=a[j];
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
				swap++;
			}
		}
		for(k=0 ; k<n ; k++)
			cout<<a[k]<<" ";
			
		printf("%16d %10d\n",comp,swap);
	}	
	

	return 0;
}
