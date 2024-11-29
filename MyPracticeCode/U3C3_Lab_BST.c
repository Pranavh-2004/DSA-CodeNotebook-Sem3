/*Level Order Traversal of a Binary Search Tree
Write a C program to construct a binary search tree(BST), 
perform level order traversal and print the elements in the same order.*/
/*
#include <stdio.h>
#include <stdlib.h>

#define MAX 20

typedef struct node
{
    int info;
    struct node* left;
    struct node* right;
}NODE;

typedef struct tree
{
    NODE *root;
}TREE;

typedef struct queue
{
    NODE* q[MAX];
    int front;
    int rear;
}QUEUE;

// Initializes the Binary Search Tree to be empty
void initTree(TREE *pt);
// Creates Binary Search Tree
void constructTree(TREE *pt,int ele);
// Prints the Binary Search tree in level order
void levelOrder(TREE *pt);
// Destroys all nodes in a Binary search tree and sets root = NULL
void destroyTree(TREE *pt);

void initQueue(QUEUE *pq);
void enqueue(QUEUE *pq, NODE *ele);
NODE* dequeue(QUEUE *pq);
int isEmpty(QUEUE *pq);

int main()
{
    TREE tobj;
    initTree(&tobj);

    int n;
    int ele;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &ele);
        constructTree(&tobj, ele);
    }

    levelOrder(&tobj);

    destroyTree(&tobj);

    return 0;
}

void initTree(TREE *pt) {
    pt->root = NULL;
}

void constructTree(TREE *pt, int ele) {
    NODE *temp = malloc(sizeof(NODE));
    temp->left = temp->right = NULL;
    temp->info = ele;

    if (pt->root == NULL) {
        pt->root = temp;
        return;
    }

    NODE *p = pt->root;
    NODE *q = NULL;

    while (p != NULL) {
        q = p;
        if (ele <= p->info) {
            p = p->left;
        } else {
            p = p->right;
        }
    }

    if (ele <= q->info) {
        q->left = temp;
    } else {
        q->right = temp;
    }
}

void levelOrder(TREE *pt) {
    if (pt->root == NULL) {
        return;
    }

    QUEUE q;
    initQueue(&q);
    enqueue(&q, pt->root);

    while (!isEmpty(&q)) {
        NODE* temp = dequeue(&q);
        printf("%d ", temp->info);

        if (temp->left != NULL) {
            enqueue(&q, temp->left);
        }

        if (temp->right != NULL) {
            enqueue(&q, temp->right);
        }
    }
    printf("\n");
}

void destroyNode(NODE *r) {
    if (r != NULL) {
        destroyNode(r->left);
        destroyNode(r->right);
        free(r);
    }
}

void destroyTree(TREE *pt) {
    destroyNode(pt->root);
    pt->root = NULL;
}

void initQueue(QUEUE *pq) {
    pq->front = 0;
    pq->rear = -1;
}

void enqueue(QUEUE *pq, NODE *ele) {
    if (pq->rear < MAX - 1) {
        pq->rear++;
        pq->q[pq->rear] = ele;
    }
}

NODE* dequeue(QUEUE *pq) {
    NODE* del = pq->q[pq->front];
    pq->front++;
    return del;
}

int isEmpty(QUEUE *pq) {
    return pq->front > pq->rear;
}
*/


/*Lowest Common Ancestor
Write a C program to construct a Binary Search Tree. 
Then input two nodes and find their Lowest Common Ancestor. 
You are expected to fill in the code for the following function: 
findLCA() : For finding the lowest common ancestor between two nodes n1 and n2.*/
/*
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int info;
    struct node* left;
    struct node* right;
}NODE;

NODE* constructTree(NODE *root,int ele);
NODE* findLCA(NODE* root, int n1, int n2,NODE* prev);
NODE* destroyTree(NODE* root);

int main()
{
NODE *root=NULL;
	
    int n;
    scanf("%d",&n);
    	
    for(int i=0;i<n;i++)
    {
        int ele;
        scanf("%d",&ele);
		root=constructTree(root,ele);
    }
	
    int n1,n2;
    scanf("%d %d",&n1,&n2);
    NODE* lca=findLCA(root,n1,n2,root);
    printf("%d",lca->info);
    destroyTree(root);
    return 0;
}

NODE* constructTree(NODE *root,int ele)
{
    NODE* node = (NODE*)malloc(sizeof(NODE));
    node->info = ele;
    node->left = NULL;
    node->right = NULL;
	
    if(root == NULL)
    {
        root = node;
    }
    else
    {
        NODE* p = root;
        NODE* q= NULL;
        while(p!=NULL)
        {
            if(node->info < p->info)
            {
                q=p;
                p = p->left;
            }
            else
            {
                q=p;
                p = p->right;
            }
        }
        if(node->info < q->info)
        {
            q->left = node;
        }
        else
        {
            q->right = node;
        }
    }
	return root;
}

NODE* destroyTree(NODE* root) 
{
    if (root != NULL) 
    {
        root->left=destroyTree(root->left);
        root->right=destroyTree(root->right);
//		printf("Freed %d\n",root->info);
        free(root);
    }
	return NULL;
}

NODE* findLCA(NODE* root, int n1, int n2,NODE* prev) 
{
    if((root->info<n1)^(root->info<n2)){
        return root;
    }
    else if((n1<root->info) && (n2<root->info)){
        return findLCA(root->left, n1, n2, root);
    }
    else if((n1>root->info) && (n2>root->info)){
        return findLCA(root->right, n1, n2, root);
    }
    else if(root->info==n1 || root->info==n2){
        return prev;
    }
    else{
        return root;
    }
}   
*/