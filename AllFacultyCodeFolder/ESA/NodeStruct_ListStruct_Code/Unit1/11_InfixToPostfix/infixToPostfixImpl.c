#include<ctype.h>
#include"infixToPostfix.h"
void initStack(STACK *ps)
{
	ps->top=-1;
}

int isEmpty(STACK *ps)
{
	return ps->top == -1;
}

//precondition: Stack is not full
void push(STACK *ps,char ele)
{
	ps->top++;
	ps->s[ps->top]=ele;
	
	//ps->s[++ps->top]=ele;
}

//precondition:Stack is not empty
char pop(STACK *ps)
{
	char poppedEle=ps->s[ps->top];
	ps->top--;
	return poppedEle;
	
	//return ps->s[ps->top--];
}

//precondition:Stack is not empty
char stackTop(STACK *ps)
{
	return ps->s[ps->top];
}
int precedence(char st,char in)
{
	switch(in)
	{
		case '+':
		case '-': if(st == '(')
					return 0;
				else
					return 1;
				break;
		case '*':
		case '/':if(st == '(' || st=='+' || st=='-')
					return 0;
				else
					return 1;
				break;
		case '(':return 0;
					break;
		case ')':if(st=='(')
					return 0;
				else
					return 1;
				break;
	}
}
void infixToPostfix(char infix[],char postfix[])
{
	STACK sobj;
	initStack(&sobj);
	
	int j=0;
	for(int i=0;infix[i]!='\0';i++)
	{
		if(isdigit(infix[i]))
		{
			postfix[j++]=infix[i];
		}
		else
		{
			while(!isEmpty(&sobj) && precedence(stackTop(&sobj),infix[i]))
			{
				postfix[j++]=pop(&sobj);
			}
			
			if(infix[i]==')')
				pop(&sobj);
			else
				push(&sobj,infix[i]);
		}
	}
	while(!isEmpty(&sobj))
		postfix[j++]=pop(&sobj);
	postfix[j]='\0';
}