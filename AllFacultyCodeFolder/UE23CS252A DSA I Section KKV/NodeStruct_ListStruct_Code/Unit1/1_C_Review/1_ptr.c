#include<stdio.h>

int main()
{
	int a=2;
	int *ptr1=&a;
	
	double b=2.5;
	double *ptr2;
	ptr2=&b;
	
	int **ptr3=&ptr1;
	
	printf("%d %d %d\n",a,*ptr1,**ptr3);
	printf("%lf %lf\n",b,*ptr2);
	printf("%p %p %p %p",ptr3,&ptr1,ptr1,&a);
}