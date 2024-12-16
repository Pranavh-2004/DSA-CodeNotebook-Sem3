#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 10
typedef struct node
{
	char info;
	struct node *left;
	struct node *right;
} NODE;

typedef struct tree
{
	NODE *root;
} TREE;

typedef struct stack
{
	int top;
	NODE *s[MAX];
} STACK;

void initStack(STACK *ps);

void initTree(TREE *pt);
void createTree(TREE *pt, char expr[MAX]);

int evalExpTree(TREE *pt);

int main()
{
	TREE tobj;
	char expr[MAX];
	initTree(&tobj);
	printf("Enter a valid postfix expression\n");
	scanf("%s", expr);

	createTree(&tobj, expr);

	printf("Result = %d\n", evalExpTree(&tobj));
}

void initStack(STACK *ps)
{
	ps->top = -1;
}

void initTree(TREE *pt)
{
	pt->root = NULL;
}

void push(STACK *ps, NODE *ele)
{
	ps->top++;
	ps->s[ps->top] = ele;
}

NODE *pop(STACK *ps)
{
	NODE *ele = ps->s[ps->top];
	ps->top--;
	return ele;
}

void createTree(TREE *pt, char expr[MAX])
{
	STACK sobj;
	initStack(&sobj);
	for (int i = 0; expr[i] != '\0'; i++)
	{
		NODE *temp = malloc(sizeof(NODE));
		temp->info = expr[i];
		temp->left = temp->right = NULL;

		if (isdigit(expr[i]))
		{
			push(&sobj, temp);
		}
		else
		{
			temp->right = pop(&sobj);
			temp->left = pop(&sobj);
			push(&sobj, temp);
		}
	}

	pt->root = pop(&sobj);
}

int eval(NODE *r)
{
	switch (r->info)
	{
	case '+':
		return eval(r->left) + eval(r->right);
		break;
	case '-':
		return eval(r->left) - eval(r->right);
		break;
	case '*':
		return eval(r->left) * eval(r->right);
		break;
	case '/':
		return eval(r->left) / eval(r->right);
		break;
	default:
		return r->info - '0';
	}
}
int evalExpTree(TREE *pt)
{
	return eval(pt->root);
}