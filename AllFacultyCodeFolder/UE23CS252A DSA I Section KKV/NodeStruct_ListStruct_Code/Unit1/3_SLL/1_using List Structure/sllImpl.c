#include<stdio.h>
#include<stdlib.h>
#include"sll.h"

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
/*
void insertFront(LIST *pl,int ele)
{
	NODE *newNode=createNode(ele);
	
	if(pl->head==NULL)
	{
		pl->head=newNode;
	}
	else
	{
		newNode->next=pl->head;
		pl->head=newNode;
	}
}
*/

void insertFront(LIST *pl,int ele)
{
	NODE *newNode=createNode(ele);

	newNode->next=pl->head;
	pl->head=newNode;
}
void insertLast(LIST *pl,int ele)
{
	NODE *newNode=createNode(ele);
	
	if(pl->head==NULL)
	{
		pl->head=newNode;
	}
	else
	{
		NODE *p=pl->head;
		
		while(p->next!=NULL)
			p=p->next;
		
		p->next=newNode;
	}
}
int deleteFront(LIST *pl,int *pele)
{
	if(pl->head==NULL)	//List empty case
		return 0;
	
	NODE *p=pl->head;
	*pele=pl->head->info;		//*pele=p->info;
	pl->head=pl->head->next;
	free(p);
	return 1;
}

int deleteLast(LIST *pl,int *pele)
{
	if(pl->head==NULL)	//List empty case
		return 0;

	if(pl->head->next==NULL)	//Single node case
	{
		*pele=pl->head->info;
		free(pl->head);
		pl->head=NULL;
	}
	else
	{
		NODE *p=pl->head;
		NODE *q=NULL;
		
		while(p->next!=NULL)
		{
			q=p;
			p=p->next;
		}
		*pele=p->info;
		free(p);
		q->next=NULL;
	}
	return 1;
}

/*
//Using single extra pointer
//though not time efficient compared to the above code

int deleteLast(LIST *pl,int *pele)
{
	if(pl->head==NULL)	//List empty case
		return 0;

	if(pl->head->next==NULL)	//Single node case
	{
		*pele=pl->head->info;
		free(pl->head);
		pl->head=NULL;
		return 1;
	}
	else
	{
		NODE *p=pl->head;
	
		while(p->next->next!=NULL)
			p=p->next;

		*pele=p->next->info;
		free(p->next);
		p->next=NULL;
		return 1;
	}
}
*/
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

int countNodes(LIST *pl)
{
	int count=0;
	
	NODE *p=pl->head;
	while(p!=NULL)
	{
		count++;
		p=p->next;
	}
	return count;
}

//Position of nodes starts from zero
int insertAtPos(LIST *pl,int ele,int pos)
{
	int n=countNodes(pl);
	
	if(pos<0 || pos>n)
		return 0;
	
	if(pos==0)
	{
		insertFront(pl,ele);
	}
	else
	{
		NODE *newNode=createNode(ele);
		NODE *p=pl->head;
		NODE *q=NULL;
		
		for(int i=0;i<pos;i++)
		{
			q=p;
			p=p->next;
		}
		
		newNode->next=p;
		q->next=newNode;
	}
	return 1;		
}

/*
//Position of nodes starts from zero
//Using a single extra pointer
int insertAtPos(LIST *pl,int ele,int pos)
{
	int n=countNodes(pl);
	
	if(pos<0 || pos>n)
		return 0;
	
	if(pos==0)
	{
		insertFront(pl,ele);
	}
	else
	{
		NODE *newNode=createNode(ele);
		NODE *p=pl->head;
		NODE *q=NULL;
		
		for(int i=1;i<pos;i++)
		{
			p=p->next;
		}
		
		newNode->next=p->next;
		p->next=newNode;
	}
	return 1;		
}
*/

//Position of nodes starts from zero
int deleteAtPos(LIST *pl,int *pele,int pos)
{
	int n=countNodes(pl);
	
	if(pos<0 || pos>=n)
		return 0;
	
	if(pos==0)
	{
		return deleteFront(pl,pele);
	}
	else
	{
		NODE *q=NULL;
		NODE *p=pl->head;
		
		for(int i=0;i<pos;i++)
		{
			q=p;
			p=p->next;
		}
		*pele=p->info;
		q->next=p->next;
		free(p);
		return 1;
	}
}

NODE* search(LIST *pl,int key)
{
	NODE *p=pl->head;
	while(p!=NULL)
	{
		if(key == p->info)
			return p;
		p=p->next;
	}
	return NULL;
}