//			ExpTree.c

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "ExpTree.h"

static int top = -1;
NODE **eStack;

NODE *CreateNode (char iData)
{
	NODE *pNode;

	if ((pNode = (NODE *) malloc (sizeof (NODE))) == NULL)
	{
		printf ("Memory allocation failure\n");
		exit (1);
	}
	pNode -> left = NULL;
	pNode -> right = NULL;
	pNode -> data = iData;
	return pNode;
}


int CheckChar (char inChar)
{
	int retVal = -1;

   	if (inChar == '+' || inChar == '-' || inChar == '*' 
				|| inChar == '/')
		retVal = 1;	// indicates an operator
   	else 
	{
		inChar = toupper (inChar);
		if (inChar >= 'A' || inChar <= 'Z')
      			retVal = 2;
	}
   	return (retVal);
}

void push(NODE *tree) 
{
   	top++;
   	eStack [top] = tree;
}
NODE *pop() 
{
   	top--;
   	return (eStack[top + 1]);
}

void construct_expression_tree(char *suffix, NODE *pStack []) 
{
   	char s;
   	NODE *newl, *p1, *p2;
   	int cType;
	eStack = pStack;
   	s = suffix[0];
   	for (int i = 1; s != 0; i++) 
	{
      		cType = CheckChar (s);
      		if (cType == 2) 	// Operand
		{
         		newl = CreateNode (s);
         		push(newl);
      		} 
		else if (cType == 1)	// Operator
		{
         		p1 = pop();
         		p2 = pop();
			newl = CreateNode (s);
         		newl->left = p2;
         		newl->right = p1;
         		push(newl);
      		}
		else
		{
			printf ("Invalid character\n");
			exit (0);
		}
      		s = suffix[i];
   	}
}

void preOrder(NODE *tree) 
{
   	if (tree != NULL) 
	{
		printf ("%c ", tree->data);
       		preOrder(tree->left);
      		preOrder(tree->right);
   	}
}

void inOrder(NODE *tree) 
{
   	if (tree != NULL) 
	{
      		inOrder(tree->left);
      		printf ("%c ", tree->data);
      		inOrder(tree->right);
   	}
}

void postOrder(NODE *tree) 
{
   	if (tree != NULL) 
	{
      		postOrder(tree->left);
      		postOrder(tree->right);
      		printf ("%c ", tree->data);
   	}
}
