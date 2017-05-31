#include "MinPriorityQueue.h"
#include "SortingAlgorithms.h"
#include "SortingAlgorithmsUtil.h"
// COMPLETED!!!
void AscendingHeapSort(int* arr, int size, int arity) {
	MinPriorityQueue* minpq = CreateMinPriortyQueue(size, arity);
	int i;

	/* YOUR CODE STARTS HERE */
	for (i = 0; i < size; i++) {
		InsertToMinPQ(minpq, arr[i]);
	}
	// take the minmium element in the Queue and place it in the end of the array
	for (i = 0; i < size; i++) {
		arr[i] = ExtractMinPQMinimum(minpq);
	}
	/* YOUR CODE ENDS HERE */

	FreeMinPQ(minpq);
}
// COMPLETED!!!
void DescendingHeapSort(int* arr, int size, int arity) {
	MinPriorityQueue* minpq = CreateMinPriortyQueue(size, arity);
	int i;

	/* YOUR CODE STARTS HERE */
	// build heap
	for (i = 0; i < size; i++) {
		InsertToMinPQ(minpq, arr[i]);
	}
	// take the minmium element in the Queue and place it in the end of the array
	for (i = size - 1; i > -1; i--) {
		arr[i] = ExtractMinPQMinimum(minpq);
	}

	
	/* YOUR CODE ENDS HERE */

	FreeMinPQ(minpq);
}

// Works on the sub-array given by 'p' (as lower bound) and 'r' (as higher bound).
// Returns the index in the given 'arr' into which the current pivot (arr[r]) was moved.
// All elements before the returned indices should be smaller than arr[r], while all elements
// after it should be equal or larger from it.
// RUNTIME: Runs in O(p-r).
// COMPLETED!!!
int Partition(int* arr, int p, int r) {
	int pivot = arr[r];
	int q = p;
	int j;

	/* YOUR CODE STARTS HERE */

	for (j = p ; j < r ; j++) {
		if (arr[j] < pivot) {
			SwapIndices(arr, j, q);
			q++;
		}
	}
	SwapIndices(arr, q, r);
	/* YOUR CODE ENDS HERE */
	
	return q;
}

// Works on the sub-array given by 'p' (as lower bound) and 'r' (as higher bound).
// Reorganizes the given 'arr' into 4 subsequent sub-array as follows, using arr[r] as pivot:
// [(elements smaller than pivot)(elements equal to pivot)(pivot)(elements larger than pivot)].
// Updates 'qRes' to hold the start of the (elements equal to pivot) sub-array.
// Updates 'tRes' to hold the index of 'pivot'.
// RUNTIME: Runs in O(p-r).
// COMPLETED!!!
void SmartPartition(int* arr, int size, int p, int r, int *qRes, int *tRes) {
	int pivot = arr[r];
	int q = p, t = p;
	int j;
	
	/* YOUR CODE STARTS HERE */
	for (j = p; j < r; j++) {
		//PrintSmartPartitionState(arr, size, p, r, pivot, q, t, j);
		if (arr[j] < pivot) {
			SwapIndices(arr, j, q);
			if (t != q) {
				SwapIndices(arr, j, t);
			}			
			q++;
			t++;
		}
		else if (arr[j] == pivot) {
			SwapIndices(arr, j, t);
			t++;
		}
		//PrintSmartPartitionState(arr, size, p, r, pivot, q, t, j);
	}
	SwapIndices(arr, r, t);
	/* YOUR CODE ENDS HERE */

	(*qRes) = q;
	(*tRes) = t;
}
// COMPLETED!!!
void StackBasedQuickSort(int* arr, int size) {
	Stack* stack = CreateStack(QuicksortDataStructureLimit(size));
	int p = -1, q = -1, r = -1;
	
	/* YOUR CODE STARTS HERE */

	Push(stack, 0);
	Push(stack, size-1);
	while ( !IsStackEmpty(stack) ) {
		r = Pop(stack);
		p = Pop(stack);
		if (!IsValidSubArray(p, r, size)) continue;
		q = Partition(arr, p, r);
		if ((q - p) <= (r - q)) {
			MaybePushIndices(stack, q + 1, r, size); // Indecies for right array = [q+1, r]
			MaybePushIndices(stack, p, q - 1, size); // Indecies for left array = [p, q-1]
		}
		else {
			MaybePushIndices(stack, p, q - 1, size); // Indecies for right array = [q+1, r]
			MaybePushIndices(stack, q + 1, r, size); // Indecies for left array = [p, q-1]
		}

	}

	/* YOUR CODE ENDS HERE */

	FreeStack(stack);
}
// TODO
void QueueBasedQuickSort(int* arr, int size) {
	Queue* queue = CreateQueue(QuicksortDataStructureLimit(size));
	int p = -1, q = -1, r = -1;

	/* YOUR CODE STARTS HERE */
	Enqueue(queue, 0);			// first p
	Enqueue(queue, size - 1);	// first r
	while (!IsQueueEmpty(queue)) {
		p = Dequeue(queue);
		r = Dequeue(queue);
		if (!IsValidSubArray(p, r, size)) 
			continue;
		q = Partition(arr, p, r);
		// We would like to insert the bigger subarray first to guarntee log(n) size of queue
		if ((q - p) < (r - q)) {
			MaybeEnqueueIndices(queue, p, q - 1, size); // Indecies for left array = [p, q-1]
			MaybeEnqueueIndices(queue, q + 1, r, size); // Indecies for right array = [q+1, r]
		}
		else {
			MaybeEnqueueIndices(queue, q + 1, r, size); // Indecies for right array = [q+1, r]
			MaybeEnqueueIndices(queue, p, q - 1, size); // Indecies for left array = [p, q-1]
		}
		
		//PrintQueueQuickSortState(queue, arr, p, q, r, size);
	}
	/* YOUR CODE ENDS HERE */

	FreeQueue(queue);
}
// COMPLETED!!!
void EqualElementQuickSort(int* arr, int size, int p, int r) {
	int q, t;

	/* YOUR CODE STARTS HERE */
	//Testing partition
	if (p < r) {
		SmartPartition(arr, size, p, r, &q, &t);
		EqualElementQuickSort(arr, q-p, p, q-1);
		EqualElementQuickSort(arr, r-t, t+1, r);
	}

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
// COMPLETED!!!
void nModuluRadixSort(int* arr, int size, int limit) {
	IntPair *a = (IntPair*)malloc(sizeof(IntPair)*size);
	int i, denominator = 1;
	
	for (i = 0; i < size; i++) {
		a[i].first = arr[i];
	}

	/* YOUR CODE STARTS HERE */
	int not_zeros; 
	for (int d = 1; d < INT_MAX; d++) { // limit the number of digits to INT_MAX (actually can use much lower number...)
		//PrintnModuluRadixSortState(arr, a, size, limit, denominator);
		not_zeros = 0;
		for (i = 0; i < size; i++) {
			a[i].second = (a[i].first % (denominator*limit)) / denominator; // extract the 'd' digit of the number on base 'limit'
			if (a[i].second)												// if all the elemnt in the array has the 'd' digit equal to zero, assumes this is the last digit.
				not_zeros = 1;
		}
		if (!not_zeros)
			break;
		CountingSort(a, size, limit-1);										// Stable sort algorithm to sort the array of the i'th digit
		denominator *= limit;												// increase power of denominator by one, denominator = limit^(d+1)
	}
		
	/* YOUR CODE ENDS HERE */

	for (i = 0; i < size; i++) {
		arr[i] = a[i].first;
	}
	free(a);
}