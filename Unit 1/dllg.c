#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	struct node *prev;
	int info;
	struct node* next;
}NODE;

typedef struct dlist
{
	NODE *head;
}DLIST;

void initList(DLIST *pdl);
void insertFront(DLIST *pdl,int ele);
void insertLast(DLIST *pdl,int ele);
void destroyList(DLIST *pdl);
void display(DLIST *pdl);
int deleteFront(DLIST *pdl,int *pe);
int deleteLast(DLIST *pdl,int *pe);
int insertAtPos(DLIST *pdl,int ele,int pos);
int deleteAtPos(DLIST *pdl,int *pe,int pos);



int main()
{
	DLIST lobj;
	
	initList(&lobj);
	int choice;
	int ele;
	int status;
	int pos;
	do
	{
		printf("1.Insert Front 2.Insert Last 3.Display\n");
		printf("4. Delete Front 5.Delete Last\n");
		printf("6.Insert At Pos 7. Delete at pos 8.Exit 9.Destroy\n");
		printf("enter the choice\n");
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
			case 3: display(&lobj);
					break;
			case 4: status=deleteFront(&lobj,&ele);
					if(status)
						printf("Del ele is %d\n",ele);
					else
						printf("List is already empty\n");
					break;
					
			case 5:status=deleteLast(&lobj,&ele);
					if(status)
						printf("Del ele is %d\n",ele);
					else
						printf("List is already empty\n");
					break;
					
			case 6:printf("Enter an integer\n");
					scanf("%d",&ele);
					printf("Enter the pos\n");
					scanf("%d",&pos);
					status=insertAtPos(&lobj,ele,pos);
					if(status==0)
						printf("Invalid position\n");
					break;
			case 7: printf("Enter the pos\n");
					scanf("%d",&pos);
					status=deleteAtPos(&lobj,&ele,pos);
					if(status)
						printf("Del ele is %d\n",ele);
					else
						printf("List is already empty or invalid pos\n");
					break;
			case 8:exit(1);		
					break;
			case 9:destroyList(&lobj);
					break;
		}
	}while(choice<10);
	//destroyList(&lobj);
}


void initList(DLIST *pdl)
{
	pdl->head=NULL;
}

NODE* getnode(int ele)
{
	NODE *temp=malloc(sizeof(NODE));
	temp->prev=NULL;
	temp->info=ele;
	temp->next=NULL;
	return temp;
}


void insertFront(DLIST *pdl,int ele)
{
	NODE *temp=getnode(ele);
	
	if(pdl->head==NULL)
	{
		pdl->head=temp;
		return;
	}
	
	temp->next=pdl->head;
	pdl->head->prev=temp;
	pdl->head=temp;
	
	
	
}

void insertLast(DLIST *pdl,int ele)
{
	
	NODE *temp=getnode(ele);
	
	if(pdl->head==NULL)
	{
		pdl->head=temp;
		return;
	}
	
	NODE *p=pdl->head;
	while(p->next!=NULL)
	{
		p=p->next;
		
	}
	
	
	p->next=temp;
	temp->prev=p;
	
	
}

void destroyList(DLIST *pdl)
{
	if(pdl->head==NULL)
		return;
	else
	{
		while(pdl->head->next!=NULL)
		{
			pdl->head=pdl->head->next;
			free(pdl->head->prev);
		}
		free(pdl->head);
		pdl->head=NULL;
	}
}

void display(DLIST *pdl)
{
	NODE *p=pdl->head;
	if(pdl->head==NULL)
		printf("List is empty\n");
	else
	{
		while(p!=NULL)
		{
			printf("%d ",p->info);
			p=p->next;
		}
	}
	
}
int deleteFront(DLIST *pdl,int *pe)
{
	if(pdl->head==NULL)
		return 0;
	
	NODE *p=pdl->head;
	pdl->head=p->next;
	
	*pe=p->info;
	free(p);
	
	if(pdl->head!=NULL)
		pdl->head->prev=NULL;
	return 1;
}

int deleteLast(DLIST *pdl,int *pe)
{
	if(pdl->head==NULL)
		return 0;
	
	NODE *p=pdl->head;
	if(p->next==NULL)
	{
		pdl->head=NULL;
		*pe=p->info;
		free(p);
		return 1;
	}
	
	while(p->next!=NULL)
	{
		p=p->next;
	}
	
	*pe=p->info;
	p->prev->next=NULL;
	free(p);
	return 1;
}

int countNodes(DLIST *pdl)
{
	NODE *p=pdl->head;
	int count=0;
	
	if(pdl->head==NULL)
		return count;
	else
	{
		while(p!=NULL)
		{
			count++;
			p=p->next;
		}
		return count;
	}
}
int insertAtPos(DLIST *pdl,int ele,int pos)
{
	int n=countNodes(pdl);
	
	if(pos<0 || pos>n)
		return 0;
	
	if(pos==0)
	{
		insertFront(pdl,ele);
		return 1;
	}
	
	if(pos==n)
	{
		insertLast(pdl,ele);
		return 1;
	}
	
	NODE *temp=getnode(ele);
	NODE *p=pdl->head;
	
	for(int i=0;i<pos;i++)
	{
		p=p->next;
	}
	
	
	temp->next=p;
	temp->prev=p->prev;
	p->prev->next=temp;
	p->prev=temp;
	
}


int deleteAtPos(DLIST *pdl,int *pe,int pos)
{
	int n=countNodes(pdl);
	
	if(pos<0 || pos>n)
		return 0;
	
	
	if(pos==0)
	{
		deleteFront(pdl,pe);
		return 1;
		
	}
	
	if(pos==n-1)
	{
		deleteLast(pdl,pe);
		return 1;
		
	}
	
	
	NODE *p=pdl->head;
	
	for(int i=0;i<pos;i++)
	{
		p=p->next;
	}
	
	p->prev->next=p->next;
	p->next->prev=p->prev;
	
	*pe=p->info;
	free(p);
	return 1;
	
}
