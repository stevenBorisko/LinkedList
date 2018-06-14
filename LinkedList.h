#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdlib.h>

//----------------------------------------------------------------------------//
// --- Structure Declarations ---
//----------------------------------------------------------------------------//

/*
--- struct LLNode ---

data (void*)
	- The data stored in the linked list
next (struct LLNode*)
	- One node closer to the back of the list
prev (struct LLNode*)
	- One node closer to the front of the list

Wrapper struct for storing data in a LinkedList
*/
struct LLNode {
	void* data;
	struct LLNode* next;
	struct LLNode* prev;
};

/*
--- LLNode ---

head (struct LLNode*)
	- The front of the list, 
tail (struct LLNode*)
	- The back of the list, 
count (unsigned int)
	- The number of elements in the list

Doubly Linked List data structure. Functions found below
*/
typedef struct {
	struct LLNode* head;
	struct LLNode* tail;
	unsigned int count;
}LinkedList;

//----------------------------------------------------------------------------//
// --- LinkedList Function Declarations ---
//----------------------------------------------------------------------------//

/*
--- LL_init ---

return (LinkedList)
	Initialized LinkedList

Creates a LinkedList and initializes it to an empty list
*/
LinkedList LL_init();

/*
--- LL_create ---

return (LinkedList*)
	Malloc'ed and initialized LinkedList

Allocates space for and initializes a LinkedList
*/
LinkedList* LL_create();

/*
--- LL_pushFront ---

ll (LinkedList*)
	- List to which p:data will be pushed in the front
data (void*)
	- Data to be pushed to p:ll

Inserts a new element to the front of the list
*/
void LL_pushFront(LinkedList* ll, void* data);

/*
--- LL_pushBack ---

ll (LinkedList*)
	- List to which p:data will be pushed in the back
data (void*)
	- Data to be pushed to p:ll

Inserts a new element to the back of the list
*/
void LL_pushBack(LinkedList* ll, void* data);

/*
--- LL_popFront ---

ll (LinkedList*)
	- List from which the return value will be popped from the front

return (void*)
	Data popped from p:ll

Removes the element at the front of the list and returns it
*/
void* LL_popFront(LinkedList* ll);

/*
--- LL_popBack ---

ll (LinkedList*)
	- List from which the return value will be popped from the back

return (void*)
	Data popped from p:ll

Removes the element at the back of the list and returns it
*/
void* LL_popBack(LinkedList* ll);

/*
--- LL_peekFront ---

ll (const LinkedList*)
	- List to be inspected

return (void*)
	The next element to be popped from the front of the list,
	I.e. the last element that was pushed to the front of the list

Returns the front of the list
*/
void* LL_peekFront(const LinkedList* ll);

/*
--- LL_peekBack ---

ll (const LinkedList*)
	- List to be inspected

return (void*)
	The next element to be popped from the back of the list,
	I.e. the last element that was pushed to the back of the list

Returns the back of the list
*/
void* LL_peekBack(const LinkedList* ll);

/*
--- LL_isEmpty ---

ll (const LinkedList*)
	- List to be inspected

return (int)
	Whether p:ll contains any elements

Returns whether the list is empty
*/
int LL_isEmpty(const LinkedList* ll);

/*
--- LL_count ---

ll (const LinkedList*)
	- List to be inspected

return (unsigned int)
	Count of all the elements in the list

Returns the number of elements in the list
*/
unsigned int LL_count(const LinkedList* ll);

/*
--- LL_clear ---

ll (LinkedList*)
	- List to be cleared
destroy (void (void*))
	- Function that handles the freeing of v:data in each element of p:list

Empties the list
*/
void LL_clear(LinkedList* ll, void (*destroy)(void*));

/*
--- LL_insert ---

ll (LinkedList*)
	- List into which p:data will be inserted at index p:index
index (unsigned int)
	- Index at which p:data will be inserted into p:ll
data (void*)
	- Data to be inserted into p:ll at index p:index

Inserts an element into the list at a specific index
*/
void LL_insert(LinkedList* ll, unsigned int index, void* data);

/*
--- LL_remove ---

ll (LinkedList*)
	- List from which the element at p:index will be removed
index (unsigned int)
	- Index of the element to remove

return (void*)
	- Data at p:index prior to removal

Removes an element from the list at a specific index
*/
void* LL_remove(LinkedList* ll, unsigned int index);

/*
--- LL_at ---

ll (const LinkedList*)
	- List to be inspected
index (unsigned int)
	- Index from which an element will be returned from p:ll
return (void*)
	- The element at index p:index in p:ll

Returns the element at a specified index in the list
*/
void* LL_at(const LinkedList* ll, unsigned int index);

#endif
