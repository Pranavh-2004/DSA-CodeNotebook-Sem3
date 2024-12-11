#include<stdio.h>

int fact(int n);

int main()
{
	int n;
	
	printf("Enter a non -ve integer\n");
	scanf("%d",&n);
	
	int res=fact(n);
	printf("%d!=%d\n",n,res);
}

int fact(int n)
{
	if(n==0)
		return 1;
	else
		return n*fact(n-1);
}