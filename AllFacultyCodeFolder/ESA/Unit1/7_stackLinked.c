#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int info;
	struct node *next;
}NODE;

int isEmpty(NODE *top);
//Precondition: Stack is already created and not full
NODE* push(NODE *top,int ele);
//Precondition: Stack is already created and not empty
int pop(NODE **top);
void display(NODE* top);
//Precondition: Stack is already created and not empty
int stackTop(NODE* top);	//int peek(NODE* top);
NODE* destroyStack(NODE *top);

int main()
{
	NODE* top=NULL;	//stack is initialized to be empty
	
	int choice,ele;
	
	do
	{
		printf("1.Push 2.Pop 3.Display 4.Peek\n");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:	printf("Enter an integer\n");
					scanf("%d",&ele);
					top=push(top,ele);
					break;
			case 2:if(isEmpty(top)==0)
					{
						ele=pop(&top);
						printf("Popped out element is %d\n",ele);
					}
					else
						printf("Stack underflow\n");
					break;
			case 3:display(top);
					break;
			case 4:if(isEmpty(top)==0)
					{
						ele=stackTop(top);
						printf("StackTop element is %d\n",ele);
					}
					else
						printf("Stack is already empty\n");
					break;
		}
		
	}while(choice<5);
	top=destroyStack(top);
}

int isEmpty(NODE *top)
{
	return top==NULL;
}
//Precondition: Stack is already created and not full
NODE* push(NODE *top,int ele)
{
	NODE *newNode=malloc(sizeof(NODE));
	
	newNode->info=ele;
	newNode->next=top;
	
	top=newNode;
	return top;
}

//Precondition: Stack is already created and not empty
int pop(NODE **top)
{
	NODE *p=*top;
	
	int poppedEle=p->info;	//int poppedEle=(*top)->info;
	*top=(*top)->next;		//*top=p->next;
	free(p);
	
	return poppedEle;
}
void display(NODE* top)
{
	if(top==NULL)
		printf("Empty Stack\n");
	else
	{
		while(top!=NULL)
		{
			printf("%d ",top->info);
			top=top->next;
		}
		printf("\n");
	}
}
//Precondition: Stack is already created and not empty
int stackTop(NODE* top)	//int peek(NODE* top);
{
	return top->info;
}
NODE* destroyStack(NODE *top)
{
	NODE *p=top;
	
	while(top!=NULL)
	{
		top=top->next;
		printf("%d freed\n",p->info);
		free(p);
		p=top;
	}
	return top;
}