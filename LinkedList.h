#ifndef LINKEDLIST_H
#define LINKEDLIST_H

/*
var	data	(void*)
	the data stored in the linked list
var	next	(struct LLNode*)
	one node closer to the back of the list
var	prev	(struct LLNode*)
	one node closer to the front of the list

Wrapper struct for storing data in a LinkedList
*/
struct LLNode {
	void* data;
	struct LLNode* next;
	struct LLNode* prev;
};

/*
var	head	(struct LLNode*)
	the front of the list, 
var	tail	(struct LLNode*)
	the back of the list, 
var	count	(unsigned int)
	the number of elements in the list

Doubly Linked List data structure. Functions found below
*/
typedef struct {
	struct LLNode* head;
	struct LLNode* tail;
	unsigned int count;
}LinkedList;

/*
return		(LinkedList)
	initialized LinkedList

Creates a LinkedList and initializes it to an empty list
*/
LinkedList LL_init();

/*
return		(LinkedList*)
	malloc'ed and initialized LinkedList

Allocates space for and initializes a LinkedList
*/
LinkedList* LL_create();

/*
param	ll	(LinkedList*)
	list to which p:data will be pushed in the front
param	data	(void*)
	data to be pushed to p:ll

Inserts a new element to the front of the list
*/
void LL_pushFront(LinkedList* ll, void* data);

/*
param	ll	(LinkedList*)
	list to which p:data will be pushed in the back
param	data	(void*)
	data to be pushed to p:ll

Inserts a new element to the back of the list
*/
void LL_pushBack(LinkedList* ll, void* data);

/*
param	ll	(LinkedList*)
	list from which the return value will be popped from the front
return		(void*)
	data popped from p:ll

Removes the element at the front of the list and returns it
*/
void* LL_popFront(LinkedList* ll);

/*
param	ll	(LinkedList*)
	list from which the return value will be popped from the back
return		(void*)
	data popped from p:ll

Removes the element at the back of the list and returns it
*/
void* LL_popBack(LinkedList* ll);

/*
param	ll	(const LinkedList*)
	list to be inspected
return		(void*)
	the next element to be popped from the front of the list,
	i.e. the last element that was pushed to the front of the list

Returns the front of the list
*/
void* LL_peekFront(const LinkedList* ll);

/*
param	ll	(const LinkedList*)
	list to be inspected
return		(void*)
	the next element to be popped from the back of the list,
	i.e. the last element that was pushed to the back of the list

Returns the back of the list
*/
void* LL_peekBack(const LinkedList* ll);

/*
param	ll	(const LinkedList*)
	list to be inspected
return		(int)
	whether p:ll contains any elements

Returns whether the list is empty
*/
int LL_isEmpty(const LinkedList* ll);

/*
param	ll	(const LinkedList*)
	list to be inspected
return		(unsigned int)
	count of all the elements in the list

Returns the number of elements in the list
*/
unsigned int LL_count(const LinkedList* ll);

/*
param	ll	(LinkedList*)
	list to be cleared
param	destroy	(void (void*))
	function that handles the freeing of v:data in each element of p:list
return		(void)

Empties the list
*/
void LL_clear(LinkedList* ll, void (*destroy)(void*));

/*
param	ll	(LinkedList*)
	list into which p:data will be inserted at index p:index
param	index	(unsigned int)
	index at which p:data will be inserted into p:ll
param	data	(void*)
	data to be inserted into p:ll at index p:index
return		(void)

Inserts an element into the list at a specific index
*/
void LL_insert(LinkedList* ll, unsigned int index, void* data);

/*
param	ll	(const LinkedList*)
	list to be inspected
param	index	(unsigned int)
	index from which an element will be returned from p:ll
return		(void*)
	the element at index p:index in p:ll

Returns the element at a specified index in the list
*/
void* LL_at(const LinkedList* ll, unsigned int index);

#endif
