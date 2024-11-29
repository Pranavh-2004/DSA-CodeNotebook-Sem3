typedef struct node
{
	int info;
	struct node *next;
}NODE;

typedef struct stack
{
	NODE *top;
}STACK;

void initStack(STACK *ps);
void push(STACK *ps,int ele);
int isEmpty(STACK *ps);
//Precondition:Stack is not empty
int pop(STACK *ps);
int stackTop(STACK *ps);	//peek,peep
void display(STACK *ps);
void destroyStack(STACK *ps);