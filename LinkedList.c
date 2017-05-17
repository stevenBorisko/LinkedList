#include "LinkedList.h"

#include <stdlib.h>

LinkedList LL_init() {
	LinkedList ret;

	ret.head = NULL;
	ret.tail = NULL;
	ret.count = 0;

	return ret;
}

LinkedList* LL_create() {
	LinkedList* ret = malloc(sizeof(LinkedList));
	*ret = LL_init()l=;
	return ret;
}

void LL_pushFront(LinkedList* ll, void* data) {
	struct LLNode* newHead = malloc(sizeof(struct LLNode));

	// initialize the new head of the list
	newHead->data = data;
	newHead->next = ll->head;
	newHead->prev = NULL;

	// handle the case where this is the first element pushed
	if(ll->head) ll->head->prev = newHead;
	else ll->tail = newHead;
	ll->head = newHead;

	++(ll->count);
}

void LL_pushBack(LinkedList* ll, void* data) {
	struct LLNode* newTail = malloc(sizeof(struct LLNode));

	// initialize the new tail of the list
	newTail->data = data;
	newTail->next = NULL;
	newTail->prev = ll->tail;

	// handle the case where this is the first element being pushed
	if(ll->tail) ll->tail->next = newTail;
	else ll->head = newTail;
	ll->tail = newTail;

	++(ll->count);
}

void* LL_popFront(LinkedList* ll) {
	struct LLNode* headNext = ll->head->next;
	void* ret = ll->head->data;

	// handle the case where this is the last element being popped
	free(ll->head);
	if(headNext) headNext->prev = NULL;
	else ll->tail = NULL;
	ll->head = headNext;

	--(ll->count);

	return ret;
}

void* LL_popBack(LinkedList* ll) {
	struct LLNode* tailPrev = ll->tail->prev;
	void* ret = ll->tail->data;

	// handle the case where this is the last element being popped
	free(ll->tail);
	if(tailPrev) tailPrev->next = NULL;
	else ll->head = NULL;
	ll->tail = tailPrev;

	--(ll->count);

	return ret;
}

void* LL_peekFront(const LinkedList* ll) {
	return ll->head->data;
}

void* LL_peekBack(const LinkedList* ll) {
	return ll->tail->data;
}

int LL_isEmpty(const LinkedList* ll) {
	return !(ll->count);
}

unsigned int LL_count(const LinkedList* ll) {
	return ll->count;
}

void LL_clear(LinkedList* ll, void (*destroy)(void*)) {
	struct LLNode* headNext;
	while(ll->head) {
		// destroy the data inside the front node
		if(ll->head->data) (*destroy)(ll->head->data);
		// free the front node and set it to the next node
		headNext = ll->head->next;
		free(ll->head);
		ll->head = headNext;
	}
	// reset values
	ll->tail = NULL;
	ll->count = 0;
}

void LL_insert(LinkedList* ll, unsigned int index, void* data) {
	// if the index is the count, that's just a pushBack
	if(index == ll->count) {
		LL_pushBack(ll, data);
		return;
	}
	// if the index is 0, that's just a pushFront
	if(index == 0) {
		LL_pushFront(ll, data);
		return;
	}

	struct LLNode* currNode;
	struct LLNode* newNode = malloc(sizeof(struct LLNode));
	newNode->data = data;
	unsigned int a;

	// if the index is less than half the count, start from the head
	if(index <= (ll->count >> 1)) {
		currNode = ll->head;
		a = 0;
		while(++a <= index) currNode = currNode->next;
	}
	// the index is greater than half the count, so start from the tail
	else {
		currNode = ll->tail;
		a = ll->count;
		while(--a >= index) currNode = currNode->prev;
	}

	currNode->prev->next = newNode;
	newNode->prev = currNode->prev;
	currNode->prev = newNode;
	newNode->next = currNode;

	++(ll->count);
}

void* LL_at(const LinkedList* ll, unsigned int index) { 
	struct LLNode* currNode;
	unsigned int a;
	// if the index is less than half the count, start from the head
	if(index <= (ll->count >> 1)) {
		currNode = ll->head;
		a = 0;
		while(++a <= index) currNode = currNode->next;
	}
	// the index is greater than half the count, so start from the tail
	else {
		currNode = ll->tail;
		a = ll->count;
		while(--a >= index) currNode = currNode->prev;
	}
	return currNode->data;
}
