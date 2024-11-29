#include<stdio.h>
#include<stdlib.h>
#define MAX 3
typedef struct arrayList
{
	int last;
	int a[MAX];	
}ARLST;

void initList(ARLST *pal);
int append(ARLST *pal,int ele);
int deleteLast(ARLST *pal,int *pele);
void display(ARLST *pal);




int main()
{
	ARLST al;
	
	initList(&al);	//List is initialized to be empty
	
	int choice,ele,status;
	
	
	do
	{
		printf("1.InsertEnd 2.DeleteEnd 3.Display 4.exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("Enter an integer\n");
					scanf("%d",&ele);
					status=append(&al,ele);
					if(status)
						printf("%d inserted successfully\n",ele);
					else
						printf("List is already full\n");
					break;
			case 2: status=deleteLast(&al,&ele);
					if(status)
						printf("%d deleted successfully\n",ele);
					else
						printf("List is already empty\n");
					break;
			case 3: display(&al);
					break;
			case 4:exit(1);
					break;
		}
		
	}while(choice<5);
}



void initList(ARLST *pal)
{
	pal->last=-1;
}
int append(ARLST *pal,int ele)
{
	if(pal->last==MAX-1)
		return 0;
	else
	{
		pal->last++;
		pal->a[pal->last]=ele;
		return 1;
	}
}
int deleteLast(ARLST *pal,int *pele)
{
	if(pal->last==-1)
		return 0;
	else
	{
		*pele=pal->a[pal->last];
		pal->last--;
		return 1;
	}
}
void display(ARLST *pal)
{
	if(pal->last==-1)
		printf("Empty List\n");
	else
	{
		for(int i=0;i<=pal->last;i++)
			printf("%d ",pal->a[i]);
	}
	printf("\n");
}
