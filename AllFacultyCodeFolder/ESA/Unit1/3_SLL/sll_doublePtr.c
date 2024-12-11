#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int info;
	struct node *next;
}NODE;

void initList(NODE **phead);
void insertFront(NODE **phead,int ele);
void insertLast(NODE **phead,int ele);
void displayList(NODE **phead);
void destroyList(NODE **phead);

int main()
{
	NODE *head;
	
	initList(&head);
	
	int choice,status,ele;
	
	printf("1.InsertFront 2.InsertLast 3.Display\n");
	scanf("%d",&choice);
	do
	{
		switch(choice)
		{
			case 1:printf("Enter an integer\n");
					scanf("%d",&ele);
					insertFront(&head,ele);
					break;
			case 2:printf("Enter an integer\n");
					scanf("%d",&ele);
					insertLast(&head,ele);
					break;
			case 3:displayList(&head);
					break;
		}
		printf("1.InsertFront 2.InsertLast 3.Display\n");
		scanf("%d",&choice);
	}while(choice<4);
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
void insertLast(NODE **phead,int ele)
{
	NODE *newNode=createNode(ele);
	
	if(*phead==NULL)
	{
		*phead=newNode;
	}
	else
	{
		NODE *p=*phead;
		while(p->next!=NULL)
			p=p->next;
		
		p->next=newNode;
	}
}
void displayList(NODE **phead)
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
	
	while(p!=NULL)	//while(pl->head!=NULL)
	{
		*phead=(*phead)->next;
		printf("%d freed\n",p->info);
		free(p);
		p=*phead;
	}
}