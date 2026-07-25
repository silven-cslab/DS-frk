/* Graph Representation: Using Adjacency List */

/*
 * This program creates the graph.
 * Intializes, the graph with the user given vertices values.
 * Associates edge/connections between the specified vertices.
 * Prints the adjacency List.
 * Deletes the specified association that is between any two vertices.
*/


/* Preprocessing Directives */
#include<stdio.h>	//For Basic I/O functions.
#include<stdlib.h>		//For DMA functions like malloc(), free(),...


/* Global Declarations */
/*- Adjacency List Node Definition -*/
struct node {
	int data;
	struct node *next;
};


/*- Graph Node Definition -*/
struct graph {
	int numVertices;
	struct node **adjList;
};


/* Function Prototypes */
struct node *createNode(int);
struct graph *createGraph(int);
struct graph *insertVertex(int, struct graph* );
struct graph *insertEdge(int, int, struct graph* );
void printadjList(struct graph* );
struct graph *deleteEdge(int, int, struct graph* );
struct node *delete(struct node *, int);


/* Main Function */
int main()
{
	int n, e1, i, V1, V2;

	//Taking the no. of nodes from the user:
	printf("\nEnter the total no. of vertices for the graph: ");
	scanf("%d", &n);

	//Creating the Graph:
	struct graph *Graph = createGraph(n);

	//Printing the graph:
	printadjList(Graph);

	printf("\nFor how many pairs vertices you want associate an edge: ");
	scanf("%d", &e1);

	for(i=0;i<e1;i++)
	{
		printf("\nEnter the vertices V1 and V2 between which an edge must be associated: ");
		scanf("%d%d", &V1, &V2);

		Graph = insertEdge(V1, V2, Graph);
	}

	//Print the modified Graph:
	printadjList(Graph);

	printf("\nEnter the vertices V1 and V2 between which an edge should deleted: ");
	scanf("%d%d", &V1, &V2);

	Graph = deleteEdge(V1, V2, Graph);

	//Print the modified Graph:
	printadjList(Graph);


	return 0;
}


/* Function Definitions */

//createNode():
//This helper creates a node with the given value.

struct node *createNode(int val)
{
	struct node *newNode = malloc(sizeof(struct node));

	//Checking for errors:
	if(newNode == NULL)
	{
		printf("\nMemory allocation failed!\n\n");
		return NULL;
	}

	newNode -> data = val;
	newNode -> next = NULL;

	return newNode;
}


//createGraph():
//This helper function creates the graph.

struct graph* createGraph(int numVertices)
{
	int i;
	struct graph *Graph = malloc(sizeof(struct graph));

	//Checking vertices count error:
	if(numVertices <= 0)
	{
		printf("\nNot enough vertices to create the graph!!\n\n");
		return NULL;
	}

	//Checking memory allocation errors:
	if(Graph == NULL)
	{
		printf("\nMemory allocation failed!!\n\n");
		return NULL;
	}

	Graph -> numVertices = numVertices;

	//Now allocating the memory for the adjacency list:
	Graph -> adjList = malloc(numVertices * sizeof(struct node *));

	//Checking for the memeory allocation errors:
	if(Graph -> adjList == NULL)
	{
		printf("\nMemory allocation failed!!\n\n");
		return NULL;
	}

	//Now inserting all of the vertices:
	printf("\nEnter all of the values of vertices of the graph: ");
	for(i = 0;i < numVertices;i++)
	{
		Graph -> adjList[i] = NULL;
		Graph = insertVertex(i, Graph);
	}

	return Graph;
}


//insertVertex():
//This helper function is used to insert the vertices into the graph.

struct graph* insertVertex(int vIndex, struct graph* Graph)
{
	int vertex;

	scanf("%d", &vertex);

	struct node *newNode = createNode(vertex);
	Graph -> adjList[vIndex] = newNode;

	return Graph;	
}


//insertEdge():
//This helper function is used to associate an edge between any teo specified vertices.

struct graph *insertEdge(int V1, int V2, struct graph *Graph)
{
	int i, V1i, V2i;

	if(V1 == V2)
	{
		printf("\nSelf-Looping isn't allowed!\n\n");
		return Graph;
	}

	for(i=0;i<(Graph -> numVertices);i++)
	{
		V1i = -1;
		if(V1 == Graph -> adjList[i] -> data)
		{
			V1i = i;
			break;
		}
	}

	for(i=0;i<(Graph -> numVertices);i++)
	{
		V2i = -1;
		if(V2 == Graph -> adjList[i] -> data)
		{
			V2i = i;
			break;
		}
	}

	if(V1i == -1 || V2i == -1)
	{
		printf("\nVertex. Not found!\n\n");
		return Graph;
	}

	//Adjacency to V1:
	struct node *newV2 = createNode(V2);
	struct node *temp2 = Graph -> adjList[V1i];
	while(temp2 -> next != NULL)
	{
		temp2 = temp2-> next;
	}
	temp2 -> next = newV2;


	//Adjacency to V2:
	struct node *newV1 = createNode(V1);
	struct node *temp1 = Graph -> adjList[V2i];
	while(temp1 -> next != NULL)
	{
		temp1 = temp1 -> next;
	}
	temp1 -> next = newV1;

	return Graph;
}


void printadjList(struct graph *Graph)
{
	int i;
	printf("\n\nGraph : Adjacency List Representation\n");
	printf("=========================================\n");

	for(i=0;i<(Graph -> numVertices);i++)
	{
		struct node *temp = Graph -> adjList[i];

		printf("%d : ", temp -> data);
		while(temp != NULL)
		{
			printf("%d -> ", temp -> data);

			if(temp -> next == NULL)
			{
				printf("\b\b\b \n");
			}
			temp = temp -> next;
		}
	}
	printf("\n==========================================\n\n");
}


struct graph *deleteEdge(int V1, int V2, struct graph *Graph)
{
	int i, V1i, V2i;

	if(Graph -> numVertices <= 0)
	{
		printf("\nGraph is empty!!\n\n");
		return Graph;
	}
	
	for(i=0;i<(Graph -> numVertices);i++)
	{
		V1i = -1;
		if(V1 == Graph -> adjList[i] -> data)
		{
			V1i = i;
			break;
		}
	}

	for(i=0;i<(Graph -> numVertices);i++)
	{
		V2i = -1;
		if(V2 == Graph -> adjList[i] -> data)
		{
			V2i = i;
			break;
		}
	}

	if(V1i == -1 || V2i == -1)
	{
		printf("\nVertex. Not found!!\n\n");
		return Graph;
	}

	if((Graph -> adjList[V1i] -> next == NULL) || (Graph -> adjList[V2i] -> next == NULL))
	{
		printf("\nNo adjacencies found!!\n\n");
		return Graph;
	}
	//Delete the adjacency of V2 in V1:
	Graph -> adjList[V1i] = delete(Graph -> adjList[V1i], V2);

	//Delete the adjacency of V1 in V2:
	Graph -> adjList[V2i] = delete(Graph -> adjList[V2i], V1);

	return Graph;
}


struct node *delete(struct node *VadjList, int V)
{
	struct node *temp = VadjList;

	struct node *prev = NULL;
	while(temp -> next != NULL)
	{
		if(temp -> data == V)
		{
			break;
		}

		prev = temp;
		temp = temp -> next;
	}

	if(prev == NULL)
	{
		VadjList = temp -> next;
		return VadjList;
	}

	prev -> next = temp -> next;

	return VadjList;
}


		
