#include<stdio.h>

void swapV(int a,int b);
void swapR(int *pa,int *pb);

int main()
{
	int a=2,b=3;
	printf("Call by Value\n");
	printf("Before swap:\n");
	printf("a=%d b=%d\n",a,b);
	swapV(a,b);
	printf("After swap:\n");
	printf("a=%d b=%d\n",a,b);
	
	printf("\nCall by Address\n");
	printf("Before swap:\n");
	printf("a=%d b=%d\n",a,b);
	swapR(&a,&b);
	printf("After swap:\n");
	printf("a=%d b=%d\n",a,b);
}

void swapV(int a,int b)
{
	int temp=a;
	a=b;
	b=temp;
//	printf("In function swap:a=%d b=%d\n",a,b);
}

void swapR(int *pa,int *pb)
{
	int temp=*pa;
	*pa=*pb;
	*pb=temp;
}