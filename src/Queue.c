#include "LinkedList.h"
#include "Queue.h"

struct queue {
	List * dataList;
	int limit;
	int used;
};

Queue* CreateQueue(int limit) {
	Queue* queue = (Queue*)malloc(sizeof(Queue));
	queue->dataList = CreateList();
	queue->limit = limit;
	queue->used = 0;
	return queue;
}

BOOL IsQueueEmpty(Queue* queue) {
	/* YOUR CODE STARTS HERE */

	/* YOUR CODE ENDS HERE */
}

BOOL IsQueueFull(Queue* queue) {
	return queue->limit == queue->used;
}

void Enqueue(Queue* queue, int data) {
	if (IsQueueFull(queue)) {
		if (DEBUG) {
			printf("Trying to insert to a full queue!\n");
		}
		return;
	}
	/* YOUR CODE STARTS HERE */

	/* YOUR CODE ENDS HERE */
	queue->used++;
}

int Dequeue(Queue* queue) {
	ListNode* first;
	int data;
	if (IsQueueEmpty(queue)) {
		if (DEBUG) {
			printf("Trying to remove from an empty queue!\n");
		}
		return INT_MIN;
	}
	/* YOUR CODE STARTS HERE */

	/* YOUR CODE ENDS HERE */
	data = GetNodeData(first);
	free(first);
	queue->used--;
	return data;
}

void PrintQueue(Queue* queue) {	
	if (DEBUG) {
		printf("Dumping Queue State Snapshot:\n");
		printf("Limit: %d, Used: %d\n", queue->limit, queue->used);
		printf("First -> ");
		PrintListFlat(queue->dataList);
		printf("<- Last\n\n");
	}
}

void FreeQueue(Queue* queue) {
	FreeList(queue->dataList);
	free(queue);
}