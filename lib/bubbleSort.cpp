#include<iostream>
#include "../include/bubbleSort.h"
#include "../include/arrFunc.h"
using namespace std;

//Input: Integer array arr
//Output: Array sorted using bubble sort algorithm
int* BubbleSort(int *arr)
{

	int arrLen = getArrSize(arr);
	int index=arrLen;
	
	while(index>0)
	{
		for(int i=0; i<index; i++)
		{
			int j=i+1;
			
			if(j==arrLen)
				break;

			if(arr[i] > arr[j])
				BubbleSortHelper(arr, i, j);
		}
		index--;
	}

	return arr;
}

//Helper function to swap arr[i] and arr[j]
void BubbleSortHelper(int *arr, int i, int j)
{
	int tmp = arr[i];
	arr[i]=arr[j];
	arr[j]=tmp;
	
	return;
}
