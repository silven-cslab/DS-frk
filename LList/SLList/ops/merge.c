/** ===== Singly Linked List : Merge Operation ===== **/


/** ===== Documentation ===== **/
/*
 * This program creates a singly linked lists.(Dynamically allocates the memory for the lists)
 * Initializes their data elements with the user given values.
 * And, display these two lists.
 * Creates a new list that is a merged list of the both list.
 * And, finally displays the merged list.
*/


/** ===== Global Declaration ===== **/
/* ---- Node Definition ---- */
struct node {
	int data;
	struct node *next;
};

struct node header1, header2, header3, *N1 = NULL, *N2 = NULL;	//Declaraing here for the global access.
int n1, n2;


/** ===== Function Prototypes ===== **/
int create(struct node *, int);
int init(struct node, struct node *, int);
int display(struct node);
int merge(struct node, struct node);


/** ===== Main Function ===== **/
int main()
{
	//First list:
	create(N1, n1);

	return 0;	//Exit Status.
}


/** ===== Function Definitions ===== **/

//create():
//This function allocates the memory for the nodes in the list.

int create(struct node *N, int size);
{
	//Asking the user for the total no. of nodes:
	printf("\nEnter the no. of nodes in the list: ");
	scanf("%d", &size);

	if(size < 1)
	{
		printf("\nNo elements to create the list!!\n");
		return 1;
	}

	//Allocating the memory:
	N = malloc(size * (sizeof(struct node *)));

	//Checking if the allocation is failed:
	if(N == NULL)
	{
		printf("\nMemory Allocation failed!!\n");
		return 1;
	}

	return 0;
}


//init():
//This function initializes all the data elements in the given node list with the user given values.

int init(struct node header, struct node *N, int size)
{
	//Linking the list to the header node:
	header.next = N;

	//Initializing with values:
	printf("\nEnter the node values: ");
	for(i=0;i<size;i++)
	{
		scanf("%d", &((N+i)->data));

		if(i == n-1)
		{
			(N+i)->next = NULL;
			break;
		}

		(N+i) -> next = ((N+i)+1);
	}

	printf("\nSuccessfully initialized the list with values.\n");

	return 0;
}


//display():
//This function traverses through the list and displays the node values.

int display(struct node header)
{
	struct node *temp = NULL;
	temp = header.next;

	//Traversing through the list:
	printf("\nThe list is : \n");
	while(temp != NULL)
	{
		printf("[ %d ] -> ", temp -> data);
		temp = temp -> next;
	}
	printf("[ NULL ]\n");

	return 0;
}
