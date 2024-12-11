#define MAX 3
typedef struct stack
{
	int s[MAX];
	int top;
}STACK;

void initStack(STACK *ps);
int isFull(STACK *ps);
int isEmpty(STACK *ps);
//precondition: Stack is not full
void push(STACK *ps,int ele);
//precondition:Stack is not empty
int pop(STACK *ps);
//precondition:Stack is not empty
int stackTop(STACK *ps);
void display(STACK *ps);