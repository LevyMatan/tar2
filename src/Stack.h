#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "Util.h"

struct stack;
typedef struct stack Stack;

// Creates an empty stack, that can hold up to 'limit' elements.
Stack* CreateStack(int limit);

// Returns TRUE iff  the given 'stack' is empty. Returns FALSE otherwise.
// RUNTIME: Runs in O(1).
BOOL IsStackEmpty(Stack* stack);

// Returns TRUE iff the given 'stack' is full. Returns FALSE otherwise.
// RUNTIME: Runs in O(1).
BOOL IsStackFull(Stack* stack);

// Inserts the given 'data' element to the top of the given 'stack'.
// If 'stack' is full, 'data' will not be inserted and a message will be printed to stdout (screen).
// RUNTIME: Runs in O(1).
void Push(Stack* stack, int data);

// Removes and returns the top element in the given 'stack'.
// RUNTIME: Runs in O(1).
int Pop(Stack* stack);

// Prints the contents of the given 'stack' to stdout (screen).
// Will only work when DEBUG is set to TRUE.
void PrintStack(Stack* stack);

// Frees all the memory used by the given 'stack'.
void FreeStack(Stack* stack);