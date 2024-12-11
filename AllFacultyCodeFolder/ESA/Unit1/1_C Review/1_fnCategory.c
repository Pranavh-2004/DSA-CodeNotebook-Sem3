//Addition of 2 integers
//Different ways of writing a function in C

/*
#include<stdio.h>

int main()
{
	int num1,num2;
	
	printf("Enter 2 integers\n");
	scanf("%d%d",&num1,&num2);
	
	int res=num1+num2;
	printf("%d+%d=%d\n",num1,num2,res);
}
*/

/*
//Function without return value, without parameter
#include<stdio.h>

void add(void);

int main()
{
	add();
}

void add(void)
{
	int num1,num2;
	
	printf("Enter 2 integers\n");
	scanf("%d%d",&num1,&num2);
	
	int res=num1+num2;
	printf("%d+%d=%d\n",num1,num2,res);	
}
*/

/*
//Function without return value, with parameter

#include<stdio.h>

void add(int a,int b);

int main()
{
	int num1,num2;
	
	printf("Enter 2 integers\n");
	scanf("%d%d",&num1,&num2);
	
	add(num1,num2);
}

void add(int a,int b)
{
	int res=a+b;
	printf("%d+%d=%d\n",a,b,res);
}
*/

/*
//Function with return value, without parameters
#include<stdio.h>

int add(void);

int main()
{
	int res=add();
	printf("%d\n",res);
}

int add(void)
{
	int num1,num2;
	
	printf("Enter 2 integers\n");
	scanf("%d%d",&num1,&num2);
	
	printf("%d+%d=",num1,num2);
	return num1+num2;
}
*/

//Function with return value, with parameter

#include<stdio.h>

int add(int a,int b);

int main()
{
	int num1,num2;
	
	printf("Enter 2 integers\n");
	scanf("%d%d",&num1,&num2);
	
	int res=add(num1,num2);
	printf("%d+%d=%d\n",num1,num2,res);
}
int add(int a,int b)
{
	return a+b;
}