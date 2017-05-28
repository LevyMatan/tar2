#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "Util.h"

struct listNode;
typedef struct listNode ListNode;

struct list;
typedef struct list List;

// Creates a new ListNode object with the given 'data' as its data.
ListNode* CreateNode(int data);

// Returns the underlying data of the given 'node' list node.
int GetNodeData(ListNode* node);

// Frees the memory associated with the given 'node' list node.
// Does NOT recursively frees 'node's next list node.
void FreeNode(ListNode* node);

// Creates and returns a new empty list.
List* CreateList();

// Returns TRUE iff the given 'lst' is empty.
// Otherwise, returns FALSE.
// RUNTIME: Runs in O(1).
BOOL IsListEmpty(List* lst);

// Inserts the given 'newTail' list node to the tail (end) of the given 'lst'.
// RUNTIME: Runs in O(1).
void InsertToListTail(List* lst, ListNode* newTail);

// Inserts the given 'newHead' list node to the head (beginning) of the given 'lst'.
// RUNTIME: Runs in O(1).
void InsertToListHead(List* lst, ListNode* newHead);

// Removes and returns the first list node in the given 'lst'.
// RUNTIME: Runs in O(1).
ListNode* RemoveFromListHead(List* lst);

// Prints the data of all the list nodes in the given 'lst' from beginning to end.
// The printing is flat: no additional info or explanation is printed besides the data itself.
// Will only work when DEBUG is set to TRUE.
void PrintListFlat(List* lst);

// Frees all the memory used by the given 'lst', including the list nodes it contains,
// and the memory used to hold the List members (head, tail).
void FreeList(List* lst);