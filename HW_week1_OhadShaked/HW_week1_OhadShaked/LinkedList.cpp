#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include "LinkedList.h"

using namespace std;

#define ZERO 0
#define ONE 1

void AddNode(Node** head, unsigned int newValue)
{
	//making a new node to contain the given value.
	Node* newNode = new Node;
	//setting the node's value to the given value.
	newNode->value = newValue;
	//placing the node at the head of the linked list.
	newNode->next = *head;
	//*head = newNode;//
}

void RemoveNode(Node** head)
{
	//making a temp node for the freeing and deleting proccess (if needed).
	Node* temp = new Node;

	//if the node exist's (not NULL).
	if (*head)
	{
		//setting temp to the current node.
		temp = *head;
		//setting the current node to the next one.
		*head = (*head)->next;
		//deleting the current node's dynamic memory.
		delete temp;
		//printing the result to the user.
		cout << "SUCCESS: The head node was removed successfully.\n" << endl;
	}
	else
	{
		//printing the error result to the user.
		cout << "ERROR: there is no node to delete!\n" << endl;
	}
}