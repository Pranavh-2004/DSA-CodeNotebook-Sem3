//Array implementation of priority queue
#include<stdio.h>
#define MAX 4

typedef struct PriorityQueue
{
	int data;
	int priority;
}PQ;

int isFull(int n);
//Precondition: queue is created and not full
void enqueue(PQ q[],int *n,int ele,int pri);
int isEmpty(int n);
//Precondition: queue is created and not empty
PQ dequeue(PQ q[],int *n);
void display(PQ q[],int n);

int main()
{
	PQ q[MAX];
	int n=0;	//queue is initialized to be empty
	PQ delEle;
	
	int choice,ele,pri;
	
	do
	{
		printf("1.Enqueue 2.Dequeue 3.Display\n");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:if(isFull(n)==0)
					{
						printf("Enter an integer\n");
						scanf("%d",&ele);
						printf("Enter the priority\n");
						scanf("%d",&pri);
						enqueue(q,&n,ele,pri);
					}
					else
						printf("Queue is already full\n");
					break;
			case 2:if(isEmpty(n)==0)
					{
						delEle=dequeue(q,&n);
						printf("Dequeued element info:%d priority %d\n",delEle.data,delEle.priority);
					}
					else
						printf("Queue is already empty\n");
					break;
			case 3:display(q,n);
					break;
		}
		
	}while(choice<4);
}	

int isFull(int n)
{
	return n==MAX;
}

//Precondition: queue is created and not full
void enqueue(PQ q[],int *n,int ele,int pri)
{
	int i=*n-1;
	PQ key;
	
	key.data=ele;
	key.priority=pri;
	
	while(i>=0 && q[i].priority<pri)
	{
		q[i+1]=q[i];
		i--;
	}
	q[i+1]=key;
	(*n)++;
}

int isEmpty(int n)
{
	return n==0;
}

//Precondition: queue is created and not empty
PQ dequeue(PQ q[],int *n)
{
	int i=*n-1;
	
	PQ delEle=q[i];
	(*n)--;
	
	return delEle;
}
void display(PQ q[],int n)
{
	if(n==0)
	{
		printf("Empty Queue\n");
	}
	else
	{
		for(int i=0;i<n;i++)
		{
			printf("Data:%d Priority:%d\n",q[i].data,q[i].priority);
		}
	}
}