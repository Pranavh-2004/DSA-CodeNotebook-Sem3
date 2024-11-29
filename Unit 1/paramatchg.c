#include<stdio.h>
#define MAX 30

typedef struct stack
{
	int top;
	char a[MAX];	
}STACK;

void initStack(STACK *ps);
int isEmpty(STACK *ps);
void push(STACK *ps,char ele);
char pop(STACK *ps);
int chkBalParentheses(char str[]);




int main()
{
	char str[30];
	
	printf("Enter a parenthesized expression\n");
	scanf("%s",str);
	
	if(chkBalParentheses(str))
		printf("Balanced\n");
	else
		printf("Not balanced\n");
}


void initStack(STACK *ps)
{
	ps->top=-1;
}

int isEmpty(STACK *ps)
{
	return ps->top==-1;
}

void push(STACK *ps,char ele)
{
	ps->top++;
	ps->a[ps->top]=ele;
	
	//ps->a[++(ps->top)]=ele;
}
char pop(STACK *ps)
{
	char poppedEle=ps->a[ps->top];
	ps->top--;
	
	return poppedEle;
	
	//return ps->a[ps->top--];
}

int chkBalParentheses(char str[])
{
	STACK s;
	
	initStack(&s);
	
	for(int i=0;str[i]!='\0';i++)
	{
		if(str[i]=='(' || str[i]=='[' || str[i]=='{')
			{
				push(&s,str[i]);
			}
		else if(str[i]==')' || str[i]==']' || str[i]=='}')	
		{
			if(isEmpty(&s))
				return 0;
			switch(str[i])
			{
				case ')':if(pop(&s)!='(')
							return 0;
						break;
				
				case ']':if(pop(&s)!='[')
							return 0;
						break;
		        case '}':if(pop(&s)!='{')
							return 0;
						break;
			}
		}
	}
	
return isEmpty(&s);	
}