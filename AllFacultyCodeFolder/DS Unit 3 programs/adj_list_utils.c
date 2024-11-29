// A C Program to demonstrate adjacency list representation of graphs
#include <stdio.h>
#include <stdlib.h>
#include "adj_list.h"

 
// A utility function to create a new adjacency list node
ADJLISTNODE* newAdjListNode(int dest) 
{
    ADJLISTNODE* newNode = malloc(sizeof(ADJLISTNODE));
    if (newNode == NULL)
    {
        printf ("malloc failure 1\n");
	exit (0);
    }
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}
 
// A utility function that creates a graph of V vertices
GRAPH* createGraph(int V) 
{
    GRAPH* graph = malloc(sizeof(GRAPH));
    
    if (graph == NULL)
    {
        printf ("memory allocation failure 2\n");
	exit (0);
    }

    graph->V = V;
    // Create an array of adjacency lists.  Size of array will be V
    graph->array = malloc(V * sizeof(ADJLIST));
    if (graph->array == NULL)
    {
        printf ("Memory allocation failure 3\n");
        exit (0);
    }
 
    // Initialize each adjacency list as empty by making head as NULL
    int i;
    for (i = 0; i < V; ++i)
        graph->array[i].head = NULL;
 
    return graph;
}
 
// Adds an edge to an undirected graph
void addEdge(GRAPH* graph, int src, int dest, int numVertices) 
{
    if ((src < 0 || src > numVertices) || (dest < 0 || dest > numVertices))
    {
        printf ("either source or destination vertex number is out of range\n");
        printf ("Unable to create the edge\n");
    }
    else
    {
        // Add an edge from src to dest.  A new node is added to the adjacency
        // list of src.  The node is added at the begining
        ADJLISTNODE* newNode = newAdjListNode(dest);
        newNode->next = graph->array[src].head;
        graph->array[src].head = newNode;
 
        // Since graph is undirected, add an edge from dest to src also
        newNode = newAdjListNode(src);
        newNode->next = graph->array[dest].head;
        graph->array[dest].head = newNode;
    }
}
 
// A utility function to print the adjacency list representation of graph
void printGraph(GRAPH* graph) 
{
    int v;
    for (v = 0; v < graph->V; ++v) 
    {
        ADJLISTNODE *pNavigate = graph->array[v].head;
        printf("\n Adjacency list of vertex %d\n head ", v);
        while (pNavigate) 
        {
            printf("-> %d", pNavigate->dest);
            pNavigate = pNavigate->next;
        }
        printf("\n");
    }
}

void free_mem (GRAPH *pGraph)
{
    printf ("free_mem yet to be implemented\n");

}

