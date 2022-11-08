#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include "Stack.h"

using namespace std;

//setting constant define variables
#define ZERO 0
#define ONE 1

/*
Function reverses the numbers stored in a given array using the stack structure.
Input: int* nums, unsigned int size
Output: none.
*/
void reverse(int* nums, unsigned int size)
{
	Stack* s = new Stack();
	int* tempArr = nums;

	//looping to push all of the numbers from the array into the stack.
	for (int i = ZERO; i < size; i++)
	{
		push(s, tempArr[i]);
	}
	//popping the numbers from the stack (starts from last one that was enterd --> reversed).
	for (int i = ZERO; i < size; i++)
	{
		nums[i] = pop(s);
	}
}

int* reverse10()
{
	return NULL;
}