#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include "Queue.h"

using namespace std;

//setting constant define variables
#define ZERO 0
#define ONE 1

/*
Function initializes the given queue: index numbers to zero, size to the given size, and the values to a dynamic array with the given size.
Input: Queue* q, unsigned int size
Output: none.
*/
void initQueue(Queue* q, unsigned int size)
{
	q->InsertIndex = ZERO;
	q->ReleaseIndex = ZERO;
	q->size = size;
	q->values = new int[size];
}

/*
Function cleans all of the values that are stored in the queue's dynamic array (set's them to zero).
Input: Queue* q
Output: none.
*/
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

/*
Function checks if the given Queue is empty.
Input: Queue* s
Output: true/false based on the result.
*/
bool isEmpty(Queue* s)
{
	if (s->InsertIndex == s->ReleaseIndex)
	{
		return true;
	}
	return false;
}

/*
Function checks if the given Queue is full.
Input: Queue* s
Output: true/false based on the result.
*/
bool isFull(Queue* s)
{
	if (AddIndexInRange((s->InsertIndex), (s->size)) == (s->ReleaseIndex))
	{
		return true;
	}
	return false;
}

/*
Function checks if a given index is in the range of a given size.
if it is, the function adds 1 to the number and returns the new index. if it isn't, the function sets the index number to 0 and returns it.
Input: int index, int size
Output: the given index value increased by one / zero (if it's not in range).
*/
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
