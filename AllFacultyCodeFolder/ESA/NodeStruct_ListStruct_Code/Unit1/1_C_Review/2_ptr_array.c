#include<stdio.h>

int main()
{
	int a[]={10,20,30};
	
	int *ptr=a;
	
	printf("%d %d %d\n",a[0],a[1],a[2]);
	printf("%d %d %d\n",*(ptr),*(ptr+1),*(ptr+2));
	
	int b=*ptr++;
	printf("%d %d\n",b,*ptr);
	
	ptr=a;
	int c=*++ptr;
	printf("%d %d\n",c,*ptr);
	
	ptr=a;
	int d=++*ptr;
	printf("%d %d\n",d,*ptr);
}