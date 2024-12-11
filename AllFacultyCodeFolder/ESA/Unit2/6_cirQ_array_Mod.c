//Array implementation of circular queue using Mod
#include<stdio.h>
#define MAX 4

typedef struct circularQueue
{
	int q[MAX];
	int front;
	int rear;
}CQ;

void initQueue(CQ *pq);
int isFull(CQ *pq);
//Precondition:Queue is created and not full
void enqueue(CQ *pq,int ele);
int isEmpty(CQ *pq);
//Precondition:Queue is created and not empty
int dequeue(CQ *pq);
void display(CQ *pq);

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
			case 1:if(isFull(&qobj)==0)
					{
						printf("Enter an integer\n");
						scanf("%d",&ele);
						enqueue(&qobj,ele);
					}
					else
						printf("Queue already full\n");
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
}

void initQueue(CQ *pq)
{
	pq->front=-1;
	pq->rear=-1;
}

int isFull(CQ *pq)
{
	return (pq->rear+1)%MAX == pq->front;
}


//Precondition:Queue is created and not full
//Set rear and front appropriately
//Insert element indexed at rear
void enqueue(CQ *pq,int ele)
{
	if(isEmpty(pq))
	{
		pq->front=0;
		pq->rear=0;
	}
	else
		pq->rear = (pq->rear+1)%MAX;
	
	pq->q[pq->rear]=ele;
}

int isEmpty(CQ *pq)
{
	return pq->front==-1;	//return pq->rear==-1;
}

//Precondition:Queue is created and not empty
//Fetch the element indexed at front
//Set front and rear appropriately
//Return back the fetched element
int dequeue(CQ *pq)
{
	int ele=pq->q[pq->front];
	
	if(pq->front == pq->rear)	//After dequeuing single ele, Q becomes empty
	{
		initQueue(pq);	//pq->front=-1;pq->rear=-1;
	}
	else
		pq->front=(pq->front+1)%MAX;
	
	return ele;
}

//Queue exists from front to rear (inclusive of both)
void display(CQ *pq)
{
	if(isEmpty(pq))
		printf("Empty Queue\n");
	else
	{
		int i=pq->front;
		
		while(i!=pq->rear)
		{
			printf("%d ",pq->q[i]);
			i=(i+1)%MAX;
		}
		printf("%d\n",pq->q[i]);
	}
}