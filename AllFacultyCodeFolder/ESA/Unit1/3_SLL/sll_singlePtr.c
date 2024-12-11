#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int info;
	struct node *next;
}NODE;

NODE* initList(NODE *head);
NODE* insertFront(NODE *head,int ele);
NODE* insertLast(NODE *head,int ele);
void displayList(NODE *head);
NODE* destroyList(NODE *head);

int main()
{
	NODE *head;
	
	head=initList(head);
	
	int choice,status,ele;
	
	printf("1.InsertFront 2.InsertLast 3.Display\n");
	scanf("%d",&choice);
	do
	{
		switch(choice)
		{
			case 1:printf("Enter an integer\n");
					scanf("%d",&ele);
					head=insertFront(head,ele);
					break;
			case 2:printf("Enter an integer\n");
					scanf("%d",&ele);
					head=insertLast(head,ele);
					break;
			case 3:displayList(head);
					break;
		}
		printf("1.InsertFront 2.InsertLast 3.Display\n");
		scanf("%d",&choice);
	}while(choice<4);
	head=destroyList(head);
}

NODE* initList(NODE *head)
{
	head=NULL;
	return head;
}


NODE* createNode(int ele)
{
	NODE *newNode=malloc(sizeof(NODE));
	newNode->info=ele;
	newNode->next=NULL;
	
	return newNode;
}

NODE* insertFront(NODE *head,int ele)
{
	NODE *newNode=createNode(ele);
	newNode->next=head;
	head=newNode;
	
	return head;
}
NODE* insertLast(NODE *head,int ele)
{
	NODE *newNode=createNode(ele);
	
	if(head==NULL)
	{
		head=newNode;
	}
	else
	{
		NODE *p=head;
		while(p->next!=NULL)
			p=p->next;
		
		p->next=newNode;
	}
	return head;
}
void displayList(NODE *head)
{
	if(head==NULL)
		printf("Empty List\n");
	else
	{
		NODE *p=head;
		
		while(p!=NULL)
		{
			printf("%d ",p->info);
			p=p->next;
		}
		printf("\n");
	}
}
NODE* destroyList(NODE *head)
{
	NODE *p=head;
	
	while(p!=NULL)	//while(head!=NULL)
	{
		head=head->next;
		printf("%d freed\n",p->info);
		free(p);
		p=head;
	}
	return head;
}