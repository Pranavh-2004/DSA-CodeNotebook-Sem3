#include<stdio.h>
#include"deqLinked.h"

int main()
{
	QUEUE qobj;
	
	initQueue(&qobj);
	
	int ele,choice,status;
	
	do
	{
		printf("1.EnqueueFront 2.EnqueueRear 3.DequeueFront 4.DequeueRear 5.Display\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("Enter the integer data\n");
					scanf("%d",&ele);
					enqueueFront(&qobj,ele);
					break;
			case 2: printf("Enter the integer data\n");
					scanf("%d",&ele);
					enqueueRear(&qobj,ele);
					break;
			case 3:if(isEmpty(&qobj))
						printf("Queue is already empty\n");
					else
					{
						ele=dequeueFront(&qobj);
						printf("Deqd %d\n",ele);
					}
					break;
			case 4:if(isEmpty(&qobj))
						printf("Queue is already empty\n");
					else
					{
						ele=dequeueRear(&qobj);
						printf("Deqd %d\n",ele);
					}
					break;
			case 5:display(&qobj);
					break;
		}
	}while(choice<6);
	destroyQueue(&qobj);
}