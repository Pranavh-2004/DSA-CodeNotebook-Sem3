//Ascending Priority Queue using Linked approach
//Enqueue: Ordered insertion O(n), Dequeue: DeleteFront O(1)

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int info;
	int priority;
	struct node *next;
}NODE;

int isEmpty(NODE *head);
NODE* enqueue(NODE *head,int ele,int pri);
//Precondition: Queue is not empty
NODE* dequeue(NODE *head,int *ele,int *pri);
void display(NODE *head);
NODE* destroyQueue(NODE *head);

int main()
{
	NODE *head=NULL;	//Priority queue is initialized to be empty
	int choice,ele,pri;
	
	do
	{
		printf("1.Enqueue 2.Dequeue 3.Display\n");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:	printf("Enter an integer\n");
					scanf("%d",&ele);
					printf("Enter priority\n");
					scanf("%d",&pri);
					head=enqueue(head,ele,pri);
					break;
			case 2:if(isEmpty(head)==0)
					{
						head=dequeue(head,&ele,&pri);
						printf("Dequeued element info %d,priority %d\n",ele,pri);
					}
					else
						printf("Queue is already empty\n");
					break;
			case 3:display(head);
					break;
		}
		
	}while(choice<4);
	head=destroyQueue(head);
}

int isEmpty(NODE *head)
{
	return head==NULL;
}

NODE* enqueue(NODE *head,int ele,int pri)
{
	NODE *newNode=malloc(sizeof(NODE));
	newNode->info=ele;
	newNode->priority=pri;
	newNode->next=NULL;
	
	NODE *p=head,*q=NULL;
	
	while(p!=NULL && p->priority < pri)
	{
		q=p;
		p=p->next;
	}
	if(q==NULL)	//insertion as first node if(p==head)
	{
		newNode->next=head;
		head=newNode;
	}
	else	//insertion at intermediate or end position
	{
		newNode->next=p;
		q->next=newNode;
	}
	
	return head;
}
//Precondition: Queue is not empty
NODE* dequeue(NODE *head,int *ele,int *pri)
{
	NODE *p=head;
	*ele=p->info;
	*pri=p->priority;
	
	head=head->next;
	free(p);
	
	return head;
}
void display(NODE *head)
{
	if(head==NULL)
		printf("Empty Queue\n");
	else
	{
		while(head!=NULL)
		{
			printf("Info:%d Priority:%d\n",head->info,head->priority);
			head=head->next;
		}
	}
}

NODE* destroyQueue(NODE *head)
{
	NODE *p=head;
	
	while(head!=NULL)
	{
		head=head->next;
		printf("freed Node info:%d priority:%d\n",p->info,p->priority);
		p=head;
	}
	return head;
}