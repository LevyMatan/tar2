#include "LinkedList.h"

struct listNode {
	int data;
	struct listNode* next;
};

struct list {
	ListNode * head;
	ListNode * tail;
};

ListNode* CreateNode(int data)
{
	ListNode *result;

	result = (ListNode *)malloc(sizeof(ListNode));
	result->data = data;
	result->next = NULL;

	return result;
}

int GetNodeData(ListNode* node) {
	return node->data;
}

void FreeNode(ListNode* node) {
	free(node);
}

List* CreateList()
{
	List* lst = (List*)malloc(sizeof(List));
	lst->head = lst->tail = NULL;
	return lst;
}

BOOL IsListEmpty(List* lst)
{
	return (lst->head == NULL);
}

void InsertToListTail(List* lst, ListNode* newTail)
{
	ListNode* prevTail = lst->tail;
	if (IsListEmpty(lst)) {
		lst->head = newTail;
	}
	else {
		prevTail->next = newTail;
	}
	lst->tail = newTail;
}

void InsertToListHead(List* lst, ListNode* newHead)
{
	ListNode* prevHead = lst->head;
	if (IsListEmpty(lst)) {
		lst->tail = newHead;
	}
	else {
		newHead->next = prevHead;
	}
	lst->head = newHead;
}

ListNode* RemoveFromListHead(List* lst) {
	ListNode* head;
	if (IsListEmpty(lst)) {
		return NULL;
	}
	head = lst->head;
	lst->head = head->next;
	return head;
}

void FreeList(List* lst) {
	ListNode* curr = lst->head;
	ListNode* next;

	while (curr != NULL) {
		next = curr->next;
		free(curr);
		curr = next;
	}
	free(lst);
}

void PrintListFlat(List* lst) {
	ListNode* curr = lst->head;
	if (DEBUG) {
		while (curr != NULL) {
			printf("%d ", curr->data);
			curr = curr->next;
		}
	}
}