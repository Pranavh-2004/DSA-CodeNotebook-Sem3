#include<stdio.h>
#include<stdlib.h>
#define MAX 20

typedef struct node
{
	struct node *left;
	int info;
	struct node *right;
}NODE;

NODE* insertNode(NODE *root,int ele);
void preorder(NODE *root);
void inorder(NODE *root);
void postorder(NODE *root);
NODE* destroyTree(NODE *root);

int main()
{
	NODE *root=NULL;
	
	int choice,ele;
	
	do
	{
		printf("1.InsertNode 2.Preorder 3.Inorder 4.Postorder\n");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1: printf("Enter the element\n");
					scanf("%d",&ele);
					root=insertNode(root,ele);
					break;
			case 2:if(root==NULL)
						printf("Empty Tree\n");
					else
					{
						printf("Preorder Traversal\n");
						preorder(root);
						printf("\n");
					}
					break;
			case 3:if(root==NULL)
						printf("Empty Tree\n");
					else
					{
						printf("Inorder Traversal\n");
						inorder(root);
						printf("\n");
					}
					break;
			case 4:if(root==NULL)
						printf("Empty Tree\n");
					else
					{
						printf("Postorder Traversal\n");
						postorder(root);
						printf("\n");
					}
					break;
		}
	}while(choice<5);
	root=destroyTree(root);
	if(root==NULL)
		printf("Empty Tree\n");
	else
		printf("There is a mistake in freeing\n");
}

NODE *createNode(int ele)
{
	NODE *newNode=malloc(sizeof(NODE));
	
	newNode->info=ele;
	newNode->left=NULL;
	newNode->right=NULL;
	
	return newNode;
}

NODE* insertNode(NODE *root,int ele)
{
	NODE *newNode=createNode(ele);
	
	if(root==NULL)
	{
		root=newNode;
	}
	else
	{
		NODE *p=root;
		NODE *q=NULL;
		
		while(p!=NULL)
		{
			if(newNode->info < p->info)
			{
				q=p;
				p=p->left;
			}
			else
			{
				q=p;
				p=p->right;
			}
		}
		if(newNode->info < q->info)
		{
			q->left=newNode;
		}
		else
		{
			q->right=newNode;
		}
	}
	return root;
}

void push(NODE *s[],int *top,NODE *ele)
{
	s[++(*top)]=ele;
}

NODE* pop(NODE *s[],int *top)
{
	return s[(*top)--];
}
int isEmpty(int top)
{
	return top==-1;
}

void preorder(NODE *root)
{
	NODE *s[MAX];
	int top=-1;
	
	push(s,&top,root);
	
	while(!isEmpty(top))
	{
		root=pop(s,&top);
		printf("%d ",root->info);
		
		if(root->right!=NULL)
			push(s,&top,root->right);
		
		if(root->left!=NULL)
			push(s,&top,root->left);
	}
}

void inorder(NODE *root)
{
	NODE *s[MAX];
	int top=-1;
	
	while(root!=NULL || !isEmpty(top))
	{
		if(root!=NULL)
		{
			push(s,&top,root);
			root=root->left;
		}
		else
		{
			root=pop(s,&top);
			printf("%d ",root->info);
			root=root->right;
		}
	}
}

void postorder(NODE *root)
{
	NODE *s1[MAX],*s2[MAX];
	int top1=-1,top2=-1;
	
	push(s1,&top1,root);
	
	while(!isEmpty(top1))
	{
		root=pop(s1,&top1);
		push(s2,&top2,root);
		
		if(root->left!=NULL)
			push(s1,&top1,root->left);
		
		if(root->right!=NULL)
			push(s1,&top1,root->right);
	}
	
	while(!isEmpty(top2))
	{
		root=pop(s2,&top2);
		printf("%d ",root->info);
	}
}

NODE* destroyTree(NODE *root)
{
	if(root != NULL)
	{
		root->left=destroyTree(root->left);
		root->right=destroyTree(root->right);
		printf("%d freed\n",root->info);
		free(root);
	}	
	return NULL;
}