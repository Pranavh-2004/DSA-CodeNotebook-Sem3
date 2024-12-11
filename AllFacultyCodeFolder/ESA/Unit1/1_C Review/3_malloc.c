#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n=4;
	int *ptr=malloc(n*sizeof(int));
	
	printf("Junk values\n");
	for(int i=0;i<n;i++)
		printf("%d ",*(ptr+i));	//printf("%d ",ptr[i]);

	printf("\nEnter 4 integers\n");
	for(int i=0;i<n;i++)
		scanf("%d",(ptr+i));	//scanf("%d",&ptr[i]);
	
	printf("User entered values\n");
	for(int i=0;i<n;i++)
		printf("%d ",*(ptr+i));	//printf("%d ",ptr[i]);
	
	free(ptr);
}