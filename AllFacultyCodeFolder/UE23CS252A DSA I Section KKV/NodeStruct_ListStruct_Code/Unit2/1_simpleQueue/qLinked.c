#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int info;
	struct node *next;
}NODE;

typedef struct queue
{
	NODE *front;
	NODE *rear;
}QUEUE;

void initQueue(QUEUE *pq);
int isEmpty(QUEUE *pq);
void enqueue(QUEUE *pq,int ele);
//Precondition: queue is not empty
int dequeue(QUEUE *pq);
void display(QUEUE *pq);
void destroyQueue(QUEUE *pq);

int main()
{
	QUEUE qobj;
	
	initQueue(&qobj);
	
	int choice,ele;
	
	printf("1.Enqueue 2.Dequeue 3.display\n");
	scanf("%d",&choice);
	
	do
	{
		switch(choice)
		{
			case 1:	printf("Enter an integer\n");
					scanf("%d",&ele);
					enqueue(&qobj,ele);
					break;
			case 2:if(isEmpty(&qobj))
						printf("Queue is already empty\n");
					else
					{
						ele=dequeue(&qobj);
						printf("Dequeued %d\n",ele);
					}
					break;
			case 3:display(&qobj);
					break;

			}
		printf("1.Enqueue 2.Dequeue 3.display\n");
		scanf("%d",&choice);	
	}while(choice<4);
	destroyQueue(&qobj);
}

void initQueue(QUEUE *pq)
{
	pq->front=NULL;
	pq->rear=NULL;
}

int isEmpty(QUEUE *pq)
{
	return pq->front==NULL;		//return pq->rear==NULL
}

void enqueue(QUEUE *pq,int ele)
{
	NODE *newNode=malloc(sizeof(NODE));
	newNode->info=ele;
	newNode->next=NULL;
	
	if(isEmpty(pq))
	{
		pq->front=newNode;
		pq->rear=newNode;
	}
	else
	{
		pq->rear->next=newNode;
		pq->rear=newNode;	//pq->rear=pq->rear->next;
	}
}
//Precondition: queue is not empty
int dequeue(QUEUE *pq)
{
	int ele=pq->front->info;
	if(pq->front==pq->rear)	//Single node case//if(pq->front->next==NULL)
	{
		free(pq->front);
		pq->front=NULL;
		pq->rear=NULL;
	}
	else
	{
		NODE *p=pq->front;
		pq->front=pq->front->next;
		free(p);
	}
	return ele;
}

void display(QUEUE *pq)
{
	if(pq->front==NULL)		//pq->rear=NULL
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
	NODE *p=pq->front;
	
	while(pq->front!=NULL)
	{
		pq->front=pq->front->next;
		free(p);
		p=pq->front;
	}
	pq->rear=NULL;
}