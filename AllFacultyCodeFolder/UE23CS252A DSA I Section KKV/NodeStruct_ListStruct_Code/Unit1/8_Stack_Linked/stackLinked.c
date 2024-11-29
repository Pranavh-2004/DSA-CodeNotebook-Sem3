#include<stdio.h>
#include"stackLinked.h"

int main()
{
	STACK sobj;
	
	initStack(&sobj);
	
	int choice,ele;
	
	printf("1.Push 2.Pop 3.display 4.StackTop\n");
	scanf("%d",&choice);
	
	do
	{
		switch(choice)
		{
			case 1:printf("Enter an integer\n");
					scanf("%d",&ele);
					push(&sobj,ele);
					break;
			case 2:if(isEmpty(&sobj))
						printf("Stack underflow\n");
					else
					{
						ele=pop(&sobj);
						printf("Popped %d\n",ele);
					}
					break;
			case 3:display(&sobj);
					break;
			case 4:if(isEmpty(&sobj))
						printf("Stack is Empty\n");
					else
					{
						ele=stackTop(&sobj);
						printf("Stack Top is %d\n",ele);
					}
					break;
			}
		printf("1.Push 2.Pop 3.display 4.StackTop\n");
		scanf("%d",&choice);	
	}while(choice<5);
	destroyStack(&sobj);
}