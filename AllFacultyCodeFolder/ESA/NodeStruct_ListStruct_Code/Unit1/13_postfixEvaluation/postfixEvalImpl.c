#include<ctype.h>
#include<limits.h>
#include"postfixEval.h"

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