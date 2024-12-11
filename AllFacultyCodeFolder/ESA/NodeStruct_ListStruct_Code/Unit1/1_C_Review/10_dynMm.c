#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n=3;
	int *ptr=calloc(n,sizeof(int));
	
	printf("Default Values:\n");
	for(int i=0;i<n;i++)
		printf("%d ",*(ptr+i));
	
	printf("\nEnter 3 integers\n");
	for(int i=0;i<n;i++)
		scanf("%d",(ptr+i));
	
	
	printf("Updated Values:\n");
	for(int i=0;i<n;i++)
		printf("%d ",*(ptr+i));
	
	n=5;
	ptr=realloc(ptr,n*sizeof(int));
	printf("\nAfter realloc:\n");
	for(int i=0;i<n;i++)
		printf("%d ",*(ptr+i));
	
	free(ptr);
}