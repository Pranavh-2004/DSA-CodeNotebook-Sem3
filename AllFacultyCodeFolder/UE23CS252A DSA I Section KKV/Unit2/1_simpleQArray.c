//Implementation of a simple queue
//Not a space efficient approach
//Vacant space of the dequeued elements is not utilized again until 
//all the elements are dequeued

#include<stdio.h>
#define MAX 3

int isFull(int rear);
int isEmpty(int front,int rear);
//Precondition: Queue is already created and not full
void enqueue(int q[],int *rear,int ele);
//Precondition: Queue is already created and not empty
int dequeue(int q[],int *front,int *rear);
void display(int q[],int front,int rear);

int main()
{
	int q[MAX];
	int front=0,rear=-1;	//queue is initialized to be empty
	
	int choice,ele;
	
	do
	{
		printf("1.Enqueue 2.Dequeue 3.Display\n");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:if(isFull(rear)==0)
					{
						printf("Enter an integer\n");
						scanf("%d",&ele);
						enqueue(q,&rear,ele);
					}
					else
						printf("Queue is already full\n");
					break;
			case 2:if(isEmpty(front,rear)==0)
					{
						ele=dequeue(q,&front,&rear);
						printf("Dequeued element is %d\n",ele);
					}
					else
						printf("Queue is already empty\n");
					break;
			case 3:display(q,front,rear);
					break;
		}
		
	}while(choice<4);
}

int isFull(int rear)
{
	return rear==MAX-1;
}
int isEmpty(int front,int rear)
{
	return front>rear;	//return front==rear+1;
}
//Precondition: Queue is already created and not full
void enqueue(int q[],int *rear,int ele)
{
	++(*rear);
	q[*rear]=ele;
	
	//q[++(*rear)]=ele;
}
//Precondition: Queue is already created and not empty
int dequeue(int q[],int *front,int *rear)
{
	int deqdEle=q[*front];
	(*front)++;
	
	if(*front>*rear)
	{
		*front=0;
		*rear=-1;
	}
	return deqdEle;
	
	//return q[(*front)++];
}
void display(int q[],int front,int rear)
{
	if(front>rear)
		printf("Empty Queue\n");
	else
	{
		for(int i=front;i<=rear;i++)
			printf("%d ",q[i]);
		printf("\n");
	}
}