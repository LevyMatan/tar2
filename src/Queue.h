#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "Util.h"

struct queue;
typedef struct queue Queue;

// Creates an empty queue, that can hold up to 'limit' elements.
Queue* CreateQueue(int limit);

// Returns TRUE iff  the given 'queue' is empty. Returns FALSE otherwise.
// RUNTIME: Runs in O(1).
BOOL IsQueueEmpty(Queue* queue);

// Returns TRUE iff the given 'queue' is full. Returns FALSE otherwise.
// RUNTIME: Runs in O(1).
BOOL IsQueueFull(Queue* queue);

// Inserts the given 'data' element to the end of the given 'queue'.
// If 'queue' is full, 'data' will not be inserted and a message will be printed to stdout (screen).
// RUNTIME: Runs in O(1).
void Enqueue(Queue* queue, int data);

// Removes and returns the first element in the given 'queue'.
// RUNTIME: Runs in O(1).
int Dequeue(Queue* queue);

// Prints the contents of the given 'queue' to stdout (screen).
// Will only work when DEBUG is set to TRUE.
void PrintQueue(Queue* queue);

// Frees all the memory used by the given 'queue'.
void FreeQueue(Queue* queue);
