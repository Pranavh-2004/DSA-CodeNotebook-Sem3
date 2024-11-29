#include<stdio.h>
#include<stdlib.h>
#include"cdll.h"

void initList(LIST *pl)
{
	pl->head=NULL;
}

void insertFront(LIST *pl,int ele)
{
	NODE *newNode=malloc(sizeof(NODE));
	newNode->info=ele;
	
	if(pl->head==NULL)	//List empty case
	{
		newNode->next=newNode;
		newNode->prev=newNode;
		pl->head=newNode;
	}
	else	//one or more nodes case
	{
		NODE *last=pl->head->prev;
		
		newNode->next=pl->head;
		newNode->prev=last;
		pl->head->prev=newNode;
		last->next=newNode;
		
		pl->head=newNode;
	}
	
}
void insertLast(LIST *pl,int ele)
{
		NODE *newNode=malloc(sizeof(NODE));
	newNode->info=ele;
	
	if(pl->head==NULL)	//List empty case
	{
		newNode->next=newNode;
		newNode->prev=newNode;
		pl->head=newNode;
	}
	else	//one or more nodes case
	{
		NODE *last=pl->head->prev;
		
		newNode->next=pl->head;
		newNode->prev=last;
		last->next=newNode;
		pl->head->prev=newNode;
	}
}
int deleteFront(LIST *pl,int *pele)
{
	if(pl->head == NULL)	//List empty case
		return 0;
	
	*pele=pl->head->info;
	if(pl->head == pl->head->next)	//Single node case
	{
		free(pl->head);
		pl->head=NULL;
	}
	else		//2 or more nodes case
	{
		NODE *last=pl->head->prev;
		
		pl->head=pl->head->next;
		last->next=pl->head;
		free(pl->head->prev);
		pl->head->prev=last;
	}
	return 1;
}
int deleteLast(LIST *pl,int *pele)
{
	if(pl->head == NULL)	//List empty case
		return 0;
	
	if(pl->head == pl->head->next)	//Single node case
	{
		*pele=pl->head->info;
		free(pl->head);
		pl->head=NULL;
	}
	else		//2 or more nodes case
	{
		NODE *last=pl->head->prev;
		
		*pele=last->info;
		last->prev->next=pl->head;
		last=last->prev;
		free(pl->head->prev);
		pl->head->prev=last;
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
	
		do
		{
			printf("%d ",p->info);
			p=p->next;
		}while(p!=pl->head);
	}
}
void destroyList(LIST *pl)
{
	if(pl->head==NULL)
		return;
	else
	{
		NODE *last=pl->head->prev;
		
		while(pl->head != last)
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
	
	if(pl->head!=NULL)
	{
		NODE *p=pl->head;
		do
		{
			count++;
			p=p->next;
		}while(p!=pl->head);
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
	else if(pos==n)
	{
		insertLast(pl,ele);
		return 1;
	}
	else
	{
		NODE *newNode=malloc(sizeof(NODE));
		newNode->info=ele;
		
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
	if(pl->head==NULL)
		return NULL;
	else
	{
		NODE *p=pl->head;
		
		do
		{
			if(key == p->info)
				return p;
			p=p->next;
		}while(p!=pl->head);
	}
	return NULL;
}