#include<stdio.h>
#include<stdlib.h>
#include"csll.h"

void initList(LIST *pl)
{
	pl->last=NULL;
}
void insertFront(LIST *pl,int ele)
{
	NODE *newNode=malloc(sizeof(NODE));
	newNode->info=ele;
	
	if(pl->last == NULL)	//List empty case
	{
		newNode->next=newNode;
		pl->last=newNode;
	}
	else
	{
		newNode->next=pl->last->next;
		pl->last->next=newNode;
	}
}
void insertLast(LIST *pl,int ele)
{
	NODE *newNode=malloc(sizeof(NODE));
	newNode->info=ele;
	
	if(pl->last==NULL)	//List empty case
	{
		newNode->next=newNode;
		pl->last=newNode;
	}
	else
	{
		newNode->next=pl->last->next;
		pl->last->next=newNode;
		pl->last=newNode;
	}
}
void display(LIST *pl)
{
	if(pl->last == NULL)
		printf("Empty List\n");
	else
	{
		NODE *p=pl->last->next;
		
		do
		{
			printf("%d ",p->info);
			p=p->next;
		}while(p!=pl->last->next);
		printf("\n");
	}
}
/*
void display(LIST *pl)
{
	if(pl->last == NULL)
		printf("Empty List\n");
	else
	{
		NODE *p=pl->last->next;
		
		while(p!=pl->last)
		{
			printf("%d ",p->info);
			p=p->next;
		}
		printf("%d\n",p->info);
	}
}
*/

int deleteFront(LIST *pl,int *pele)
{
	if(pl->last == NULL)	//List empty
		return 0;
	
	if(pl->last->next == pl->last)	//Single node case
	{
		*pele=pl->last->info;
		free(pl->last);
		pl->last=NULL;
	}
	else
	{
		NODE *p=pl->last->next;
		pl->last->next=p->next;
		*pele=p->info;
		free(p);
	}
	return 1;
}
int deleteLast(LIST *pl,int *pele)
{
	if(pl->last == NULL)	//List empty
		return 0;
	
	if(pl->last->next == pl->last)	//Single node case
	{
		*pele=pl->last->info;
		free(pl->last);
		pl->last=NULL;
	}
	else
	{
		NODE *p=pl->last->next;
		
		while(p->next!=pl->last)
			p=p->next;
		p->next=pl->last->next;
		*pele=pl->last->info;
		free(pl->last);
		pl->last=p;
	}
	return 1;	
}
void destroyList(LIST *pl)
{
	if(pl->last!=NULL)
	{
		NODE *p=pl->last->next;
		
		while(p!=pl->last)
		{
			pl->last->next = p->next;
			printf("%d freed\n",p->info);
			free(p);
			p=pl->last->next;
		}
		printf("%d freed\n",p->info);
		free(p);
		pl->last=NULL;
	}
}
int countNodes(LIST *pl)
{
	int count=0;
	
	if(pl->last!=NULL)
	{
		NODE *p=pl->last->next;
		
		while(p!=pl->last)
		{
			count++;
			p=p->next;
		}
		count++;
	}
	return count;
}
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
	if(pos==n)
	{
		insertLast(pl,ele);
		return 1;
	}
	
	NODE *newNode=malloc(sizeof(NODE));
	newNode->info=ele;
	
	NODE *p=pl->last;
	for(int i=0;i<pos;i++)
		p=p->next;
	
	newNode->next=p->next;
	p->next=newNode;
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
		NODE *p=pl->last->next;
		NODE *q=pl->last;
		
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
/*
NODE* search(LIST *pl,int key)
{
	NODE *p=pl->last;
	
	if(pl->last!=NULL)
	{
		while(p->next!=pl->last)
		{
			if(key == p->info)
			{
				return p;
			}
			p=p->next;
		}
		if(key==p->info)
			return p;
		else
			return NULL;
	}
	return NULL;
}
*/
NODE* search(LIST *pl,int key)
{	
	if(pl->last != NULL)
	{
		NODE *p=pl->last;
		do
		{
			if(key == p->info)
				return p;
			p=p->next;
		}while(p!=pl->last);
	}
	return NULL;
}
/*
NODE* search(LIST *pl,int key)
{	
	if(pl->last != NULL)
	{
		NODE *p=pl->last->next;
		do
		{
			if(key == p->info)
				return p;
			p=p->next;
		}while(p!=pl->last->next);
	}
	return NULL;
}
*/