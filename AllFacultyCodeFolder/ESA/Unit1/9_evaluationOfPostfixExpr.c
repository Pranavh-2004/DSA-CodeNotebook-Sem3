//Evaluation of a valid postfix expression
#include<stdio.h>
#include<ctype.h>
#include<limits.h>
#define MAX 30

typedef struct stack
{
	int s[MAX];
	int top;
}STACK;

int postfixEval(char postfix[]);

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

void initStack(STACK *ps)
{
	ps->top=-1;
}

//precondition: Stack is not full
void push(STACK *ps,int ele)
{
	ps->top++;
	ps->s[ps->top]=ele;
	
	//ps->s[++ps->top]=ele;
}

//precondition:Stack is not empty
int pop(STACK *ps)
{
	int poppedEle=ps->s[ps->top];
	ps->top--;
	return poppedEle;
	
	//return ps->s[ps->top--];
}

int postfixEval(char postfix[])
{
	STACK sobj;
	initStack(&sobj);
	
	for(int i=0;postfix[i]!='\0';i++)
	{
		if(isdigit(postfix[i]))
			push(&sobj,postfix[i]-'0');
		else
		{
			int op2=pop(&sobj);
			int op1=pop(&sobj);
			int res;
			switch(postfix[i])
			{
				case '+':res=op1+op2;
							break;
				case '-':res=op1-op2;
							break;
				case '*':res=op1*op2;
							break;	
				case '/':if(op2==0)
							return INT_MAX;
						res=op1/op2;
						break;
			}
			push(&sobj,res);
		}
	}
	return pop(&sobj);
}