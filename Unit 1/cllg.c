#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int info;
	struct node *next;
}NODE;

typedef struct cll
{
	NODE* last;
}CLL;

void initList(CLL* pl);
void insertFront(CLL* pl,int ele);
void insertLast(CLL* pl,int ele);
void insertAtPos(CLL* pl,int ele,int pos);
void destroyList(CLL* pl);
void display(CLL* pl);
int deleteFront(CLL* pl,int *pele);
int deleteLast(CLL* pl,int *pele);
int deleteAtPos(CLL* pl,int *pele,int pos);



int main()
{
	CLL lobj;
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

void initList(CLL* pl)
{
	pl->last=NULL;
}
void insertFront(CLL* pl,int ele)
{
	NODE *temp=malloc(sizeof(NODE));
	temp->info=ele;
	
	if(pl->last==NULL)
	{
		temp->next=temp;
		pl->last=temp;
		return;
	}
	
	temp->next=pl->last->next;
	pl->last->next=temp;	
}

void insertLast(CLL* pl,int ele)
{
	NODE *temp=malloc(sizeof(NODE));
	temp->info=ele;
	
	if(pl->last==NULL)
	{
		temp->next=temp;
		pl->last=temp;
		return;
		
	}
	temp->next=pl->last->next;
	pl->last->next=temp;
	pl->last=temp;
    	

	
}
int deleteFront(CLL* pl,int *pe)
{
	
	if(pl->last==NULL) //list is empty
	{
		//printf("empty list\n");
		return 0;
	}
	
	//single node case
	if(pl->last==pl->last->next)
	{
		*pe=pl->last->info;
		free(pl->last);
		pl->last=NULL;
		return 1;		
	}
	//multinode
	NODE *p=pl->last->next;
	pl->last->next=p->next;
	*pe=p->info;
	free(p);
	return 1;
}

int deleteLast(CLL* pl,int *pe)
{
	
	if(pl->last==NULL) //list is empty
	{
		return 0;
	}
	
	//single node case
	if(pl->last==pl->last->next)
	{
		*pe=pl->last->info;
		free(pl->last);
		pl->last=NULL;
		return 1;
		
	}
	NODE *p=pl->last->next;
	while(p->next!=pl->last)
	{
		p=p->next;
		
	}
	p->next=pl->last->next;
	*pe=pl->last->info;
	free(pl->last);
	pl->last=p;
	return 1;
	
}

void display(CLL* pl)
{
	NODE *p;
	if(pl->last==NULL)
		printf("List is empty\n");
	else
	{
		p=pl->last->next;
		while(p!=pl->last)
		{
			printf("%d ",p->info);
			p=p->next;
		}
		printf("%d\n",p->info);
	}
	
	
}
int countNodes(CLL* pl)
{
	NODE *p;
	int count=0;
	if(pl->last==NULL)
	return count;
	else
	{
		p=pl->last->next;
		while(p!=pl->last)
		{
			count++;
			p=p->next;
		}
		count++;
		return count;
	}
}
 
void insertAtPos(CLL* pl,int ele,int pos)
{
	int n=countNodes(pl);
	
	if(pos<0 || pos>n)
		return ;
	if(pos==0)
	{
		insertFront(pl,ele);
		return ;
	}
	if(pos==n)
	{
		insertLast(pl,ele);
		return ;
	}
	
	NODE *temp=malloc(sizeof(NODE));
	temp->info=ele;
	
	NODE *p=pl->last;
	
	for(int i=0;i<pos;i++)
	{
		p=p->next;
		
	}
	temp->next=p->next;
	p->next=temp;
	
}
void destroyList(CLL* pl)
{
	NODE *p;
	if(pl->last==NULL)
		return;
	else
	{
		p=pl->last->next;
		
		while(p!=pl->last)	//while(p==pl->last->next)
		{
			pl->last->next=p->next;
			printf("%d freed\n",p->info);
			free(p);
			p=pl->last->next;
		}
		printf("%d freed\n",p->info);
		free(p);		//free(pl->last);
		pl->last=NULL;
	}
}
int deleteAtPos(CLL* pl,int *pe,int pos)
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
	
	NODE *p=pl->last->next;
	NODE *q=NULL;
	
	for(int i=0;i<pos;i++)
	{
		q=p;
		p=p->next;
	}
	
	q->next=p->next;
	*pe=p->info;
	free(p);
	return 1; 
	
	
}