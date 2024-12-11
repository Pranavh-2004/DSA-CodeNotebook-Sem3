#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int info;
	struct node *next;
}NODE;

int isEmpty(NODE *front);	//int isEmpty(NODE *rear);
//Precondition: Queue is already created
void enqueue(NODE **front,NODE **rear,int ele);
//Precondition: Queue is already created and not empty
int dequeue(NODE **front,NODE **rear);
void display(NODE* front);
void destroyQueue(NODE **front,NODE **rear);

int main()
{
	NODE *front=NULL,*rear=NULL;//Queue is initialized to be empty
	
	int choice,ele;
	
	do
	{
		printf("1.Enqueue 2.Dequeue 3.Display\n");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:	printf("Enter an integer\n");
					scanf("%d",&ele);
					enqueue(&front,&rear,ele);
					break;
			case 2:if(isEmpty(front)==0)
					{
						ele=dequeue(&front,&rear);
						printf("Dequeued element is %d\n",ele);
					}
					else
						printf("Queue is already empty\n");
					break;
			case 3:display(front);
					break;
		}
		
	}while(choice<4);
	destroyQueue(&front,&rear);
}

int isEmpty(NODE *rear)	//int isEmpty(NODE *front);
{
	return rear==NULL;		//return front==NULL;
}
//Precondition: Queue is already created
void enqueue(NODE **front,NODE **rear,int ele)
{
	NODE *newNode=malloc(sizeof(NODE));
	newNode->info=ele;
	newNode->next=NULL;
	
	if(*rear==NULL)
	{
		*front=*rear=newNode;
	}
	else
	{
		(*rear)->next=newNode;
		(*rear)=newNode;	//(*rear)=(*rear)->next;
	}
}
//Precondition: Queue is already created and not empty
int dequeue(NODE **front,NODE **rear)
{
	int deqdEle=(*front)->info;
	
	if(*front==*rear)
	{
		free(*front);
		*front=*rear=NULL;
	}
	else
	{
		NODE *p=(*front);
		(*front)=(*front)->next;	//(*front)=p->next;
		free(p);
	}
	return deqdEle;
}
void display(NODE* front)
{
	if(front==NULL)
		printf("Empty Queue\n");
	else
	{
		while(front!=NULL)
		{
			printf("%d ",front->info);
			front=front->next;
		}
		printf("\n");
	}
}
void destroyQueue(NODE **front,NODE **rear)
{
	NODE *p=*front;
	
	while(*front!=NULL)
	{
		*front=(*front)->next;
		printf("%d freed\n",p->info);
		free(p);
		p=*front;
	}
	*rear=NULL;
}