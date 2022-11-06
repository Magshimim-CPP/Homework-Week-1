#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include "Queue.h"

using namespace std;

#define ZERO 0
#define ONE 1

void initQueue(Queue* q, unsigned int size)
{
	q->InsertIndex = ZERO;
	q->ReleaseIndex = ZERO;
	q->size = size;
	q->values = new int[size];
}

void cleanQueue(Queue* q)
{
	for (int i = ZERO; i < q->size; i++)
	{
		q->values[i] = ZERO;
	}
}

void enqueue(Queue* q, unsigned int newValue)
{
	if (!isFull(q))
	{
		q->values[q->InsertIndex] = newValue;
		q->InsertIndex = AddIndexInRange((q->InsertIndex), (q->size));
	}
	else 
	{
		cout << "ERROR: Queue is full!\n" << endl;
	}
}

int dequeue(Queue* q)
{
	int value = ZERO;

	if (!isEmpty(q))
	{
		value = q->values[q->ReleaseIndex];
		q->ReleaseIndex = AddIndexInRange(q->ReleaseIndex, q->size);
		return value;
	}
	else
	{
		cout << "ERROR: Queue is empty!\n" << endl;
		return -ONE;
	}
	
}

bool isEmpty(Queue* s)
{
	if (s->InsertIndex == s->ReleaseIndex)
	{
		return true;
	}
	return false;
}

bool isFull(Queue* s)
{
	if (AddIndexInRange((s->InsertIndex), (s->size)) == (s->ReleaseIndex))
	{
		return true;
	}
	return false;
}

int AddIndexInRange(int index, int size)
{
	if (index < size)
	{
		index++;
	}

	else
	{
		index = ZERO;
	}
	return index;
}
