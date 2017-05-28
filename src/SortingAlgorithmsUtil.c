#include <math.h>
#include "SortingAlgorithmsUtil.h"
#include "Stack.h"
#include "Util.h"
#include "Queue.h"

void PrintStackQuickSortState(Stack* stack, int* arr, int p, int q, int r, int size) {
	if (DEBUG) {
		printf("Dumping Stack-QuickSort State Snapshot:\n");
		printf("P: %d, Q: %d, R: %d\n", p, q, r);
		printf("Array Contents:\n");
		PrintIntArray(arr, size);
		PrintStack(stack);
	}
}

void PrintQueueQuickSortState(Queue* queue, int* arr, int p, int q, int r, int size) {
	if (DEBUG) {
		printf("Dumping Queue-QuickSort State Snapshot:\n");
		printf("P: %d, Q: %d, R: %d\n", p, q, r);
		printf("Array Contents:\n");
		PrintIntArray(arr, size);
		PrintQueue(queue);
	}
}

void MaybePrintIndex(int curr, int index, char indexChar) {
	if (curr == index) {
		printf("(%c)", indexChar);
	}
}

void PrintPartitionState(int* arr, int size, int p, int r, int pivot, int q, int j) {
	int k;
	if (DEBUG) {
		printf("Dumping Partition State Snapshot:\n");
		printf("Pivot Value: %d\n", pivot);
		printf("Array Contents:\n");
		for (k = 0; k < size; k++) {
			MaybePrintIndex(k, p, 'p');
			MaybePrintIndex(k, q, 'q');
			MaybePrintIndex(k, j, 'j');
			MaybePrintIndex(k, r, 'r');
			printf("%d ", arr[k]);
		}
		printf("\n\n");
	}
}

void PrintSmartPartitionState(int* arr, int size, int p, int r, int pivot, int q, int t, int j) {
	int k;
	if (DEBUG) {
		printf("Dumping Smart Partition State Snapshot:\n");
		printf("Pivot Value: %d\n", pivot);
		printf("Array Contents:\n");
		for (k = 0; k < size; k++) {
			MaybePrintIndex(k, p, 'p');
			MaybePrintIndex(k, q, 'q');
			MaybePrintIndex(k, t, 't');
			MaybePrintIndex(k, j, 'j');
			MaybePrintIndex(k, r, 'r');
			printf("%d ", arr[k]);
		}
		printf("\n\n");
	}
}

BOOL IsValidSubArray(int p, int r, int size) {
	return (r > p && r < size && p >= 0);
}

void MaybePushIndices(Stack* stack, int p, int r, int size) {
	if (IsValidSubArray(p, r, size)) {
		Push(stack, p);
		Push(stack, r);
	}
}

void MaybeEnqueueIndices(Queue* queue, int p, int r, int size) {
	if (IsValidSubArray(p, r, size)) {
		Enqueue(queue, p);
		Enqueue(queue, r);
	}
}

int QuicksortDataStructureLimit(int size) {
	return (int)(ceil(log(size) / log(2))) * 2;
}

void PrintCountingSortState(IntPair* arr, int* b, IntPair* c, int size, int limit) {
	if (DEBUG) {
		printf("Dumping Counting-Sort State Snapshot:\n");
		printf("Size: %d, Limit: %d (%d different values)\n", size, limit, limit+1);
		printf("Array Contents:\n");
		PrintIntPairArray(arr, size);
		printf("B-Array:\n");
		PrintIntArray(b, limit+1);
		printf("C-Array:\n");
		PrintIntPairArray(c, size);
		printf("\n");
	}
}

void PrintnModuluRadixSortState(int* arr, IntPair* a, int size, int limit, int denominator) {
	if (DEBUG) {
		printf("Dumping nModulu-Radixsort State Snapshot:\n");
		printf("Size: %d, Limit: %d (%d different values)\n", size, limit, limit + 1);
		printf("Current Denominator: %d\n", denominator);
		printf("Original Array Contents:\n");
		PrintIntArray(arr, size);
		printf("Helper Array Contents:\n");
		PrintIntPairArray(a, size);
		printf("\n");
	}
}