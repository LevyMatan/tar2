#include "MinPriorityQueue.h"
#include "SortingAlgorithms.h"
#include "SortingAlgorithmsUtil.h"

void AscendingHeapSort(int* arr, int size, int arity) {
	MinPriorityQueue* minpq = CreateMinPriortyQueue(size, arity);
	int i;

	/* YOUR CODE STARTS HERE */

	/* YOUR CODE ENDS HERE */

	FreeMinPQ(minpq);
}

void DescendingHeapSort(int* arr, int size, int arity) {
	MinPriorityQueue* minpq = CreateMinPriortyQueue(size, arity);
	int i;

	/* YOUR CODE STARTS HERE */

	/* YOUR CODE ENDS HERE */

	FreeMinPQ(minpq);
}

// Works on the sub-array given by 'p' (as lower bound) and 'r' (as higher bound).
// Returns the index in the given 'arr' into which the current pivot (arr[r]) was moved.
// All elements before the returned indices should be smaller than arr[r], while all elements
// after it should be equal or larger from it.
// RUNTIME: Runs in O(p-r).
int Partition(int* arr, int p, int r) {
	int pivot = arr[r];
	int q = p;
	int j;

	/* YOUR CODE STARTS HERE */

	/* YOUR CODE ENDS HERE */
	
	return q;
}

// Works on the sub-array given by 'p' (as lower bound) and 'r' (as higher bound).
// Reorganizes the given 'arr' into 4 subsequent sub-array as follows, using arr[r] as pivot:
// [(elements smaller than pivot)(elements equal to pivot)(pivot)(elements larger than pivot)].
// Updates 'qRes' to hold the start of the (elements equal to pivot) sub-array.
// Updates 'tRes' to hold the index of 'pivot'.
// RUNTIME: Runs in O(p-r).
void SmartPartition(int* arr, int size, int p, int r, int *qRes, int *tRes) {
	int pivot = arr[r];
	int q = p, t = p;
	int j;
	
	/* YOUR CODE STARTS HERE */

	/* YOUR CODE ENDS HERE */

	(*qRes) = q;
	(*tRes) = t;
}

void StackBasedQuickSort(int* arr, int size) {
	Stack* stack = CreateStack(QuicksortDataStructureLimit(size));
	int p = -1, q = -1, r = -1;

	/* YOUR CODE STARTS HERE */

	/* YOUR CODE ENDS HERE */

	FreeStack(stack);
}

void QueueBasedQuickSort(int* arr, int size) {
	Queue* queue = CreateQueue(QuicksortDataStructureLimit(size));
	int p = -1, q = -1, r = -1;

	/* YOUR CODE STARTS HERE */

	/* YOUR CODE ENDS HERE */

	FreeQueue(queue);
}

void EqualElementQuickSort(int* arr, int size, int p, int r) {
	int q, t;

	/* YOUR CODE STARTS HERE */

	/* YOUR CODE ENDS HERE */
}

// Sorts the IntPair array 'arr' of size 'size' in the following manner, and the following assumptions:
// IntPair elements hold two integers - 'first' and 'second'.
// CountingSort sorts the IntPair elements according the their 'second' values.
// It is assumed that all 'second' values are between [0, limit] inclusive (limit+1 different values).
// RUNTIME: Runs in O(n+k), where n=size and k=limit+1.
void CountingSort(IntPair* arr, int size, int limit) {
	IntPair* c = (IntPair*)calloc(size, sizeof(IntPair));
	int* b = (int*)calloc(limit + 1, sizeof(int));
	int i;
	
	for (i = 0; i < size; i++) {
		b[arr[i].second]++;
	}	
	for (i = 1; i < limit + 1; i++) {
		b[i] += b[i - 1];
	}		
	for (i = size-1; i >= 0; i--) {
		c[b[arr[i].second]-1] = arr[i];
		b[arr[i].second]--;
	}		
	for (i = 0; i < size; i++) {
		arr[i] = c[i];
	}	

	free(b);
	free(c);
}

void nModuluRadixSort(int* arr, int size, int limit) {
	IntPair *a = (IntPair*)malloc(sizeof(IntPair)*size);
	int i, denominator = 1;
	
	for (i = 0; i < size; i++) {
		a[i].first = arr[i];
	}

	/* YOUR CODE STARTS HERE */

	/* YOUR CODE ENDS HERE */

	for (i = 0; i < size; i++) {
		arr[i] = a[i].first;
	}
	free(a);
}