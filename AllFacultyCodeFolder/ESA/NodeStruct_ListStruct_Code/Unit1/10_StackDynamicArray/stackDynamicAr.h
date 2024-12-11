typedef struct stack
{
	int *s;
	int top;
	int size;
}STACK;

void initStack(STACK *ps,int n);
int isFull(STACK *ps);
int isEmpty(STACK *ps);
void push(STACK *ps,int ele);
//precondition:Stack is not empty
int pop(STACK *ps);
//precondition:Stack is not empty
int stackTop(STACK *ps);
void display(STACK *ps);
void doubleStackSize(STACK *ps);
void destroyStack(STACK *ps);