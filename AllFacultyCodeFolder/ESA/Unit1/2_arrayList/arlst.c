#include<stdio.h>
#include"arlst.h"

int main()
{
	LIST lobj;	//create the arrayList
	
	initList(&lobj);	//initialize the arrayList
	
	int choice,ele,status;
	
	printf("1.InsertLast 2.DeleteLast 3.Display\n");
	scanf("%d",&choice);
	
	do
	{
		switch(choice)
		{
			case 1:printf("Enter an integer\n");
					scanf("%d",&ele);
					status=insertLast(&lobj,ele);
					if(status==0)
						printf("Array List is already full\n");
					break;
			case 2:status=deleteLast(&lobj,&ele);
					if(status==0)
						printf("Array List is already empty\n");
					else
						printf("Deleted element is %d\n",ele);
					break;
			case 3:displayList(&lobj);
					break;
		}
		printf("1.InsertLast 2.DeleteLast 3.Display\n");
		scanf("%d",&choice);
	}while(choice<4);
	
}