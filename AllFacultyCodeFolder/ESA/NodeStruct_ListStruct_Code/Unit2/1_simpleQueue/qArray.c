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
	pq->front=0;
	pq->rear=-1;
}

int isEmpty(QUEUE *pq)
{
	return pq->front > pq->rear;
}
int isFull(QUEUE *pq)
{
	return pq->rear==MAX-1;
}

//Precondition: queue is not full
void enqueue(QUEUE *pq,int ele)
{
	pq->rear++;
	pq->q[pq->rear]=ele;
	
	//pq->q[++pq->rear]=ele;
}

//Precondition: queue is not empty
int dequeue(QUEUE *pq)
{
	int ele=pq->q[pq->front];
	pq->front++;
	
	return ele;
	
	//return pq->q[pq->front++];
}
void display(QUEUE *pq)
{
	if(isEmpty(pq))
		printf("Queue is empty\n");
	else
	{
		for(int i=pq->front;i<=pq->rear;i++)
			printf("%d ",pq->q[i]);
		printf("\n");
	}
}