#include<stdio.h>
#define MAX 2

int isEmpty(int top);
int isFull(int top);
//Precondition: Stack is already created and not full
void push(int s[],int *top,int ele);
//Precondition: Stack is already created and not empty
int pop(int s[],int *top);
void display(int s[],int top);
//Precondition: Stack is already created and not empty
int stackTop(int s[],int top);	//int peek(int s[],int top);

int main()
{
	int s[MAX];
	int top=-1;	//stack is initialized to be empty
	
	int choice,ele;
	
	do
	{
		printf("1.Push 2.Pop 3.Display 4.Peek\n");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:if(isFull(top)==0)
					{
						printf("Enter an integer\n");
						scanf("%d",&ele);
						push(s,&top,ele);
					}
					else
						printf("Stack overflow\n");
					break;
			case 2:if(isEmpty(top)==0)
					{
						ele=pop(s,&top);
						printf("Popped out element is %d\n",ele);
					}
					else
						printf("Stack underflow\n");
					break;
			case 3:display(s,top);
					break;
			case 4:if(isEmpty(top)==0)
					{
						ele=stackTop(s,top);
						printf("StackTop element is %d\n",ele);
					}
					else
						printf("Stack is already empty\n");
					break;
		}
		
	}while(choice<5);
}

int isEmpty(int top)
{
	return top==-1;
}

int isFull(int top)
{
	return top==MAX-1;
}

//Precondition: Stack is already created and not full
void push(int s[],int *top,int ele)
{
	(*top)++;	//++(*top) or *top=(*top)+1
	s[*top]=ele;
	
	//Instead of the above 2 lines
//	s[++(*top)]=ele;
}

//Precondition: Stack is already created and not empty
int pop(int s[],int *top)
{
	int poppedEle=s[*top];
	(*top)--;		//--(*top) or (*top)=(*top)-1
	
	return poppedEle;
	
	//Instead of above 3 lines of code
//	return s[(*top)--];
}
void display(int s[],int top)
{
	if(top==-1)
		printf("Empty Stack\n");
	else
	{
		for(int i=top;i>=0;i--)
			printf("%d ",s[i]);
		printf("\n");
	}
}
//Precondition: Stack is already created and not empty
int stackTop(int s[],int top)	//int peek(int s[],int top);
{
	return s[top];
}