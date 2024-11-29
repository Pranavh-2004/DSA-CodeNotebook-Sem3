//Array Implimentation
//Descending ordered

#include<stdio.h>
#define MAX 5

typedef struct priQ
{
	int info;
	int pri;
}PRIQ;

void insert(PRIQ *pq,int ele,int pty,int *count);
PRIQ maxDelete(PRIQ *pq,int *count);
void display(PRIQ *pq,int *count);

int main()
{
	PRIQ pq[MAX];
	PRIQ temp;
	int choice,ele,pri,count=0;
	
	do
	{
		printf("1.insert/enqueue  2.Maxdelete/dequeue 3.Display\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:if(count!=MAX-1)
			       {
				    printf("enter an integer and priority\n");
				    scanf("%d%d",&ele,&pri);
					insert(pq,ele,pri,&count);
				   }
				   else
				   printf("Queue is already full\n");
					break;
			case 2:if(count)
			       {
					   temp=maxDelete(pq,&count);
					   printf("Data:%d pri:%d",temp.info,temp.pri);
				   }
				   else
					   printf("Queue is empty\n");
				   break;
			case 3:display(pq,&count);	
			       break; 
		}
	}while(choice<4);
	
	return 0;
}

void insert(PRIQ *pq,int ele,int pty,int *count)
{
	int i=*count-1;
	
	PRIQ key;
	key.info=ele;
	key.pri=pty;
	
	while(i>=0 && key.pri>pq[i].pri)
	{
		pq[i+1]=pq[i];
		i--;
	}
	pq[i+1]=key;
	(*count)++;

}


PRIQ maxDelete(PRIQ *pq,int *count)
{
	PRIQ key=pq[0];
	
	for(int i=1;i<*count;i++)
	{
		pq[i-1]=pq[i];
		
	}
	(*count)--;
	return key;
	
}


void display(PRIQ *pq,int *count)
{
	if(*count==0)
	{
		printf("Queue is empty\n");
		return;
	}
	for(int i=0;i<*count;i++)
	{
		printf("Data:%d Pri:%d\n",pq[i].info,pq[i].pri);
	}
	
}