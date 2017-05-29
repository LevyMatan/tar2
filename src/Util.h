#pragma once

// Change this to '0' to disable printings. Change this to '1' to enable them.
// When enabled, you will still need to insert calls for printing functions in order to actually
// have them printed. Forgetting calls to printing functions in the code should not cause
// any problem when this is set to '0'.
#define DEBUG 0

#define TRUE 1
#define FALSE 0

typedef int BOOL;

typedef struct intpair {
	int first;
	int second;
} IntPair;

// Prints the first 'size' elements of the given int array 'arr' to stdout (screen).
void PrintIntArray(int* arr, int size);

// Prints the first 'size' elements of the given int-pair array 'arr' to stdout (screen).
void PrintIntPairArray(IntPair* arr, int size);

// Returns a random number between 0 and limit inclusive.
int GetRandomInt(int limit);

// Swaps the contents of the elements in indices 'i' and 'j' of the given int array 'arr'.
// Runs in O(1).
void SwapIndices(int* arr, int i, int j);

// Creates and retruns a int array of size 'size' filled with values randomly created from
// the range [0, limit] (inclusive).
int* CreateArrayRandomly(int size, int limit);

// Creates and retruns a int array of size 'size' filled with values randomly created from
// the range [0, limit] (inclusive).
// However, at least one value will appear at least (size/portion) times in the created array.
int* CreateEqualElementArray(int size, int limit, int portion);

// Returns TRUE iff the first 'size' elements of the given 'arr' are sorted.
// Returns FALSE otherwise.
// 'ascending' is used to determine whether the array should be sorted in an ascending or
// descending order.
BOOL ValidateSortedArray(int* arr, int size, BOOL ascending);
