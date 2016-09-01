//
//  testMergeSort.cpp
//  Aug2016 Practice
//
//  Created by Anna Dodd on 8/24/16.
//  Copyright © 2016 Anna Dodd. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <iostream>
#include <assert.h>
#include "MergeSort.h"
#include <stdlib.h>

void compare(int actual[], int expected[], int size)
{
	for (int ii = 0; ii < size; ++ii)
	{
		assert(actual[ii] == expected[ii]);
	}
}

using namespace std;

int main()
{
	// Testing Merge sort
	// Input: list to search, size of list

	// Input Variables:
	// Variable 1: Number of elements in list

	// Case: 0
	mergeSort(0, 0);

	// Case: 1
	int arr0Size = 1;
	int arr0 = 4;
	int arr0Expected = 4;
	mergeSort(&arr0, arr0Size);
	compare(&arr0, &arr0Expected, arr0Size);

	// Case: Power of 2, with repeated element
	int arr1Size = 8;
	int arr1[] = {3,4,623,-1,0,87,-29,87};
	int arr1Expected[] = {-29,-1,0,3,4,87,87,623};
	mergeSort(arr1, arr1Size);
	compare(arr1, arr1Expected, arr1Size);

	// Case: Non power of 2
	int arr2Size = 9;
	int arr2[] = {84,3,4,623,-1,0,87,-29,87};
	int arr2Expected[] = {-29,-1,0,3,4,84,87,87,623};
	mergeSort(arr2, arr2Size);
	compare(arr2, arr2Expected, arr2Size);

	// Variable 2: Order of elements in list

	// Case: Sorted
	int arr3Size = 8;
	int arr3[] = {-29,-1,0,3,4,87,87,623};
	int arr3Expected[] = {-29,-1,0,3,4,87,87,623};
	mergeSort(arr3, arr3Size);
	compare(arr3, arr3Expected, arr3Size);

	// Case: Reverse sorted
	int arr4Size = 9;
	int arr4[] = {623,87,87,84,4,3,0,-1,-29};
	int arr4Expected[] = {-29,-1,0,3,4,84,87,87,623};
	mergeSort(arr4, arr4Size);
	compare(arr4, arr4Expected, arr4Size);

	// Case: One element out of order
	int arr5Size = 9;
	int arr5[] = {-1,-29,0,3,4,84,87,87,623};
	int arr5Expected[] = {-29,-1,0,3,4,84,87,87,623};
	mergeSort(arr5, arr5Size);
	compare(arr5, arr5Expected, arr5Size);

	// Case: Completely out of order
	int arr6Size = 100;
	int arr6[] = {7,49,73,58,30,72,44,78,23,9,40,65,92,42,87,3,27,29,40,12,3,
		69,9,57,60,33,99,78,16,35,97,26,12,67,10,33,79,49,79,21,67,72,93,36,85,
		45,28,91,94,57,1,53,8,44,68,90,24,96,30,3,22,66,49,24,1,53,77,8,28,33,
		98,81,35,13,65,14,63,36,25,69,15,94,29,1,17,95,5,4,51,98,88,23,5,82,52,
		66,16,37,38,44};
	int arr6Expected[] = {1,1,1,3,3,3,4,5,5,7,8,8,9,9,10,12,12,13,14,15,16,16,
		17,21,22,23,23,24,24,25,26,27,28,28,29,29,30,30,33,33,33,35,35,36,36,37,
		38,40,40,42,44,44,44,45,49,49,49,51,52,53,53,57,57,58,60,63,65,65,66,66,
		67,67,68,69,69,72,72,73,77,78,78,79,79,81,82,85,87,88,90,91,92,93,94,94,
		95,96,97,98,98,99};
	mergeSort(arr6, arr6Size);
	compare(arr6, arr6Expected, arr6Size);

	cout << "Test succeeded.\n";
	return 0;
}
