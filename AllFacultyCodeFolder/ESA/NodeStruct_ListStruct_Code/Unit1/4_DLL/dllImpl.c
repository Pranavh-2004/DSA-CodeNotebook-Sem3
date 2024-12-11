#include<stdio.h>
#include<stdlib.h>
#include"dll.h"

void initList(LIST *pl)
{
	pl->head=NULL;
}

NODE* createNode(int ele)
{
	NODE *newNode=malloc(sizeof(NODE));
	
	newNode->prev=NULL;
	newNode->info=ele;
	newNode->next=NULL;
	
	return newNode;
}

void insertFront(LIST *pl,int ele)
{
	NODE *newNode=createNode(ele);
	
	if(pl->head==NULL)	//if list is empty
		pl->head=newNode;
	else
	{
		newNode->next=pl->head;
		pl->head->prev=newNode;		//newNode->next->prev=newNode;
		pl->head=newNode;
	}
}

void insertLast(LIST *pl,int ele)
{
	NODE *newNode=createNode(ele);
	
	if(pl->head==NULL)	//if list is empty
		pl->head=newNode;
	else
	{
		NODE *p=pl->head;
		
		while(p->next!=NULL)
			p=p->next;
		
		newNode->prev=p;
		p->next=newNode;
	}
}
int deleteFront(LIST *pl,int *pele)
{
	if(pl->head == NULL)	//List empty case
		return 0;
	
	*pele=pl->head->info;
	
	if(pl->head->next == NULL)	//Single node case
	{
		free(pl->head);
		pl->head=NULL;
	}
	else		//Multiple node case
	{
		pl->head=pl->head->next;
		free(pl->head->prev);
		pl->head->prev=NULL;
	}
	return 1;
}
int deleteLast(LIST *pl,int *pele)
{
	if(pl->head == NULL)	//List empty case
		return 0;
	
	if(pl->head->next == NULL)	//Single node case
	{
		*pele=pl->head->info;
		free(pl->head);
		pl->head=NULL;
	}
	else		//Multiple node case
	{
		NODE *p=pl->head;
		
		while(p->next!=NULL)
			p=p->next;
		
		*pele=p->info;
		p->prev->next=NULL;
		free(p);
	}
	return 1;
}
void display(LIST *pl)
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
	if(pl->head==NULL)
		return;
	else
	{
		while(pl->head->next!=NULL)
		{
			pl->head=pl->head->next;
			printf("%d freed\n",pl->head->prev->info);
			free(pl->head->prev);
		}
		printf("%d freed\n",pl->head->info);
		free(pl->head);
		pl->head=NULL;
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
/*
int insertAtPos(LIST *pl,int ele,int pos)
{
	int n=countNodes(pl);
	if(pos<0 || pos>n)
		return 0;
	
	if(pos==0)
	{
		insertFront(pl,ele);
		return 1;
	}
	else if(pos==n)
	{
		insertLast(pl,ele);
		return 1;
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
		newNode->prev=q;
		p->prev=newNode;
		q->next=newNode;
		return 1;
	}
}
*/

int insertAtPos(LIST *pl,int ele,int pos)
{
	int n=countNodes(pl);
	if(pos<0 || pos>n)
		return 0;
	
	if(pos==0)
	{
		insertFront(pl,ele);
		return 1;
	}
	else if(pos==n)
	{
		insertLast(pl,ele);
		return 1;
	}
	else
	{
		NODE *newNode=createNode(ele);
		
		NODE *p=pl->head;
		
		for(int i=1;i<pos;i++)
			p=p->next;
		
		newNode->next=p->next;
		newNode->prev=p;
		p->next->prev=newNode;
		p->next=newNode;
		return 1;
	}
}
int deleteAtPos(LIST *pl,int *pele,int pos)
{
	int n=countNodes(pl);
	
	if(pos<0 || pos>=n)
		return 0;
	
	if(pos==0)
		return deleteFront(pl,pele);
	else if(pos==n-1)
		return deleteLast(pl,pele);
	else
	{
		NODE *p=pl->head;
		
		for(int i=0;i<pos;i++)
			p=p->next;
		
		*pele=p->info;
		p->next->prev=p->prev;
		p->prev->next=p->next;
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