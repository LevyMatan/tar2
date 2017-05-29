#include "MinPriorityQueue.h"


struct minPriorityQueue {
	int * arr;
	int arity;
	int limit;
	int used;
};

// Returns the last index representing a node in the given 'minpq'.
int LastIndex(MinPriorityQueue* minpq) {
	return minpq->used - 1;
}

// Returns the index of the 'childNum'th child of the node represented by the given 'parentIndex'
// in the given 'minpq'. Returns -1 if such child does not exist.
// RUNTIME: Runs in O(1).
// COMPLETED
int ChildIndex(MinPriorityQueue* minpq, int parentIndex, int childNum) {
	int childIndex;
	/* YOUR CODE STARTS HERE */
	// The children of a certain parent are follow the indexing rule: arity*ParentIndex + childNum
	childIndex = minpq->arity * parentIndex + childNum;
	return ( childIndex > LastIndex(minpq) ) ? (-1) : (childIndex);
	/* YOUR CODE ENDS HERE */
}

// Returns the parent index of the node represented by the given 'childIndex' index, in the given
// 'minpq'. Returns -1 if the node has no parent in 'minpq'.
int ParentIndex(MinPriorityQueue* minpq, int childIndex) {
	if (childIndex == 0) {
		return -1;
	}
	return (childIndex - 1) / minpq->arity;
}

// Returns TRUE iff the node at the given 'nodeIndex' index in the given 'minpq' array is a leaf.
// Returns FALSE otherwise.
BOOL IsLeaf(MinPriorityQueue* minpq, int nodeIndex) {
	return ChildIndex(minpq, nodeIndex, 0) == -1;
}

void PrintMinPQ(MinPriorityQueue* minpq) {
	int i;
	if (DEBUG) {
		printf("Dumping Min Priority Queue State Snapshot:\n");
		printf("Limit: %d, Used: %d, Arity: %d\n", minpq->limit, minpq->used, minpq->arity);
		printf("Array Contents: ");
		for (i = 0; i < LastIndex(minpq); i++) {
			printf("%d ", minpq->arr[i]);
		}
		if (!IsMinPQEmpty(minpq)) {
			printf("%d\n\n", minpq->arr[LastIndex(minpq)]);
		}
		else {
			printf("\n\n");
		}
	}
}

// Bubbles down the node at index 'nodeIndex' to its rightful position in the given 'minpq'.
// If the node at index 'nodeIndex' was the only one not respecting the heap property of
// the underlying 'minpq->arr' data structure, 'minpq->arr' should be respecting the heap
// property after this method finishes its run.
// Traditionaly, used after element removal.
// RUNTIME: Runs in O(log_d_n), where d = 'minpq->arity' and when d > 1.
//			Runs in O(n) when 'minpq->arity' = 1.
void BubbleDown(MinPriorityQueue* minpq, int nodeIndex) {
	int childNum, childIndex, minChildIndex = nodeIndex;
	/* YOUR CODE STARTS HERE */
	// DEBUG
	//PrintMinPQ(minpq);
	// find min value of all children
	int minValue = minpq->arr[nodeIndex];
	for (childNum = 1; childNum <= minpq->arity; childNum++) {
		childIndex = ChildIndex(minpq, nodeIndex, childNum);
		if (childIndex == -1) {
			break;
		}
		else if ( minValue > minpq->arr[childIndex]) {
			minChildIndex = childIndex;
			minValue = minpq->arr[childIndex];
		}
	}
	// if not in right place, bubble down
	if (minChildIndex != nodeIndex) {
		SwapIndices(minpq->arr, minChildIndex, nodeIndex);
		BubbleDown(minpq, minChildIndex);
	}

	/* YOUR CODE ENDS HERE */
}

// Bubbles up the node at index 'nodeIndex' to its rightful position in the given 'minpq'.
// If the node at index 'nodeIndex' was the only one not respecting the heap property of
// the underlying 'minpq->arr' data structure, 'minpq->arr' should be respecting the heap
// property after this method finishes its run.
// Traditionaly, used after element addition.
// RUNTIME: Runs in O(log_d_n), where d = 'minpq->arity' and when d > 1.
//			Runs in O(n) when 'minpq->arity' = 1.
void BubbleUp(MinPriorityQueue* minpq, int nodeIndex) {
	int parentIndex;
	/* YOUR CODE STARTS HERE */
	int key, i = nodeIndex;
	// make sure we have a valid nodeIndex
	if (i < 0) {
		printf("You tried to bubble up an element which his index exceeds the array dimensions: lower then 0");
		return;
	} 
	if (i > LastIndex(minpq)) {
		printf("You tried to bubble up an element which his index exceeds the array dimensions: above LastIndex()");
		return;
	}

	parentIndex = ParentIndex(minpq, i);
	key = minpq->arr[i];
	while (i > -1 && minpq->arr[parentIndex] > key) {
		minpq->arr[i] = minpq->arr[parentIndex];
		i = parentIndex;
		parentIndex = ParentIndex(minpq, i);
	}
	minpq->arr[i] = key;
	/* YOUR CODE ENDS HERE */
}

MinPriorityQueue* CreateMinPriortyQueue(int limit, int arity) {
	MinPriorityQueue* minpq = (MinPriorityQueue*)malloc(sizeof(MinPriorityQueue));
	if (!minpq)
		exit(1);
	minpq->arr = (int*)malloc(sizeof(int)*limit);
	minpq->limit = limit;
	minpq->arity = arity;
	minpq->used = 0;
	return minpq;
}

BOOL IsMinPQEmpty(MinPriorityQueue* minpq) {
	return minpq->used == 0;
}

BOOL IsMinPQFull(MinPriorityQueue* minpq) {
	return minpq->used == minpq->limit;
}

void InsertToMinPQ(MinPriorityQueue* minpq, int data) {
	if (IsMinPQFull(minpq)) {
		return;
	}
	/* YOUR CODE STARTS HERE */
	// extend heap by one
	minpq->used++;
	minpq->arr[LastIndex(minpq)] = data;
	BubbleUp(minpq, LastIndex(minpq));
	/* YOUR CODE ENDS HERE */
}

int GetMinPQMinimum(MinPriorityQueue* minpq) {
	if (IsMinPQEmpty(minpq)) {
		return INT_MAX;
	}
	return minpq->arr[0];
}

int ExtractMinPQMinimum(MinPriorityQueue* minpq) {
	if (IsMinPQEmpty(minpq)) {
		return INT_MAX;
	}
	/* YOUR CODE STARTS HERE */
	// replace the min value with the last element in the MinPQMinimum
	SwapIndices(minpq->arr, 0, LastIndex(minpq));
	// reduce the size of the MinPQMinimum
	minpq->used--;
	// bubbleDown the last elemnt which is now at the root to satisfy the heap property
	BubbleDown(minpq, 0);
	/* YOUR CODE ENDS HERE */
	return minpq->arr[LastIndex(minpq) + 1];
}

void FreeMinPQ(MinPriorityQueue* minpq) {
	free(minpq->arr);
	free(minpq);
}
