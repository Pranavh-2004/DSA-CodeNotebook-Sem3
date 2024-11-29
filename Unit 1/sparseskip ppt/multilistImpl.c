#include<stdio.h>
#include<stdlib.h>
#include"multilist.h"

void initList(LIST **pl)
{
	*pl=NULL;
}
void createList(LIST **pl)
{
	LIST *p=*pl;
	
	int row=0;
	int choice;
	
	printf("Row 0 added\n");
	do{
		LIST *newNode=malloc(sizeof(LIST));
		newNode->down=NULL;
		newNode->head=NULL;
		newNode->tail=NULL;		
		
		if(*pl==NULL)
		{
			*pl=newNode;
			p=newNode;
		}
		else
		{
			p->down=newNode;
			p=p->down;
		}
		row++;
		printf("Do you want to add row %d\n",row);
		scanf("%d",&choice);
	}while(choice);
	
	p=*pl;
	row=0;
	while(p!=NULL)
	{
		printf("Do you want to add elements to row%d\n",row);
		scanf("%d",&choice);
		
		if(choice)
		{
			do
			{
				NODE *newNode=malloc(sizeof(NODE));
				printf("Enter the col no and element\n");
				scanf("%d%d",&newNode->col,&newNode->value);
				newNode->next=NULL;
				
				if(p->head==NULL)
				{
					p->head=newNode;
					p->tail=newNode;
				}
				else
				{
					p->tail->next=newNode;
					p->tail=newNode;
				}
				printf("Do you want to add elements to row%d\n",row);
				scanf("%d",&choice);
			}while(choice);
		}
		p=p->down;
		row++;
	}
}
void display(LIST **pl)
{
	LIST *p=*pl;
	
	int row=0;
	while(p!=NULL)
	{
		NODE *q=p->head;
		printf("\nRow %d:",row);
		while(q!=NULL)
		{
			printf("%d %d",q->col,q->value);
			q=q->next;
		}
		p=p->down;
		row++;
	}
}