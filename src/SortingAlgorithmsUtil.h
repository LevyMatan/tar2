#pragma once

#include "Stack.h"
#include "Queue.h"
#include "Util.h"

// Prints the state of a Stack-based Quicksort run to stdout (screen).
// 'stack' - The stack used in the Stack-based Quicksort algorithm.
// 'arr' - The array which is being sorted in-place.
// 'p' - The current low bound of the sub-array being sorted.
// 'q' - The index in the array the current pivot should go in.
// 'r' - The current high bound of the sub-array being sorted.
// 'size' - The size of the entire array.
// Will only work when DEBUG is set to TRUE.
void PrintStackQuickSortState(Stack* stack, int* arr, int p, int q, int r, int size);

// Prints the state of a Queue-based Quicksort run to stdout (screen).
// 'queue' - The queue used in the Queue-based Quicksort algorithm.
// 'arr' - The array which is being sorted in-place.
// 'p' - The current low bound of the sub-array being sorted.
// 'q' - The index in the array the current pivot should go in.
// 'r' - The current high bound of the sub-array being sorted.
// 'size' - The size of the entire array.
// Will only work when DEBUG is set to TRUE.
void PrintQueueQuickSortState(Queue* queue, int* arr, int p, int q, int r, int size);

// Prints the state of a Quicksort Partition function run to stdout (screen).
// 'arr' - The array which is being sorted in-place.
// 'size' - The size of the entire array.
// 'p' - The current low bound of the sub-array being sorted.
// 'r' - The current high bound of the sub-array being sorted.
// 'pivot' - The value of the current pivot element.
// 'q' - All the elements before this index should be smaller than the pivot.
// 'j' - The index in the traversal over the array.
// Will only work when DEBUG is set to TRUE.
void PrintPartitionState(int* arr, int size, int p, int r, int pivot, int q, int j);

// Prints the state of a Quicksort Smart Partition function run to stdout (screen).
// 'arr' - The array which is being sorted in-place.
// 'size' - The size of the entire array.
// 'p' - The current low bound of the sub-array being sorted.
// 'r' - The current high bound of the sub-array being sorted.
// 'pivot' - The value of the current pivot element.
// 'q' - All the elements before this index should be smaller than the pivot.
// 't' - All the elements between 'q' and 't'-1 should be equal to the pivot.
// 'j' - The index in the traversal over the array.
// Will only work when DEBUG is set to TRUE.
void PrintSmartPartitionState(int* arr, int size, int p, int r, int pivot, int q, int t, int j);

// Returns TRUE iff the given 'p' and 'r' indices represents a valid sub-array in an array
// of size 'size'. Namely, that (0 <= p < r <= size-1). Note that a sub-array of size 1 is
// considered NOT valid.
// Returns FALSE if the sub-array is not valid.
BOOL IsValidSubArray(int p, int r, int size);

// If the given 'p' and 'r' indices represents a valid sub-array in an array of size 'size',
// pushes them to the given 'stack' - first pushes 'p', then pushes 'r'.
void MaybePushIndices(Stack* stack, int p, int r, int size);

// If the given 'p' and 'r' indices represents a valid sub-array in an array of size 'size',
// enqueues them to the given 'queue' - first enqueues 'p', then enqueues'r'.
void MaybeEnqueueIndices(Queue* queue, int p, int r, int size);

// Returns the data structure size limit imposed on data structures used in non-recursive Quicksort.
int QuicksortDataStructureLimit(int size);

// Prints the state of a IntPair Counting Sort algorithm run to stdout (screen).
// 'arr' - The IntPair array which is being sorted.
// 'b' - The helper array used to count the number of occurences of each value, and later the
//		 number of occurences of values smaller or equal from that of a specific index.
// 'c' - The helper array used at the end of the algorithm - when the sorting is performed.
// 'size' - The number of elements in 'arr'.
// 'pivot' - The value of the current pivot element.
// 'limit' - The 'second' int of each IntPair element should have a value between [0, limit] inclusive.
// Will only work when DEBUG is set to TRUE.
void PrintCountingSortState(IntPair* arr, int* b, IntPair* c, int size, int limit);

// Prints the state of a n-Modulu Radixsort algorithm run to stdout (screen).
// 'arr' - The array which is being sorted.
// 'a' - The IntPair helper array which is being used while sorting.
// 'size' - The number of elements in 'arr' (and in 'a').
// 'limit' - Elements in 'arr' and the second int in 'a' elements should have a value between
//			 [0, limit] inclusive.
// 'denominator' - The current denominator used when calculating current modulu-n value of the
//				   first ints in 'a'.
void PrintnModuluRadixSortState(int* arr, IntPair* a, int size, int limit, int denominator);