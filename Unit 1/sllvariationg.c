//single pointer
/*
#include<stdio.h>

typedef struct node
{
	int info;
	struct node *next;  //self referential pointer
}NODE;

NODE* initList(NODE *head);

int main()
{
	NODE *head;
	head=initList(head);
	if(head==NULL)
		printf("Empty List\n");
	
	return 0;
}

NODE* initList(NODE *head)
{
	head=NULL;
	return head;
}


//Double pointer
#include<stdio.h>

typedef struct node
{
	int info;
	struct node *next;
}NODE;

NODE* initList(NODE *head);
int main()
{
	NODE *head;
	
	head=initList(head);
	
	if(head==NULL)
		printf("Empty List\n");
}

NODE* initList(NODE *head)

{
	head=NULL;
	return head;
}



#include<stdio.h>

typedef struct node
{
	int info;
	struct node *next;
}NODE;

void initList(NODE **phead);

int main()
{
	NODE *head;
	
	initList(&head);
	
	if(head==NULL)
		printf("Empty List\n");
}

void initList(NODE **phead)
{
	*phead=NULL;
}

*/

#include<stdio.h>

typedef struct node
{
	int info;
	struct node *next;
}NODE;

typedef struct llist
{
	NODE *head;
}LLIST;

void initList(LLIST *pl);
int main()
{
	LLIST  lobj;
	initList(&lobj);
	if(lobj.head==NULL)
		printf("Empty List\n");
	
	
	return 0;
}

void initList(LLIST *pl)
{
	pl->head=NULL;
}

