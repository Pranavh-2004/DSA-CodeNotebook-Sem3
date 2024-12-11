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
NODE* deleteNode(NODE *root,int ele);

int main()
{
	NODE *root=NULL;
	
	int choice,ele;
	
	do
	{
		printf("1.InsertNode 2.Preorder 3.Inorder 4.Postorder 5.DelNode\n");
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
			case 5:printf("Enter the node to be deleted\n");
					scanf("%d",&ele);
					root=deleteNode(root,ele);
					break;
		}
	}while(choice<6);
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
/* 	NODE *newNode=createNode(ele);
	
	NODE *p=root,*q=NULL;
	
	if(root==NULL)
	{
		root=newNode;
	}
	else
	{
		while(p!=NULL)
		{
			q=p;
			if(newNode->info < p->info)
				p=p->left;
			else
				p=p->right;
		}
		if(newNode->info < q->info)
			q->left = newNode;
		else
			q->right = newNode;
	}
	return root; */
	
	NODE *newNode=createNode(ele);
	
	if(root==NULL)
		return newNode;
	if(newNode->info < root->info)
		root->left = insertNode(root->left,ele);
	else
		root->right = insertNode(root->right,ele);
	
	return root;
}

void preorder(NODE *root)
{
	if(root != NULL)
	{
		printf("%d ",root->info);
		preorder(root->left);
		preorder(root->right);
	}
}
void inorder(NODE *root)
{
	if(root != NULL)
	{
		inorder(root->left);
		printf("%d ",root->info);
		inorder(root->right);
	}
}
void postorder(NODE *root)
{
	if(root != NULL)
	{
		postorder(root->left);
		postorder(root->right);
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

NODE* deleteNode(NODE *root,int ele)
{
	NODE *q=NULL;
	if(root==NULL)
	{
		return NULL;
	}
	else if(ele<root->info)
		root->left=deleteNode(root->left,ele);
	else if(ele>root->info)
		root->right=deleteNode(root->right,ele);
	else if(root->left==NULL)
	{
		q=root->right;
		free(root);
		return q;
	}
	else if(root->right==NULL)
	{
		q=root->left;
		free(root);
		return q;
	}
	else
	{
		NODE *q=root->right;
		
		while(q->left!=NULL)
			q=q->left;
		
		root->info = q->info;
		root->right=deleteNode(root->right,q->info);
	}
	return root;
	
	
}