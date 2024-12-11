#define MAX 30
typedef struct stack
{
	char s[MAX];
	int top;
}STACK;

int parenthesesMatch(char str[]);