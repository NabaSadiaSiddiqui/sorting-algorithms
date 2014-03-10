#include<iostream>
#include<cstdio>
using namespace std;

void printMsg(int option);

int getArrSize(int *arr);
void printArr(int *arr);
int* spliceArr(int *arr, int i, int j);

int* BubbleSort(int *arr);
void BubbleSortHelper(int *arr, int i, int j);

int* InsertionSort(int *arr);
void InsertionSortHelper(int *arr, int i, int j);

int* SelectionSort(int *arr);
void SelectionSortHelper(int *arr, int i, int j);

int* MergeSort(int *arr);
bool MergeSortHelper(int *arr, int a, int b, int c, int d);

int main()
{
	int userOption;

	cout << "Choose the sorting algorithm you want to use by entering the identifier number for the algorithm (e.g. enter 1 for Bubble Sort).\n\t1. Bubble sort\n\t2. Insertion sort\n\t3. Selection sort\nEnter your selection now: ";
	
	cin >> userOption;

	if(cin.eof())
		cout << "\nYou chose to terminate the program.\n";
	else
	{
		
		int tmpArr [5] = {3, 9, 6, 5, 4};
		int *arr = tmpArr;
		int *sortedArr;

		switch(userOption) {
			case 1:
				printMsg(0);
				printArr(arr);
				sortedArr=BubbleSort(arr);
				printMsg(1);
				printArr(sortedArr);
				break;
			case 2:
				printMsg(0);
				printArr(arr);
				sortedArr=InsertionSort(arr);
				printMsg(2);
				printArr(sortedArr);
				break;
			case 3:
				printMsg(0);
				printArr(arr);
				sortedArr=SelectionSort(arr);
				printMsg(3);
				printArr(sortedArr);
				break;
			default:
				cout << "Your input is invalid. Exiting program now...\n";
				break;
		}

	}

	return 0;
}

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

//Input: Integer array arr
//Output: Array sorted using merge sort algorithm
int* MergeSort(int *arr)
{
	int arrLen=getArrSize(arr);
	int n=arrLen;	//number of sublists
	int el_max=1;	//maximum number of elements per sublist
	bool evaluate=false;
	while(n>0)
	{
		for(int i=0; i<arrLen; i++)
		{
			if(MergeSortHelper(arr, i, i+el_max-1, i+el_max, i+(el_max*2)-1))
			{
				evaluate=true;
				break;
			}
			i=i+(el_max*2);
		}
		
		if(!evaluate)
		{
			n=(n/(el_max*2))+1;
			el_max *= 2;
		}
		else
		{
			n=0;
		}
	}

	return arr;
}

//Helper function to merge sublistA=arr[a:b] and sublistB=arr[c:d], and return the merged list
bool MergeSortHelper(int *arr, int a, int b, int c, int d)
{
	int *sublistA=spliceArr(arr, a, b);
	int *sublistB=spliceArr(arr, c, d);

	if(sublistB==NULL) {
		arr=sublistA;
		return true;
	}

	else
	{
		int lenA=getArrSize(sublistA);
		int lenB=getArrSize(sublistB);
		int countMax=lenA+lenB;

		for(int i=0; i<countMax; i++)
		{
			int *tmpArr=new int[countMax];
			if(sublistA[i]<sublistB[i])
				tmpArr[i]=sublistA[i];
			else
				tmpArr[i]=sublistB[i];
		}
			
	
		return false;
	}
}

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

void printMsg(int option)
{
	switch(option) {
		case 0:	//Special case to print the message right before sending unsorted array to stdout
			cout << "\nUnsorted array elements are:\n";
			break;
		case 1:
			cout << "\nArray elements organized using bubble sort:\n";
			break;
		case 2:
			cout << "\nArray elements organized using insertion sort:\n";
			break;
		case 3:
			cout << "\nArray elements organized using selection sort:\n";
			break;
		default:
			cout << "\nUnknown option\n";
			break;
	}
	
	return;
}
