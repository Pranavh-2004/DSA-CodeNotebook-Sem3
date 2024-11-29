#include<stdio.h>
#include"csll.h"

int main()
{
	LIST lobj;
	initList(&lobj);
	
	int choice,ele,pos;
	NODE *res;
	printf("1.InsertFront 2.InsertLast 3.Display 4.DeleteFront ");
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
			case 4: if(deleteFront(&lobj,&ele))
						printf("Deleted %d\n",ele);
					else
						printf("List is already empty\n");
					break;
			case 5: if(deleteLast(&lobj,&ele))
						printf("Deleted %d\n",ele);
					else
						printf("List is already empty\n");
					break;
			case 6:printf("Enter an integer\n");
					scanf("%d",&ele);
					printf("Enter the position\n");
					scanf("%d",&pos);
					if(!insertAtPos(&lobj,ele,pos))
						printf("Insert failed:Invalid position\n");
					break;
			case 7:printf("Enter the position\n");
					scanf("%d",&pos);
					if(deleteAtPos(&lobj,&ele,pos))
						printf("Deleted %d\n",ele);
					else
						printf("Delete Failed:Invalid Position\n");
					break;
			case 8:printf("Enter the search element\n");
					scanf("%d",&ele);
					res=search(&lobj,ele);
					if(res==NULL)
						printf("Element not found\n");
					else
						printf("Ele found:%d\n",res->info);
					break;
						
		}
		printf("1.InsertFront 2.InsertLast 3.Display 4.DeleteFront ");
		printf("5.DeleteLast 6.InsertAtPos 7.DeleteAtPos 8.Search\n");
		scanf("%d",&choice);
	}while(choice<9);
	
	destroyList(&lobj);
	
}