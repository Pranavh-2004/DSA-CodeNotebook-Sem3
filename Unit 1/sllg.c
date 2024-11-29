#include<stdio.h>
#include<stdlib.h>


typedef struct node
{
	int info;
	struct node *next;
}NODE;

typedef struct llist
{
	NODE *head;
}LLIST;

void initList(LLIST *pl);
void insertFront(LLIST *pl,int ele);
void insertLast(LLIST *pl,int ele);
void insertAtpos(LLIST *pl,int ele,int pos);
void deleteAtpos(LLIST *pl,int *pe,int pos);
void deleteFront(LLIST *pl,int *pe);
void deleteLast(LLIST *pl,int *pe);
void display(LLIST *pl);
//void destroy(LLIST *pl);
//int searchkey(LLIST *pl,int ele);


int main()
{
	int choice,ele,pos;
	LLIST  lobj;
	initList(&lobj);
	do
	{
		printf("1.InsertFront 2.InsertLast 3.InsertatPos 4.Display 5.deleteFront 6.DeleteLast 7.DeleteAtpos 8.Destroy 9.searchkey 10.Exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("Enter an element\n");
			       scanf("%d",&ele);
				   insertFront(&lobj,ele);
				   break;
			case 2:printf("Enter an element\n");
			       scanf("%d",&ele);
				   insertLast(&lobj,ele);
				   break;
			case 3:printf("enter an element\n");
					scanf("%d",&ele);
					printf("enter the pos\n");
					scanf("%d",&pos);
					insertAtpos(&lobj,ele,pos);
					break;		
					
			case 4:display(&lobj);
					break;
			case 5:	deleteFront(&lobj,&ele);
					printf("Deleted element is %d\n",ele);
					break;
			case 6:	deleteLast(&lobj,&ele);
					printf("Deleted element is %d\n",ele);
					break;	
					
			case 7:	printf("enter the pos\n");
					scanf("%d",&pos);
					deleteAtpos(&lobj,&ele,pos);
					printf("Deleted element is %d\n",ele);
					break;
					/*
			case 8:	destroy(&lobj);
					break;
			case 9:printf("Enter search element\n");
			       scanf("%d",&ele);
				   pos=searchkey(&lobj,ele);
				   if(pos>-1)
					   printf("found at %d\n",pos);
				   else
					   printf("not found\n");
				   break;*/
			case 10:exit(1);		
					break;
				   
		}
	}while(choice<10);
	
	
	return 0; 
}

void initList(LLIST *pl)
{
	pl->head=NULL;
}

NODE* getNode(int ele)
{
	NODE *temp=malloc(sizeof(NODE));
	temp->info=ele;
	temp->next=NULL;
	return temp;
	
}

void insertFront(LLIST *pl,int ele)
{
	NODE *temp=getNode(ele);
	temp->next=pl->head;
	pl->head=temp;	
	
}

void insertLast(LLIST *pl,int ele)
{
	NODE *temp=getNode(ele);
	if(pl->head==NULL)
	{
		pl->head=temp;
	}
	
	NODE *p=pl->head;
	while(p->next!=NULL)
	{
		p=p->next;
		
	}
	p->next=temp;
	
}

void display(LLIST *pl)
{
	NODE *p=pl->head;
	if(pl->head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	
	while(p!=NULL)
	{
		printf("%d",p->info);
		p=p->next;
	}
	printf("\n");
	
}

void deleteFront(LLIST *pl,int *pe)
{
	NODE *p=pl->head;
	pl->head=p->next;
	*pe=p->info;
	free(p);
	
}

void deleteLast(LLIST *pl,int *pe)
{
	NODE *p=pl->head;
	NODE *q;
	if(p->next==NULL)
	{
		pl->head=NULL;
		*pe=p->info;
		free(p);
		
	}
	while(p->next!=NULL)
	{
		q=p;
		p=p->next;
	}
	q->next=NULL;
	*pe=p->info;
	free(p);
}

void insertAtpos(LLIST *pl,int ele,int pos)
{
	NODE *temp=getNode(ele);
	
	if(pos==0)
	{
		temp->next=pl->head;
		pl->head=temp;
		return;
	}
	
	NODE *p=pl->head;
	NODE *q=NULL;
	
	for(int i=0;i<pos;i++)
	{
		q=p;
		p=p->next;
	}
	
	q->next=temp;
	temp->next=p;
	
	
}

void deleteAtpos(LLIST *pl,int *pe,int pos)
{
	NODE *p=pl->head;
	NODE *q=NULL;
	if(pl->head==NULL)
		return;
	if(pos==0)
	{
		pl->head=p->next;
		*pe=p->info;
		free(p);
		return;
	}
		for(int i=0;i<pos;i++)
		{
			q=p;
			p=p->next;
		}
		
		q->next=p->next;
		*pe=p->info;
		free(p);
		return;
}