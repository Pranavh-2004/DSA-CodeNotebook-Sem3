#include<stdio.h>

int sod(int n);
int cod(int n);

int main()
{
	int n;
	printf("Enter a positive integer\n");
	scanf("%d",&n);
	
	printf("Sum of digits=%d\n",sod(n));
	printf("Count of digits=%d\n",cod(n));
}

int sod(int n)
{
	if(n==0)
		return 0;
	else
		return (n%10)+sod(n/10);
}

int cod(int n)
{
	if(n==0)
		return 0;
	else
		return 1+cod(n/10);
}