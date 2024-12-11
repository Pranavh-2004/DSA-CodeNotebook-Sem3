#include<stdio.h>
#include"arlst.h"

int main()
{
	ARLST lobj;
	initList(&lobj);
	
	int choice,ele,status;
	printf("1.Append 2.DeleteLast 3.Display\n");
	scanf("%d",&choice);
	
	do
	{
		switch(choice)
		{
			case 1:printf("Enter an integer\n");
					scanf("%d",&ele);
					status=append(&lobj,ele);
					if(status==0)
						printf("List is already full\n");
					else
						printf("%d inserted successfully\n",ele);
					break;
			case 2:status=deleteLast(&lobj,&ele);
					if(status==0)
						printf("List is already empty\n");
					else
						printf("Deleted element is %d\n",ele);
					break;
			case 3:display(&lobj);
					break;
		}
		printf("1.Append 2.DeleteLast 3.Display\n");
		scanf("%d",&choice);
	}while(choice<4);
}