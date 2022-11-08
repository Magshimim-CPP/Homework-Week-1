#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include "Stack.h"

using namespace std;

//setting constant define variables
#define ZERO 0
#define ONE 1

/*
Function creates a new node with the given value, and adds the node to the head of the stack.
Input: Stack* s, unsigned int element
Output: none.
*/
void push(Stack* s, unsigned int element)
{
    //making a new node to contain the given element.
    Node* temp = new Node();
    //setting the node's value to the given element.
    temp->value = element;
    //the 'next' pointer of temp will point to the current head of the stack.
    temp->next = s->head;
    //making temp the new head of the stack.
    s->head = temp;
}

/*
Function checks if the given Stack is empty.
Input: Stack* s
Output: true/false based on the result.
*/
bool isEmpty(Stack* s)
{
    //if there is no head to the stack (empty), returning true.
    if (s->head == NULL)
    {
        return true;
    }
    return false;
}

/*
Function returns the value stored in the head node (or -1 if the stack is empty).
Input: Stack* s
Output: the value stored in the current head node, (or -1 if the stack is empty).
*/
int pop(Stack* s)
{
    Node* temp = NULL;
    int return_val = ZERO;

    //If the stack isn't empty
    if (!isEmpty(s))
    {
        //setting temp to the current head node.
        temp = s->head;
        //saving the head node's value in 'return_val'
        return_val = temp->value;
        //moving the head node one forward (to the next node of the stack).
        s->head = s->head->next;
        //deleting the current head node.
        delete temp;
        //returning the value from the popped node (return_val).
        return return_val;
    }
    //if the stack is empty, printing error message and returning -1.
    else
    {
        cout << "ERROR: Stack is empty!\n" << endl;
        return -ONE;
    }
}

/*
Function cleans the value in each node (sets to zero), and deletes the node.
Input: Stack* s
Output: none.
*/
void cleanStack(Stack* s)
{
    Node* temp = NULL;

    //looping through the nodes untill the stack is empty.
    while (!isEmpty(s))
    {
        //setting temp to the current head
        temp = s->head;
        //moving the head one forwart (to the next node of the stack)
        s->head = s->head->next;
        //setting the value stored in the current head node to 0.
        temp->value = ZERO;
        //deleting the current head node (freeing dynamic memory).
        delete temp;
    }
}

/*
Function initializes the given Stack (sets the head node to null).
Input: Stack* s
Output: none.
*/
void initStack(Stack* s)
{
    //setting the stack's head node to NULL at initialization.
    s->head = NULL;
}
