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
	//setting queue properties to defult values.
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
	//looping through the values array of the queue, and setting the values to 0.
	for (int i = ZERO; i < q->size; i++)
	{
		q->values[i] = ZERO;
	}
}

/*
Function adds a new given value to the current InsertIndex, and moves the insertion index number 1 forward.
(or printing error if the queue is full).
Input: Queue* q, unsigned int newValue
Output: none.
*/
void enqueue(Queue* q, unsigned int newValue)
{
	//If the queue isn't full
	if (!isFull(q))
	{
		//setting the 'InsertIndex' slot in the values array to the given 'newValue'.
		q->values[q->InsertIndex] = newValue;
		//moving the InsertIndex one slot forward.
		q->InsertIndex = AddIndexInRange((q->InsertIndex), (q->size));
	}
	//if the queue was full, printing error message.
	else 
	{
		cout << "ERROR: Queue is full!\n" << endl;
	}
}

/*
Function returns the element in the top of the queue, or -1 if the given queue is empty.
Input: Queue* q
Output: the value stored in the current ReleaseIndex, (or -1 if the queue is empty).
*/
int dequeue(Queue* q)
{
	int value = ZERO;

	//If the queue isn't empty
	if (!isEmpty(q))
	{
		//setting 'value' to the current value stored in the ReleaseIndex of the values array.
		value = q->values[q->ReleaseIndex];
		//moving the ReleaseIndex one slot forward.
		q->ReleaseIndex = AddIndexInRange(q->ReleaseIndex, q->size);
		//returning the value.
		return value;
	}
	//if the queue is empty, printing error message and returning -1.
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
	//if the InsertIndex is the same number as the ReleaseIndex, retutning true (empty).
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
	//if the next InsertIndex is equal to the current ReleaseIndex (queue is full), returning true.
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
