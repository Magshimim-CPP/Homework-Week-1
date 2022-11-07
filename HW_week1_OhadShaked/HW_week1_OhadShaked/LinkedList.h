#ifndef LINKEDLIST_H
#define LINKEDLIST_H


/* a queue contains positive integer values. */
typedef struct Node
{
	unsigned int value;
	Node* next;
	Node* head;
	Node* tail;

} Node;

void AddNode(Node** head, unsigned int newValue);
void RemoveNode(Node** head);

#endif /* LINKEDLIST_H */