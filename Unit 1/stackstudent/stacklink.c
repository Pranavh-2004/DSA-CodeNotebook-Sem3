#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int info;
	struct node *next;
}NODE;

typedef struct stack
{
	NODE *top;
}STACK;

void initStack(STACK *ps);
int isEmpty(STACK *ps);
void push(STACK *ps,int ele);
int pop(STACK *ps);
int stackTop(STACK *ps);
void display(STACK *ps);
void destroyStack(STACK *ps);



int main()
{
	STACK sobj;
	
	initStack(&sobj);
	
	int choice;
	int ele;
	
	do{
		printf("1.Push 2.Pop 3.Display 4.StackTop/Peek 5.IsEmpty 6.exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("Enter an integer\n");
					scanf("%d",&ele);
					push(&sobj,ele);
					break;
			case 2: if(!isEmpty(&sobj))
					{
						ele=pop(&sobj);
						printf("Popped %d\n",ele);
					}
					else
						printf("Stack is empty\n");
					break;
			case 3:display(&sobj);
					break;
			case 4: if(!isEmpty(&sobj))
						printf("StackTop is %d\n",stackTop(&sobj));
					else 
						printf("Stack is Empty\n");
					break;
			case 5: if(isEmpty(&sobj))
						printf("Empty Stack\n");
					else
						printf("Stack is not empty\n");
					break;	
			case 6:exit(1);
			       break;
		}
	}while(choice<7);
	
	destroyStack(&sobj);
}




void initStack(STACK *ps)
{
	ps->top=NULL;
}

NODE* createNode(int ele)
{
	NODE* newNode=malloc(sizeof(NODE));
	
	newNode->info=ele;
	newNode->next=NULL;
	
	return newNode;
}
void push(STACK*ps,int ele)
{
	NODE* newNode=createNode(ele);
	
	newNode->next=ps->top;
	ps->top=newNode;	
}

void display(STACK* ps)
{
	if(ps->top==NULL)
		printf("Stack is Empty\n");
	else
	{
		NODE* p=ps->top;
		
		while(p!=NULL)
		{
			printf("%d ",p->info);
			p=p->next;
		}
		
	}
}
void destroyStack(STACK* ps)
{
	NODE *p;
	
	while(ps->top!=NULL)
	{
		p=ps->top;
		ps->top=ps->top->next;	//ps->top=p->next;
		printf("%d freed\n",p->info);
		free(p);
	}
}

/*precondition: Stack is not empty,
deleted ele info is returned back*/
int pop(STACK* ps)
{
	int delEle;
	NODE *p=ps->top;
	delEle=p->info;		//delEle=ps->top->info;
	ps->top=ps->top->next;
	free(p);
	return delEle;
}

int isEmpty(STACK *ps)
{
	return ps->top==NULL;
}

int stackTop(STACK *ps)
{
	return ps->top->info;

}