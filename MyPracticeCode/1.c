// BFS traversal of a connected graph using adjacency list
#include <stdio.h>
#include <stdlib.h>
#define MAX 20

typedef struct node
{
	int info;
	struct node *next;
} NODE;

void initGraph(NODE *V[]);
void createGraph(NODE *V[]);
void bfs(NODE *V[], int n, int visited[MAX], int src);

int main()
{
	NODE *V[MAX];
	int n;
	int visited[MAX] = {0};
	int src;

	initGraph(V);

	printf("Enter the number of vertices\n");
	scanf("%d", &n);

	printf("Enter the adjacency information\n");
	createGraph(V);

	printf("Enter the source vertex\n");
	scanf("%d", &src);

	printf("BFS traversal\n");
	bfs(V, n, visited, src);
}

void initGraph(NODE *V[])
{
	for (int i = 0; i < MAX; i++)
		V[i] = NULL;
}
void createGraph(NODE *V[])
{
	int src, dest;
	NODE *newNode;
	printf("Enter source and destination vertices of an edge\n");
	printf("Enter -1 -1 to stop adding edges\n");

	scanf("%d%d", &src, &dest);

	while (src != -1 && dest != -1)
	{
		newNode = malloc(sizeof(NODE));
		newNode->info = dest;
		newNode->next = V[src];
		V[src] = newNode;

		NODE *newNode2 = malloc(sizeof(NODE));
		newNode2->info = src;
		newNode2->next = V[dest];
		V[dest] = newNode2;

		scanf("%d%d", &src, &dest);
	}
}
void bfs(NODE *V[], int n, int visited[MAX], int src)
{
	int q[MAX], front = 0, rear = -1; // queue created and initialized to be empty
	int v;
	NODE *p = NULL;

	q[++rear] = src;  // enqueue src
	visited[src] = 1; // mark src visited

	while (front <= rear) // while q is not empty
	{
		v = q[front++];	  // dequeue and store in v
		printf("%d ", v); // print it

		p = V[v]; // To traverse the nodes adjacent to v

		while (p != NULL) // For all nodes adjacent to v
		{
			if (visited[p->info] == 0) // If adjacent node is unvisited
			{
				q[++rear] = p->info;  // enqueue unvisited adjacent vertex
				visited[p->info] = 1; // mark unvisited adjacent vertex visited
			}
			p = p->next;
		}
	}
}
