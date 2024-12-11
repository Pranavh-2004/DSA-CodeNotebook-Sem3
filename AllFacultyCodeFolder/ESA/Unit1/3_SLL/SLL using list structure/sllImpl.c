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
//Assume that memory is allocated to the node successfully
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

//Assume that memory is allocated to the node successfully
void insertFront(LIST *pl,int ele)
{
	NODE *newNode=createNode(ele);
	newNode->next=pl->head;
	pl->head=newNode;
}

//Assume that memory is allocated to the node successfully
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

void displayList(LIST *pl)
{
	if(pl->head==NULL)
		printf("Empty List\n");
	else
	{
		NODE *p=pl->head;
		
		while(p!=NULL)
		{
			printf("%d ",p->info);
			p=p->next;
		}
		printf("\n");
	}
}
void destroyList(LIST *pl)
{
	NODE *p=pl->head;
	
	while(p!=NULL)	//while(pl->head!=NULL)
	{
		pl->head=pl->head->next;
		printf("%d freed\n",p->info);
		free(p);
		p=pl->head;
	}
}
/*
int deleteFront(LIST *pl,int *pele)
{
	int returnValue=0;
	if(pl->head==NULL)	//List empty case
		returnValue=0;
	else if(pl->head->next == NULL)	//Single node case
	{
		*pele=pl->head->info;
		free(pl->head);
		pl->head=NULL;
		returnValue=1;
	}
	else	//2 or more nodes case
	{
		*pele=pl->head->info;
		NODE *p=pl->head;
		pl->head=pl->head->next;
		free(p);
		returnValue=1;
	}
	return returnValue;
}
*/
int deleteFront(LIST *pl,int *pele)
{
	int returnValue=0;
	if(pl->head==NULL)	//List empty case
		returnValue=0;
	else	//One or more nodes case
	{
		NODE *p=pl->head;
		*pele=pl->head->info;		//*pele=p->info;
		pl->head=pl->head->next;
		free(p);
		returnValue=1;
	}
	return returnValue;
}


int deleteLast(LIST *pl,int *pele)
{
	int returnValue=0;
	if(pl->head==NULL)	//List empty case
		returnValue=0;
	else if(pl->head->next == NULL)	//Single node case
	{
		*pele=pl->head->info;
		free(pl->head);
		pl->head=NULL;
		returnValue=1;
	}
	else		//2 or more nodes case
	{
		NODE *p=pl->head;
		NODE *q;
		
		while(p->next!=NULL)
		{
			q=p;
			p=p->next;
		}
		*pele=p->info;
		free(p);
		q->next=NULL;
		returnValue=1;
	}
	return returnValue;
}

int countNodes(LIST *pl)
{
	int count=0;
	NODE *p=pl->head;
	while(p != NULL)
	{
		count++;
		p=p->next;
	}
	return count;	
}

int insertAtPos(LIST *pl,int pos,int ele)
{
	int n=countNodes(pl);
	
	int returnValue=0;
	
	if(pos<0 || pos>n)
		returnValue=0;
	else if(pos==0)
	{
		insertFront(pl,ele);
		returnValue=1;
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
		
		returnValue=1;
	}
	return returnValue;
}

int deleteAtPos(LIST *pl,int pos,int *pele)
{
	int n=countNodes(pl);
	
	int returnValue=0;
	
	if(pos<0 || pos>=n)
		returnValue=0;
	else if(pos==0)
	{
		returnValue=deleteFront(pl,pele);
	}
	else
	{
		NODE *p=pl->head;
		NODE *q=NULL;
		
		for(int i=0;i<pos;i++)
		{
			q=p;
			p=p->next;
		}
		
		q->next=p->next;
		*pele=p->info;
		free(p);
		returnValue=1;
	}
	return returnValue;
}