#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int info;
	struct node *next;
}NODE;

void initList(NODE **phead);
void insertFront(NODE **phead,int ele);
void display(NODE **phead);
void destroyList(NODE **phead);

int main()
{
	NODE *head;
	
	initList(&head);
	insertFront(&head,200);
	insertFront(&head,100);
	
	display(&head);
	destroyList(&head);
}

void initList(NODE **phead)
{
	*phead=NULL;
}

NODE* createNode(int ele)
{
	NODE *newNode=malloc(sizeof(NODE));
	newNode->info=ele;
	newNode->next=NULL;
	
	return newNode;
}

void insertFront(NODE **phead,int ele)
{
	NODE *newNode=createNode(ele);
	
	newNode->next=*phead;
	*phead=newNode;
}

void display(NODE **phead)
{
	if(*phead==NULL)
		printf("Empty List\n");
	else
	{
		NODE *p=*phead;
		
		while(p!=NULL)
		{
			printf("%d ",p->info);
			p=p->next;
		}
		printf("\n");
	}
}
void destroyList(NODE **phead)
{
	NODE *p=*phead;
	
	while(*phead!=NULL)
	{
		*phead=(*phead)->next;
		printf("%d freed\n",p->info);
		free(p);
		p=*phead;
	}
}