#include "LinkedList.h"
#include "Stack.h"

struct stack {
	List * dataList;
	int limit;
	int used;
};

Stack* CreateStack(int limit) {
	Stack* stack = (Stack*)malloc(sizeof(Stack));
	stack->dataList = CreateList();
	stack->limit = limit;
	stack->used = 0;
	return stack;
}

BOOL IsStackEmpty(Stack* stack) {
	return IsListEmpty(stack->dataList);
}

BOOL IsStackFull(Stack* stack) {
	return stack->used == stack->limit;
}

void Push(Stack* stack, int data) {
	if (IsStackFull(stack)) {
		if (DEBUG) {
			printf("Trying to insert to a full stack!\n");
		}
		return;
	}
	InsertToListHead(stack->dataList, CreateNode(data));
	stack->used++;
}

int Pop(Stack* stack) {
	ListNode* top;
	int data;
	if (IsStackEmpty(stack)) {
		if (DEBUG) {
			printf("Trying to remove from an empty stack!\n");
		}		
		return INT_MIN;
	}
	top = RemoveFromListHead(stack->dataList);
	stack->used--;
	data = GetNodeData(top);
	free(top);
	return data;
}

void FreeStack(Stack* stack) {
	FreeList(stack->dataList);
	free(stack);
}

void PrintStack(Stack* stack) {	
	if (DEBUG) {
		printf("Dumping Stack State Snapshot:\n");
		printf("Limit: %d, Used: %d\n", stack->limit, stack->used);
		printf("Top -> ");
		PrintListFlat(stack->dataList);
		printf("<- Bottom\n\n");
	}
}