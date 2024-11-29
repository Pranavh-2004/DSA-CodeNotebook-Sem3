/*			Adj_Matrix_Utils.c		*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Adj_Matrix_Utils.h"

static int adj [MAX][MAX];

// BFS from given source s
void bfs_traversal(int V, int s) {
  
    // Create a queue for BFS
    int q[MAX], front = 0, rear = 0;    

    // Initially mark all the vertices as not visited
    // When we push a vertex into the q, we mark it as 
    // visited
    bool visited[MAX] = { false };
    
    // Mark the source node as visited and enqueue it
    visited[s] = true;
    q[rear++] = s;
    
    // Iterate over the queue
    while (front < rear) 
    {
        // Dequeue a vertex and print it
        int curr = q[front++];
        printf("%d ", curr);
        
        // Get all adjacent vertices of the dequeued vertex
        // If an adjacent node has not been visited, mark it 
	// visited and enqueue it
        for (int i = 0; i <= V; i++) 
        {
            if (adj[curr][i] == 1 && !visited[i]) 
            {
                visited[i] = true;
                q[rear++] = i;
            }
        }
    }
}

void dfs_traversal (int V, int s)
{
	// To be implemented
	printf ("To be implemented\n");
}


bool create_edge (int num_nodes)
{
    int origin, destin;
    bool retVal = false;

    printf("Enter edge (row col) : ");
    scanf("%d %d", &origin, &destin);
    if ((origin != 0) && (destin != 0))
    {
        if (origin > num_nodes || destin > num_nodes 
		    || origin <= 0 || destin <= 0) 
            printf("Invalid edge!\n");
        else
        {
            adj[origin][destin] = 1;
            adj[destin][origin] = 1;
            retVal = true;
        }
    }
    return retVal;
}


void create_graph(int num_nodes) 
{
    int i, max_edges, origin, destin;

    max_edges = num_nodes * (num_nodes - 1);
 
    for (i = 1; i <= max_edges; i++) 
    {
        if (!create_edge (num_nodes))
            break;
    }
}
 
void display(int num_nodes) 
{
    int i, j;
    int n = num_nodes;
    for (i = 1; i <= n; i++) 
    {
        for (j = 1; j <= n; j++)
            printf("%4d", adj[i][j]);
        printf("\n");
    }
}
 
void insert_node(int *num_node) 
{
    int i;
    int n = *num_node;  
    n++;
    printf("The inserted node is %d \n", n);
    for (i = 1; i <= n; i++) 
    {
        adj[i][n] = 0;
        adj[n][i] = 0;
    }
    *num_node = n;
}
 
void delete_node(char u, int *num_nodes) 
{
    int i, j;
    int n = *num_nodes;
    if (n == 0) 
    {
        printf("Graph is empty\n");
        return;
    }
    if (u > n) 
    {
        printf("This node is not present in the graph\n");
        return;
    }
    for (i = u; i <= n - 1; i++)
        for (j = 1; j <= n; j++) 
        {
            adj[j][i] = adj[j][i + 1];
            adj[i][j] = adj[i + 1][j];
        }
    n--;
    *num_nodes = n;
}
