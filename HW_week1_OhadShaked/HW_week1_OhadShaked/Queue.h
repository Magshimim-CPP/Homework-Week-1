#ifndef QUEUE_H
#define QUEUE_H


/* a queue contains positive integer values. */
typedef struct Queue
{
	unsigned int InsertIndex;
	unsigned int ReleaseIndex;
	unsigned int size;
	int* values;

} Queue;

void initQueue(Queue* q, unsigned int size); // Initializes the given queue: index numbers to zero, size to the given size, and the values to a dynamic array with the given size.
void cleanQueue(Queue* q); // Cleans all of the values that are stored in the queue's dynamic array (set's them to zero).

void enqueue(Queue* q, unsigned int newValue);
int dequeue(Queue* q); // Returns the element in the top of the queue, or -1 if the given queue is empty.

bool isEmpty(Queue* s); // Checks if the given Queue is empty.
bool isFull(Queue* s); // Checks if the given Queue is full.

int AddIndexInRange(int index, int size); // Checks if a given index is in the range of a given size.

#endif /* QUEUE_H */