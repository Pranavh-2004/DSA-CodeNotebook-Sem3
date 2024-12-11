#include<stdio.h>
#define MAX 3

typedef struct queue
{
	int info;
	int priority;
}QUEUE;

void enqueue(QUEUE pq[],int data,int pri,int *count);
QUEUE dequeue(QUEUE pq[],int *count);

int main()
{
	QUEUE pq[MAX];
	
	int data=100;
	int pri=100;
	
	int count=0;
	if(count!=MAX)
	{
		enqueue(pq,data,pri,&count);
	}
	
	data=200;
	pri=200;
	if(count!=MAX)
	{
		enqueue(pq,data,pri,&count);
	}
	
	data=150;
	pri=150;
	if(count!=MAX)
	{
		enqueue(pq,data,pri,&count);
	}
	
	QUEUE ele;
	if(count!=0)
	{
		ele=dequeue(pq,&count);
		printf("Deqd ele info:%d, priority=%d\n",ele.info,ele.priority);
	}
	
	if(count!=0)
	{
		ele=dequeue(pq,&count);
		printf("Deqd ele info:%d, priority=%d\n",ele.info,ele.priority);
	}
	
	if(count!=0)
	{
		ele=dequeue(pq,&count);
		printf("Deqd ele info:%d, priority=%d\n",ele.info,ele.priority);
	}
}

void enqueue(QUEUE pq[],int data,int pri,int *count)
{
	int i=(*count)-1;
	QUEUE key;
	key.info=data;
	key.priority=pri;
	
	while(i>=0 && key.priority < pq[i].priority)
	{
		pq[i+1]=pq[i];
		i--;
	}
	pq[i+1]=key;
	(*count)++;
}

QUEUE dequeue(QUEUE pq[],int *count)
{
	return pq[--(*count)];
}