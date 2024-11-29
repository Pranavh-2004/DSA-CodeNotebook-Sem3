#include<stdio.h>
#include"sll.h"

int main()
{
	LIST lobj;
	
	initList(&lobj);
	
	int choice,status,ele,pos;
	
	printf("1.InsertFront 2.InsertLast 3.Display ");
	printf("4.DeleteFront 5.DeleteLast 6.InsertAtPos 7.DeleteAtPos\n");
	scanf("%d",&choice);
	do
	{
		switch(choice)
		{
			case 1:printf("Enter an integer\n");
					scanf("%d",&ele);
					insertFront(&lobj,ele);
					break;
			case 2:printf("Enter an integer\n");
					scanf("%d",&ele);
					insertLast(&lobj,ele);
					break;
			case 3:displayList(&lobj);
					break;
			case 4:status=deleteFront(&lobj,&ele);
					if(status==0)
						printf("Linked List is already empty\n");
					else
						printf("Deleted element is %d\n",ele);
					break;
			case 5:status=deleteLast(&lobj,&ele);
					if(status==0)
						printf("Linked List is already empty\n");
					else
						printf("Deleted element is %d\n",ele);
					break;
			case 6:printf("Enter the position\n");
					scanf("%d",&pos);
					printf("Enter an integer\n");
					scanf("%d",&ele);
					status=insertAtPos(&lobj,pos,ele);
					if(status==0)
						printf("Invalid position\n");
					break;
			case 7:printf("Enter the position\n");
					scanf("%d",&pos);
					status=deleteAtPos(&lobj,pos,&ele);
					if(status==0)
						printf("Invalid position\n");
					else
						printf("Deleted element is %d\n",ele);
					break;
		}
		printf("1.InsertFront 2.InsertLast 3.Display ");
		printf("4.DeleteFront 5.DeleteLast 6.InsertAtPos 7.DeleteAtPos\n");
		scanf("%d",&choice);
	}while(choice<8);
	destroyList(&lobj);
}