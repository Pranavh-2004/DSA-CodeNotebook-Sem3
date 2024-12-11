//DFS traversal of a connected graph using adjacency list, recursive
#include<stdio.h>
#include<stdlib.h>
#define MAX 20

typedef struct node
{
	int info;
	struct node *next;
}NODE;

void initGraph(NODE *V[]);
void createGraph(NODE *V[]);
void dfs(NODE *V[],int n,int visited[MAX],int src);
void destroyGraph(NODE *V[],int n);

int main()
{
	NODE *V[MAX];
	int n;
	int visited[MAX]={0};
	int src;
	
	initGraph(V);
	
	printf("Enter the number of vertices\n");
	scanf("%d",&n);
	
	printf("Enter the adjacency information\n");
	createGraph(V);
	
	printf("Enter the source vertex\n");
	scanf("%d",&src);
	
	printf("DFS traversal\n");
	dfs(V,n,visited,src);
	
	destroyGraph(V,n);
//	printf("After graph destruction\n");
//	displayGraph(V,n);
}

void initGraph(NODE *V[])
{
	for(int i=0;i<MAX;i++)
		V[i]=NULL;
}
void createGraph(NODE *V[])
{
	int src,dest;
	NODE *newNode;
	printf("Enter source and destination vertices of an edge\n");
	printf("Enter -1 -1 to stop adding edges\n");
	
	scanf("%d%d",&src,&dest);
	
	while(src!=-1 && dest!=-1)
	{
		newNode=malloc(sizeof(NODE));
		newNode->info=dest;
		newNode->next=V[src];
		V[src]=newNode;
		scanf("%d%d",&src,&dest);
	}
}
void dfs(NODE *V[],int n,int visited[MAX],int src)
{
	int s[MAX],top=-1;
	int v;
	NODE *p=NULL;
	
	s[++top]=src;
	visited[src]=1;
	printf("%d ",src);
	
	while(top!=-1)
	{
		v=s[top];
		
		p=V[v];
		
		while(p!=NULL)
		{
			if(visited[p->info] == 0)
				break;
			p=p->next;
		}
		if(p==NULL)
			top--;
		else
		{
			s[++top]=p->info;
			visited[p->info]=1;
			printf("%d ",p->info);
		}
	}
}
void destroyGraph(NODE *V[],int n)
{
	NODE *p=NULL;
	
	for(int i=0;i<n;i++)
	{
		p=V[i];
		while(p!=NULL)
		{
			V[i]=p->next;
			free(p);
			p=V[i];
		}
	}
}