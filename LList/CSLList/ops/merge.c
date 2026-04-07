/** ===== Circular Singly Linked List : Merge Operation ===== **/


/** ===== Documentation ===== **/
/*
 * This program creates a circular singly linked lists.(Dynamically allocates the memory for the lists)
 * Initializes their data elements with the user given values.
 * And, display these two lists.
 * Creates a new list that is a merged list of the both list.
 * And, finally displays the merged list.
*/


/** ===== Preprocessing Directives ===== **/
#include<stdio.h>		//For Basic I/O functions.
#include<stdlib.h>	//For DMA functions like malloc(), free(),...


/** ===== Global Declaration ===== **/
/* ---- Node Definition ---- */
struct node {
	int data;
	struct node *next;
};

struct node *header1 = NULL, *header2 = NULL, *header3 = NULL, *header = NULL, *N1 = NULL, *N2 = NULL;	//Declaraing here for the global access.
int n1, n2, size;


/** ===== Function Prototypes ===== **/
struct node* createNode(int value);
void createList(int n);
void freeList(struct node *head);
int display(struct node *);
int merge(struct node *, struct node *);


/** ===== Main Function ===== **/
int main()
{
	int status = 0;
	//Allocating memory for header nodes:
	header1 = malloc(sizeof(struct node));
	header2 = malloc(sizeof(struct node));
	header3 = malloc(sizeof(struct node));
	if(header1 == NULL || header2 == NULL || header3 == NULL)
	{
		printf("Memory allocation failed!\n");
		status = 1;
		goto cleanup;
	}
	header1->next = NULL;
	header2->next = NULL;
	header3->next = NULL;

	
	//First list:
	printf("\nThe first list: \n");
	printf("\nEnter the no. of nodes in the list: ");
	scanf("%d", &n1);
	if(n1 < 1)
	{
		printf("\nNo elements to create the list!!\n");
		status = 1;
		goto cleanup;
	}
	printf("\nEnter the node values: ");
	header = header1;
	createList(n1);
	if(display(header1))
	{
		status = 1;
		goto cleanup;
	}

	//Second List:
	printf("\nThe second list: \n");
	printf("\nEnter the no. of nodes in the list: ");
	scanf("%d", &n2);
	if(n2 < 1)
	{
		printf("\nNo elements to create the list!!\n");
		status = 1;
		goto cleanup;
	}
	printf("\nEnter the node values: ");
	header = header2;
	createList(n2);
	if(display(header2))
	{
		status = 1;
		goto cleanup;
	}

	//Merging:
	printf("\nThe merged list: \n");
	if(merge(header1, header2))
	{
		status = 1;
		goto cleanup;
	}
	if(display(header3)) status = 1;		//Display the merged list.

	cleanup:
	//Free the memory:
	if(header3 != NULL && header3->next != NULL)
	{
		freeList(header3);
		if(header1 != NULL) header1->next = NULL;
		if(header2 != NULL) header2->next = NULL;
	}
	else
	{
		if(header1 != NULL) freeList(header1);
		if(header2 != NULL) freeList(header2);
	}

	free(header1); header1 = NULL;
	free(header2); header2 = NULL;
	free(header3); header3 = NULL;

	return status;	//Exit Status.
}


/** ===== Function Definitions ===== **/

//createNode():
//This function allocates memory for a single node.

struct node* createNode(int value)
{
	struct node *newNode = (struct node*)malloc(sizeof(struct node));

	if(newNode == NULL)
	{
		printf("Memory allocation failed!\n");
		return NULL;
	}

	newNode->data = value;
	newNode->next = NULL;

	return newNode;
}


//createList():
//This function initializes the list with user-provided values.

void createList(int n)
{
	struct node *temp, *last = NULL;

	for(int i = 0; i < n; i++)
	{
		int val;
		scanf("%d", &val);

		struct node *newNode = createNode(val);

		if(newNode == NULL)
		{
			freeList(header);
			return;
		}

		if(header->next == NULL)
		{
			header->next = newNode;
			newNode->next = newNode; // circular
		}
		else
		{
			newNode->next = header->next;
			last->next = newNode;
		}

		last = newNode;
		temp = newNode;
	}

	if(temp != NULL)
	{
		temp->next = header->next;
	}

	printf("\nSuccessfully initialized the list with values.\n");
}

void freeList(struct node *head)
{
	if(head->next == NULL)
	{
		return;
	}

	struct node *first = head->next;
	struct node *curr = first->next;
	while(curr != first)
	{
		struct node *next = curr->next;
		free(curr);
		curr = next;
	}
	free(first);
	head->next = NULL;
}


//display():
//This function traverses through the list and displays the node values.

int display(struct node *header)
{
	struct node *temp = NULL;
	temp = header->next;

	//Traversing through the list:
	printf("\nThe list is : \n");
	do
	{
		printf("[ %d ] -> ", temp -> data);
		temp = temp -> next;
	}while(temp != header -> next);

	printf("[ FIRST NODE ]\n");

	return 0;
}


//merge():
//This function merges two linked lists as a single list.

int merge(struct node *h1, struct node *h2)
{
	//Linking the first list to the header:
	header3->next = h1->next;

	struct node *temp = NULL;
	temp = header3->next;

	//Traversing till the last node of the first list:
	do
	{
		temp = temp -> next;
	}while(temp -> next != header3 -> next);

	//Linking last node of list1 to first node of list2:
	temp -> next = h2->next;

	//Making the circular link:
	//First traversing till the last node of the second list:
	do
	{
		temp = temp -> next;
	}while(temp -> next != h2 -> next);

	temp -> next = header3 -> next;

	return 0;
}
