//BFS traversal of a connected or disconnected graph
//using adjacency matrix
#include<stdio.h>
#define MAX 20

void createGraph(int a[MAX][MAX],int n);
void bfs(int a[MAX][MAX],int n,int visited[MAX],int src);

int main()
{
	int adj[MAX][MAX]={0},n,visited[MAX]={0},src;
	
	printf("Enter the number of vertices\n");
	scanf("%d",&n);
	
	printf("Enter the adjacency information\n");
	createGraph(adj,n);
	
	printf("Enter the source vertex\n");
	scanf("%d",&src);
	
	printf("BFS traversal\n");
	bfs(adj,n,visited,src);
	
	for(int i=0;i<n;i++)
	{
		if(visited[i]==0)	//If any vertex is left unvisited
		{
			printf("\n");
			bfs(adj,n,visited,i);	//start traversal from the unvisited vertex
		}
	}
}

void createGraph(int a[MAX][MAX],int n)
{
	int src,dest;
	
	printf("Enter source and destination vertices of an edge\n");
	printf("Enter -1 -1 to stop adding edges\n");
	
	scanf("%d%d",&src,&dest);
	
	while(src!=-1 && dest!=-1)
	{
		a[src][dest]=1;
		scanf("%d%d",&src,&dest);
	}
}

void bfs(int a[MAX][MAX],int n,int visited[MAX],int src)
{
	int q[MAX],front=0,rear=-1;	//queue is created and initialized to be empty
	int v;
	
	q[++rear]=src;	//enqueue source vertex
	visited[src]=1;	//mark source vertex visited
	
	while(front<=rear)	//while the queue is not empty
	{
		v=q[front++];	//dequeue and store in v
		printf("%d ",v);	//print it
		
		for(int i=0;i<n;i++)	//To traverse the nodes adjacent to v
		{
			if(a[v][i]==1 && visited[i]==0)	//For all nodes 'i' adjacent to v and unvisited
			{
				q[++rear]=i;	//enqueue unvisited adjacent vertex
				visited[i]=1;	//mark unvisited adjacent vertex visited
			}
		}
	}
}