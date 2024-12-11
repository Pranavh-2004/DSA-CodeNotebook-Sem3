#include<stdio.h>
#include<stdlib.h>

#define MAX 10

typedef struct node
{
	int info;
	struct node *next;
}NODE;

void initGraph(NODE *V[MAX]);
void createGraph(NODE *V[MAX]);
void displayGraph(NODE *V[MAX],int n);
void destroyGraph(NODE *V[MAX],int n);

int main()
{
	NODE *V[MAX];
	int n;
	
	printf("Enter the no. of vertices\n");
	scanf("%d",&n);
	initGraph(V);
	
	printf("Enter adjacency info\n");
	createGraph(V);
	
	displayGraph(V,n);
	destroyGraph(V,n);
	
//	displayGraph(V,n);
}

void initGraph(NODE *V[MAX])
{
	for(int i=0;i<MAX;i++)
		V[i]=NULL;
}

void createGraph(NODE *V[MAX])
{
	int src,dest;
	
	printf("Enter source and destination vertices of an edge\n");
	printf("Enter -1 -1 when there are no more edges\n");
	scanf("%d%d",&src,&dest);
	
	while(src!=-1 && dest!=-1)
	{
		NODE *newNode=malloc(sizeof(NODE));
		newNode->info=dest;
		newNode->next=V[src];
		V[src]=newNode;
		scanf("%d%d",&src,&dest);
	}
}

void displayGraph(NODE *V[MAX],int n)
{
	NODE *p;
	for(int i=0;i<n;i++)
	{
		p=V[i];
		printf("V[%d]->",i);
		
		while(p!=NULL)
		{
			printf("%d->",p->info);
			p=p->next;
		}
		printf("NULL\n");
	}
}

void destroyGraph(NODE *V[MAX],int n)
{
	NODE *p;
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