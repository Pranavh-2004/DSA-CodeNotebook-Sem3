//Array implementation of double ended queue
#include<stdio.h>
#define MAX 4

typedef struct deque
{
	int q[MAX];
	int front;
	int rear;
}DQ;

void initQueue(DQ *pq);
int isFull(DQ *pq);
//Precondition:Queue is created and not full
void enqueueRear(DQ *pq,int ele);
int isEmpty(DQ *pq);
//Precondition:Queue is created and not empty
int dequeueFront(DQ *pq);
//Precondition:Queue is created and not full
void enqueueFront(DQ *pq,int ele);
//Precondition:Queue is created and not empty
int dequeueRear(DQ *pq);
void display(DQ *pq);

int main()
{
	DQ qobj;	//Creates the queue
	initQueue(&qobj);	//Initializes queue to be empty
	
	int choice,ele;
	
	do
	{
		printf("1.EnqueueRear 2.DequeueFront 3.Display");
		printf("4.EnqueueFront 5.DequeueRear\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:if(isFull(&qobj)==0)
					{
						printf("Enter an integer\n");
						scanf("%d",&ele);
						enqueueRear(&qobj,ele);
					}
					else
						printf("Queue already full\n");
					break;
			case 2:if(isEmpty(&qobj)==0)
					{
						ele=dequeueFront(&qobj);
						printf("Dequeued element is %d\n",ele);
					}
					else
						printf("Queue is already empty\n");
					break;
			case 3:display(&qobj);
					break;
			case 4:if(isFull(&qobj)==0)
					{
						printf("Enter an integer\n");
						scanf("%d",&ele);
						enqueueFront(&qobj,ele);
					}
					else
						printf("Queue already full\n");
					break;
			case 5:if(isEmpty(&qobj)==0)
					{
						ele=dequeueRear(&qobj);
						printf("Dequeued element is %d\n",ele);
					}
					else
						printf("Queue is already empty\n");
					break;
		}
	}while(choice<6);
}

void initQueue(DQ *pq)
{
	pq->front=-1;
	pq->rear=-1;
}

int isFull(DQ *pq)
{
	return (pq->rear==MAX-1 && pq->front==0) || (pq->rear+1 == pq->front);
}


//Precondition:Queue is created and not full
//Set rear and front appropriately
//Insert element indexed at rear
void enqueueRear(DQ *pq,int ele)
{
	if(isEmpty(pq))
	{
		pq->front=0;
		pq->rear=0;
	}
	else if(pq->rear==MAX-1)
		pq->rear=0;
	else
		(pq->rear)=pq->rear+1;
	
	pq->q[pq->rear]=ele;
}

int isEmpty(DQ *pq)
{
	return pq->front==-1;	//return pq->rear==-1;
}

//Precondition:Queue is created and not empty
//Fetch the element indexed at front
//Set front and rear appropriately
//Return back the fetched element
int dequeueFront(DQ *pq)
{
	int ele=pq->q[pq->front];
	
	if(pq->front == pq->rear)
	{
		initQueue(pq);	//pq->front=-1;pq->rear=-1;
	}
	else if(pq->front == MAX-1)
		pq->front=0;
	else
		pq->front=pq->front+1;
	
	return ele;
}

//Queue exists from front to rear (inclusive of both)
void display(DQ *pq)
{
	if(isEmpty(pq))
		printf("Empty Queue\n");
	else
	{
		int i=pq->front;
		
		while(i!=pq->rear)
		{
			printf("%d ",pq->q[i]);
			if(i==MAX-1)
				i=0;
			else
				i++;
		}
		printf("%d\n",pq->q[i]);
	}
}

//Precondition:Queue is created and not full
//Set rear and front appropriately
//Insert element indexed at front
void enqueueFront(DQ *pq,int ele)
{
	if(isEmpty(pq))
	{
		pq->front=0;
		pq->rear=0;
	}
	else if(pq->front==0)
		pq->front=MAX-1;
	else
		pq->front=(pq->front)-1;
	
	pq->q[pq->front]=ele;
}

//Precondition:Queue is created and not empty
//Fetch the element indexed at rear
//Set front and rear appropriately
//Return back the fetched element
int dequeueRear(DQ *pq)
{
	int ele=pq->q[pq->rear];
	
	if(pq->front == pq->rear)
	{
		initQueue(pq);
	}
	else if(pq->rear == 0)
		pq->rear=MAX-1;
	else
		pq->rear=(pq->rear)-1;
	
	return ele;	
}