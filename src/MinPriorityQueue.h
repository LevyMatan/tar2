#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "Util.h"

struct minPriorityQueue;
typedef struct minPriorityQueue MinPriorityQueue;

// Creates and returns a new Minimum Priority Queue that can hold up to 'limit' objects and
// is of arity 'arity, which stands for the number of children each full parent should have.
// Examples:
//		Arity 1 means that the underlying data structure is equivalent to a linked list.
//		Arity 2 means that the underlying data structure is a full binary tree.
//		Arity 3 means that the underlying data structure is a full tertiary tree.
MinPriorityQueue* CreateMinPriortyQueue(int limit, int arity);

// Returns TRUE iff the given 'minpq' is empty. Returns FALSE otherwise.
// RUNTIME: Runs in O(1).
BOOL IsMinPQEmpty(MinPriorityQueue* minpq);

// Returns TRUE iff the given 'minpq' is full. Returns FALSE otherwise.
// RUNTIME: Runs in O(1).
BOOL IsMinPQFull(MinPriorityQueue* minpq);

// Inserts the given 'data' to the given 'minpq'.
// RUNTIME: Runs in O(log_d_n) : logn in base d, where d is the arity of the underlying tree.
// If d = 1, runs in O(n).
void InsertToMinPQ(MinPriorityQueue* minpq, int data);

// Returns the minimum object in the given 'minpq'.
// RUNTIME: Runs in O(1).
int GetMinPQMinimum(MinPriorityQueue* minpq);

// Removes and returns the minimum object in the given 'minpq'.
// RUNTIME: Runs in O(log_d_n) : logn in base d, where d is the arity of the underlying tree.
// If d = 1, runs in O(n).
int ExtractMinPQMinimum(MinPriorityQueue* minpq);

// Prints the underlying members, including the priority queue data structure, of the given 'minpq.
// Will only work when DEBUG is set to TRUE.
void PrintMinPQ(MinPriorityQueue* minpq);

// Frees all the memory used by the given 'minpq'.
void FreeMinPQ(MinPriorityQueue* minpq);

