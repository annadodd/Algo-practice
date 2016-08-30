//
//  testMergeSort.cpp
//  Aug2016 Practice
//
//  Created by Anna Dodd on 8/24/16.
//  Copyright © 2016 Anna Dodd. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include "MergeSort.h"

using namespace std;

int main()
{
	// Merge sort input: list to search
	// Variables:
	// Number of elements in list
		// 0
		// 1
		// Power of 2
		// Non power of 2
	// Order of elements in list
		// Sorted
		// Reverse sorted
		// One element out of order
		// Out of order
	// Content of elements
		// All positive
		// All negative
		// Mix
	// Also try:
		// Smarter merge sort which can identify reversely sorted lists
		// Divide list into three (why does this not matter?, asymptotically equal)
		// In place merge sort...

	/*// Test 1: Zero elements
	int* zeroArray = 0;
	mergeSort(zeroArray, 0);

	int oneElemArr[] = {1};
	mergeSort(oneElemArr, 1);*/

	int pwTwoArr[] = {3,4,623,-1,0,87,-29,84};
	mergeSort(pwTwoArr, 8);
	printArray(pwTwoArr, 8);


	int ranArr[] = {4, 5, 1, 20, -1, 0};
	mergeSort(ranArr, 6);
	printArray(ranArr, 6);
	
	
}
