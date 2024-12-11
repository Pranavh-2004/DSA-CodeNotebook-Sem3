//Connectivity of a directed graph using adjacency matrix
#include<stdio.h>
#define MAX 20

void createGraph(int a[MAX][MAX],int n);
int strongConnectivity(int a[MAX][MAX],int n);
int weakConnectivity(int a[MAX][MAX],int n);

int main()
{
	int adj[MAX][MAX]={0},n;
	
	printf("Enter the number of vertices\n");
	scanf("%d",&n);
	
	printf("Enter the adjacency information\n");
	createGraph(adj,n);
	
	if(strongConnectivity(adj,n))
		printf("Directed graph is strongly connected\n");
	else if(weakConnectivity(adj,n))
		printf("Directed graph is weakly connected\n");
	else
		printf("Directed graph is disconnected\n");
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
//		printf("%d ",v);	//print it
		
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

int strongConnectivity(int a[MAX][MAX],int n)
{
	int visited[MAX];
	
	for(int v=0;v<n;v++)
	{
		//Making all the vertices unvisited
		for(int i=0;i<n;i++)
		{
			visited[i]=0;
		}
		
		bfs(a,n,visited,v);
		
		for(int i=0;i<n;i++)
		{
			if(visited[i]==0)
				return 0;
		}
	}
	return 1;
}

void removeEdgeDirection(int a[MAX][MAX],int b[MAX][MAX],int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(a[i][j])
			{
				b[i][j]=1;
				b[j][i]=1;
			}
		}
	}
}

int weakConnectivity(int a[MAX][MAX],int n)
{
	int b[MAX][MAX]={0};
	
	removeEdgeDirection(a,b,n);
	
	int visited[MAX]={0};
	
	bfs(b,n,visited,0);
	
	for(int i=0;i<n;i++)
	{
		if(visited[i]==0)	//If any vertex is left unvisited
		{
			return 0;
		}
	}
	return 1;
}