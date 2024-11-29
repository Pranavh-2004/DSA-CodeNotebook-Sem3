#include<stdio.h>
#include<limits.h>
#include<ctype.h>
#define MAX 30

typedef struct stack
{
	int top;
	float s[MAX];	
}STACK;

void initStack(STACK *ps);
void push(STACK *ps,int ele);
float pop(STACK *ps);
//Precondition: postfix[] holds a valid postfix expression
float postfixEval(char *);


int main()
{
	char postfix[MAX];
	printf("Enter a valid postfix Expression\n");
	scanf("%s",postfix);
	printf("Result=%f\n",postfixEval(postfix));
	return 0;
}




void initStack(STACK *ps)
{
	ps->top=-1;
}

void push(STACK *ps,int ele)
{
	ps->top++;
	ps->s[ps->top]=ele;
	
	//ps->a[++(ps->top)]=ele;
}

float pop(STACK *ps)
{
	int res=ps->s[ps->top];
	ps->top--;
	
	return res;
	
	//return ps->a[ps->top--];
}
//Precondition: postfix[] holds a valid postfix expression
float postfixEval(char *pfix)
{
	STACK s;
	initStack(&s);
	float op1,op2,res;
	for(int i=0;pfix[i]!='\0';i++)
	{
		if(isdigit(pfix[i]))
			push(&s,pfix[i]-'0');
		else
		{
			op2=pop(&s);
		    op1=pop(&s);
			switch(pfix[i])
			{
				case '+':res=op1+op2;
				         break;
				case '-':res=op1-op2;
				         break;	
				case '*':res=op1*op2;
				         break;	
				case '/':res=op1/op2;
				         break;			 
						 
			}
			push(&s,res);
		}
	}
	return pop(&s);
	
}






/*#include<stdio.h>
#include<limits.h>
#include<ctype.h>
#define MAX 30

typedef struct stack
{
	int top;
	int s[MAX];	
}STACK;

void initStack(STACK *ps);
void push(STACK *ps,int ele);
int pop(STACK *ps);
//Precondition: postfix[] holds a valid postfix expression
float postfixEval(char *);


int main()
{
	char postfix[MAX];
	printf("Enter a valid postfix Expression\n");
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

void push(STACK *ps,int ele)
{
	ps->top++;
	ps->s[ps->top]=ele;
	
	//ps->a[++(ps->top)]=ele;
}
int pop(STACK *ps)
{
	int res=ps->s[ps->top];
	ps->top--;
	
	return res;
	
	//return ps->a[ps->top--];
}
//Precondition: postfix[] holds a valid postfix expression
float postfixEval(char *pfix)
{
	STACK s;
	initStack(&s);
	
	for(int i=0;pfix[i]!='\0';i++)
	{
		if(isdigit(pfix[i]))
			push(&s,pfix[i]-'0');	//pushes the digit on to stack
		else
		{
			int op2=pop(&s);
			int op1=pop(&s);
			
			int res;
			switch(pfix[i])
			{
				case '+': res=op1+op2;
							break;
				case '-': res=op1-op2;
							break;
				case '*': res=op1*op2;
							break;
				case '/': if(op2==0)
							{
								return INT_MAX;
							}
							res=op1/op2;
							break;
			}
			push(&s,res);
		}
	}
	return pop(&s);
}

*/

