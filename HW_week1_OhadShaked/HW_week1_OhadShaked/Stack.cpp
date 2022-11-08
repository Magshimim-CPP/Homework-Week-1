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

int pop(Stack* s)
{
    Node* temp = NULL;
    int return_val = ZERO;

    temp = s->head;

    return_val = temp->value;

    s->head = s->head->next;

    delete temp;

    return return_val;
}

void cleanStack(Stack* s)
{
    Node* temp = NULL;

    while (!isEmpty(s))
    {
        temp = s->head;

        s->head = s->head->next;

        delete temp;
    }
}

void initStack(Stack* s)
{
    s->head = NULL;
}
