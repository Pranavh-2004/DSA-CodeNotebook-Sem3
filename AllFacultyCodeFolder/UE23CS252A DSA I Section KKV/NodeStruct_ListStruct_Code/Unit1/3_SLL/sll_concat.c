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
void insertFront(LIST *pl,int ele);
void concat(LIST *pl1,LIST *pl2);
void display(LIST *pl);
void destroyList(LIST *pl);

int main()
{
	LIST lobj1,lobj2;
	
	initList(&lobj1);
	initList(&lobj2);

/*
//List1 and List2 not empty	
	insertFront(&lobj1,30);
	insertFront(&lobj1,20);
	insertFront(&lobj1,10);
	
	insertFront(&lobj2,50);
	insertFront(&lobj2,40);
*/	

/*
//List1 empty
	insertFront(&lobj2,50);
	insertFront(&lobj2,40);
*/

/*
//List2 empty	
	insertFront(&lobj1,30);
	insertFront(&lobj1,20);
	insertFront(&lobj1,10);
*/	
	
	printf("List 1:");
	display(&lobj1);
	
	printf("List 2:");
	display(&lobj2);
	
	concat(&lobj1,&lobj2);
	printf("Concatenated List:");
	display(&lobj1);
	
	destroyList(&lobj1);
	
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
void insertFront(LIST *pl,int ele)
{
	NODE *newNode=createNode(ele);

	newNode->next=pl->head;
	pl->head=newNode;
}
void concat(LIST *pl1,LIST *pl2)
{
	if(pl1->head==NULL)	//check if list1 is empty
	{
		pl1->head=pl2->head;
	}
	else if(pl2->head!=NULL) //check if list2 is not empty
	{
		NODE *p=pl1->head;
		
		while(p->next!=NULL)
			p=p->next;
		
		p->next=pl2->head;
		pl2->head=NULL;	//This is not a mandatory operation
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