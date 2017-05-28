#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "SortingAlgorithms.h"
#include "Util.h"

#define NON_UNIFORM_PORTION 3

#define MANUAL_MODE 1
#define BUILTIN_MODE 2

#define CONTINUE 1
#define QUIT 2

#define ASCENDING_HEAPSORT 1
#define DESCENDING_HEAPSORT 2
#define STACK_QUICKSORT 3
#define QUEUE_QUICKSORT 4
#define EQUAL_ELEMENT_QUICKSORT 5
#define RADIXSORT 6

#define HEAPSORT_ALGORITHMS(choice) (choice == ASCENDING_HEAPSORT || choice == DESCENDING_HEAPSORT)

int* ReadArrayFromInput(int size) {
	int* arr = (int*)malloc(sizeof(int)*size);
	int i;

	printf("Enter array (in one line, sepereated by spaces):");
	for (i = 0; i < size; i++) {
		scanf("%d", arr + i);
	}

	return arr;
}

int* ReadArray(int* sizeRes, int* limitRes) {
	int size, choice, limit=0, i;
	int* arr = NULL;

	printf("Insert array size:\n");
	scanf("%d", &size);

	printf("Create array...\n");
	printf("1. From input\n");
	printf("2. Randomly\n");
	printf("3. Equal Element Random\n");
	scanf("%d", &choice);

	if (choice == 1) {
		arr = ReadArrayFromInput(size);
		for (i = 0; i < size; i++) {
			limit = max(limit, arr[i]);
		}
	}
	else if (choice == 2) {
		printf("Insert max value:\n");
		scanf("%d", &limit);
		arr = CreateArrayRandomly(size, limit);
	}
	else if (choice == 3) {
		printf("Insert max value:\n");
		scanf("%d", &limit);
		arr = CreateEqualElementArray(size, limit, NON_UNIFORM_PORTION);
	}

	*sizeRes = size;
	*limitRes = limit;
	return arr;
}

BOOL RunBenchmark(int* arr, int size, int choice, int limit, int arity, float* runtime) {
	BOOL ascending = TRUE;
	clock_t start = clock();
	switch (choice) {
		case ASCENDING_HEAPSORT:
			AscendingHeapSort(arr, size, arity);
			break;
		case DESCENDING_HEAPSORT:
			ascending = FALSE;
			DescendingHeapSort(arr, size, arity);
			break;
		case STACK_QUICKSORT:
			StackBasedQuickSort(arr, size);
			break;
		case QUEUE_QUICKSORT:
			QueueBasedQuickSort(arr, size);
			break;
		case EQUAL_ELEMENT_QUICKSORT:
			EqualElementQuickSort(arr, size, 0, size - 1);
			break;
		case RADIXSORT:
			nModuluRadixSort(arr, size, limit);
			break;
		default:
			break;
	}
	clock_t end = clock();
	*runtime = (float)(end - start) / CLOCKS_PER_SEC;
	return ValidateSortedArray(arr, size, ascending);
}

BOOL RunBenchmarkFromInput() {
	int* arr;
	int size, choice, limit, arity = 0;
	float runtime;
	BOOL isSorted;

	arr = ReadArray(&size, &limit);
	printf("Array created!\n");
	PrintIntArray(arr, size);
	printf("\n");

	printf("Choose Algorithm:\n");
	printf("1. Ascending Heapsort\n");
	printf("2. Descending Heapsort\n");
	printf("3. Stack-Based Quicksort\n");
	printf("4. Queue-Based Quicksort\n");
	printf("5. Equal-Element Quicksort\n");
	printf("6. n-Modulu Radixsort\n");
	scanf("%d", &choice);
	printf("\n");

	if (HEAPSORT_ALGORITHMS(choice)) {
		printf("Choose Arity:\n");
		scanf("%d", &arity);
		printf("\n");
	}

	isSorted = RunBenchmark(arr, size, choice, limit, arity, &runtime);
	if (isSorted) {
		printf("The Array Is Sorted!:\n");
	} else {
		printf("The Array Is NOT Sorted!:\n");
	}
	PrintIntArray(arr, size);
	printf("\n");
	printf("Algorithm Runtime: %f\n", runtime);

	free(arr);

	return isSorted;
}

void RunManualMode() {
	int choice = QUIT;
	do {
		printf("\n");
		RunBenchmarkFromInput();
		printf("\nGo again?\n");
		printf("1. Yes\n");
		printf("2. No\n");
		scanf("%d", &choice);
	} while (choice == CONTINUE);
}

void RunBuiltInMode() {

}

void main() {
	int choice;
	
	printf("Choose run-mode:\n");
	printf("1. Input choices manually\n");
	printf("2. Run built-in benchmark\n");
	scanf("%d", &choice);

	switch (choice) {
		case MANUAL_MODE:
			RunManualMode();
		case BUILTIN_MODE:
			RunBuiltInMode();
		default:
			break;
	}
}