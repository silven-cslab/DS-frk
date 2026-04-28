/** ==== Queues: EnQueue Implementation ==== **/


/** ==== Documentation ==== **/
/*
 * This program creates a queue which is represented using arrays.
 * Then, adds the given element to the queue.
 * And, finally prints all of the elements in the queue
*/


/** ==== Preprocessing Directives ==== **/
#include<stdio.h>	//For Basic I/O functions.


/** ==== Function Prototypes ==== **/
int createQ(int *, int *, int *, int );
int display(int *, int , int );
int enqueue(int *, int , int *, int);


/** ==== Main Function ==== **/
int main()
{
	//Declaring the required variables:
	int n, front = 0, rear = 0;

	printf("\nEnter the total no. of elements in the queue: ");
	scanf("%d", &n);

	int Q[n];

	//Creating the Queue:
	if(createQ(&Q[0], &front, &rear, n))  return 1;

	//Displaying the created queue:
	if(display(&Q[0], front, rear))  return 1; 

	//Now adding a new item to the queue:
	if(enqueue(&Q[0], front, &rear, n))  return 1;

	//Displaying the modified queue:
	if(display(&Q[0], front, rear))  return 1;

	return 0;
}


/** ==== Function Definitions ==== **/
//createQ():
//This function creates the queue and initializes the queue with the user given values.

int createQ(int *Q, int *f, int *r, int n)
{
	//Declaring the required variables:
	int n1, i;

	//Checking the edge case:
	if(n < 1)
	{
		printf("\nThe size of the array is not enough!!\n\n");
		return 1;
	}

	printf("\nFor how many Queue elements you want to enter the data for: ");
	scanf("%d", &n1);

	printf("\nEnter the elements of the Queue: ");
	for(i=0;i<n1;i++)
	{
		scanf("%d", Q + i);
		if(i == 0)  continue;

		*r = *r + 1;
	}

	printf("\nSuccessfully created and intialized the queue.\n\n");

	return 0;
}


//display():
//This function displays all of the elements in the given queue.

int display(int *Q, int f, int r)
{
	int i;

	//Checking edge case:
	if(f == r)
	{
		printf("\nNo elements in the queue.\n\n");
		return 1;
	}

	printf("\nThe Queue is: ");
	for(i=0;i<=r;i++)
	{
		if(i == 0)
		{
			printf("FRONT -> ");
		}

		printf("[ %d ] -> ", *(Q + i));

		if(i == r)
		{
			printf("REAR\n\n");
		}	
	}

	printf("\nSuccessfully printed the list.\n\n");

	return 0;
}


//enqueue():
//This function adds a new item to the queue.

int enqueue(int *Q, int f, int *r, int n)
{
	//Checking edge case:
	if(*r == n)
	{
		printf("Queues is full.\n\n");
		return 1;
	}
	//Declaring the required variables:
	int item;

	printf("\nEnter the value of the new item: ");
	scanf("%d", &item);

	*r = *r + 1;
	*(Q + *r) = item;
	
	return 0;
}
