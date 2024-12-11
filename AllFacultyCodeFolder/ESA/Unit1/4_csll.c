#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int info;
	struct node *next;
}NODE;

NODE* initList(NODE *last);
NODE* insertFront(NODE *last,int ele,int *pstatus);
NODE* insertLast(NODE *last,int ele,int *pstatus);
void displayList(NODE *last);
NODE* destroyList(NODE* last);
NODE* deleteFront(NODE *last,int *pele,int *pstatus);
NODE* deleteLast(NODE *last,int *pele,int *pstatus);
NODE* insertAtPos(NODE *last,int pos,int ele,int *pstatus);
NODE* deleteAtPos(NODE *last,int pos,int *pele,int *pstatus);

int main()
{
	NODE *last;
	
	last=initList(last);
	
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
					last=insertFront(last,ele,&status);
					if(status==0)
						printf("InsertFront failed\n");
					break;
			case 2:printf("Enter an integer\n");
					scanf("%d",&ele);
					last=insertLast(last,ele,&status);
					if(status==0)
						printf("InsertFront failed\n");
					break;
			case 3:displayList(last);
					break;
			case 4:last=deleteFront(last,&ele,&status);
					if(status==0)
						printf("DeleteFront failed\n");
					else
						printf("Deleted element is %d\n",ele);
					break;
			case 5:last=deleteLast(last,&ele,&status);
					if(status==0)
						printf("DeleteLast failed\n");
					else
						printf("Deleted element is %d\n",ele);
					break;
			case 6:printf("Enter the position\n");
					scanf("%d",&pos);
					printf("Enter an integer\n");
					scanf("%d",&ele);
					last=insertAtPos(last,pos,ele,&status);
					if(status==0)
						printf("InsertAtPos failed\n");
					break;
			case 7:printf("Enter the position\n");
					scanf("%d",&pos);
					last=deleteAtPos(last,pos,&ele,&status);
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
	last=destroyList(last);
}

NODE* initList(NODE *last)
{
	last=NULL;
	return last;
}

NODE* insertFront(NODE *last,int ele,int *pstatus)
{
	NODE *newNode=malloc(sizeof(NODE));
	
	*pstatus=0;
	
	if(newNode!=NULL)
	{
		newNode->info=ele;
		
		if(last==NULL)
		{
			newNode->next=newNode;
			last=newNode;
		}
		else
		{
			newNode->next=last->next;
			last->next=newNode;
		}
		*pstatus=1;
	}
	return last;
}
NODE* insertLast(NODE *last,int ele,int *pstatus)
{
	NODE *newNode=malloc(sizeof(NODE));
	
	*pstatus=0;
	
	if(newNode!=NULL)
	{
		newNode->info=ele;
		
		if(last==NULL)
		{
			newNode->next=newNode;
			last=newNode;
		}
		else
		{
			newNode->next=last->next;
			last->next=newNode;
			last=newNode;	//last=last->next;
		}
		*pstatus=1;
	}
	return last;
}
void displayList(NODE *last)
{
	if(last==NULL)
		printf("Empty List");
	else
	{
		NODE *p=last->next;
		
		do
		{
			printf("%d ",p->info);
			p=p->next;
		}while(p!=last->next);
	}
	printf("\n");
}
NODE* destroyList(NODE* last)
{
	if(last!=NULL)
	{
		NODE *p=last->next;
		
		while(p!=last)
		{
			last->next=p->next;
			printf("%d freed\n",p->info);
			free(p);
			p=last->next;
		}
		printf("%d freed\n",p->info);
		free(p);
		last=NULL;
	}
	return last;
}

NODE* deleteFront(NODE *last,int *pele,int *pstatus)
{
	if(last==NULL)	//List Empty Case
		*pstatus=0;
	else if(last==last->next)	//Single node case
	{
		*pele=last->info;
		free(last);
		last=NULL;
		*pstatus=1;
	}
	else		//Multiple node case
	{
		NODE *p=last->next;
		*pele=p->info;
		last->next=p->next;
		free(p);
		*pstatus=1;
	}
	return last;
}
NODE* deleteLast(NODE *last,int *pele,int *pstatus)
{
		if(last==NULL)	//List Empty Case
		*pstatus=0;
	else if(last==last->next)	//Single node case
	{
		*pele=last->info;
		free(last);
		last=NULL;
		*pstatus=1;
	}
	else		//Multiple node case
	{
		NODE *p=last->next;
		
		while(p->next!=last)
			p=p->next;
		
		*pele=last->info;
		p->next=last->next;
		free(last);
		last=p;
		*pstatus=1;
	}
	return last;
}
int countNodes(NODE *last)
{
	int count=0;
	
	if(last!=NULL)
	{
		NODE *p=last->next;
		do
		{
			count++;
			p=p->next;
		}while(p!=last->next);
	}
	return count;
}
NODE* insertAtPos(NODE *last,int pos,int ele,int *pstatus)
{
	int n=countNodes(last);
	*pstatus=0;
	
	if(pos<0 || pos>n)
		*pstatus=0;
	else if(pos==0)
	{
		last=insertFront(last,ele,pstatus);
	}
	else if(pos==n)
	{
		last=insertLast(last,ele,pstatus);
	}
	else
	{
		NODE *newNode=malloc(sizeof(NODE));
		if(newNode!=NULL)
		{
			newNode->info=ele;
			NODE *p=last->next;
			
			for(int i=0;i<pos-1;i++)
				p=p->next;
			
			newNode->next=p->next;
			p->next=newNode;
			
			*pstatus=1;
		}
	}
	return last;
}
NODE* deleteAtPos(NODE *last,int pos,int *pele,int *pstatus)
{
	int n=countNodes(last);
	*pstatus=0;
	
	if(pos<0 || pos>=n)
		*pstatus=0;
	else if(pos==0)
	{
		last=deleteFront(last,pele,pstatus);
	}
	else if(pos==n-1)
	{
		last=deleteLast(last,pele,pstatus);
	}
	else
	{
		NODE *p=last->next;
		NODE *q=last;
		
		for(int i=0;i<pos;i++)
		{
			q=p;
			p=p->next;
		}
		
		*pele=p->info;
		q->next=p->next;
		free(p);
		*pstatus=1;
	}
	return last;
}