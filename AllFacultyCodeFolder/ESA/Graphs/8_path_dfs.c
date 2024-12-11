//To determine if there exists a path between 2 vertices

#include<stdio.h>
#define MAX 20

void createGraph(int a[MAX][MAX],int n);
int chkPath(int a[MAX][MAX],int n,int visited[MAX],int src,int dest);

int main()
{
	int adj[MAX][MAX]={0},n,visited[MAX]={0},src,dest;
	
	printf("Enter the number of vertices\n");
	scanf("%d",&n);
	
	printf("Enter the adjacency information\n");
	createGraph(adj,n);
	
	printf("Enter the source and destination vertex\n");
	scanf("%d%d",&src,&dest);

	if(chkPath(adj,n,visited,src,dest))
		printf("Path exists between %d and %d\n",src,dest);
	else
		printf("Path does not exist between %d and %d\n",src,dest);
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

//using dfs to determine if there exists path b/w 2 vertices
int chkPath(int a[MAX][MAX],int n,int visited[MAX],int src,int dest)
{
//	printf("%d ",src);	//Print src
	visited[src]=1;	//Mark src visited
	
	for(int i=0;i<n;i++)	//To traverse the nodes adjacent to src
	{
		if(a[src][i]==1  && visited[i]==0)	//For the first vertex 'i' adjacent and unvisited, start exploring 'i'
			if(i==dest || chkPath(a,n,visited,i,dest))	//start exploring 'i'
				return 1;
	}
	return 0;
}