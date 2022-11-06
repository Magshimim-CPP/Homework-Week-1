#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include "Queue.h"

using namespace std;

void initQueue(Queue* q, unsigned int size)
{
	q->InsertIndex = 0;
	q->ReleaseIndex = 0;
	q->size = size;
	q->values = (int*)malloc(size * sizeof(int));
}

bool isEmpty(Queue* s)
{
	if (s->InsertIndex == s->ReleaseIndex)
	{
		return true;
	}
	return false;
}
