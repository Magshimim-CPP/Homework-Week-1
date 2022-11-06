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

void initQueue(Queue* q, unsigned int size);
void cleanQueue(Queue* q);

void enqueue(Queue* q, unsigned int newValue);
int dequeue(Queue* q); // return element in top of queue, or -1 if empty

bool isEmpty(Queue* s);
bool isFull(Queue* s);

int AddIndexInRange(int index, int size);

#endif /* QUEUE_H */