//Right in threaded BST
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	struct node *left;
	int info;
	struct node *right;
	int rThread;
}NODE;

NODE* createTree(NODE *root);
void inorder(NODE *root);

int main()
{
	NODE *root=NULL;
	
	root=createTree(root);
	inorder(root);
}

NODE *createNode(int ele)
{
	NODE *newNode=malloc(sizeof(NODE));
	newNode->left=NULL;
	newNode->info=ele;
	newNode->right=NULL;
	newNode->rThread=1;
	
	return newNode;
}

void setLeft(NODE *cur,NODE *newNode)
{
	newNode->right=cur;
	cur->left=newNode;
}

void setRight(NODE *cur,NODE *newNode)
{
	newNode->right=cur->right;
	cur->right=newNode;
	cur->rThread=0;
}

NODE* createTree(NODE *root)
{
	int choice,ele;
	
	NODE *newNode=NULL;
	NODE *p=root;
	NODE *q=NULL;
	
	do
	{
		printf("Enter node info\n");
		scanf("%d",&ele);
		
		newNode=createNode(ele);
		
		if(root==NULL)
			root=newNode;
		else
		{
			p=root;
			
			while(p!=NULL)
			{
				q=p;
				
				if(newNode->info < p->info)
					p=p->left;
				else
				{
					if(p->rThread==1)
						break;
					p=p->right;
				}
			}
			if(p==NULL)
				setLeft(q,newNode);
			else
				setRight(p,newNode);
		}
		
		printf("Do you want to add one more node\n");
		scanf("%d",&choice);
	}while(choice);
	return root;
}
void inorder(NODE *root)
{
	NODE *p=root;
	NODE *q=NULL;
	
	while(p!=NULL)
	{
		while(p!=NULL)	//Moves to the leftmost
		{
			q=p;
			p=p->left;
		}
		printf("%d ",q->info);
		p=q->right;
		
		while(q->rThread==1 && p!=NULL)
		{
			printf("%d ",p->info);
			q=p;
			p=p->right;
		}
	}
}