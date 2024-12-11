#include<stdio.h>
#include<stdlib.h>
#include"stackDynamicAr.h"

void initStack(STACK *ps,int n)
{
	ps->top=-1;
	ps->size=n;
	ps->s=malloc(ps->size*sizeof(int));
}

int isFull(STACK *ps)
{
	return ps->top == ps->size-1;
}

int isEmpty(STACK *ps)
{
	return ps->top == -1;
}

//precondition: Stack is not full
void push(STACK *ps,int ele)
{
	if(isFull(ps))
		doubleStackSize(ps);
	ps->top++;
	ps->s[ps->top]=ele;
	
	//ps->s[++ps->top]=ele;
}

//precondition:Stack is not empty
int pop(STACK *ps)
{
	int poppedEle=ps->s[ps->top];
	ps->top--;
	return poppedEle;
	
	//return ps->s[ps->top--];
}

//precondition:Stack is not empty
int stackTop(STACK *ps)
{
	return ps->s[ps->top];
}
void display(STACK *ps)
{
	if(isEmpty(ps))
		printf("Empty Stack\n");
	else
	{
		for(int i=ps->top;i>=0;i--)
			printf("%d ",ps->s[i]);
		printf("\n");
	}
}
void doubleStackSize(STACK *ps)
{
	ps->size=ps->size*2;
	ps->s=realloc(ps->s,ps->size*sizeof(int));
}
void destroyStack(STACK *ps)
{
	free(ps->s);
	ps->top=-1;
	ps->size=0;
}
