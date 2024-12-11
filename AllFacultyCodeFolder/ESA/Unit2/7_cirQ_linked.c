//Linked implementation of circular queue
//Singly linked circular queue:
//Both enqueueRear and dequeueFront can be done in constant time
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int info;
	struct node *next;
}NODE;

typedef struct circularQueue
{
	NODE *front;
	NODE *rear;
}CQ;

void initQueue(CQ *pq);
//Precondition:Queue is created
void enqueue(CQ *pq,int ele);
int isEmpty(CQ *pq);
//Precondition:Queue is created and not empty
int dequeue(CQ *pq);
void display(CQ *pq);
void destroyQueue(CQ *pq);

int main()
{
	CQ qobj;	//Creates the queue
	initQueue(&qobj);	//Initializes queue to be empty
	
	int choice,ele;
	
	do
	{
		printf("1.Enqueue 2.Dequeue 3.Display\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:	printf("Enter an integer\n");
					scanf("%d",&ele);
					enqueue(&qobj,ele);
					break;
			case 2:if(isEmpty(&qobj)==0)
					{
						ele=dequeue(&qobj);
						printf("Dequeued element is %d\n",ele);
					}
					else
						printf("Queue is already empty\n");
					break;
			case 3:display(&qobj);
					break;
		}
	}while(choice<4);
	destroyQueue(&qobj);
}

void initQueue(CQ *pq)
{
	pq->front=NULL;
	pq->rear=NULL;
}

//Precondition:Queue is created and not full
void enqueue(CQ *pq,int ele)
{
	NODE *newNode=malloc(sizeof(NODE));
	newNode->info=ele;
	
	if(isEmpty(pq))
	{
		newNode->next=newNode;
		pq->front=newNode;
		pq->rear=newNode;
	}
	else
	{
		newNode->next=pq->front;
		pq->rear->next=newNode;
		pq->rear=newNode;
	}
}

int isEmpty(CQ *pq)
{
	return pq->front==NULL;	//return pq->rear==NULL;
}

//Precondition:Queue is created and not empty
int dequeue(CQ *pq)
{
	int ele=pq->front->info;
	
	if(pq->front == pq->rear)
	{
		free(pq->front);
		initQueue(pq);
	}
	else 
	{
		pq->front=pq->front->next;
		free(pq->rear->next);
		pq->rear->next=pq->front;
	}
	
	return ele;
}
void display(CQ *pq)
{
	if(isEmpty(pq))
		printf("Empty Queue\n");
	else
	{
		NODE* p=pq->front;
		
		while(p!=pq->rear)
		{
			printf("%d ",p->info);
			p=p->next;
		}
		printf("%d\n",p->info);
	}
}

void destroyQueue(CQ *pq)
{
	if(!isEmpty(pq))
	{
		NODE *p=pq->front;
		while(p!=pq->rear)
		{
			pq->front=pq->front->next;
			printf("Freed %d\n",p->info);
			free(p);
			p=pq->front;
		}
		printf("Freed %d\n",p->info);
		free(p);
	}
	pq->rear=NULL;
	pq->front=NULL;
}