#include<iostream>
#include<cstdio>
#include<cstdlib>
#include "../include/arrFunc.h"
#include "../include/bubbleSort.h"
#include "../include/insertionSort.h"
#include "../include/selectionSort.h"

using namespace std;

void printMsg(int option);

int main(int argc, char *argv[])
{
	//Check input for array
	if(argc!=2)
	{
		cout << "ERROR::Please provide array for sorting. Array elements should be entered as a string of white-space separated numbers, e.g. \"1 2 3 4 5\".\n\t$ ./sort <array of int>\n";
		exit(EXIT_FAILURE);
	}

	cout << "Choose the sorting algorithm you want to use by entering the identifier number for the algorithm (e.g. enter 1 for Bubble Sort).\n\t1. Bubble sort\n\t2. Insertion sort\n\t3. Selection sort\nEnter your selection now: ";
	
	int *arr=splitArr(argv[1]);
	int userOption;
	cin >> userOption;

	while(!cin.eof()) 
	{	
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
				exit(EXIT_FAILURE);
				break;
		}

		for(int i=0; i<50; i++)
		{
			cout << "--";
		}

		cout << "\n\nChoose a sorting algorithm again.\n1.Bubble sort\n2.Insertion sort\n3.Selection sort\nEnter your selection now: ";
		cin >> userOption;

	}
	
	if(cin.eof())
		cout << "\n\n\nYou chose to terminate the program.\n";
	
	return 0;
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
