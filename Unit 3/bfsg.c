/*#include<stdio.h>
#define MAX 10

void readgraph(int a[MAX][MAX],int n);
void bfs(int a[MAX][MAX],int n,int visited[MAX],int source);

int main()
{
	int a[MAX][MAX],n,visited[MAX]={0},source;
	printf("Enter the no of nodes\n");
	scanf("%d",&n);
	
	printf("Enter the adjacency matrix\n");
	readgraph(a,n);
	
	printf("Enter the source vertex\n");
	scanf("%d",&source);
	
	printf("BFS Traversal\n");
	bfs(a,n,visited,source);
	
	return 0;
}

void readgraph(int a[MAX][MAX],int n)
{
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	
}
void bfs(int a[MAX][MAX],int n,int visited[MAX],int source)
{
	int q[n];
	int f=0,r=-1;
	
	q[++r]=source;
	visited[source]=1;
	
	while(f<=r)
	{
		int v=q[f++];
		printf("%d",v);
		
		for(int i=0;i<n;i++)
		{
			if(a[v][i] && visited[i]==0)
			{
				q[++r]=i;
				visited[i]=1;
			}
		}
		
		
		
	}
	
}

//connected or disconnected graph

#include<stdio.h>
#define MAX 10

void readgraph(int a[MAX][MAX],int n);
void bfs(int a[MAX][MAX],int n,int visited[MAX],int source);

int main()
{
	int a[MAX][MAX],n,visited[MAX]={0},source;
	printf("Enter the no of nodes\n");
	scanf("%d",&n);
	
	printf("Enter the adjacency matrix\n");
	readgraph(a,n);
	
	printf("Enter the source vertex\n");
	scanf("%d",&source);
	
	printf("BFS Traversal\n");
	bfs(a,n,visited,source);
	
	for(int i=0;i<n;i++)
	{
		if(visited[i]==0)
		{
			printf("graph is disconnected\n");
			return 0;
			
		}
	}
	printf("graph is connected\n");
	return 0;
}

void readgraph(int a[MAX][MAX],int n)
{
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	
}
void bfs(int a[MAX][MAX],int n,int visited[MAX],int source)
{
	int q[n];
	int f=0,r=-1;
	
	q[++r]=source;
	visited[source]=1;
	
	while(f<=r)
	{
		int v=q[f++];
		printf("%d",v);
		
		for(int i=0;i<n;i++)
		{
			if(a[v][i] && visited[i]==0)
			{
				q[++r]=i;
				visited[i]=1;
			}
		}
		
		
		
	}
	
}
*/

//path
#include<stdio.h>
#define MAX 10

void readgraph(int a[MAX][MAX],int n);
int bfs(int a[MAX][MAX],int n,int visited[MAX],int source,int dest);

int main()
{
	int a[MAX][MAX],n,visited[MAX]={0},source,dest;
	printf("Enter the no of nodes\n");
	scanf("%d",&n);
	
	printf("Enter the adjacency matrix\n");
	readgraph(a,n);
	
	printf("Enter the source vertex\n");
	scanf("%d",&source);
	
	printf("Enter the dest vertex\n");
	scanf("%d",&dest);
	
	printf("BFS Traversal\n");
	if(bfs(a,n,visited,source,dest))
	{
		printf("path exists  from %d to %d\n",source,dest);
	}
	else
		printf("path doesnot exists  from %d to %d\n",source,dest);
	
	return 0;
}

void readgraph(int a[MAX][MAX],int n)
{
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	
}
int bfs(int a[MAX][MAX],int n,int visited[MAX],int source,int dest)
{
	int q[n];
	int f=0,r=-1;
	
	q[++r]=source;
	visited[source]=1;
	
	while(f<=r)
	{
		int v=q[f++];
		//printf("%d",v);
		
		for(int i=0;i<n;i++)
		{
			if(a[v][i] && visited[i]==0)
			{
				q[++r]=i;
				visited[i]=1;
				
				if(i==dest)
					return 1;
			}
		}
		
		
		
	}
	return 0;
}