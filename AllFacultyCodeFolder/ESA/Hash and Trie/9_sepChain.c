//Store student records in a hash table of size 7
//Hash function: h(key)=key%tableSize
//Collision Resolution: Separate Chaining or Open hashing

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 7

typedef struct element
{
	int rNo;
	char name[30];
	struct element *next;
}NODE;

void initTable(NODE *ht[SIZE]);
void insertRecord(NODE *ht[SIZE],int rollNo,char name[]);
int deleteRecord(NODE *ht[SIZE],int rollNo);
int searchRecord(NODE *ht[SIZE],int rollNo,char name[]);
void displayTable(NODE *ht[SIZE]);
void destroyTable(NODE *ht[SIZE]);

int main()
{
	NODE *ht[SIZE];	//Hash table is created
	
	initTable(ht);	//Hash table set to be empty
	
	int choice,rollNo,status;
	char name[25];
	
	do
	{
		printf("1.Insert 2.Delete 3.Search 4.Display\n");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:printf("Enter roll number\n");
					scanf("%d",&rollNo);
					fflush(stdin);
					printf("Enter name\n");
					scanf("%[^\n]",name);
					insertRecord(ht,rollNo,name);
					break;
			case 2:printf("Enter roll number\n");
					scanf("%d",&rollNo);
					status=deleteRecord(ht,rollNo);
					if(status==0)
						printf("Record not found\n");
					break;
			case 3:printf("Enter roll number\n");
					scanf("%d",&rollNo);
					status=searchRecord(ht,rollNo,name);
					if(status)
						printf("Record found, name is %s\n",name);
					else
						printf("Record not found\n");
					break;
			case 4:displayTable(ht);
					break;
		}
	}while(choice<5);
	destroyTable(ht);
}

void initTable(NODE *ht[SIZE])
{
	for(int i=0;i<SIZE;i++)
		ht[i]=NULL;
}

int hashFunction(int key)
{
	return key%SIZE;
}

//InsertFront is used to insert records
void insertRecord(NODE *ht[SIZE],int rollNo,char name[])
{
	int index=hashFunction(rollNo);
	
	NODE *newNode=malloc(sizeof(NODE));
	newNode->rNo=rollNo;
	strcpy(newNode->name,name);
	newNode->next=ht[index];
	ht[index]=newNode;	
}

int deleteRecord(NODE *ht[SIZE],int rollNo)
{
	int index=hashFunction(rollNo);
	
	NODE *p=ht[index];
	NODE *q=NULL;
	
	while(p!=NULL && p->rNo!=rollNo)
	{
		q=p;
		p=p->next;
	}
	
	if(p!=NULL)	//Element present
	{
		if(q==NULL)	//Handling deletion of first element
		{
			ht[index]=p->next;
		}
		else	//Handling intermediate or last element deletion
		{
			q->next=p->next;
		}
		free(p);
		return 1;
	}
	return 0;
}
int searchRecord(NODE *ht[SIZE],int rollNo,char name[])
{
	int index=hashFunction(rollNo);
	
	NODE *p=ht[index];
	
	while(p!=NULL)
	{
		if(p->rNo==rollNo)
		{
			strcpy(name,p->name);
			return 1;
		}
		p=p->next;
	}
	return 0;
}
void displayTable(NODE *ht[SIZE])
{
	NODE *p=NULL;
	
	for(int i=0;i<SIZE;i++)
	{
		p=ht[i];
		printf("ht[%d]->",i);
		while(p!=NULL)
		{
			printf("%d %s ->",p->rNo,p->name);
			p=p->next;
		}
		printf("NULL\n");
	}
}
void destroyTable(NODE *ht[SIZE])
{
	NODE *p=NULL;
	for(int i=0;i<SIZE;i++)
	{
		p=ht[i];
		while(p!=NULL)
		{
			ht[i]=p->next;
			free(p);
			p=ht[i];
		}
	}
}