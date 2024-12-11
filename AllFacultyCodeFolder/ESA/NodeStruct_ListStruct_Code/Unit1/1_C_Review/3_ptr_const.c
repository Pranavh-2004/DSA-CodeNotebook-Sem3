//Pointers and constness

#include<stdio.h>

int main()
{
	const int a=10;			//int const a=10;
//	a=10;

//Pointer pointing to constant data
	const int *ptr=&a;
//	*ptr=*ptr+1;

	printf("%d %d\n",a,*ptr);
	
	int b=20;
	ptr=&b;
	printf("%d %d\n",b,*ptr);

//	*ptr=30;
	b=30;
	printf("%d %d\n",b,*ptr);
	
	
//constant pointer
	int *const cptr=&b;
	*cptr=100;
	printf("%d %d\n",b,*cptr);
	
//	cptr=&b;


//constant pointer to constant data
	const int *const iptr=&a;
//	*iptr=50;
//	iptr=&b;
}