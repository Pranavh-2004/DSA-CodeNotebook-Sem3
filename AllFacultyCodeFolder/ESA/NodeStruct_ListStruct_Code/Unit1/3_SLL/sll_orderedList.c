#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int info;
	struct node *next;
}NODE;

typedef struct list
{
	NODE *head;
}LIST;

void initList(LIST *pl);
void orderedList(LIST *pl,int ele);
void display(LIST *pl);
void destroyList(LIST *pl);

int main()
{
	LIST lobj;
	
	initList(&lobj);
	orderedList(&lobj,20);
	orderedList(&lobj,30);
	orderedList(&lobj,25);
	orderedList(&lobj,10);
	
	display(&lobj);
	destroyList(&lobj);
}

void initList(LIST *pl)
{
	pl->head=NULL;
}

NODE* createNode(int ele)
{
	NODE *newNode=malloc(sizeof(NODE));
	newNode->info=ele;
	newNode->next=NULL;
	
	return newNode;
}

void orderedList(LIST *pl,int ele)
{
	NODE *newNode=createNode(ele);
	
	NODE *p=pl->head;
	NODE *q=NULL;
	
	while(p!=NULL && p->info < newNode->info)
	{
		q=p;
		p=p->next;
	}
	if(q==NULL)	//node to be inserted is the first node
	{
		newNode->next=pl->head;	//newNode->next=p;
		pl->head=newNode;
	}
	else	//node to be inserted is in middle or at the end
	{
		newNode->next=p;
		q->next=newNode;
	}
}

void display(LIST *pl)
{
	if(pl->head==NULL)
	{
		printf("Empty List\n");
	}
	else
	{
		NODE *p=pl->head;
		
		while(p!=NULL)
		{
			printf("%d ",p->info);
			p=p->next;
		}
	}
	printf("\n");
}
void destroyList(LIST *pl)
{
	NODE *p;
	
	while(pl->head!=NULL)
	{
		p=pl->head;
		pl->head=pl->head->next;
		printf("%d freed\n",p->info);
		free(p);
	}
}