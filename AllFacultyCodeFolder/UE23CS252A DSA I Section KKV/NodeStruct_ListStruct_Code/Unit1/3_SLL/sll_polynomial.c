#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct node
{
	int coeff;
	int powx;
	struct node *next;
}NODE;

typedef struct polynomial
{
	NODE *head;
}POLYNOMIAL;

void initPolynomial(POLYNOMIAL *pl);
void createPolynomial(POLYNOMIAL *pl);
void insertLast(POLYNOMIAL *pl,int cf,int px);
void addPolynomial(POLYNOMIAL *pl1,POLYNOMIAL *pl2,POLYNOMIAL *pl3);
void displayPolynomial(POLYNOMIAL *pl);
void destroyPolynomial(POLYNOMIAL *pl);
int evalPolynomial(POLYNOMIAL *pl,int x);

int main()
{
	POLYNOMIAL pobj1,pobj2,pobj3;
	
	initPolynomial(&pobj1);
	initPolynomial(&pobj2);
	initPolynomial(&pobj3);
	
	printf("Enter 1st Polynomial\n");
	createPolynomial(&pobj1);
	displayPolynomial(&pobj1);
	
	printf("Enter 2nd Polynomial\n");
	createPolynomial(&pobj2);
	displayPolynomial(&pobj2);
	
	addPolynomial(&pobj1,&pobj2,&pobj3);
	printf("Resultant Polynomial:");
	displayPolynomial(&pobj3);
	
	int x;
	printf("Enter the value of x\n");
	scanf("%d",&x);
	
	printf("Result of evaluation:%d\n",evalPolynomial(&pobj3,x));
	destroyPolynomial(&pobj1);
	destroyPolynomial(&pobj2);
	destroyPolynomial(&pobj3);
}

void initPolynomial(POLYNOMIAL *pl)
{
	pl->head=NULL;
}
void createPolynomial(POLYNOMIAL *pl)
{
	int cf,px,choice;
	
	do
	{
		printf("Enter the coeff and pow\n");
		scanf("%d%d",&cf,&px);
		insertLast(pl,cf,px);
		printf("Do you want to add one more term\n");
		scanf("%d",&choice);
	}while(choice);
}
void insertLast(POLYNOMIAL *pl,int cf,int px)
{
	NODE *newNode=malloc(sizeof(NODE));
	newNode->coeff=cf;
	newNode->powx=px;
	newNode->next=NULL;
	
	if(pl->head==NULL)	//check if list is empty
	{
		pl->head=newNode;
	}
	else
	{
		NODE *p=pl->head;
		
		while(p->next!=NULL)
			p=p->next;
		
		p->next=newNode;
	}
}
void displayPolynomial(POLYNOMIAL *pl)
{
	NODE *p=pl->head;
	
	while(p->next!=NULL)
	{
		printf("(%dx^%d)+",p->coeff,p->powx);
		p=p->next;
	}
	printf("(%dx^%d)\n",p->coeff,p->powx);
}
void destroyPolynomial(POLYNOMIAL *pl)
{
	NODE *p=pl->head;
	
	while(pl->head!=NULL)
	{
		pl->head=pl->head->next;
//		printf("%dx^%d freed\n",p->coeff,p->powx);
		free(p);
		p=pl->head;
	}
}
void addPolynomial(POLYNOMIAL *pl1,POLYNOMIAL *pl2,POLYNOMIAL *pl3)
{
	NODE *p=pl1->head;
	NODE *q=pl2->head;
	
	int cf,px;
	
	while(p!=NULL && q!=NULL)
	{
		if(p->powx == q->powx)
		{
			cf=p->coeff+q->coeff;
			px=p->powx;		//px=q->powx;
			p=p->next;
			q=q->next;
		}
		else if(p->powx > q->powx)
		{
			cf=p->coeff;
			px=p->powx;
			p=p->next;
		}
		else
		{
			cf=q->coeff;
			px=q->powx;
			q=q->next;
		}
		insertLast(pl3,cf,px);
	}
	while(p!=NULL)
	{
		cf=p->coeff;
		px=p->powx;
		p=p->next;
		insertLast(pl3,cf,px);
	}
	while(q!=NULL)
	{
		cf=q->coeff;
		px=q->powx;
		q=q->next;
		insertLast(pl3,cf,px);
	}
}
int evalPolynomial(POLYNOMIAL *pl,int x)
{
	NODE *p=pl->head;
	int sum=0;
	
	while(p!=NULL)
	{
		sum=sum+(p->coeff*pow(x,p->powx));
		p=p->next;
	}
	return sum;
}