#ifndef LINKEDLIST_H
#define LINKEDLIST_H


/* a queue contains positive integer values. */
typedef struct Node
{
	//Node structure values.
	unsigned int value;
	Node* next;
	Node* head;

} Node;

void AddNode(Node** head, unsigned int newValue); // Create and adds a new node with the given value to the head of the linked list.
void RemoveNode(Node** head); // Deletes the current head of the list, and sets the next node (head->next) to be the head.

#endif /* LINKEDLIST_H */