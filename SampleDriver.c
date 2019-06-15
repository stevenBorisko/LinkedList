#include "LinkedList.h"

#include <stdio.h>

#define NAME_BUFFER_LENGTH 128

//----------------------------------------------------------------------------//
// Structure Definitions
//----------------------------------------------------------------------------//

typedef struct {
	char* name;
	unsigned int age;
} Person;

//----------------------------------------------------------------------------//
// Helper Function Declarations
//----------------------------------------------------------------------------//

void printList(FILE* out, const LinkedList* list);
int inputPerson(FILE* out, FILE* in, LinkedList* list);
int removePerson(FILE* out, FILE* in, LinkedList* list);
int shameUser(FILE* out, FILE* in, LinkedList* list);

//----------------------------------------------------------------------------//
// Main
//----------------------------------------------------------------------------//

int main(int argc, char** argv) {
	LinkedList list = LL_init();
	char reading;
	int (*action)(FILE*, FILE*, LinkedList*);

	for(reading = 'a'; reading != 'n';) {
		if(reading == 'a') action = inputPerson;
		else if(reading == 'r') action = removePerson;
		else action = shameUser;

		while(action(stdout, stdin, &list));

		printList(stdout, &list);

		fprintf(stdout, "Action (a/r/n): ");
		fscanf(stdin, "%c%*c", &reading);
	}

	return 0;
}

//----------------------------------------------------------------------------//
// Helper Function Implementations
//----------------------------------------------------------------------------//

void printList(FILE* out, const LinkedList* list) {
	Person* currPerson;
	const LLNode* currNode;
	unsigned int index;
	for(
		currNode = list->head, index = 0;
		currNode != NULL;
		currNode = currNode->next, ++index
	) {
		currPerson = currNode->data;
		fprintf(out, "%u) %s, %u\n", index, currPerson->name, currPerson->age);
	}
}

int inputPerson(FILE* out, FILE* in, LinkedList* list) {
		// Allocate and initialize memory for a new person
		Person* newPerson = malloc(sizeof(Person));
		newPerson->name = malloc(NAME_BUFFER_LENGTH);
		newPerson->age = 0;

		// Input data for the new person
		fprintf(out, "New Person...\n\tName: ");
		fscanf(in, "%[^\n]%*c", newPerson->name);
		fprintf(out, "\tAge: ");
		fscanf(in, "%u%*c", &newPerson->age);

		// Add new person to the list
		LL_pushBack(list, (void*)newPerson);

		return 0;
}

int removePerson(FILE* out, FILE* in, LinkedList* list) {
	unsigned int index;
	fprintf(out, "Remove Person...\n\tIndex: ");
	fscanf(in, "%u%*c", &index);

	if(index < LL_count(list)) {
		LL_remove(list, index);
		return 0;
	} else {
		fprintf(out, "\tBad input.\n");
		return 1;
	}
}

int shameUser(FILE* out, FILE* in, LinkedList* list) {
	fprintf(out, "Enter a single character for action\n");
	fprintf(out, "\ta: Add\n\tr: Remove\n\tn: None (exit program)\n");
	return 0;
}
