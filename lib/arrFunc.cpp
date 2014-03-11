#include<iostream>
#include "../include/arrFunc.h"
using namespace std;

int getArrSize(int *arr)
{
	if(arr==NULL)
		return 0;

	int count=0;
	while(arr[count]!='\0')
	{
		count++;
	}

	return (count--);
}

void printArr(int *arr)
{
	int arrLen=getArrSize(arr);
	for(int i=0; i<arrLen; i++)
		cout << arr[i] << " ";

	cout << "\n";

	return;
}

//Return arr[i:j]
int* spliceArr(int *arr, int i, int j)
{
	//Error handling
	int arrLen=getArrSize(arr);
	if(i<arrLen && j>=arrLen)
		j=arrLen-1;
	else if(i>=arrLen || j>=arrLen || i<0 || j<0)
		return NULL;

	int arrSize=j-i+1;
	int *newArr=new int[arrSize];
	int pos=i;

	for(int k=0; k<arrSize; k++)
	{
		newArr[k]=arr[pos];
		pos++;
	}
	
	return newArr;
}

//Split a string arr (whose elements are integers) into an array of substrings. The separator is ' '. It returns the new array
int* splitArr(char *arr)
{
	if(arr==NULL)
		return NULL;

	//Get len of arr
	int arrLen=0;
	while(arr[arrLen])
		arrLen++;
	
	//Create a new array arrInt and assign it values from arr which are not white spaces
	int *arrInt=new int[arrLen/2];
	int pos=0;
	for(int i=0; i<arrLen; i++)
	{
		if(arr[i]!=' ')
		{
			arrInt[pos]=arr[i]-48;
			pos++;
		}
	}

	return arrInt;
}
