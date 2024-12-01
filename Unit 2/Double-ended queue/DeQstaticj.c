#include<stdio.h>
#define MAX 5

typedef struct queue
{
	int q[MAX];
	int front,rear;
}QUEUE;

void initQueue(QUEUE *pq);
void enqueueRear(QUEUE *pq,int ele);
int dequeueFront(QUEUE *pq);
void enqueueFront(QUEUE *pq,int ele);
int dequeueRear(QUEUE *pq);
int isEmpty(QUEUE *pq);
int isFull(QUEUE *pq);
void display(QUEUE *pq);



int main()
{
	QUEUE qobj;
	
	initQueue(&qobj);
	
	int ele,choice;
	
	do
	{
		printf("1.EnqueueRear 2.EnQueueFront 3.DequeueFront 4.DequeueRear 5.Display\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("Enter the integer data\n");
					scanf("%d",&ele);
					if(!isFull(&qobj))
						enqueueRear(&qobj,ele);
					else
						printf("Queue is already full\n");
					break;
			case 2: printf("Enter the integer data\n");
					scanf("%d",&ele);
					if(!isFull(&qobj))
						enqueueFront(&qobj,ele);
					else
						printf("Queue is already full\n");
					break;
			case 3:if(!isEmpty(&qobj))
					{
						ele=dequeueFront(&qobj);
						printf("Deqd %d\n",ele);
					}
					else
						printf("Queue is already empty\n");
					break;
			case 4:if(!isEmpty(&qobj))
					{
						ele=dequeueRear(&qobj);
						printf("Deqd %d\n",ele);
					}
					else
						printf("Queue is already empty\n");
					break;
			case 5:display(&qobj);
					break;
		}
	}while(choice<6);
}



void initQueue(QUEUE *pq)
{
	pq->front=-1;
	pq->rear=-1;
}
void enqueueRear(QUEUE *pq,int ele)
{
	if(isEmpty(pq))
	{
		pq->front=0;
		pq->rear=0;
		pq->q[pq->rear]=ele;
	}
	else
	{
		pq->rear=(pq->rear+1)%MAX;
		pq->q[pq->rear]=ele;
	}
}
void enqueueFront(QUEUE *pq,int ele)
{
	if(isEmpty(pq))
	{
		pq->front=0;
		pq->rear=0;
		pq->q[pq->rear]=ele;
	}
	else
	{
		pq->front=(pq->front-1+MAX)%MAX;
		pq->q[pq->front]=ele;	
			
	}	
}
int dequeueRear(QUEUE *pq)
{
	int ele=pq->q[pq->rear];
	if(pq->front == pq->rear)	//Single element
		initQueue(pq);
	else
		pq->rear=(pq->rear-1+MAX)%MAX;		
	
	return ele;	
}
int dequeueFront(QUEUE *pq)
{
	int ele=pq->q[pq->front];
	if(pq->front == pq->rear)	//Single element
		initQueue(pq);
	else
		pq->front=(pq->front+1)%MAX;
	
	return ele;
}
int isEmpty(QUEUE *pq)
{
	return pq->front==-1;		//return pq->rear==-1;
}
int isFull(QUEUE *pq)
{
	return (pq->rear+1)%MAX == pq->front;
}
void display(QUEUE *pq)
{
	if(isEmpty(pq))
		printf("Empty Queue\n");
	else
	{
		for(int i=pq->front;i!=pq->rear;i=(i+1)%MAX)
			printf("%d ",pq->q[i]);
		printf("%d\n",pq->q[pq->rear]);
	}
}