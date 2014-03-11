#include<iostream>
#include "../include/selectionSort.h"
#include "../include/arrFunc.h"
using namespace std;

//Input: unsorted Integer array arr
//Output: array sorted using selection sort algorithm
int* SelectionSort(int *arr)
{
	int arrLen=getArrSize(arr);

	for(int i=0; i<arrLen; i++)
	{
		int minNum=arr[i];
		int swapIndex=i;
	
		for(int j=i+1; j<arrLen; j++)
		{
			if(arr[j]<minNum)
			{
				minNum=arr[j];
				swapIndex=j;
			}
		}

		SelectionSortHelper(arr, i, swapIndex);
	}
	
	return arr;
}

//Helper function to swap arr[i] and arr[j]
void SelectionSortHelper(int *arr, int i, int j)
{
	if(i==j)
		return;
	else {
		int tmp=arr[i];
		arr[i]=arr[j];
		arr[j]=tmp;
	}
	
	return;
}
