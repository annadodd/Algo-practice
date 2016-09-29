#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// assumes [start, end] is inclusive range of indices
int partition(vector<int>& arr, int start, int end) {
	// Always select the last element in the 'sub-array' as a pivot.'
	int p = arr[end];

	int leftPartitionSize = 0;
	int rightPartitionSize = 0;

	int leftStartIdx = start;
	int rightStartIdx = start;



	for (int i = start; i < end; ++i) {
		if (arr[i] <= p) {

			/*
			 If an element is lower than the pivot, you should swap it
			 with a larger element on the left-side of the sub-array.
			 */
			//cout << "swap " << arr[i] << " and " << arr[rightStartIdx] << "\n";
			swap(arr[i], arr[rightStartIdx]);

			leftPartitionSize += 1;
			rightStartIdx += 1;
		}
		else {
			// Stay put
			rightPartitionSize += 1;
		}
	}
	swap(arr[end], arr[rightStartIdx]);
	/*
	 At the end of the partitioning method, the pivot
	 should be swapped with the first element of the right
	 partition, consisting of all larger elements, of the sub-array.
	 */

	for (int i = 0; i < arr.size(); ++i) {
		cout << arr[i] << " ";
	}
	cout << endl;

	// Returns index where pivot value is placed
	int pivotIdx = end;
	//cout << "pivot index : " << rightStartIdx << endl;
	return rightStartIdx;
}
// assumes [start, end] is inclusive range of indices
void quicksort(vector<int>& arr, int start, int end) {
	// Base case
	// Compute size:
	int size = end - start + 1;
	if (size <= 1) {
		return;
	}
	// Partition
	int pivotIdx = partition(arr, start, end);
	int leftStart = start;
	int leftEnd = pivotIdx - 1;

	int rightStart = pivotIdx + 1;
	int rightEnd = end;

	// Call on left, right with corresponding indices
	//cout << "doing left hand side, start: " << leftStart << " end: " << leftEnd << endl;
	quicksort(arr, leftStart, leftEnd);
	//cout << "doing right hand side, start: " << rightStart << " end: " << rightEnd << endl;
	quicksort(arr, rightStart, rightEnd);


}


int main()
{
	int n;
	cin >> n;

	vector <int> arr(n);
	for(int i = 0; i < (int)n; ++i) {
		cin >> arr[i];
	}

	quicksort(arr, 0, (int)arr.size() - 1);

	return 0;
}
