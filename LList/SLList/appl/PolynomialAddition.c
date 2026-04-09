/** ==== Applications of the Single Linked List: Polynomial Addition ==== **/


/** ==== Documentation ==== **/
/*
 * This program creates two linked lists p and q for the two polynomials.
 * Takes the values of the polynomial equations like coefficients and exponents from the user.
 * Adds the polynomial equations in two another polynomial equation r.
 * And, finally prints all of the polynomial equations p, q, r.
*/


/** ==== Preprocessing Directives ==== **/
#include<stdio.h>		//For Basic I/O functions like printf(), scanf(),...
#include<stdlib.h>	//For DMA functions like malloc(), free(),...


/** ==== Global Declarations ==== **/
/* ---- Node definition ---- **/
struct node{
	int coeff;
	int exp;
	struct node *next = NULL;
};


/** ==== Function Prototypes ==== **/
//Node Creation:
struct node *createNode(int, int);
int createList(struct node *, int);

//Miscellaneous Functions:
char *OrdinalIndication(int);


/** ==== Main Function ==== **/
int main()
{
	int Pn;
	struct node *P = NULL;
	
	printf("\n ======= Polynomial addition ======== \n\n");
	printf("At first enter the values of the first polynomial equation: \n");
	printf("Enter the total no. of terms in the first polynomial: ");
	scanf("%d", &Pn);

	//Creating and initializing the first polynomial's list:
	if(createList(Pn))  return 1;
	
}


/** ==== Function Definitions: ==== **/
//createNode():
//This function is used to create and allocate memory for a node:

struct node *createNode(int coeff, int exp)
{
	struct node *newNode = malloc(sizeof(struct node));

	if(newNode == NULL)
	{
		printf("\nMemory allocation failed!!.");
		return NULL;
	}

	//Assiging the data values to the new node:
	newNode -> coeff = coeff;
	newNode -> exp = exp;
	newNode -> next = NULL;

	return newNode;
}


//createList():
//This function is used to create the single linked list with the user given values:

int createList(struct node *head, int n);
{
	int c, e, i;
	struct node *lastNode = NULL, *temp = NULL;

	//Checking edge cases:
	if(n < 1)
	{
		printf("Not enough nodes in the list!!.");
		return 1;
	}

	for(i = 1;i <= n;i++)
	{
		printf("\nEnter %d%s term's coefficient: ", i, OrdinalIndication(i));
		scanf("%d", &c);
		printf("\nEnter %d%s term's exponent: ", i, OrdinalIndication(i));
		scanf("%d", &e);
		
		//Create newNode:
		struct node *new = createNode(c, e);

		//Linking the nodes together:
		if(head -> next = NULL)
		{
			head -> next = new;
		}
		else
		{
			lastNode -> next = new;
		}

		lastNode = new;
		temp = new;
	}

	if(temp != NULL)
	{
		temp -> next = NULL;
	}

	return 0;
}


/* ---- Miscellaneous Functions ---- */
//OrdinalIndication():
//This function gives the ordinal indication of the number passed.

char *OrdinalIndication(int num)
{
	switch(num)
	{
		case 1:
			{
				return "st";
			}
		case 2:
			{
				return "nd";
			}
		case 3:
			{
				return "rd";
			}
		default:
			{
				return "th";
			}

	}
}
