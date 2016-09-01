//
//  main.cpp
//  Aug2016 Practice
//
//  Created by Anna Dodd on 8/24/16.
//  Copyright © 2016 Anna Dodd. All rights reserved.
//

#include <iostream>

// Helper
void copyArray(int* source, int* dest, int size);
void printArray(int source[], int size);

// Recursive merge sort implementation
void mergeSort(int arr[], int size)
{
	// 1. Check for base case: size 0 or size 1 array (return if so)
	if (size <= 1)
	{
		return;
	}

	// 2. Split array--find starting pts and corresponding size
	int sizePartition1 = size / 2;
	int sizePartition2 = size - sizePartition1;
	int partition1[sizePartition1];
	int partition2[sizePartition2];

	copyArray(arr, partition1, sizePartition1);
	copyArray(arr + sizePartition1, partition2, sizePartition2);

	// 3. Recursive call
	mergeSort(partition1, sizePartition1); // [0, sizePartition1)
	mergeSort(partition2, sizePartition2); // [sizePartition1, sizePartition2)

	int ii = 0;
	int idxP1 = 0;
	int idxP2 = 0;

	// 4. Merge the resulting partitions (these partitions are sorted by now)
	while ((ii < size) && (idxP1 < sizePartition1) && (idxP2 < sizePartition2))
	{
		if (partition1[idxP1] < partition2[idxP2])
		{
			arr[ii++] = partition1[idxP1++];
		}
		else
		{
			arr[ii++] = partition2[idxP2++];
		}
	}
	while (idxP1 < sizePartition1)
	{
		arr[ii++] = partition1[idxP1++];
	}
	while (idxP2 < sizePartition2)
	{
		arr[ii++] = partition2[idxP2++];
	}
}
void copyArray(int* source, int* dest, int size)
{
	for (int ii = 0; ii < size; ++ii)
	{
		dest[ii] = source[ii];
	}
}
void printArray(int source[], int size)
{
	for (int ii = 0; ii < size; ++ii)
	{
		std::cout << source[ii] << "\t";
	}
	std::cout << "\n";
}
