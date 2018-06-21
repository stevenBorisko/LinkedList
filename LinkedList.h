#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdlib.h>

//----------------------------------------------------------------------------//
// --- Structure Declarations ---
//----------------------------------------------------------------------------//

/*
--- LLNode ---

data (void*)
	- The data stored in the linked list
next (LLNode*)
	- One node closer to the back of the list
prev (LLNode*)
	- One node closer to the front of the list

Wrapper struct for storing data in a LinkedList
*/
typedef struct LLNode {
	void* data;
	struct LLNode* next;
	struct LLNode* prev;
} LLNode;

/*
--- LLNode ---

head (LLNode*)
	- The front of the list, 
tail (LLNode*)
	- The back of the list, 
count (unsigned int)
	- The number of elements in the list

Doubly Linked List data structure. Functions found below
*/
typedef struct {
	LLNode* head;
	LLNode* tail;
	unsigned int count;
} LinkedList;

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
--- LL_pushFront ---

ll (LinkedList*)
	- List to which `data` will be pushed in the front
data (void*)
	- Data to be pushed to `ll`

Inserts a new element to the front of the list
*/
void LL_pushFront(LinkedList* ll, void* data);

/*
--- LL_pushBack ---

ll (LinkedList*)
	- List to which `data` will be pushed in the back
data (void*)
	- Data to be pushed to `ll`

Inserts a new element to the back of the list
*/
void LL_pushBack(LinkedList* ll, void* data);

/*
--- LL_popFront ---

ll (LinkedList*)
	- List from which the return value will be popped from the front

return (void*)
	Data popped from `ll`

Removes the element at the front of the list and returns it
*/
void* LL_popFront(LinkedList* ll);

/*
--- LL_popBack ---

ll (LinkedList*)
	- List from which the return value will be popped from the back

return (void*)
	Data popped from `ll`

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
	Whether `ll` contains any elements

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
	- param (void*)
		* data to be freed (or not, if you need to keep the elements elsewhere)
	- Function that handles the freeing of `data` in each element of `ll`

Empties the list
*/
void LL_clear(LinkedList* ll, void (*destroy)(void*));

/*
--- LL_insert ---

ll (LinkedList*)
	- List into which `data` will be inserted at index `index`
index (unsigned int)
	- Index at which `data` will be inserted into `ll`
data (void*)
	- Data to be inserted into `ll` at index `index`

Inserts an element into the list at a specific index
*/
void LL_insert(LinkedList* ll, unsigned int index, void* data);

/*
--- LL_remove ---

ll (LinkedList*)
	- List from which the element at `index` will be removed
index (unsigned int)
	- Index of the element to remove

return (void*)
	- Data at `index` prior to removal

Removes an element from the list at a specific index
*/
void* LL_remove(LinkedList* ll, unsigned int index);

/*
--- LL_at ---

ll (const LinkedList*)
	- List to be inspected
index (unsigned int)
	- Index from which an element will be returned from `ll`
return (void*)
	- The element at index `index` in `ll`

Returns the element at a specified index in the list
*/
void* LL_at(const LinkedList* ll, unsigned int index);

/*
--- LL_search ---

ll (const LinkedList*)
	- List to be inspected
match (int (void*))
	- param (void*)
		* data that is being searched
	- return (int)
		0: data does not match, keep searching
		1: data matches, return it
	- Functions to determine if an element is the one for which the
	function is searching
data (void**)
	- The address of an allocated void*. This void* will be set to the data
	found (if it was found).
	- If the data was not found, this is set to NULL

return (unsigned int)
	ll->count: data was not found.
	< ll->count: data was found. Value is the index in the list. `*data`
		will be set to the data of this element

Searches a list for a specific element.
	- Returns both the element and the index.
*/
unsigned int LL_search(
	const LinkedList* ll,
	int (*match)(void*),
	void** data
);

/*
--- LL_array ---

ll (const LinkedList*)
	- List to be converted
arr (void**)
	- Memory allocated prior to function call
		* array must be at least `ll->count` elements long
	- Will be filled with a shallow copy of the data in `ll`

Performs a shallow copy of the data in a LinkedList into an array
*/
void LL_array(const LinkedList* ll, void** arr);

#endif
