#include<stdio.h>
#include"arlst.h"

void initList(LIST *pl)
{
	pl->last=-1;
}

/*
//Multiple return statements
int isFull(LIST *pl)
{
	if(pl->last==MAX-1)
		return 1;
	else
		return 0;
}
*/

/*
//Single return statement
int isFull(LIST *pl)
{
	int returnValue=0;
	
	if(pl->last==MAX-1)
		returnValue=1;
	else
		returnValue=0;
	
	return returnValue;
}
*/

int isFull(LIST *pl)
{
	return pl->last==MAX-1;
}
int insertLast(LIST *pl,int ele)
{
	int returnValue=0;
	
	if(isFull(pl))
		returnValue=0;
	else
	{
		(pl->last)++;
		pl->a[pl->last]=ele;
		returnValue=1;
	}
	return returnValue;
}

int isEmpty(LIST *pl)
{
	return pl->last==-1;
}

int deleteLast(LIST *pl,int *pele)
{
	int returnValue=0;
	
	if(isEmpty(pl))
		returnValue=0;
	else
	{
		*pele=pl->a[pl->last];
		(pl->last)--;
		returnValue=1;
	}
	return returnValue;
}

void displayList(LIST *pl)
{
	if(isEmpty(pl))
		printf("Empty List");
	else
	{
		for(int i=0;i<=pl->last;i++)
			printf("%d ",pl->a[i]);
	}
	printf("\n");
}