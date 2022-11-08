#ifndef STACK_H
#define STACK_H

#include "LinkedList.h"

/* a positive-integer value stack, with no size limit */
typedef struct Stack
{
	//Stack structure values.
	Node* head;
	
} Stack;

void push(Stack* s, unsigned int element); 
int pop(Stack* s); // Returns the value stored in the current head node (or -1 if the stack is empty).

void initStack(Stack* s); // Initializes the given Stack
void cleanStack(Stack* s); // Cleans the value in each node (sets to zero), and deletes the node.

bool isEmpty(Stack* s); // Checks if the given Stack is empty.

//bool isFull(Stack* s); //no need for "isFull" if there is no size limit

#endif // STACK_H