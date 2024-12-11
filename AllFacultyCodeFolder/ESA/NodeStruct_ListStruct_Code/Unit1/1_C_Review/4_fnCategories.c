/* 
#include<stdio.h>

int main()
{
	int a,b,res;
	
	printf("Enter 2 integers\n");
	scanf("%d%d",&a,&b);
	
	res=a+b;
	printf("Sum=%d\n",res);
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
	int a,b,res;
	
	printf("Enter 2 integers\n");
	scanf("%d%d",&a,&b);
	
	res=a+b;
	printf("Sum=%d\n",res);
}
*/
/*
//Function without return value, with parameter
#include<stdio.h>

void add(int a,int b);

int main()
{
	int a,b;
	printf("Enter 2 integers\n");
	scanf("%d%d",&a,&b);	
	
	add(a,b);
}

void add(int a,int b)
{
	int res=a+b;
	printf("sum=%d\n",res);
}
*/

/*
//Function with return value, without parameter
#include<stdio.h>

int add(void);

int main()
{
	int res=add();
	printf("sum=%d\n",res);
}

int add(void)
{
	int a,b;
	printf("Enter 2 integers\n");
	scanf("%d%d",&a,&b);

	return 	a+b;
}
*/

//Function with return value, with parameter
#include<stdio.h>

int add(int a,int b);

int main()
{
	int a,b,res;
	printf("Enter 2 integers\n");
	scanf("%d%d",&a,&b);
	
	res=add(a,b);
	printf("sum=%d\n",res);
}

int add(int a,int b)
{
	return a+b;
}