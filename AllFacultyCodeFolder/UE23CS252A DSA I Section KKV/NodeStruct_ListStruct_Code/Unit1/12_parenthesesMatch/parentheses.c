#include<stdio.h>
#include"parentheses.h"

int main()
{
	char str[30];
	printf("Enter a parenthesized expression\n");
	scanf("%s",str);
	
	if(parenthesesMatch(str))
		printf("Valid\n");
	else
		printf("Invalid\n");
}