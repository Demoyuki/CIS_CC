/*
	Modified by: Victor Marrujo
	Assignment: Chpt4 PA
	Filename: LinkedList.c
	Date: Feburary 19th, 2024 (completed on Feburary 22h, 2024) 
*/ 

#include <stdio.h>
#include <stdlib.h>

// struct to hold the data and pointer of a node
struct node 
{
	int data;
	struct node *next;
} 	node;

// pointers to the head node
struct node *head = NULL;

// Function to perform the same list operation as the pseudocode found in section 4.2.5
void listPrepend(int data)
{

	//create a link
	struct node *lk = (struct node*) malloc(sizeof(struct node));
	lk->data = data;

	// point it to old first node
	lk->next = head;

	//point first to new first node
	head = lk;
}

// Function to perform the same list operation as the pseudocode found in section 4.2.3
void listAppend(int data)
{
	if (head == NULL) 
	{ // list is empty
		listPrepend(data);
	} 
		else 
		{
		//create a link
		struct node *lk = (struct node*) malloc(sizeof(struct node));
		lk->data = data;
		struct node *linkedlist = head;

		// point it to old first node
		while(linkedlist->next != NULL) {
			linkedlist = linkedlist->next;
		}
   
		//point first to new first node
		linkedlist->next = lk;
	}
}

// Function to perform the same list operation as the pseudocode found in section 4.3.1
void listInsertAfter(struct node *list, int data)
{
	struct node *lk = (struct node*) malloc(sizeof(struct node));
	lk->data = data;
	lk->next = list->next;
	list->next = lk;
}

// Function to perform the same list operation as the pseudocode found in section 4.4.1
// Function removes the node that is passed in, not the next node
void listRemoveNode(int key)
{
	struct node *temp = head, *prev;
	if (temp != NULL && temp->data == key) 
	{
		head = temp->next;
		return;
	}

	// Find the key to be deleted
	while (temp != NULL && temp->data != key) 
	{
		prev = temp;
		temp = temp->next;
	}

	// If the key is not present
	if (temp == NULL) return;

	// Remove the node
	prev->next = temp->next;
}

// Function to perform the same list operation as the pseudocode found in section 4.5.1
// Function will return a 1 if found or 0 if not found
int listSearch(int key)
{
	struct node *temp = head;
	while(temp != NULL) {
		if (temp->data == key) {
			return 1;
		}
		temp=temp->next;
	}
	return 0;
}

//Function to perform the same list operation as the  pseudocode found in section 4.9.1
void listTraverse()
{
	struct node *p = head;
	printf("\nThe list order is: ");

	//start from the beginning
	while(p != NULL) {
		printf("%d ",p->data);
		p = p->next;
	}
}

// Implement sumDataValues method
int sumDataValues() 
{
	struct node *temp = head;
	int sum = 0;
	while(temp != NULL) {
		sum += temp->data;
		temp = temp->next;
	}
	return sum;
}

int main()
{
	// Statements ==============================================================
	
	// Append a node with a data value of 1 to the linked list
    listAppend(1);

    // Append a node with a data value of 2 to the linked list
    listAppend(2);

    // Prepend a node with a data value of 3 to the linked list
    listPrepend(3);

    // Insert a node with a data value of 4 after the head node in the linked list
    listInsertAfter(head, 4);
	//listTraverse();
    // Insert a node with a data value of 5 at the end of the linked list
    listAppend(5);

	// Insert a node with a data value of 6 after the node with a data value of 4 in the linked list
	struct node *node4 = head->next; // find the node with data value 4
	listInsertAfter(node4, 6);
	//listTraverse();
	
	// Insert a node with a data value of 7 after the node with a data value of 2 in the linked list
	struct node *node2 = head->next->next->next->next; // find the node with data value 2
	listInsertAfter(node2, 7);


    // Display the list
    listTraverse();

    // Remove the head node
    listRemoveNode(head->data);

    // Remove the node after the node with a data value of 7
    listRemoveNode(5);

    // Display the list
    listTraverse();

    // Search for the node with a data value of 5 and display if it was found or not found
    if (listSearch(5)) {
        printf("\n\nNode with data value 5 found.");
    } else {
        printf("\n\nNode with data value 5 not found.");
    }

    // Search for the node with a data value of 2 and display if it was found or not found
    if (listSearch(2)) {
        printf("\nNode with data value 2 found.\n");
    } else {
        printf("\nNode with data value 2 not found.\n");
    }

    // Sum and display the sum of the node values
    int sum = sumDataValues();
    printf("\nSum of Linked List data values is: %d\n", sum);

    return 0;
}
