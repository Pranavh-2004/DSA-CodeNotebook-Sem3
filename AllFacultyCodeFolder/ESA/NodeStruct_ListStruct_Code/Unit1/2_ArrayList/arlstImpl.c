#include<stdio.h>
#include"arlst.h"

void initList(ARLST *pal)
{
	pal->last=-1;
}
int isFull(ARLST *pal)
{
	return pal->last == MAX-1;
}

int append(ARLST *pal,int ele)
{
	if(isFull(pal))
		return 0;
	else
	{
		pal->last++;
		pal->a[pal->last]=ele;
		return 1;
	}
	
}

int isEmpty(ARLST *pal)
{
	return pal->last == -1;
}
int deleteLast(ARLST *pal,int *pele)
{
	if(isEmpty(pal))
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