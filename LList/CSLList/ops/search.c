/** ===== Circular Single Linked List: Linear Search ===== **/


/** ===== Documentation ===== **/
/*
 * This program shows the implementation of the search operation on a Circular Single Linked List.
 * In this we do the following processes:
 	* Creation of the List.
	* Initialization of the List with certain values.
	* Display the List.
	* Then, searches for an element specified by the user in the list.
 * At last, prints the element position if it is found. 
 * If the element is not found then prints a message that tells that element was not found.
*/


/** ===== Preprocessing Directives ===== **/
#include<stdio.h>	//For Basic I/O functions like printf(), scanf(),....
#include<stdlib.h>		//For DMA functions like malloc(), free(),....


/** ===== Global Declaration ===== **/
/* ---- Node Definition ---- */
struct node {
	int data;
	struct node *next;
};

struct node *header = NULL, *N = NULL, new;		//Declaraing here for global access.
int n;


/** ===== Function Prototypes ===== **/
int create(void);
int init(void);
int display(struct node *);
int search(void);



/** ===== Main Function ===== **/
int main()
{
	header = malloc(sizeof(struct node));

	if(create()) return 1;
	init();
	if(display(header)) return 1;
	search();

	//Free memory:
	free(header);  header = NULL;
	free(N); N = NULL;

	return 0;
}


/** ===== Function Definitions ===== **/
//create():
//This function allocates the memory for the nodes.

int create()
{
	//Taking the total no. of nodes from the user:
	printf("\nEnter the no. of nodes of the list: ");
	scanf("%d", &n);

	if(n < 1)
	{
		printf("\nInsufficient nodes to create a list!!\n\n");		//Handling edge cases.
		return 1;
	}

	//Allocating the memory for the n nodes.
	N = malloc(n * sizeof(struct node));

	if(N == NULL)
	{
		printf("\nMemory allocation failed!");		//Checking if memory allocation is done or not.
		return 1;				
	}

	return 0;
}


//init():
//This function initializes all of the nodes in the list with a certain values.

int init()
{
	int i = 0;

	//Linking header node to the N nodes.
	header -> next = &N[0];

	//Taking the data of all the nodes.
	printf("\nEnter the data of all of the nodes: ");
	while(i < n)
	{
		scanf("%d", &((N+i) -> data));
		if(i == n-1)
		{
			(N+i) -> next = header -> next;
			return 0;
		}

		(N+i) -> next = ((N+i)+1);
		i += 1;
	}

	printf("\nSuccessfully initialized all the nodes with data.\n\n");

	return 0;
}


//display():
//This function displays all of the nodes of the list.

int display(struct node *head)
{
	//Checking the edge case:
	if(head -> next == NULL)
	{
		printf("\nThe list is empty!!\n\n");
		return 1;
	}

	struct node *temp = head -> next;

	//Traversing through the list to print all the nodes:
	printf("\nThe List is: \n");
	do
	{
		printf("[ %d ] -> ", temp -> data);
		temp = temp -> next;
	}while(temp != header -> next);

	printf(" [ FIRST NODE ]");
	printf("\nSuccessfully printed the list!!.\n");

	return 0;
}


//search():
//This function takes an element from the user and searches for the element in the list.

int search()
{
	int key, i = 0;
	
	//Taking the element from the user:
	printf("\nEnter the element that is to be searched: ");
	scanf("%d", &key);

	struct node *temp = NULL;
	temp = header -> next;

	//Traversing through the entire list:
	do
	{
		if(temp -> data == key)		//Comparing the node with key.
		{
			printf("\n%d is found in the list at the position: %d\n", key, i);
			
			return 0;
		}
		i += 1;
		temp = temp -> next;
	}while(temp != header -> next);	

	printf("\nElement was not found.\n");
	
	return 1;
}
