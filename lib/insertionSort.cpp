#include<iostream>
#include "../include/insertionSort.h"
#include "../include/arrFunc.h"
using namespace std;

//Input: Integer array arr
//Output: Array sorted using insertion sort algorithm
int* InsertionSort(int *arr)
{
	int arrLen = getArrSize(arr);
	
	for(int i=1; i<arrLen; i++)
	{
		int tarEl = arr[i];

		for(int j=0; j<i; j++)
		{
			if(tarEl < arr[j])
			{
				InsertionSortHelper(arr, i, j);
				break;
			}
		}

	}	

	return arr;
}

//Helper function to insert arr[i] into position j of the array arr, and accordingly shift elements i+1 through arrLen
void InsertionSortHelper(int *arr, int i, int j)
{
	int arrLen = getArrSize(arr);
	int tarEl = arr[i];

	int *tmpArr = spliceArr(arr, j, i-1);

	arr[j]=tarEl;
	int pos=j+1;
	for(int k=0; k<getArrSize(tmpArr); k++)
	{
		arr[pos]=tmpArr[k];
		pos++;
	}

	return;
}
