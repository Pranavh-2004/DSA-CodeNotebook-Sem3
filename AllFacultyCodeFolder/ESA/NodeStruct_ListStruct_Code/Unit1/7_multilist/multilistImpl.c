#include<stdio.h>
#include<stdlib.h>
#include"multilist.h"

void initList(LIST **ppl)
{
	*ppl=NULL;
}
void createList(LIST **ppl)
{
	int row=0,choice;
	LIST *p=*ppl;
	
	do
	{
		printf("Row %d added\n",row);
		
		LIST *newNode=malloc(sizeof(LIST));
		newNode->down=NULL;
		newNode->head=NULL;
		newNode->tail=NULL;
		
		if(*ppl==NULL)
		{
			*ppl=newNode;
			p=newNode;
		}
		else
		{
			p->down=newNode;
			p=newNode;	//p=p->down;
		}
		
		printf("Do you want to add one more row\n");
		scanf("%d",&choice);
		row++;
	}while(choice);
	
	row=0;
	p=*ppl;
	
	while(p!=NULL)
	{
		printf("Do you want to add entry to row %d\n",row);
		scanf("%d",&choice);
		
		while(choice)
		{
			NODE *newNode=malloc(sizeof(NODE));
			printf("Enter the column num and value\n");
			scanf("%d%d",&newNode->col,&newNode->val);
			newNode->next=NULL;
			
			if(p->head==NULL)
			{
				p->head=newNode;
				p->tail=newNode;
			}
			else
			{
				p->tail->next=newNode;
				p->tail=newNode;	//p->tail=p->tail->next;
			}
			printf("Do you want to add one more entry to row %d\n",row);
			scanf("%d",&choice);
		}
		p=p->down;
		row++;
	}
}
void displayList(LIST **ppl)
{
	LIST *p=*ppl;
	NODE *q;
	int row=0;
	while(p!=NULL)
	{
		q=p->head;
		printf("Row %d\n",row);
		while(q!=NULL)
		{
			printf("ColNum:%d,Value:%d\n",q->col,q->val);
			q=q->next;
		}
		row++;
		p=p->down;
	}
	
}