#include<stdio.h>
#include"cdll.h"

int main()
{
	LIST lobj;
	
	initList(&lobj);
	
	int choice,ele,pos;
	NODE *res=NULL;
	printf("1.InsertFront 2.InsertLast 3.display 4.DeleteFront ");
	printf("5.DeleteLast 6.InsertAtPos 7.DeleteAtPos 8.Search\n");
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
			case 3:display(&lobj);
					break;
			case 4:if(deleteFront(&lobj,&ele))
					printf("Deleted %d\n",ele);
				else
					printf("List is already empty\n");
				break;
			case 5:if(deleteLast(&lobj,&ele))
					printf("Deleted %d\n",ele);
				else
					printf("List is already empty\n");
				break;	
			case 6:printf("Enter an integer\n");
					scanf("%d",&ele);
					printf("Enter the position\n");
					scanf("%d",&pos);
					if(insertAtPos(&lobj,ele,pos)==0)
						printf("Invalid Position\n");
					break;
			case 7:printf("Enter the position\n");
					scanf("%d",&pos);
					if(deleteAtPos(&lobj,&ele,pos))
						printf("Deleted ele is %d\n",ele);
					else
						printf("Deletion failed:Invalid Position\n");
					break;
			case 8:printf("Enter the element to be searched\n");
					scanf("%d",&ele);
					res=search(&lobj,ele);
					if(res==NULL)
						printf("Element not found\n");
					else
						printf("Search successful, %d found\n",res->info);
					break;
		}
		printf("1.InsertFront 2.InsertLast 3.display 4.DeleteFront ");
		printf("5.DeleteLast 6.InsertAtPos 7.DeleteAtPos 8.Search\n");
		scanf("%d",&choice);
	}while(choice<9);
	destroyList(&lobj);
}