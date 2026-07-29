/* Graph : Adjacency Matrix Representation */


/*
 * This program creates a graph.
 * Inserts, the vertices into the graph.
 * Associates, the edges between the specified vertices.
 * Prints the adjacency matrix of the graph.
 * Deletes, an edge between the specified the vertices.
 * Deletes a vertex of the graph.
*/


/* Preprocessing Directives */
#include<stdio.h>	//For Basic I/O functions.
#include<stdlib.h>		//For DMA functions like malloc(), realloc(), calloc(), free(),....


/* Global Declarations */
/*- Graph Structure -*/
typedef struct {
	int V;
	int *vertices;
	int **adjMatrix;
} Graph;


/*- Function Prototypes -*/
Graph *createGraph(int);
Graph *insertVertex(Graph *, int);
Graph *insertEdge(Graph *, int, int);
void printGraph(Graph *);
Graph *deleteEdge(Graph *, int, int);



/* Main Function */
int main()
{
	int i, n, V1, V2;

	printf("\nEnter the total no. of vertices: ");
	scanf("%d", &n);

	Graph *g = createGraph(n);

	printGraph(g);
	
	printf("\nEnter how many new vertices you want to insert in the graph: ");
	scanf("%d", &n);

	printf("\nEnter the values of the vertices: ");
	for(i=0;i<n;i++)
	{
		scanf("%d", &V1);
		g = insertVertex(g, V1);
	}

	printGraph(g);	

	printf("\nEnter for how many pairs of the vertices you want to associate an edge: ");
	scanf("%d", &n);

	for(i=0;i<n;i++)
	{
		printf("\nEnter the vertices V1, V2: ");
		scanf("%d%d", &V1, &V2);
		g = insertEdge(g, V1, V2);
	}

	printGraph(g);
	

	printf("\nEnter for how many pairs of the vertices you want to delete an edge: ");
	scanf("%d", &n);

	for(i=0;i<n;i++)
	{
		printf("\nEnter the vertices V1, V2: ");
		scanf("%d%d", &V1, &V2);
		g = deleteEdge(g, V1, V2);
	}

	printGraph(g);

}


/* Function Definitions */

Graph *createGraph(int V)
{
	int i;
	Graph *g = malloc(sizeof(Graph));

	if(g == NULL)
	{
		printf("\nMemory allocation failed!!\n\n");
		return NULL;
	}

	g -> V = V;
	g -> vertices = NULL;
	g -> adjMatrix = NULL;

	g -> vertices = malloc(V * sizeof(int));

	if(g -> vertices == NULL)
	{
		printf("\nMemory allocation failed!!\n\n");
		return NULL;
	}

	g -> adjMatrix = calloc(V, sizeof(int *));

	if(g -> adjMatrix == NULL)
	{
		printf("\nMemory allocation failed!!\n\n");
		return NULL;
	}

	for(i=0;i<(g -> V);i++)
	{
		g -> adjMatrix[i] = calloc(V, sizeof(int));

		if(g -> adjMatrix[i] == NULL)
		{
			printf("\nMemory allocation failed!!\n\n");
			return NULL;
		}
	}

	printf("\nEnter all of the vertices of the graph: ");
	for(i=0;i<(g -> V);i++)
	{
		scanf("%d", &(g ->vertices[i]));
	}

	return g;
}


Graph *insertVertex(Graph *g, int V)
{
	int i;

	//Reallocate memory for the vertices array:
	int *tempvertices = realloc(g -> vertices, (g -> V + 1) * sizeof(int));

	if(tempvertices == NULL)
	{
		printf("\nMemory allocation failed!!\n\n");
		return g;
	}

	g -> vertices = tempvertices;
	g -> vertices[g->V] = V;


	//Allocate memory for a new row pointer in the adjMatrix:
	int **tempMatrix = realloc(g -> adjMatrix, (g -> V + 1)*sizeof(int *));

	if(tempMatrix == NULL)
	{
		printf("\nMemory allocation failed!!\n\n");
		return g;
	}

	g -> adjMatrix = tempMatrix;

	//Reallocate a new column for all of the existing rows:
	for(i=0;i<(g->V);i++)
	{
		int *tempRow = realloc(g->adjMatrix[i], (g -> V + 1) * sizeof(int));

		if(tempRow == NULL)
		{
			printf("\nMemory allocation failed!!\n\n");
			return g;
		}

		g -> adjMatrix[i] = tempRow;
		g -> adjMatrix[i][g -> V] = 0;
	}

	//For new pointer allocate memory:
	g -> adjMatrix[g -> V] = calloc((g -> V + 1), sizeof(int));

	if(g -> adjMatrix[g -> V] == NULL)
	{
		printf("\nMemory allocation failed!!\n\n");
		return g;
	}
	(g -> V)++;

	return g;
}


Graph *insertEdge(Graph *g, int V1, int V2)
{
	int i, V1i = -1, V2i = -1;

	if(V1 == V2)
	{
		printf("\nSelf Looping isnt allowed!!\n\n");
		return g;
	}

	for(i=0;i<(g->V);i++)
	{
		if(g->vertices[i] == V1)
		{
			V1i = i;
			break;
		}
	}

	for(i=0;i<(g->V);i++)
	{
		if(g->vertices[i] == V2)
		{
			V2i = i;
			break;
		}
	}

	if(V1i == -1 || V2i == -1)
	{
		printf("\nVertex not found.\n\n");
		return g;
	}

	g -> adjMatrix[V1i][V2i] = 1;
	g -> adjMatrix[V2i][V1i] = 1;

	return g;
}



void printGraph(Graph *g)
{
    int i, j;
    if(g -> V <= 0)
    {
        printf("\nGraph is empty!!\n\n");
        return;
    }
    printf("\n\nGraph - Adjacency Representation");
    printf("\n======================================\n\n  ");

    for(i=0;i<g -> V;i++)
    {
        printf("%d  ", g -> vertices[i]);
    }
    printf("\n");
    for(i=0;i<g->V;i++)
    {
        printf("%d ", g -> vertices[i]);
        for(j=0;j<g->V;j++)
        {
            printf("%d  ", g -> adjMatrix[i][j]);
        }
        printf("\n");
    }
    printf("\n======================================\n\n");
}


Graph *deleteEdge(Graph *g, int V1, int V2)
{
	int i, V1i = -1, V2i = -1;

	for(i=0;i<(g -> V);i++)
	{
		if(g -> vertices[i] == V1)
		{
			V1i =i;
		}
	}

	for(i=0;i<(g -> V);i++)
	{
		if(g -> vertices[i] == V2)
		{
			V2i = i;
		}
	}

	if(V1i == -1 || V2i == -1)
	{
		printf("\nVertex found.\n\n");
		return g;
	}

	g -> adjMatrix[V1i][V2i] = 0;
	g -> adjMatrix[V2i][V1i] = 0;

	return g;
}
