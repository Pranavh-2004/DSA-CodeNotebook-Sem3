#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX 20

typedef struct node
{
	struct node *left;
	char info;
	struct node *right;
}NODE;

NODE* exprTree(char postfix[],NODE *root);
//int evalExprTree(NODE *root);
void preorder(NODE *root);
void inorder(NODE *root);
void postorder(NODE *root);
NODE* destroyTree(NODE *root);

int main()
{
	NODE *root=NULL;
	
	char postfix[MAX];
	
	printf("Enter a valid postfix expression\n");
	scanf("%s",postfix);
	
	root=exprTree(postfix,root);
	
	if(root==NULL)
		printf("Empty Tree\n");
	else
	{
		printf("Preorder Traversal\n");
		preorder(root);
		printf("\nInorder Traversal\n");
		inorder(root);
		printf("\nPostorder Traversal\n");
		postorder(root);
	}
	printf("\n");
	root=destroyTree(root);
}

void push(NODE *s[],int *top,NODE *ele)
{
	s[++(*top)]=ele;
}

NODE* pop(NODE *s[],int *top)
{
	return s[(*top)--];

/*	
	NODE *ele=s[*top];
	(*top)--;
	return ele;
*/
}

NODE* exprTree(char postfix[],NODE *root)
{
	NODE *s[MAX];
	int top=-1;
	
	char ch;
	for(int i=0;postfix[i]!='\0';i++)
	{
		ch=postfix[i];
		
		NODE *newNode=malloc(sizeof(NODE));
		newNode->info=ch;
		
		if(isdigit(ch))
		{
			newNode->left=NULL;
			newNode->right=NULL;
		}
		else
		{
			newNode->right=pop(s,&top);
			newNode->left=pop(s,&top);
		}
		push(s,&top,newNode);
	}
	root=pop(s,&top);
	return root;
}

//int evalExprTree(NODE *root);

void preorder(NODE *root)
{
	if(root != NULL)
	{
		printf("%c",root->info);
		preorder(root->left);
		preorder(root->right);
	}
}
void inorder(NODE *root)
{
	if(root != NULL)
	{
		inorder(root->left);
		printf("%c",root->info);
		inorder(root->right);
	}
}
void postorder(NODE *root)
{
	if(root != NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%c",root->info);
	}
}

NODE* destroyTree(NODE *root)
{
	if(root != NULL)
	{
		root->left=destroyTree(root->left);
		root->right=destroyTree(root->right);
		printf("%c freed\n",root->info);
		free(root);
	}	
	return NULL;
}