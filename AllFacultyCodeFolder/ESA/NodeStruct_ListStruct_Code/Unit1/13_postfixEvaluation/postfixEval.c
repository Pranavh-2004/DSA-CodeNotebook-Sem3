#include<stdio.h>
#include<limits.h>
#include"postfixEval.h"

int main()
{
	char postfix[30];
	
	printf("Enter a valid postfix expression\n");
	scanf("%s",postfix);
	
	int res=postfixEval(postfix);
	if(res==INT_MAX)
		printf("Divide by zero error\n");
	else
		printf("Result=%d\n",res);
}