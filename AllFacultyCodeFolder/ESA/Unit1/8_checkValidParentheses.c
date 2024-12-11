#include<stdio.h>
#define MAX 200

int chkValidParentheses(char expr[]);

int main()
{
	char expr[MAX];
	
	printf("Enter a parenthesized expression\n");
	scanf("%s",expr);
	
	if(chkValidParentheses(expr))
		printf("Valid\n");
	else
		printf("Invalid\n");
}

int isEmpty(int top)
{
	return top==-1;
}

//Assume stack is big enough to hold the input parenthesized expression
//Precondition: Stack is already created and not full
void push(char s[],int *top,char ele)
{
	(*top)++;	//++(*top) or *top=(*top)+1
	s[*top]=ele;
	
	//Instead of the above 2 lines
//	s[++(*top)]=ele;
}

//Precondition: Stack is already created and not empty
char pop(char s[],int *top)
{
	char poppedEle=s[*top];
	(*top)--;		//--(*top) or (*top)=(*top)-1
	
	return poppedEle;
	
	//Instead of above 3 lines of code
//	return s[(*top)--];
}

int chkValidParentheses(char expr[])
{
	char s[MAX];
	int top=-1;	//stack is initialized to be empty
	
	char ch;
	for(int i=0;expr[i]!='\0';i++)
	{
		ch=expr[i];
		
		if(ch=='(' || ch=='[' || ch=='{')
			push(s,&top,ch);
		else if(ch==')' || ch==']' || ch=='}')
		{
			if(isEmpty(top))
				return 0;
			switch(ch)
			{
				case ')':if(pop(s,&top)!='(')
							return 0;
						break;
				case ']':if(pop(s,&top)!='[')
							return 0;
						break;
				case '}':if(pop(s,&top)!='{')
							return 0;
						break;
			}
		}
	}
	return isEmpty(top);
}