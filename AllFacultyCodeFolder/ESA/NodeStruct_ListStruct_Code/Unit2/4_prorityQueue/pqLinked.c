//Ascending Priority Queue
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
	NODE *head;
}QUEUE;

void initQueue(QUEUE *pq);
void enqueue(QUEUE *pq,int ele,int pri);
//void display(QUEUE *pq);
void destroyQueue(QUEUE *pq);
void dequeue(QUEUE *pq,int *ele,int *pri);

int main()
{
	QUEUE qobj;
	
	initQueue(&qobj);
	enqueue(&qobj,20,20);
	enqueue(&qobj,30,30);
	enqueue(&qobj,25,25);
	enqueue(&qobj,10,10);
	
	int ele,pri;
	if(qobj.head!=NULL)
	{
		dequeue(&qobj,&ele,&pri);
		printf("Deqd info %d,priority %d\n",ele,pri);
	}
	
	if(qobj.head!=NULL)
	{
		dequeue(&qobj,&ele,&pri);
		printf("Deqd info %d,priority %d\n",ele,pri);
	}
	
//	display(&qobj);
	destroyQueue(&qobj);
}

void initQueue(QUEUE *pq)
{
	pq->head=NULL;
}

NODE* createNode(int ele,int pri)
{
	NODE *newNode=malloc(sizeof(NODE));
	newNode->info=ele;
	newNode->priority=pri;
	newNode->next=NULL;
	
	return newNode;
}

void enqueue(QUEUE *pq,int ele,int pri)
{
	NODE *newNode=createNode(ele,pri);
	
	NODE *p=pq->head;
	NODE *q=NULL;
	
	while(p!=NULL && p->priority < newNode->priority)
	{
		q=p;
		p=p->next;
	}
	if(q==NULL)	//node to be inserted is the first node
	{
		newNode->next=pq->head;	//newNode->next=p;
		pq->head=newNode;
	}
	else	//node to be inserted is in middle or at the end
	{
		newNode->next=p;
		q->next=newNode;
	}
}
/* 
void display(QUEUE *pq)
{
	if(pl->head==NULL)
	{
		printf("Empty List\n");
	}
	else
	{
		NODE *p=pl->head;
		
		while(p!=NULL)
		{
			printf("%d ",p->info);
			p=p->next;
		}
	}
	printf("\n");
} 
*/
void destroyQueue(QUEUE *pq)
{
	NODE *p;
	
	while(pq->head!=NULL)
	{
		p=pq->head;
		pq->head=pq->head->next;
//		printf("%d freed\n",p->info);
		free(p);
	}
}

//pq is pointing to a non empty queue
void dequeue(QUEUE *pq,int *ele,int *pri)
{
	NODE *p=pq->head;
	*ele=p->info;
	*pri=p->priority;
	
	pq->head=pq->head->next;
	free(p);
}