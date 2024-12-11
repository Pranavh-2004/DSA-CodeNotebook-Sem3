#include<stdio.h>
#include<stdlib.h>

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
//Precondition: Tree not empty
int findMinIter(NODE *root);
//Precondition: Tree not empty
int findMinRec(NODE *root);
//Precondition: Tree not empty
int findMaxIter(NODE *root);
//Precondition: Tree not empty
int findMaxRec(NODE *root);
int findHeight(NODE *root);
int findLeafCount(NODE *root);
void findNodeCount1(NODE *root,int *count);
int findNodeCount2(NODE *root);
//Iterative Search
NODE* searchI(NODE *root,int ele);
//Recursive Search
NODE *searchR(NODE *root,int ele);

int main()
{
	NODE *root=NULL;
	
	int choice,ele,res;
	NODE *result=NULL;
	
	do
	{
		printf("1.Insert Node 2.Preorder 3.Inorder 4.Postorder\n");
		printf("5.FindMinIter 6.FindMinRec 7.FindMaxIter 8.FindMaxRec\n");
		printf("9.Height 10.LeafCount 11.NodeCount1 12.NodCount2\n");
		printf("13.SearchIterative 14.SearchRecursive\n");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:printf("Enter the element\n");
					scanf("%d",&ele);
					root=insertNode(root,ele);
					break;
			case 2:if(root==NULL)
						printf("Empty tree\n");
					else
					{
						preorder(root);
						printf("\n");
					}
					break;
			case 3:if(root==NULL)
						printf("Empty tree\n");
					else
					{
						inorder(root);
						printf("\n");
					}
					break;
			case 4:if(root==NULL)
						printf("Empty tree\n");
					else
					{
						postorder(root);
						printf("\n");
					}
					break;
			case 5:if(root==NULL)
						printf("Empty Tree\n");
					else
					{
						res=findMinIter(root);
						printf("Min ele is %d\n",res);
					}
					break;
			case 6:if(root==NULL)
						printf("Empty Tree\n");
					else
					{
						res=findMinRec(root);
						printf("Min ele is %d\n",res);
					}
					break;
			case 7:if(root==NULL)
						printf("Empty Tree\n");
					else
					{
						res=findMaxIter(root);
						printf("Max ele is %d\n",res);
					}
					break;
			case 8:if(root==NULL)
						printf("Empty Tree\n");
					else
					{
						res=findMaxRec(root);
						printf("Max ele is %d\n",res);
					}
					break;
			case 9:res=findHeight(root);
					if(res==-1)
						printf("Empty Tree\n");
					else
						printf("Height=%d\n",res);
					break;
			case 10:res=findLeafCount(root);
					if(res==0)
						printf("Empty Tree\n");
					else
						printf("LeafCount=%d\n",res);
					break;
			case 11:res=0;
					findNodeCount1(root,&res);
					if(res==0)
						printf("Empty Tree\n");
					else
						printf("NodeCount=%d\n",res);
					break;
			case 12:res=findNodeCount2(root);
					if(res==0)
						printf("Empty Tree\n");
					else
						printf("Node count=%d\n",res);
					break;		
			case 13:printf("Enter the ele to be searched\n");
					scanf("%d",&ele);
					result=searchI(root,ele);
					if(result==NULL)
						printf("Element not found\n");
					else
						printf("Element %d found\n",ele);
					break;
			case 14:printf("Enter the ele to be searched\n");
					scanf("%d",&ele);
					result=searchR(root,ele);
					if(result==NULL)
						printf("Element not found\n");
					else
						printf("Element %d found\n",ele);
					break;
		}
	}while(choice<15);
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

void preorder(NODE *root)
{
	if(root!=NULL)
	{
		printf("%d ",root->info);
		preorder(root->left);
		preorder(root->right);
	}
}

void inorder(NODE *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d ",root->info);
		inorder(root->right);
	}	
}
void postorder(NODE *root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d ",root->info);
	}	
}

NODE* destroyTree(NODE *root)
{
	if(root!=NULL)
	{
		root->left=destroyTree(root->left);
		root->right=destroyTree(root->right);
		printf("%d freed\n",root->info);
		free(root);
		root=NULL;
	}
	return root;
}

//Precondition: Tree not empty
int findMinIter(NODE *root)
{
	while(root->left != NULL)
		root=root->left;
	
	return root->info;
}
//Precondition: Tree not empty
int findMinRec(NODE *root)
{
	if(root->left!=NULL)
		return findMinRec(root->left);
	
	return root->info;
}

//Precondition: Tree not empty
int findMaxIter(NODE *root)
{
	while(root->right != NULL)
		root=root->right;
	
	return root->info;
}
//Precondition: Tree not empty
int findMaxRec(NODE *root)
{
	if(root->right!=NULL)
		return findMaxRec(root->right);
	
	return root->info;
}

int max(int a,int b)
{
	return a>b?a:b;
}

int findHeight(NODE *root)
{
	if(root==NULL)
		return -1;
	else
		return 1+max(findHeight(root->left),findHeight(root->right));
}

int findLeafCount(NODE *root)
{
	if(root==NULL)
		return 0;
	else if(root->left == NULL && root->right == NULL)
		return 1;
	else
		return findLeafCount(root->left)+findLeafCount(root->right);
}

void findNodeCount1(NODE *root,int *count)
{
	if(root!=NULL)
	{
		(*count)++;
		findNodeCount1(root->left,count);
		findNodeCount1(root->right,count);
	}
}

int findNodeCount2(NODE *root)
{
	if(root==NULL)
		return 0;
	else 
		return 1+findNodeCount2(root->left)+findNodeCount2(root->right);
}

//Iterative Search
NODE* searchI(NODE *root,int ele)
{
	while(root!=NULL)
	{
		if(ele==root->info)
			return root;
		else if(ele<root->info)
			root=root->left;
		else
			root=root->right;
	}
	return root;	//return NULL;
}

//Recursive Search
NODE *searchR(NODE *root,int ele)
{
	if(root==NULL)
		return root;	//return NULL;
	else if(ele==root->info)
		return root;
	else if(ele < root->info)
		return searchR(root->left,ele);
	else
		return searchR(root->right,ele);
}