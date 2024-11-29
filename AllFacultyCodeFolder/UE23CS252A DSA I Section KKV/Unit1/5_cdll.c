#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	struct node *prev;
	int info;
	struct node *next;
}NODE;

NODE* initList(NODE *head);
NODE* insertFront(NODE *head,int ele,int *pstatus);
NODE* insertLast(NODE *head,int ele,int *pstatus);
void displayList(NODE *head);
NODE* destroyList(NODE* head);
NODE* deleteFront(NODE *head,int *pele,int *pstatus);
NODE* deleteLast(NODE *head,int *pele,int *pstatus);
NODE* insertAtPos(NODE *head,int pos,int ele,int *pstatus);
NODE* deleteAtPos(NODE *head,int pos,int *pele,int *pstatus);

int main()
{
	NODE *head;
	
	head=initList(head);
	
	int choice,status,ele,pos;
	
	printf("1.InsertFront 2.InsertLast 3.Display 4.DeleteFront");
	printf("5.DeleteLast 6.InsertAtPos 7.DeleteAtPos\n");
	scanf("%d",&choice);
	do
	{
		switch(choice)
		{
			case 1:printf("Enter an integer\n");
					scanf("%d",&ele);
					head=insertFront(head,ele,&status);
					if(status==0)
						printf("InsertFront failed\n");
					break;
			case 2:printf("Enter an integer\n");
					scanf("%d",&ele);
					head=insertLast(head,ele,&status);
					if(status==0)
						printf("InsertFront failed\n");
					break;
			case 3:displayList(head);
					break;
			case 4:head=deleteFront(head,&ele,&status);
					if(status==0)
						printf("DeleteFront failed\n");
					else
						printf("Deleted element is %d\n",ele);
					break;
			case 5:head=deleteLast(head,&ele,&status);
					if(status==0)
						printf("DeleteLast failed\n");
					else
						printf("Deleted element is %d\n",ele);
					break;
			case 6:printf("Enter the position\n");
					scanf("%d",&pos);
					printf("Enter an integer\n");
					scanf("%d",&ele);
					head=insertAtPos(head,pos,ele,&status);
					if(status==0)
						printf("InsertAtPos failed\n");
					break;
			case 7:printf("Enter the position\n");
					scanf("%d",&pos);
					head=deleteAtPos(head,pos,&ele,&status);
					if(status==0)
						printf("DeleteAtPos failed\n");
					else
						printf("Deleted element is %d\n",ele);
					break;
		}
		printf("1.InsertFront 2.InsertLast 3.Display 4.DeleteFront");
		printf("5.DeleteLast 6.InsertAtPos 7.DeleteAtPos\n");
		scanf("%d",&choice);
	}while(choice<8);
	head=destroyList(head);
}

NODE* initList(NODE *head)
{
	head=NULL;
	return head;
}

NODE* insertFront(NODE *head,int ele,int *pstatus)
{
	NODE *newNode=malloc(sizeof(NODE));
	
	*pstatus=0;
	
	if(newNode!=NULL)
	{
		newNode->info=ele;
		
		if(head==NULL)
		{
			newNode->prev=newNode;
			newNode->next=newNode;
			head=newNode;
		}
		else
		{
			NODE *end=head->prev;
			
			newNode->prev=end;
			newNode->next=head;
			end->next=newNode;
			head->prev=newNode;
			
			head=newNode;
		}
		*pstatus=1;
	}
	return head;
}
NODE* insertLast(NODE *head,int ele,int *pstatus)
{
	NODE *newNode=malloc(sizeof(NODE));
	
	*pstatus=0;
	
	if(newNode!=NULL)
	{
		newNode->info=ele;
		
		if(head==NULL)
		{
			newNode->prev=newNode;
			newNode->next=newNode;
			head=newNode;
		}
		else
		{
			NODE *end=head->prev;
			
			newNode->prev=end;
			newNode->next=head;
			end->next=newNode;
			head->prev=newNode;
		}
		*pstatus=1;
	}
		return head;
}
void displayList(NODE *head)
{
	if(head==NULL)
		printf("Empty List");
	else
	{
		NODE *p=head;
		
		do
		{
			printf("%d ",p->info);
			p=p->next;
		}while(p!=head);
	}
	printf("\n");
}
NODE* destroyList(NODE* head)
{
	if(head!=NULL)
	{
		NODE *end=head->prev;
			
		while(head!=end)
		{
			printf("%d freed\n",head->info);
			head=head->next;
			free(head->prev);
		}
		printf("%d freed\n",head->info);
		free(head);
		head=NULL;
	}
	return head;
}
NODE* deleteFront(NODE *head,int *pele,int *pstatus)
{
	if(head==NULL)	//List empty case
	{
		*pstatus=0;
	}
	else if(head==head->next)	//Single node case
	{
		*pele=head->info;
		free(head);
		*pstatus=1;
		head=NULL;
		*pstatus=1;
	}
	else		//Multiple node case
	{
		NODE *end=head->prev;
		*pele=head->info;
		
		head=head->next;
		free(head->prev);
		head->prev=end;
		end->next=head;
		*pstatus=1;
	}
	return head;
}
NODE* deleteLast(NODE *head,int *pele,int *pstatus)
{
	if(head==NULL)	//List empty case
	{
		*pstatus=0;
	}
	else if(head==head->next)	//Single node case
	{
		*pele=head->info;
		free(head);
		*pstatus=1;
		head=NULL;
	}
	else		//Multiple node case
	{
		NODE *end=head->prev->prev;
		
		*pele=head->prev->info;
		
		head->prev=end;
		free(end->next);
		end->next=head;
		*pstatus=1;
	}
	return head;
}
int countNodes(NODE *head)
{
	int count=0;
	if(head!=NULL)
	{
		NODE *p=head;
		do
		{
			count++;
			p=p->next;
		}while(p!=head);
	}
	return count;
}
NODE* insertAtPos(NODE *head,int pos,int ele,int *pstatus)
{
	int n=countNodes(head);
	*pstatus=0;
	
	if(pos<0 || pos>n)
		*pstatus=0;
	else if(pos==0)
	{
		head=insertFront(head,ele,pstatus);
	}
	else if(pos==n)
	{
		head=insertLast(head,ele,pstatus);
	}
	else
	{
		NODE *newNode=malloc(sizeof(NODE));
		if(newNode!=NULL)
		{
			newNode->info=ele;
			NODE *p=head;
			
			for(int i=0;i<pos-1;i++)
				p=p->next;
			
			newNode->prev=p;
			newNode->next=p->next;
			newNode->next->prev=newNode;	//p->next->prev=newNode;
			p->next=newNode;
			*pstatus=1;
		}
	}
	return head;
}
NODE* deleteAtPos(NODE *head,int pos,int *pele,int *pstatus)
{
	int n=countNodes(head);
	*pstatus=0;
	
	if(pos<0 || pos>=n)
		*pstatus=0;
	else if(pos==0)
	{
		head=deleteFront(head,pele,pstatus);
	}
	else if(pos==n-1)
	{
		head=deleteLast(head,pele,pstatus);
	}
	else
	{
		NODE *p=head;
		
		for(int i=0;i<pos;i++)
			p=p->next;
		
		p->prev->next=p->next;
		p->next->prev=p->prev;
		*pele=p->info;
		free(p);
		*pstatus=1;
	}
	return head;
}