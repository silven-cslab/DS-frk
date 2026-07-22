/* Graphs : Implementation of the Insertion of edge operation */


/* 
 * This program creates a graph.
 * And, takes specified no. of vertices and their values from the user.
 * And, do the implementation of the graph with the taken values using Adjacency List Representation.
 * Inserts a new edge between the specified edges.
*/


/* Preprocessing Directives */
#include<stdio.h>	//For Basic I/O functions like printf(), scanf(),..
#include<stdlib.h>		//For DMA functions like malloc(), free(),....


/* Global Declarations */
// -- Node Defintion --
struct node {
	int data;
	struct node *next;
};

// -- Graph Node Definition --
struct graph {
	struct node **adjList;
	struct graph *next;
};


// -- Function Protottypes --
struct node *createNode(int);
struct graph *createGraph(int );
struct graph *insertVertex(int, int, struct graph*);
struct graph *insertEdge(int, int, struct graph*);


/* Main Function */
int main()
{
	int n;

	//Taking the no. of vertices:
	printf("\nEnter the total no. of vertices of the graph: ");
	scanf("%d", &n);

	//Creating the Graph:
	struct graph *graph = createGraph(n);

	return 0;
}


/* Function Definitions */

//createNode():
//This helper function creates the node with given value.

struct node* createNode(int value)
{
	struct node* newNode = malloc(sizeof(struct node));

	//Checking errors:
	if(newNode == NULL)
	{
		printf("\nMemory allocation failed!!\n\n");
		return NULL;
	}

	newNode -> data = value;
	newNode -> next = NULL;

	return newNode;
}


//createGraph():
//This helper function creates the graph and returns the created graph.

struct graph *createGraph(int vertices)
{
	int i, vertex;
	struct graph *Graph = malloc(vertices * sizeof(struct graph));

	printf("\nEnter all of the values of the graph: ");
	for(i=0;i<vertices;i++)
	{
		scanf("%d", &vertex);

		Graph = insertVertex(i, vertex, Graph);
	}

	return Graph;
}


//insertVertex():
//This helper function inserts the vertex to the graph(Adjacency List).

struct graph *insertVertex(int vIndex, int vertex, struct graph* Graph)
{
	 
	 Graph -> adjList[vIndex] -> data = vertex;
	 Graph -> adjList[vIndex] -> next = NULL;

	 return Graph;
}

