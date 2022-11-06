#ifndef LINKEDLIST_H
#define LINKEDLIST_H


/* a queue contains positive integer values. */
typedef struct LinkedList
{
	unsigned int value;
	LinkedList* next;
	LinkedList* head;
	LinkedList* tail;

} LinkedList;

void AddNode(unsigned int value);
void RemoveNode();

#endif /* LINKEDLIST_H */