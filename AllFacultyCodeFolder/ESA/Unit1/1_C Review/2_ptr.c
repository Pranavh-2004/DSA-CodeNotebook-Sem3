#include<stdio.h>

int main()
{
	int a=2;
	int *ptr;
	ptr=&a;
	
	//int *ptr=&a;
	
	printf("%d %d\n",a,*ptr);
	printf("Address of a: %u %p %p\n",&a,&a,ptr);
	
	int **dptr=&ptr;
	printf("%d %d %d\n",a,*ptr,**dptr);
	printf("Address of ptr:%p %p\n",&ptr,dptr);
}