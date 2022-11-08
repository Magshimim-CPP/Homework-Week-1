#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include "Stack.h"

using namespace std;

//setting constant define variables
#define ZERO 0
#define ONE 1
#define ARR_LEN 10

/*
Function reverses the numbers stored in a given array using the stack structure.
Input: int* nums, unsigned int size
Output: none.
*/
void reverse(int* nums, unsigned int size)
{
	Stack* s = new Stack();

	//looping to push all of the numbers from the array into the stack.
	for (int i = ZERO; i < size; i++)
	{
		push(s, nums[i]);
	}
	//popping the numbers from the stack (starts from last one that was pushed --> reversed).
	for (int i = ZERO; i < size; i++)
	{
		nums[i] = pop(s);
	}
}

/*
Function takes input for 10 numbers in a array, reverses the array, and returns the reversed array.
Input: no input.
Output: the created reversed array (int* nums).
*/
int* reverse10()
{
	//creating a dynamic array for the numbers.
	int* nums = new int(ARR_LEN);

	//taking input for 10 numbers.
	cout << "Please enter 10 numbers:\n" << endl;
	for (int i = ZERO; i < ARR_LEN; i++)
	{
		cout << "num 1: " << endl;
		cin >> nums[i];
	}

	//reversing the array.
	reverse(nums, ARR_LEN);

	//returning the reversed array.
	return nums;
}