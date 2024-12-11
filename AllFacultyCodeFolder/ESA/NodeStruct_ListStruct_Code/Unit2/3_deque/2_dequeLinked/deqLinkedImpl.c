#include<stdio.h>
#include<stdlib.h>
#include"deqLinked.h"

void initQueue(QUEUE *pq)
{
	pq->front=NULL;
	pq->rear=NULL;
}
void enqueueRear(QUEUE *pq,int ele)
{
	NODE *newNode=malloc(sizeof(NODE));
	newNode->prev=NULL;
	newNode->info=ele;
	newNode->next=NULL;
	
	if(isEmpty(pq))
	{
		pq->front=newNode;
		pq->rear=newNode;
	}
	else
	{
		newNode->prev=pq->rear;
		pq->rear->next=newNode;
		pq->rear=newNode;
	}
}
void enqueueFront(QUEUE *pq,int ele)
{
	NODE *newNode=malloc(sizeof(NODE));
	newNode->prev=NULL;
	newNode->info=ele;
	newNode->next=NULL;
	
	if(isEmpty(pq))
	{
		pq->front=newNode;
		pq->rear=newNode;
	}
	else
	{
		newNode->next=pq->front;
		pq->front->prev=newNode;
		pq->front=newNode;
	}
}

//pq points to a non empty queue
int dequeueFront(QUEUE *pq)
{
	int ele=pq->front->info;
	
	if(pq->front==pq->rear)	//Single node
	{
		free(pq->front);
		pq->front=NULL;
		pq->rear=NULL;
	}
	else
	{
		pq->front=pq->front->next;
		free(pq->front->prev);
		pq->front->prev=NULL;
	}
	return ele;
}

//pq points to a non empty queue
int dequeueRear(QUEUE *pq)
{
	int ele=pq->rear->info;
	
	if(pq->front==pq->rear)	//Single node
	{
		free(pq->rear);
		pq->front=NULL;
		pq->rear=NULL;
	}
	else
	{
		pq->rear=pq->rear->prev;
		free(pq->rear->next);
		pq->rear->next=NULL;
	}
	return ele;
}
int isEmpty(QUEUE *pq)
{
	return pq->front==NULL; //return pq->rear==NULL;
}
void display(QUEUE *pq)
{
	if(isEmpty(pq))
		printf("Empty Queue\n");
	else
	{
		NODE *p=pq->front;
		while(p!=NULL)
		{
			printf("%d ",p->info);
			p=p->next;
		}
		printf("\n");
	}
}
void destroyQueue(QUEUE *pq)
{
	if(pq->front!=NULL)
	{
		while(pq->front->next!=NULL)
		{
			printf("%d freed\n",pq->front->info);
			pq->front=pq->front->next;
			free(pq->front->prev);
		}
		printf("%d freed\n",pq->front->info);
		free(pq->front);
		pq->front=NULL;
		pq->rear=NULL;
	}
}