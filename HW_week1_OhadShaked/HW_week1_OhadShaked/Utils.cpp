#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include "Stack.h"

using namespace std;

#define ZERO 0
#define ONE 1

void reverse(int* nums, unsigned int size)
{
	Stack* s = new Stack();
	int* arr = nums;

	for (int i = ZERO; i < size; i++)
	{
		push(s, arr[i]);
	}

	for (int i = ZERO; i < size; i++)
	{
		*nums = pop(s);
		nums++;
	}
}

int* reverse10()
{
	
}