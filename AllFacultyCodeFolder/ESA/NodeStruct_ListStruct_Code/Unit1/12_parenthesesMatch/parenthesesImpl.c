#include"parentheses.h"
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


int parenthesesMatch(char str[])
{
	STACK sobj;
	initStack(&sobj);
	for(int i=0;str[i]!='\0';i++)
	{
		if(str[i] == '(' || str[i] == '[' ||str[i] == '{')
			push(&sobj,str[i]);
		else if(str[i] == ')' || str[i] == ']' ||str[i] == '}')
		{
			if(isEmpty(&sobj))
				return 0;
			switch(str[i])
			{
				case ')':if(pop(&sobj) != '(')
							return 0;
						break;
				case ']':if(pop(&sobj) != '[')
							return 0;
						break; 
				case '}':if(pop(&sobj) != '{')
							return 0;
						break;
			}
			
		}
	}
	return isEmpty(&sobj);
}