//			ExpTreeMain.c

#include <stdio.h>
#include <stdlib.h>
#include "ExpTree.h"

int main (int argc, char **argv) 
{
	char postfixExpr [100];
	NODE *eStack [50];
   	printf ("Enter Postfix Expression : ");
   	scanf ("%s", postfixExpr);
   	construct_expression_tree(postfixExpr, eStack);
   	printf ("\nIn-Order Traversal : ");
   	inOrder(eStack[0]);
   	printf ("\nPre-Order Traversal : ");
   	preOrder(eStack[0]);
   	printf ("\nPost-Order Traversal : ");
   	postOrder(eStack[0]);
   	return 0;
}