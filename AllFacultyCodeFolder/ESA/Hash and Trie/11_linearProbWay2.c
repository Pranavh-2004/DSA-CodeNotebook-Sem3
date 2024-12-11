//Store student records in a hash table of size 7
//Hash function: h(key)=key%tableSize
//Collision Resolution: Linear probing or closed hashing or open addressing

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 7

typedef struct element
{
	int rNo;
	char name[30];
	int mark;
}NODE;

void initTable(NODE ht[SIZE],int *n);
int insertRecord(NODE ht[SIZE],int rollNo,char name[],int *n);
int deleteRecord(NODE ht[SIZE],int rollNo,int *n);
int searchRecord(NODE ht[SIZE],int rollNo,char name[],int n);
void displayTable(NODE ht[SIZE]);

int main()
{
	NODE ht[SIZE];	//Hash table is created
	int n;
	
	initTable(ht,&n);	//Hash table set to be empty
	
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
					status=insertRecord(ht,rollNo,name,&n);
					if(status==0)
						printf("Table already full\n");
					break;
			case 2:printf("Enter roll number\n");
					scanf("%d",&rollNo);
					status=deleteRecord(ht,rollNo,&n);
					if(status==0)
						printf("Record not found\n");
					break;
			case 3:printf("Enter roll number\n");
					scanf("%d",&rollNo);
					status=searchRecord(ht,rollNo,name,n);
					if(status)
						printf("Record found, name is %s\n",name);
					else
						printf("Record not found\n");
					break;
			case 4:displayTable(ht);
					break;
		}
	}while(choice<5);
}

void initTable(NODE ht[SIZE],int *n)
{
	for(int i=0;i<SIZE;i++)
		ht[i].mark=-1;
	
	(*n)=0;
}

int hashFunction(int key)
{
	return key%SIZE;
}

int insertRecord(NODE ht[SIZE],int rollNo,char name[],int *n)
{
	if(*n==SIZE)
		return 0;
	
	int index=hashFunction(rollNo);	//generate hash index
	
	while(ht[index].mark!=-1)	//while a vacant spot is not found
	{
		index=(index+1)%SIZE;	//collision resolution
	}
		
	ht[index].rNo=rollNo;
	strcpy(ht[index].name,name);
	ht[index].mark=1;	
	(*n)++;
	
	return 1;
}
int deleteRecord(NODE ht[SIZE],int rollNo,int *n)
{
	if(*n==0)
		return 0;
		
	int index=hashFunction(rollNo);
	
	int count=0;
	
	while(count < *n && ht[index].rNo!=rollNo)
	{
		if(ht[index].mark!=-1)
			count++;
		index=(index+1)%SIZE;
	}
	
	if(ht[index].mark == 1 && ht[index].rNo==rollNo)
	{
		ht[index].mark=-1;
		(*n)--;
		return 1;
	}
	
	return 0;
}
int searchRecord(NODE ht[SIZE],int rollNo,char name[],int n)
{
	if(n==0)
		return 0;
		
	int index=hashFunction(rollNo);
	
	int count=0;
	
	while(count < n && ht[index].rNo!=rollNo)
	{
		if(ht[index].mark!=-1)
			count++;
		index=(index+1)%SIZE;
	}
	
	if(ht[index].mark == 1 && ht[index].rNo==rollNo)
	{
		strcpy(name,ht[index].name);
		return 1;
	}
	
	return 0;
}
void displayTable(NODE ht[SIZE])
{
	for(int i=0;i<SIZE;i++)
	{
		if(ht[i].mark==1)
			printf("ht[%d]:%d %s\n",i,ht[i].rNo,ht[i].name);
		else
			printf("ht[%d]:\n",i);
	}
	
}