//DFS traversal of a connected graph using adjacency matrix, iterative
#include<stdio.h>
#define MAX 20

void createGraph(int a[MAX][MAX],int n);
void dfs(int a[MAX][MAX],int n,int visited[MAX],int src);

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
	dfs(adj,n,visited,src);
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

void dfs(int a[MAX][MAX],int n,int visited[MAX],int src)
{
	int s[MAX],top=-1;	//stack created & initialized to be empty
	int v;
	int i;
	
	s[++top]=src;	//push src to stack
	printf("%d ",src);	//print it
	visited[src]=1;	//mark src visited
	
	while(top!=-1)	//while teh stack is not empty
	{
		v=s[top];	//peek the stack
		
		for(i=0;i<n;i++)	//To traverse the nodes adjacent to v
		{
			if(a[v][i]==1 && visited[i]==0)	//For the first vertex 'i' adjacent and unvisited, start exploring 'i'
				break;
		}
		if(i==n)	//if no more vertex 'i' adjacent & unvisited from 'v', pop & discard 'v'
			top--;
		else	//explore 'i'
		{
			s[++top]=i;	//push 'i' to stack
			printf("%d ",i);	//print it
			visited[i]=1;	//mark 'i' visited
		}
	}
}