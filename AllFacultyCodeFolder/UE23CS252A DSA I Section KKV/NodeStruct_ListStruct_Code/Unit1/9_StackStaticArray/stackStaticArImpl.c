#include<stdio.h>
#include"stackStaticAr.h"

void initStack(STACK *ps)
{
	ps->top=-1;
}

int isFull(STACK *ps)
{
	return ps->top == MAX-1;
}

int isEmpty(STACK *ps)
{
	return ps->top == -1;
}

//precondition: Stack is not full
void push(STACK *ps,int ele)
{
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

