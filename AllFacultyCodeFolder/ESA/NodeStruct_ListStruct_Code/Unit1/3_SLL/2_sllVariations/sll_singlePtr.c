#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int info;
	struct node *next;
}NODE;

NODE* initList(NODE *head);
NODE* insertFront(NODE *head,int ele);
void display(NODE *head);
NODE* destroyList(NODE *head);

int main()
{
	NODE *head;
	head=initList(head);
	
	head=insertFront(head,200);
	head=insertFront(head,100);
	
	display(head);
	
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
	NODE* newNode=createNode(ele);
	
	newNode->next=head;
	head=newNode;
	
	return head;
}
void display(NODE *head)
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
	
	while(head!=NULL)
	{
		head=head->next;
		printf("%d freed\n",p->info);
		free(p);
		p=head;
	}
	return head;
}