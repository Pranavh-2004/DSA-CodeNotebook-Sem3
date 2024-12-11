#include<stdio.h>
#define MAX 3
typedef struct queue
{
	int q[MAX];
	int front;
	int rear;
}QUEUE;

void initQueue(QUEUE *pq);
int isEmpty(QUEUE *pq);
int isFull(QUEUE *pq); 
//Precondition: queue is not full
void enqueue(QUEUE *pq,int ele);
//Precondition: queue is not empty
int dequeue(QUEUE *pq);
void display(QUEUE *pq);

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
			case 1:if(isFull(&qobj))
						printf("Queue is already full\n");
					else
					{
						printf("Enter an integer\n");
						scanf("%d",&ele);
						enqueue(&qobj,ele);
					}
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
}

void initQueue(QUEUE *pq)
{
	pq->front=-1;
	pq->rear=-1;
}

int isEmpty(QUEUE *pq)
{
	return pq->front==-1;	//return pq->rear==-1;
}
int isFull(QUEUE *pq)
{
	return (pq->rear+1)%MAX == pq->front;
}

//Precondition: queue is not full
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
//Precondition: queue is not empty
int dequeue(QUEUE *pq)
{
	int ele=pq->q[pq->front];
	if(pq->front == pq->rear)	//Single element
	{
		initQueue(pq);
	}
	else
	{
		pq->front=(pq->front+1)%MAX;
	}
	return ele;
}
void display(QUEUE *pq)
{
	if(isEmpty(pq))
		printf("Empty Queue\n");
	else
	{
		int i;
		for(i=pq->front;i!=pq->rear;i=(i+1)%MAX)
			printf("%d ",pq->q[i]);
		printf("%d\n",pq->q[i]);	//To print the last element
	}
}