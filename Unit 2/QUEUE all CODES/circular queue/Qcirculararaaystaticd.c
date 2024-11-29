#include<stdio.h>
#define MAX 3

typedef struct queue
{
	int q[MAX];
	int front,rear;
}QUEUE;

void initQueue(QUEUE *pq);
void enqueue(QUEUE *pq,int ele);
int dequeue(QUEUE *pq);
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
		printf("1.Enqueue 2.Dequeue 3.Display\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("Enter the integer data\n");
					scanf("%d",&ele);
					if(!isFull(&qobj))
						enqueue(&qobj,ele);
					else
						printf("Queue is already full\n");
					break;
			case 2:if(!isEmpty(&qobj))
					{
						ele=dequeue(&qobj);
						printf("Deqd %d\n",ele);
					}
					else
						printf("Queue is already empty\n");
					break;
			case 3:display(&qobj);
					break;
		}
	}while(choice<4);
}



void initQueue(QUEUE *pq)
{
	pq->front=-1;
	pq->rear=-1;
}
void enqueue(QUEUE *pq,int ele)
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
int dequeue(QUEUE *pq)
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