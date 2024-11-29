#define MAX 30
typedef struct stack
{
	int s[MAX];
	int top;
}STACK;

int postfixEval(char postfix[]);
