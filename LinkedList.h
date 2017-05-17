#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct LLNode {
	void* data;
	struct LLNode* next;
	struct LLNode* prev;
};

typedef struct {
	struct LLNode* head;
	struct LLNode* tail;
	unsigned int count;
}LinkedList;

LinkedList LL_create();

void LL_pushFront(LinkedList* ll, void* data);

void LL_pushBack(LinkedList* ll, void* data);

void* LL_popFront(LinkedList* ll);

void* LL_popBack(LinkedList* ll);

void* LL_peekFront(const LinkedList* ll);

void* LL_peekBack(const LinkedList* ll);

int LL_isEmpty(const LinkedList* ll);

unsigned int LL_count(const LinkedList* ll);

void LL_clear(LinkedList* ll, void (*destroy)(void*));

void LL_insert(LinkedList* ll, unsigned int index, void* data);

void* LL_at(const LinkedList* ll, unsigned int index);

#endif
