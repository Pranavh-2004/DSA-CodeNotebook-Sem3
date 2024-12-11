//DFS traversal of a connected or disconnected graph
//using adjacency matrix, recursive
#include<stdio.h>
#define MAX 20

void createGraph(int a[MAX][MAX],int n);
void dfsRecur(int a[MAX][MAX],int n,int visited[MAX],int src);

int main()
{
	int adj[MAX][MAX]={0},n,visited[MAX]={0},src;
	
	printf("Enter the number of vertices\n");
	scanf("%d",&n);
	
	printf("Enter the adjacency information\n");
	createGraph(adj,n);
	
	printf("Enter the source vertex\n");
	scanf("%d",&src);
	
	printf("DFS traversal\n");
	dfsRecur(adj,n,visited,src);
	
	for(int i=0;i<n;i++)
	{
		if(visited[i]==0)	//If any vertex is left unvisited
		{
			printf("\n");
			dfsRecur(adj,n,visited,i);	//start traversal from the unvisited vertex
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

void dfsRecur(int a[MAX][MAX],int n,int visited[MAX],int src)
{
	printf("%d ",src);	//Print src
	visited[src]=1;	//Mark src visited
	
	for(int i=0;i<n;i++)	//To traverse the nodes adjacent to src
	{
		if(a[src][i]==1  && visited[i]==0)	//For the first vertex 'i' adjacent and unvisited, start exploring 'i'
			dfsRecur(a,n,visited,i);	//start exploring 'i'
	}
}