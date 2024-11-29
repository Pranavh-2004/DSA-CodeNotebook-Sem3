#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	struct node *prev;
	int info;
	struct node *next;
}NODE;

typedef struct cdll
{
	NODE* head;
}CDLL;

void initList(CDLL* pl);
void insertFront(CDLL* pl,int ele);
void insertLast(CDLL* pl,int ele);
void insertAtPos(CDLL* pl,int ele,int pos);
void destroyList(CDLL* pl);
void display(CDLL* pl);
int deleteFront(CDLL* pl,int *pe);
int deleteLast(CDLL* pl,int *pe);
int deleteAtPos(CDLL* pl,int *pe,int pos);

int main()
{
	CDLL lobj;
	initList(&lobj);
	int choice,ele,pos;
	
	do{
		printf("1.Insert Front 2.Insert Last 3.Insert At Pos 4.Display\n");
		printf("5.Delete Front 6.Delete Last 7.Delete At Pos\n");
		printf("Enter your choice\n");
		scanf("%d",&choice);
		
		switch(choice)
		{
				case 1:printf("Enter an integer\n");
						scanf("%d",&ele);
						insertFront(&lobj,ele);
						break;
				case 2:printf("Enter an integer\n");
						scanf("%d",&ele);
						insertLast(&lobj,ele);
						break;
				case 3:printf("Enter an integer\n");
						scanf("%d",&ele);
						printf("Enter the pos\n");
						scanf("%d",&pos);
						insertAtPos(&lobj,ele,pos);
							
						break;
				case 4: display(&lobj);
						break;
				case 5:if(deleteFront(&lobj,&ele))
							printf("Deleted ele is %d\n",ele);
						else
							printf("Deletion Failed\n");
						break;
				case 6:if(deleteLast(&lobj,&ele))
							printf("Deleted ele is %d\n",ele);
						else
							printf("Deletion Failed\n");
						break;
				case 7:	printf("Enter the pos\n");
						scanf("%d",&pos);
						if(deleteAtPos(&lobj,&ele,pos))
							printf("Deleted ele is %d\n",ele);
						else
							printf("Deletion Failed\n");
						break;
		}
	}while(choice<8);
	destroyList(&lobj);
	return 0;
}

void initList(CDLL* pl)
{
	pl->head=NULL;
}

void insertFront(CDLL* pl,int ele)
{
	NODE *temp=malloc(sizeof(NODE));
	temp->info=ele;
	
	if(pl->head==NULL)
	{
		temp->next=temp;
		temp->prev=temp;
		pl->head=temp;
		return;
	}
	
	NODE *last=pl->head->prev;
	
	temp->next=pl->head;
	temp->prev=pl->head->prev;
	last->next=temp;
	pl->head->prev=temp;
	pl->head=temp;
	
	
}
void insertLast(CDLL* pl,int ele)
{
	NODE *temp=malloc(sizeof(NODE));
	temp->info=ele;
	
	if(pl->head==NULL)
	{
		temp->next=temp;
		temp->prev=temp;
		pl->head=temp;
		return;
	}
	
	NODE *last=pl->head->prev;
	
	temp->prev=last;
	temp->next=pl->head;
	last->next=temp;
	pl->head->prev=temp;
	
}
int countNodes(CDLL* pl)
{
	if(pl->head==NULL)
		return 0;
	
	NODE  *p=pl->head;
	int count=0;
	   do
		{
			count++;
			p=p->next;
		}while(p!=pl->head);
		
		return count;
	
}

void insertAtPos(CDLL* pl,int ele,int pos)
{
	int n=countNodes(pl);
	if(pos<0 || pos>n)
		return;
	if(pos==0)
	{
		insertFront(pl,ele);
		return;
	}
	if(pos==n)
	{
		insertLast(pl,ele);
		return;
	}
	
	NODE *p=pl->head;
	for(int i=0;i<pos;i++)
	{
		p=p->next;
	}
	
	NODE *temp=malloc(sizeof(NODE));
	temp->info=ele;
	
	temp->next=p;
	temp->prev=p->prev;
	p->prev->next=temp;
	p->prev=temp;		
}

void destroyList(CDLL* pl)
{
	if(pl->head==NULL)
		return;
	    NODE *p=pl->head;
		NODE *last=pl->head->prev;
		while(pl->head!=last)
		{
			//printf("Freed %d\n",pl->head->info);
			pl->head=p->next;
			free(p);
			p=pl->head;
		}
		//printf("Freed %d\n",pl->head->info);
		free(pl->head);
		pl->head=NULL;
	
}
/* 
void destroyList(CDLL* pl)
{
	if(pl->head==NULL)
		return;
	else
	{
		NODE pl->head->prev->next=NULL;
		while(pl->head->next!=NULL)
		{
			pl->head=pl->head->next;
			free(pl->head->prev);
		}
		free(pl->head);
		pl->head=NULL;
	}
} */
void display(CDLL* pl)
{
	if(pl->head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	NODE *p=pl->head;
		do
		{
			printf("%d ",p->info);
			p=p->next;
		}while(p!=pl->head);
		printf("\n");
	
}
int deleteFront(CDLL* pl,int *pe)
{
	if(pl->head==NULL)
		return 0;
	
	NODE *last=pl->head->prev;
	if(pl->head==last)
	{
		*pe=pl->head->info;
	     free(pl->head);
		 pl->head=NULL;
		 return 1;
	}
	pl->head->next->prev=last;
	last->next=pl->head->next;	
	
	*pe=pl->head->info;
	free(pl->head);
	pl->head=last->next;
	return 1;
	
}

int deleteLast(CDLL* pl,int *pe)
{
	if(pl->head==NULL)
		return 0;
	
	NODE *last=pl->head->prev;
	
	if(pl->head==last)
	{
		*pe=pl->head->info;
	     free(pl->head);
		 pl->head=NULL;
		 return 1;
	}
		 
	*pe=last->info;
    last->prev->next=pl->head;
    pl->head->prev=last->prev;
    free(last);	
	return 1;
	
		
}
int deleteAtPos(CDLL* pl,int *pe,int pos)
{
	int n=countNodes(pl);
	if(pos<0 || pos>n)
		return 0;
	if(pos==0)
	{
		deleteFront(pl,pe);
		return 1;
	}
	if(pos==n-1)
	{
		deleteLast(pl,pe);
		return 1;
	}
	
	NODE *p=pl->head;
	for(int i=0;i<pos;i++)
	{
		p=p->next;
	}
	p->prev->next=p->next;
	p->next->prev=p->prev;
	
	*pe=p->info;
	free(p);

	
}