#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define COMPARE(x,y) ( (x)>(y) ? 1 : ((x)==(y) ? 0 : -1) )
using namespace std;

int binsearch(int[],int,int,int);

int main(void)
{
	int n;
	cout<<"\nHow many integers you wanna enter : ";
	cin>>n;
	
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
		cout<<"\nEnter integer "<<i+1<<" : ";
		cin>>p[i];
	}
	
	cout<<endl<<"The entered array is : ";
	for(i=0 ; i<n ; i++)
		cout<<p[i]<<" ";
	
	sort(p,p+n);
	cout<<endl<<endl<<"The sorted array is  : ";
	for(i=0 ; i<n ; i++)
		cout<<p[i]<<" ";
		
	int searchnum;
	cout<<"\n\nEnter the no. you wanna search for : ";
	cin>>searchnum;
	
	int x = binsearch(p,searchnum,0,n-1);
	
	if(x==-1)
		cout<<"\nNumber "<<searchnum<<" NOT FOUND in array\n"<<endl;
	else
		cout<<"\nNumber "<<searchnum<<" present at INDEX : "<< x <<endl<<endl;

	return 0;
}

int binsearch(int list[],int searchnum,int left,int right)
{
	int middle;
	
	if(left<=right)
	{
		middle=(left+right)/2;
		switch(COMPARE(list[middle],searchnum))
		{
			case 1:
				return binsearch(list,searchnum,left,middle-1);
		
			case 0:
				return middle;
				
			case -1:
				return binsearch(list,searchnum,middle+1,right);
		}
	}
	
	return -1;
}





