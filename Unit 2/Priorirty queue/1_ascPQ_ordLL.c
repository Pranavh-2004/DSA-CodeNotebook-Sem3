#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int info;
	int priority;
	struct node *next;
}NODE;

typedef struct queue
{
	NODE *front;
}QUEUE;

void initQueue(QUEUE *pq);
void enqueue(QUEUE *pq,int ele,int pri);
int dequeue(QUEUE *pq);				//MinDelete
void display(QUEUE *pq);
void destroyQueue(QUEUE *pq);



int main()
{
	QUEUE qobj;
	
	initQueue(&qobj);
	
	enqueue(&qobj,100,100);
	enqueue(&qobj,10,10);
	enqueue(&qobj,50,50);
	
	display(&qobj);
	
	printf("\n");
	if(qobj.front!=NULL)
		printf("Deqd %d\n",dequeue(&qobj));
	
	if(qobj.front!=NULL)
		printf("Deqd %d\n",dequeue(&qobj));
	
	destroyQueue(&qobj);
}




void initQueue(QUEUE *pq)
{
	pq->front=NULL;
}
void enqueue(QUEUE *pq,int ele,int pri)
{
	NODE *p=pq->front;
	NODE *q=NULL;
	
	NODE *newNode=malloc(sizeof(NODE));
	newNode->info=ele;
	newNode->priority=pri;
	newNode->next=NULL;
	
	while(p!=NULL && newNode->priority > p->priority)
	{
		q=p;
		p=p->next;
	}
	
	if(q==NULL)
	{
		newNode->next=p;
		pq->front=newNode;
	}
	else
	{
		newNode->next=p;
		q->next=newNode;
	}
}

int dequeue(QUEUE *pq)
{
	NODE *p=pq->front;
	
	int ele=p->info;
	
	pq->front=pq->front->next;
	free(p);
	
	return ele;
}
void display(QUEUE *pq)
{
	if(pq->front==NULL)
		printf("Empty QUEUE\n");
	else
	{
		NODE *p=pq->front;
		
		while(p!=NULL)
		{
			printf("Info=%d Priority=%d |",p->info,p->priority);
			p=p->next;
		}
	}
}

void destroyQueue(QUEUE *pq)
{
	NODE *p=pq->front;
	while(pq->front!=NULL)
	{
		pq->front=pq->front->next;
		printf("%d freed\n",p->info);
		free(p);
		p=pq->front;
	}
}