#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include "Stack.h"

using namespace std;

//setting constant define variables
#define ZERO 0
#define ONE 1

void push(Stack* s, unsigned int element)
{
    Node* temp = new Node();

    temp->value = element;

    temp->next = s->head;

    s->head = temp;
}

/*
Function checks if the given Stack is empty.
Input: Stack* s
Output: true/false based on the result.
*/
bool isEmpty(Stack* s)
{
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
        temp = s->head;

        return_val = temp->value;

        s->head = s->head->next;

        delete temp;

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

    while (!isEmpty(s))
    {
        temp = s->head;

        s->head = s->head->next;

        temp->value = ZERO;

        delete temp;
    }
}

/*
Function initializes the given Stack (sets the head node to null.
Input: Stack* s
Output: none.
*/
void initStack(Stack* s)
{
    s->head = NULL;
}
