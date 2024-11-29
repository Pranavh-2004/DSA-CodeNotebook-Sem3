//BST LL
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int info;
	struct node *left;
	struct node *right; 
}NODE;

typedef struct tree
{
	struct node *root;
}TREE;

void initTree(TREE *pt);
void createTree(TREE *pt);
void inorder(TREE *pt);
void preorder(TREE *pt);
void postorder(TREE *pt);

int searchRecursive(TREE *pt,int ele);
void deleteNode(TREE *pt,int ele);

int findMin(TREE* pt);
int findMax(TREE *pt);
int findHeight(TREE *pt);
int leafCount(TREE *pt);
int nodeCount(TREE *pt);


int main()
{
	TREE tobj;
	
	initTree(&tobj);
	
	createTree(&tobj);
	
	printf("Inorder traversal\n");
	inorder(&tobj);
	
	printf("Preorder traversal\n");
	preorder(&tobj);
	
	printf("Postorder traversal\n");
	postorder(&tobj);
	/*
	int ele;
	printf("Enter an integer element\n");
    scanf("%d",&ele);
	
	if(searchRecursive(&tobj,ele))
	{
		printf("%d found\n",ele);
	    				 
	}
	else
	{
		printf("%d not found\n",ele);
	}
	*/
	
	
	int ele;
	printf("Enter an integer element\n");
    scanf("%d",&ele);
	if(searchRecursive(&tobj,ele))
	{
		//printf("%d not found\n",ele);
	    deleteNode(&tobj,ele);
		inorder(&tobj);
					 
	}
	
	int min=findMin(&tobj);
	if(min==-1)
		printf("Empty Tree\n");
	else
		printf("Min=%d\n",min);
	
	int max=findMax(&tobj);
	if(max==-1)
		printf("Empty Tree\n");
	else
		printf("Max=%d\n",max);
	
	int res1=findHeight(&tobj);//height and depth both are same no nedd to again 
	if(res1==-1)
		printf("Empty Tree\n");
	else
		printf("Tree Height=%d\n",res1);
	
	int res2=leafCount(&tobj);
	if(res2==-1)
		printf("Empty Tree\n");
	else
		printf("No of leafnodes=%d\n",res2);
		
	int res3=nodeCount(&tobj);
	if(res3==-1)
		printf("Empty Tree\n");
	else
		printf("No of nodes=%d\n",res3);
	
}


void initTree(TREE *pt)
{
	pt->root=NULL;
}

void createTree(TREE *pt)
{
	int choice;
	
	NODE *temp=malloc(sizeof(NODE));
	temp->left=temp->right=NULL;
	printf("enter the info\n");
	scanf("%d",&temp->info);
	
	pt->root=temp;
	
	printf("Do you want to add one more node\n");
	scanf("%d",&choice);
	
	while(choice)
	{
		temp=malloc(sizeof(NODE));
	    temp->left=temp->right=NULL;
	    printf("enter the info\n");
	    scanf("%d",&temp->info);
		
	
	    NODE *p=pt->root;
	    NODE *q=NULL;
	    while(p!=NULL)
	      {
	        if(temp->info<=p->info)
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
		  
		  if(temp->info<=q->info)
			  q->left=temp;
		  else
			  q->right=temp;
		  
		  printf("Do you want to add one more node\n");
	      scanf("%d",&choice);
		  
  }	
	
}



void inord(NODE *r)
{
	if(r!=NULL)
	{
		inord(r->left);
		printf("%d",r->info);
		inord(r->right);
	}
	
	
}

void inorder(TREE *pt)
{
	inord(pt->root);
}


void preord(NODE *r)
{
	if(r!=NULL)
	{
		printf("%d",r->info);
		preord(r->left);

		preord(r->right);
	}
	
	
}

void preorder(TREE *pt)
{
	preord(pt->root);
}

void postord(NODE *r)
{
	if(r!=NULL)
	{
		postord(r->left);
		
		postord(r->right);
		printf("%d",r->info);
	}
	
	
}

void postorder(TREE *pt)
{
	postord(pt->root);
}

int searchNode(NODE *r,int ele)
{
	if(r!=NULL)
	{
		if(ele==r->info)
			return 1;
		else if(ele<r->info)
			return searchNode(r->left,ele);
		else
			return searchNode(r->right,ele);
	}
	
}

int searchRecursive(TREE *pt,int ele)
{
	return searchNode(pt->root,ele);
}

NODE* delNode(NODE *r,int ele)
{
	NODE *temp=NULL,*p=NULL,*q=NULL;
	if(r==NULL)
		return r;
	if(ele<r->info)
		r->left=delNode(r->left,ele);
	else if(ele>r->info)
		r->right=delNode(r->right,ele);
	else if(r->left==NULL)
	{
		temp=r->right;
		free(r);
		return temp;
	}
	else if(r->right==NULL)
	{
		temp=r->left;
		free(r);
		return temp;
	}
	else
	{
		p=r->right;
		while(p->left!=NULL)
		{
			q=p;
			p=p->left;
		}
		r->info=p->info;
		q->left=p->right;
		free(p);
	}
	return r;
	
}
	
void deleteNode(TREE *pt,int ele)
{
	pt->root=delNode(pt->root,ele);
}

int findMinimum(NODE *r)
{
	if(r==NULL)
		return -1;
	while(r->left!=NULL)
		r=r->left;
	return r->info;
	
	
}
int findMin(TREE *pt)
{
	return findMinimum(pt->root);
}
int findMaximum(NODE *r)
{
	if(r==NULL)
		return -1;
	while(r->right!=NULL)
		r=r->right;
	return r->info;
}
int findMax(TREE *pt)
{
	return findMaximum(pt->root);
}

int max(int a,int b)
{
	return a>b?a:b;
}

int height(NODE *p)
{
	if(p==NULL)
		return -1;
	return 1+max(height(p->left),height(p->right));
	
	
}
int findHeight(TREE *pt)
{
	return height(pt->root);
}
int findLeafCount(NODE *p)
{
	if(p==NULL)
		return 0;
	if(p->left==NULL && p->right==NULL)
		return 1;
	return findLeafCount(p->left)+findLeafCount(p->right);
	
}
int leafCount(TREE *pt)
{
	if(pt->root==NULL)
		return -1;
	return findLeafCount(pt->root);	
}


int findnodeCount(NODE *p)
{		
	if(p==NULL)
		return 0;
	return (1+findnodeCount(p->left)+findnodeCount(p->right));
}	

int nodeCount(TREE *pt)
{
	if(pt->root==NULL)
		return -1;
	return findnodeCount(pt->root);	
	
}

