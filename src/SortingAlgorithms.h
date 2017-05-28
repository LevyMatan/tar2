#pragma once

// Sorts the given 'arr' array of size 'size' in an ascending order using a MinPriorityQueue
// with arity 'arity'.
// RUNTIME: O(nlogn).
void AscendingHeapSort(int* arr, int size, int arity);
// Sorts the given 'arr' array of size 'size' in a descending order using a MinPriorityQueue
// with arity 'arity'.
// RUNTIME: O(nlogn).
inline void DescendingHeapSort(int* arr, int size, int arity) {
	MinPriorityQueue* minpq = CreateMinPriortyQueue(size, arity);
	int i;

	/* YOUR CODE STARTS HERE */
	minpq->arr = arr;
	// Build MinPQ
	minpq->used = size;
	for (i = size / arity; i > 0; i--) {

	}
	/* YOUR CODE ENDS HERE */

	FreeMinPQ(minpq);
}

// Sorts the given 'arr' array of size 'size' using Quicksort in a non-recursive manner - 
// using a single stack which is limited to holding (2 * cieling(log(n))) elements.
// Uses the regular Partition algorithm for partitioning the current sub-array.
// RUNTIME: O(nlogn) on average, would be approaching O(n^2) when arrays have many repeating values.
// SPACE COMPLEXITY: O(logn) (The algorithm never requires mores than O(logn) memory).
void StackBasedQuickSort(int* arr, int size);
// Sorts the given 'arr' array of size 'size' using Quicksort in a non-recursive manner - 
// using a single queue which is limited to holding (2 * cieling(log(n))) elements.
// Uses the regular Partition algorithm for partitioning the current sub-array.
// RUNTIME: O(nlogn) on average, would be approaching O(n^2) when arrays have many repeating values.
// SPACE COMPLEXITY: O(logn) (The algorithm never requires mores than O(logn) memory).
void QueueBasedQuickSort(int* arr, int size);
// Sorts the given 'arr' array of size 'size' using Quicksort recursive manner.
// Uses the Smart Partition algorithm for partitioning the current sub-array - the smart
// partition algorithm divides the array into 4 (instead of 3) sub-arrays:
// [(elements smaller than pivot)(elements equal to pivot)(pivot)(elements larger than pivot)].
// RUNTIME: O(nlogn) on average, repeating values actually shorten algorithm runtime in practice.
void EqualElementQuickSort(int* arr, int size, int p, int r);

// Sorts the given 'arr' array of size 'size' using Modulu Radixsort - in which the given 'limit'
// is used as the base for comparison in each iteration. Radixsort uses Counting Sort with values
// ranging between [0, limit-1] inclusive in each iteration. Think how.
// RUNTIME: O((n+k)*log_k_n), where n=size and k=limit.
//			Note that for size=n^c, where c is some constant, and limit=n, the runtime will be
//			O((n+n)*log_n_n^c) = O(n) (c iterations of counting sort).
void nModuluRadixSort(int* arr, int size, int limit);

