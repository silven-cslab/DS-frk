/** Dijkstra Algorithm Implementation **/

/*
 * This program shows the implementation of insertion opertions on graphs for graph creation.
 * Then, prompts the user for a source vertex.
 * Then, based on the dijkstra algorithm calculates the shortest distance from the source vertex to the every other vertex of the graph.
*/

//Preprocessing Directives:
#include<stdio.h>	//For Basic I/O functions.
#include<stdlib.h>		//For DMA functions like malloc(), free(),...
#include<stdbool.h>	//For boolean data types....

#define INFINITY 9999


//Global Declarations:

/*- Graph Object Definition -*/
typedef struct {
	int V;
	int *vertices;
	int **adjMatrix;
} Graph;


//Function Definition:

Graph *insertVertex(Graph *G, int V)
{
	int i;

	//Increase the size of the vertices array:
	int *tempVertices = realloc(G -> vertices, (G -> V + 1) * sizeof(int));

	if(tempVertices == NULL)
	{
		printf("\nMemory allocation failed!!\n\n");
		return NULL;
	}

	G -> vertices = tempVertices;
	G -> vertices[G -> V] = V;


	//Increase the size for the new row pointer:
	int **tempMatrix = realloc(G -> adjMatrix, (G -> V + 1) * sizeof(int));

	if(tempMatrix == NULL)
	{
		printf("\nMemory allocation failed!!\n\n");
		return NULL;
	}

	G -> adjMatrix = tempMatrix;

	//Increase the column size for each row:
	for(i=0;i<(G -> V);i++)
	{
		int *tempRow = G -> adjMatrix[i];

		tempRow = realloc(G -> adjMatrix[i], (G -> V + 1) * sizeof(int));

		if(tempRow == NULL)
		{
			printf("\nMemory allocation failed!!\n\n");
			return NULL;
		}

		G -> adjMatrix[i] = tempRow;
		G -> adjMatrix[i][G -> V] = 0;
	}

	//Allocate for all the new entries of the new row:
	G -> adjMatrix[G -> V] = calloc(G -> V + 1, sizeof(int));

	if(G -> adjMatrix[G -> V] == NULL)
	{
		printf("\nMemory allocation failed!!\n\n");
		return NULL;
	}

	G -> V++;
	return G;
}


Graph *insertEdge(Graph *G, int v1, int v2)
{
	int V1i = -1, V2i = -1, i, weight;

	if(v1 == v2)
	{
		printf("\nSelf Looping isn't allowed!!\n\n");
		return G;
	}	

	for(i=0;i<(G->V);i++)
	{
		if(G -> vertices[i] == v1)
		{
			V1i = i;
			break;
		}
	}

	for(i = 0;i<(G -> V);i++)
	{
		if(G -> vertices[i] == v2)
		{
			V2i = i;
			break;
		}
	}

	if((V1i == -1 || V2i == -1) || (V1i > G -> V) || (V2i > G -> V))
	{
		printf("\nVertex not found!!\n\n");
		return G;
	}

	printf("\nEnter the weight of the edge: ");
	scanf("%d", &weight);

	G -> adjMatrix[V1i][V2i] = weight;
	G -> adjMatrix[V2i][V1i] = weight;

	return G;
}


void printGraph(Graph *G)
{
	int i, j;

	if(G -> V <= 0)
	{
		printf("\nGraph is empty!!\n\n");
		return;
	}	

	printf("\nGraph: Adjacency Matrix Representation");
	printf("\n========================================\n\n  ");

	for(i = 0;i<G -> V;i++)
	{
		printf("%d ", G -> vertices[i]);
	}
	printf("\n");

	for(i=0;i<G -> V;i++)
	{
		printf("%d ", G -> vertices[i]);
		for(j = 0;j<G -> V;j++)
		{
			printf("%d ", G -> adjMatrix[i][j]);
		}	
		printf("\n");
	}
	printf("\n========================================\n\n");

	return;
}


void destroyGraph(Graph *G)
{
	int i;

	if(G == NULL)
	{
		printf("\nGraph doesn't exist!!\n\n");
		return;
	}

	//Free vertices array:
	free(G -> vertices);

	//Free adjMatrix:
	for(i = 0;i<(G->V);i++)
	{
		if(G -> adjMatrix[i] != NULL)
		{
			free(G -> adjMatrix[i]);
		}
	}

	free(G -> adjMatrix);
	free(G);
}



int indexV(Graph *G, int src)
{
	int i;

	for(i = 0;i<(G -> V);i++)
	{
		if(G -> vertices[i] == src)
		{
			return src;
		}
	}

	return -1;
}


int searchMin(int *d, bool *known, int size)
{
	int min = -1, i, minIndex;

	for(i = 0;i<size;i++)
	{
		if(known[i] == false && d[i] < min)
		{
			min = d[i];
			minIndex = i;
		}
	}

	return minIndex;
}


int Dijkstra(Graph *G, int src)
{	
	int i, j, path[G -> V], d[G -> V];
	bool known[G -> V], complete;
	int srci = indexV(G, src);

	if(srci == -1)
	{
		printf("\nSource vertex doesn't exist in the graph!!\n\n");
		return 1;
	}

	for(i = 0;i < (G -> V);i++)
	{
		known[i] = false;
		if(G -> adjMatrix[srci][i] != 0)
		{
			d[i] = G -> adjMatrix[srci][i];
			path[i] = src;
		}
		else
		{
			d[i] = INFINITY;
			path[i] = -1;
		}
	}

	known[srci] = true;
	d[srci] = 0;
	complete = false;

	//print output tables:
	printf("+===============+=======+=======+=======+\n");
	printf("| Vertex\t| Known\t| Path\t| d[i]\t|\n");
	for(i = 0;i<(G -> V);i++)
	{
		printf("|    %d\t\t| %s\t| %d\t| %d\t|\n", G -> vertices[i], known[i] ? "True" : "False", path[i], d[i]);
	}
	printf("+===============+=======+=======+=======+\n");

	while(!complete)
	{
		j = searchMin(&d[0], &known[0], G -> V);
		known[j] = true;

		for(i = 0;i < (G -> V);i++)
		{
			if((known[i] = false) && (G -> adjMatrix[j][i] != 0))
			{
				if(d[j] + G -> adjMatrix[j][i] < d[i]) 
				{	
					d[i] = d[j] + G -> adjMatrix[j][i];
					path[i] = j;
				}
			}


			//print output tables:
			printf("+===============+=======+=======+=======+\n");
			printf("| Vertex\t| Known\t| Path\t| d[i]\t|\n");
			for(i = 0;i<(G -> V);i++)
			{
				printf("|    %d\t\t| %s\t| %d\t| %d\t|\n", G -> vertices[i], known[i] ? "True" : "False", path[i], d[i]);
			}
			printf("+===============+=======+=======+=======+\n");

		}

		complete = true;

		for(i = 0;i< (G -> V);i++)
		{
			if(known[i] = false)
			{
				complete = false;
				break;
			}
		}
	}

	return 0;
}


void GraphMain()
{
	char ch;
	int i, j, n, v, v1, choice, src;

	Graph *G = malloc(sizeof(Graph));
	G -> V = 0;
    	G -> vertices = NULL;
    	G -> adjMatrix = NULL;

	//Menu:
	do
	{
		printf("\n ===== Graph Implementation: Using Adjacency Matrix\n\n");
		printf("\n1. Insert a vertex,\n2. Insert an edge,\n3. Show Adjacency Matrix,\n4. Shortest Paths,\n5. Exit.\n\n");
		printf("Choose: ");
		
		scanf("%d", &choice);
		switch(choice){
			case 1:
				printf("\nEnter the value of the vertex: ");
				scanf("%d", &v);

				G = insertVertex(G, v);
				printGraph(G);
				break;

			case 2:
				printf("\nEnter the pair between which the edge should be associated: ");
				scanf("%d%d", &v, &v1);

				G = insertEdge(G, v, v1);
				printGraph(G);
				break;
			
			case 3:
				printGraph(G);
				break;

			case 4:
				printf("\nEnter the source vertex: ");
				scanf("%d", &src);

				if(Dijkstra(G, src))  return;
				break;	

			case 5:
				printf("\n\n ........... Exit .............\n\n");
				return;

			default:
				printf("\nInvalid Option!!\n\n");
		}

		printf("\nDo you want to continue(Y/n)?");
		scanf(" %c", &ch);
	}while(ch == 'Y' || ch == 'y');

	destroyGraph(G);
}

int main()
{
	GraphMain();

	return 0;
}
