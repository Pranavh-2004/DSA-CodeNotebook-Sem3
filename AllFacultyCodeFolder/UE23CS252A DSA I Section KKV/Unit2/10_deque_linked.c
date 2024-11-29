//Linked implementation of double ended queue
//Doubly linked list: enqueueRear,enqueueFront and 
//ddequeueFront, dequeueRear all done in constant time

#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int info;
	struct node *prev,*next;
}NODE;

typedef struct deque
{
	NODE *front,*rear;
}DEQUE;

void initQueue(DEQUE* pq);
//Precondition:Queue is created
void enqueueFront(DEQUE* pq,int ele);
//Precondition:Queue is created
void enqueueRear(DEQUE* pq,int ele);
int isEmpty(DEQUE*pq);
//Precondition:Queue is created and not empty
int dequeueFront(DEQUE* pq);
//Precondition:Queue is created and not empty
int dequeueRear(DEQUE* pq);
void display(DEQUE* pq);
void destroyQueue(DEQUE* pq);

int main()
{
	struct deque qobj;
	initQueue(&qobj);
	
	int choice,ele;

	do
	{
		printf("1.EnqueueFront 2.EnqueueRear 3.DequeueFront 4.DequeueRear 5.Display 6.EXIT\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("Enter the element\n");
					scanf("%d",&ele);
					enqueueFront(&qobj,ele);
					break;
			case 2:printf("Enter the value\n");
					scanf("%d",&ele);
					enqueueRear(&qobj,ele);
					break;					
			case 3:if(!isEmpty(&qobj))
						printf("Deleted element:%d\n",dequeueFront(&qobj));
					else
						printf("Already Empty Queue\n");
					break;
			case 4:if(!isEmpty(&qobj))
						printf("Deleted element:%d\n",dequeueRear(&qobj));
					else
						printf("Already Empty Queue\n");
					break;
			case 5: display(&qobj);
					break;
		}
	}while(choice<6);
	destroyQueue(&qobj);
	return 0;
}

void initQueue(DEQUE* pq)
{
	pq->front=pq->rear=NULL;
}

void enqueueFront(DEQUE* pq,int ele)
{
	NODE *newNode=malloc(sizeof(NODE));
	newNode->info=ele;
	newNode->prev=NULL;
	newNode->next=NULL;

	if(isEmpty(pq))
	{
		pq->front=pq->rear=newNode;
		return;
	}	
	newNode->next=pq->front;
	pq->front->prev=newNode;
	pq->front=newNode;
}
void enqueueRear(DEQUE* pq,int ele)
{
	NODE *newNode=malloc(sizeof(NODE));
	newNode->info=ele;
	newNode->prev=NULL;
	newNode->next=NULL;
	
	if(isEmpty(pq))
	{
		pq->front=pq->rear=newNode;
		return;
	}
	newNode->prev=pq->rear;
	pq->rear->next=newNode;
	pq->rear=newNode;
}
int isEmpty(DEQUE* pq)
{
	return pq->front==NULL;
}
int dequeueFront(DEQUE* pq)
{
	int ele=pq->front->info;
	if(pq->front==pq->rear)
	{
		free(pq->front);
		pq->front=pq->rear=NULL;
	}
	else
	{
		pq->front=pq->front->next;
		free(pq->front->prev);
		pq->front->prev=NULL;
	}
	return ele;
}
int dequeueRear(DEQUE* pq)
{
	int ele=pq->rear->info;
	if(pq->front==pq->rear)
	{
		free(pq->rear);
		pq->front=pq->rear=NULL;
	}
	else
	{
		pq->rear=pq->rear->prev;
		free(pq->rear->next);
		pq->rear->next=NULL;
	}
	return ele;
}

void display(DEQUE* pq)
{
	NODE *p=pq->front;
	
	if(pq->front==NULL)
	{
		printf("Empty Queue\n");
		return;
	}
	while(p!=NULL)
	{
		printf("%d ",p->info);
		p=p->next;
	}
	printf("\n");
}
void destroyQueue(DEQUE* pq)
{
	NODE *p=pq->front;

	while(p!=pq->rear)
	{
		printf("%d freed\n",p->info);
		p=p->next;
		free(p->prev);
	}
	printf("%d freed\n",p->info);
	free(p);
	pq->front=pq->rear=NULL;
}