#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	struct node *prev;
	int info;
	struct node *next;
}NODE;

typedef struct queue
{
	NODE *front;
	NODE *rear;
}QUEUE;

void initQueue(QUEUE *pq);
void enqueueRear(QUEUE *pq,int ele);
void enqueueFront(QUEUE *pq,int ele);
int dequeueFront(QUEUE *pq);
int dequeueRear(QUEUE *pq);
int isEmpty(QUEUE *pq);
void display(QUEUE *pq);
void destroyQueue(QUEUE *pq);


//To be edited
int main()
{
	QUEUE qobj;
	
	initQueue(&qobj);
	
	int ele,choice,status;
	
	do
	{
		printf("1.EnqueueFront 2.EnqueueRear 3.DequeueFront 4.DequeueRear 5.Display\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("Enter the integer data\n");
					scanf("%d",&ele);
					enqueueFront(&qobj,ele);
					break;
			case 2: printf("Enter the integer data\n");
					scanf("%d",&ele);
					enqueueRear(&qobj,ele);
					break;
			case 3:if(isEmpty(&qobj))
						printf("Queue is already empty\n");
					else
					{
						ele=dequeueFront(&qobj);
						printf("Deqd %d\n",ele);
					}
					break;
			case 4:if(isEmpty(&qobj))
						printf("Queue is already empty\n");
					else
					{
						ele=dequeueRear(&qobj);
						printf("Deqd %d\n",ele);
					}
					break;
			case 5:display(&qobj);
					break;
		}
	}while(choice<6);
	destroyQueue(&qobj);
}




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
	}
}
void destroyQueue(QUEUE *pq)
{
	while(pq->front->next!=NULL)
	{
		pq->front=pq->front->next;
		free(pq->front->prev);
	}
	free(pq->front);
	pq->front=NULL;
	pq->rear=NULL;
}