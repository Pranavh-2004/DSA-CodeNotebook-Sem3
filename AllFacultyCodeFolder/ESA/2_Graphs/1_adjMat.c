/* //Adjacency Matrix Representation of a Graph

#include<stdio.h>
#define MAX 10

void createGraph(int a[MAX][MAX],int n);
void displayGraph(int a[MAX][MAX],int n);

int main()
{
	int a[MAX][MAX];
	int n;
	
	printf("Enter the number of vertices\n");
	scanf("%d",&n);
	
	printf("Enter the adjacency information\n");
	createGraph(a,n);
	
	printf("Graph in matrix format\n");
	displayGraph(a,n);
}

void createGraph(int a[MAX][MAX],int n)
{
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%d",&a[i][j]);
}

void displayGraph(int a[MAX][MAX],int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
} */

//Adjacency Matrix Representation of a Graph

#include<stdio.h>
#define MAX 10

void createGraph(int a[MAX][MAX],int n);
void displayGraph(int a[MAX][MAX],int n);

int main()
{
	int a[MAX][MAX]={0};
	int n;
	
	printf("Enter the number of vertices\n");
	scanf("%d",&n);
	
	printf("Enter the adjacency information\n");
	createGraph(a,n);
	
	printf("Graph in matrix format\n");
	displayGraph(a,n);
}

void createGraph(int a[MAX][MAX],int n)
{
	int src,dest;
	
	printf("Enter source and destination vertices of an edge\n");
	printf("Enter -1 -1 when there are no more edges\n");
	scanf("%d%d",&src,&dest);
	
	while(src!=-1 && dest!=-1)
	{
		a[src][dest]=1;
		scanf("%d%d",&src,&dest);
	}	
}

void displayGraph(int a[MAX][MAX],int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
}