//simple queue
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
int isFull(QUEUE *pq);
int isEmpty(QUEUE *pq);
void display(QUEUE *pq);

int main()
{
	QUEUE q;
	int choice,ele;
	initQueue(&q);
	printf("1.enqueue 2.Dequeue 3.isfull 4.isempty 5.display\n");
	printf("enter your choice\n");
	scanf("%d",&choice);
	do
	{
		switch(choice)
		{
			case 1:printf("enter an ele");
			       scanf("%d",&ele);
				   if(!isFull(&q))
				   {
					   enqueue(&q,ele);
					   printf("%d enqd\n",ele);
				   }
				   else
					   printf("q is already full\n");
				   break;
			case 2:if(!isEmpty(&q))
				       printf("Deqd %d\n",dequeue(&q));
				   else
					   printf("qm is already empty\n");
				   break;
            case 3:if(isFull(&q))
				       printf("Queue Full\n");
				   else
					   printf("Queue can take ele\n");
				   break;
			case 4:if(isEmpty(&q))
				       printf("queue empty\n");
				   else
					   printf("queue is not empty\n");
				   break;
			case 5:display(&q);
			       break;
		}
	printf("1.enqueue 2.Dequeue 3.isfull 4.isempty 5.display\n");
	printf("enter your choice\n");
	scanf("%d",&choice);
	}while(choice<6);
	return 0;
}

void initQueue(QUEUE *pq)
{
	pq->front=0;
	pq->rear=-1;
}

void enqueue(QUEUE *pq,int ele)
{
	pq->rear++;
	pq->q[pq->rear]=ele;
}

int dequeue(QUEUE *pq)
{
	int ele=pq->q[pq->front];
	pq->front++;
	return ele;
}

int isFull(QUEUE *pq)
{
	return pq->rear==MAX-1;
}

int isEmpty(QUEUE *pq)
{
	return pq->front>pq->rear;
}

void display(QUEUE *pq)
{
	if(isEmpty(pq))
	{
		printf("Queue is empty\n");
		return;
	}
	for(int i=pq->front;i<=pq->rear;i++)
	{
		printf("%d",pq->q[i]);
	}
	printf("\n");
}