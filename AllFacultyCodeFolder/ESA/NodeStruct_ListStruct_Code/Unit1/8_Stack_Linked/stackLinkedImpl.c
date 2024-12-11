#include<stdio.h>
#include<stdlib.h>
#include"stackLinked.h"

void initStack(STACK *ps)
{
	ps->top=NULL;
}
NODE* createNode(int ele)
{
	NODE *newNode=malloc(sizeof(NODE));
	newNode->info=ele;
	newNode->next=NULL;
	
	return newNode;
}

void push(STACK *ps,int ele)
{
	NODE *newNode=createNode(ele);
	
	newNode->next=ps->top;
	ps->top=newNode;
}
int isEmpty(STACK *ps)
{
	return ps->top==NULL;
}
//Precondition:Stack is not empty
int pop(STACK *ps)
{
	NODE *p=ps->top;
	
	int poppedEle=ps->top->info;	//int poppedEle=p->info;
	ps->top=ps->top->next;	//ps->top=p->next;
	free(p);
	
	return poppedEle;
}
int stackTop(STACK *ps)	//peek,peep
{
	return ps->top->info;
}
void display(STACK *ps)
{
	if(ps->top == NULL)
		printf("Stack is Empty\n");
	else
	{
		NODE *p=ps->top;
		
		while(p!=NULL)
		{
			printf("%d ",p->info);
			p=p->next;
		}
		printf("\n");
	}
}
void destroyStack(STACK *ps)
{
	NODE *p=ps->top;
	
	while(ps->top!=NULL)
	{
		p=ps->top;
		printf("%d freed\n",p->info);
		ps->top=ps->top->next;
		free(p);
	}
}