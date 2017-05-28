#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Util.h"

void PrintIntArray(int* arr, int size) {
	int i;
	if (DEBUG) {
		for (i = 0; i < size - 1; i++) {
			printf("%d ", arr[i]);
		}
		printf("%d\n", arr[size - 1]);
	}
}

void PrintIntPairArray(IntPair* arr, int size) {
	int i;
	if (DEBUG) {
		for (i = 0; i < size - 1; i++) {
			printf("(%d,%d) ", arr[i].first, arr[i].second);
		}
		printf("(%d,%d)\n", arr[size-1].first, arr[size - 1].second);
	}
}

/* return a random number between 0 and limit inclusive.
*/
int GetRandomInt(int limit) {
	static BOOL firstCall = TRUE;
	if (firstCall) {
		srand((unsigned int)time(NULL));
		firstCall = FALSE;
	}
	return rand() % (limit+1);
}

void SwapIndices(int* arr, int i, int j) {
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

int* CreateArrayRandomly(int size, int limit) {
	int* arr = (int*)malloc(sizeof(int)*size);
	int i;

	for (i = 0; i < size; i++) {
		*(arr + i) = GetRandomInt(limit);
	}

	return arr;
}

int* CreateEqualElementArray(int size, int limit, int portion) {
	int* arr = (int*)malloc(sizeof(int)*size);
	int i, repeatingNum;

	for (i = 0; i < size; i++) {
		arr[i] = -1;
	}

	repeatingNum = GetRandomInt(limit);
	for (i = 0; i < size; i++) {
		if (!GetRandomInt(portion - 1)) {
			arr[i] = repeatingNum;
		}
	}

	for (i = 0; i < size; i++) {
		if (arr[i] == -1) {
			arr[i] = GetRandomInt(limit);
		}
	}

	return arr;
}



BOOL ValidateSortedArray(int* arr, int size, BOOL ascending) {
	int i;
	for (i = 0; i < size - 1; i++) {
		if ((ascending && arr[i] > arr[i + 1]) || 
			(!ascending && arr[i] < arr[i + 1])) {
			return FALSE;
		}
	}
	return TRUE;
}