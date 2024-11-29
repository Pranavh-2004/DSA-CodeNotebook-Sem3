#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int info;
    struct node *left;
    struct node *right;
} NODE;

typedef struct tree{
    struct node *root;
} TREE;

void initTree(TREE *pt);
void createTree(TREE *pt);
void inTraversal(NODE *r);
void inorder(TREE *pt);
void preTraversal(NODE *r);
void preorder(TREE *pt);
void postTraversal(NODE *r);
void postorder(TREE *pt);
void destroyNode(NODE *r);
void destroyTree(TREE *pt);
int findMinimum(NODE *r);
int findMin(TREE *pt);
int findMaximum(NODE *r);
int findMax(TREE *pt);
int searchNode(NODE *r, int ele);
int searchRecursive(TREE *pt, int ele);
NODE *delNode(NODE *r, int ele);
void deleteNode(TREE *pt, int ele);
int height(NODE *r);
int findHeight(TREE *pt);
int findLeafCount(NODE *r);
int leafCount(TREE *pt);
int findNodeCount(NODE *r);
int nodeCount(TREE *pt);
int max(int a, int b);

int main(){
    TREE tobj;
    initTree(&tobj);
    createTree(&tobj);

    printf("Inorder traversal:\n");
    inorder(&tobj);

    printf("Preorder traversal:\n");
    preorder(&tobj);

    printf("Postorder traversal:\n");
    postorder(&tobj);

    destroyTree(&tobj);

    int min = findMin(&tobj);
    if (min == -1) {
        printf("Empty Tree\n");
    } else {
        printf("Min = %d\n", min);
    }

    int max = findMax(&tobj);
    if (max == -1) {
        printf("Empty Tree\n");
    } else {
        printf("Max = %d\n", max);
    }

    int height = findHeight(&tobj);
    if (height == -1) {
        printf("Empty Tree\n");
    } else {
        printf("Tree Height = %d\n", height);
    }

    int leafs = leafCount(&tobj);
    if (leafs == -1) {
        printf("Empty Tree\n");
    } else {
        printf("Leaf Node count = %d\n", leafs);
    }

    int nodes = nodeCount(&tobj);
    if (nodes == -1) {
        printf("Empty Tree\n");
    } else {
        printf("Node count = %d\n", nodes);
    }

    int ele;
    printf("Enter an integer element\n");
    scanf("%d", &ele);

    if (searchRecursive(&tobj, ele)) {
        printf("%d found, deleting it\n", ele);
        deleteNode(&tobj, ele);
    } else {
        printf("%d not found\n", ele);
    }

    return 0;
}

void initTree(TREE *pt) {
    pt->root = NULL;
}

void createTree(TREE *pt) {
    int choice;
    NODE *temp = malloc(sizeof(NODE));
    temp->left = temp->right = NULL;

    printf("Enter info\n");
    scanf("%d", &temp->info);
    pt->root = temp;

    printf("1. Create another node 2. Exit\n");
    scanf("%d", &choice);

    while (choice == 1) {
        temp = malloc(sizeof(NODE));
        temp->left = temp->right = NULL;

        printf("Enter info\n");
        scanf("%d", &temp->info);

        NODE *p = pt->root;
        NODE *q = NULL;

        while (p != NULL) {
            q = p;
            if (temp->info <= p->info) {
                p = p->left;
            } else {
                p = p->right;
            }
        }

        if (temp->info <= q->info) {
            q->left = temp;
        } else {
            q->right = temp;
        }

        printf("1. Create another node 2. Exit\n");
        scanf("%d", &choice);
    }
}

void inTraversal(NODE *r) {
    if (r != NULL) {
        inTraversal(r->left);
        printf("%d ", r->info);
        inTraversal(r->right);
    }
}

void inorder(TREE *pt) {
    inTraversal(pt->root);
}

void preTraversal(NODE *r) {
    if (r != NULL) {
        printf("%d ", r->info);
        preTraversal(r->left);
        preTraversal(r->right);
    }
}

void preorder(TREE *pt) {
    preTraversal(pt->root);
}

void postTraversal(NODE *r) {
    if (r != NULL) {
        postTraversal(r->left);
        postTraversal(r->right);
        printf("%d ", r->info);
    }
}

void postorder(TREE *pt) {
    postTraversal(pt->root);
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

int findMinimum(NODE *r) {
    if (r == NULL) {
        return -1;
    }
    while (r->left != NULL) {
        r = r->left;
    }
    return r->info;
}

int findMin(TREE *pt) {
    return findMinimum(pt->root);
}

int findMaximum(NODE *r) {
    if (r == NULL) {
        return -1;
    }
    while (r->right != NULL) {
        r = r->right;
    }
    return r->info;
}

int findMax(TREE *pt) {
    return findMaximum(pt->root);
}

int searchNode(NODE *r, int ele) {
    if (r != NULL) {
        if (ele == r->info) {
            return 1;
        } else if (ele < r->info) {
            return searchNode(r->left, ele);
        } else {
            return searchNode(r->right, ele);
        }
    }
    return 0;
}

int searchRecursive(TREE *pt, int ele) {
    return searchNode(pt->root, ele);
}

NODE *delNode(NODE *r, int ele) {
    if (r == NULL) {
        return r;
    }
    if (ele < r->info) {
        r->left = delNode(r->left, ele);
    } else if (ele > r->info) {
        r->right = delNode(r->right, ele);
    } else {
        // Node with only one child or no child
        if (r->left == NULL) {
            NODE *temp = r->right;
            free(r);
            return temp;
        } else if (r->right == NULL) {
            NODE *temp = r->left;
            free(r);
            return temp;
        }

        // Node with two children, get the inorder successor
        NODE *p = r->right;
        NODE *q = NULL;
        while (p->left != NULL) {
            q = p;
            p = p->left;
        }
        r->info = p->info;
        if (q != NULL) {
            q->left = p->right;
        } else {
            r->right = p->right;
        }
        free(p);
    }
    return r;
}

void deleteNode(TREE *pt, int ele) {
    pt->root = delNode(pt->root, ele);
}

int height(NODE *r) {
    if (r == NULL) {
        return 0;
    }
    return max(height(r->left), height(r->right)) + 1;
}

int findHeight(TREE *pt) {
    return height(pt->root);
}

int findLeafCount(NODE *r) {
    if (r == NULL) {
        return 0;
    }
    if (r->left == NULL && r->right == NULL) {
        return 1;
    }
    return findLeafCount(r->left) + findLeafCount(r->right);
}

int leafCount(TREE *pt) {
    return findLeafCount(pt->root);
}

int findNodeCount(NODE *r) {
    if (r == NULL) {
        return 0;
    }
    return findNodeCount(r->left) + findNodeCount(r->right) + 1;
}

int nodeCount(TREE *pt) {
    return findNodeCount(pt->root);
}

int max(int a, int b) {
    return (a > b) ? a : b;
}


//idk why im keeping below code
/*
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int info;
    struct node *left;
    struct node *right;
}NODE;

typedef struct tree{
    struct node *root;
}TREE;

void initTree(TREE *pt);
// NODE *createNode(void);
void createTree(TREE *pt);
void inTraversal(NODE *r);
void inorder(TREE *pt);
void preTraversal(NODE *r);
void preorder(TREE *pt);
void postTraversal(NODE *r);
void postorder(TREE *pt);
void destroyNode(NODE *r);
void destroyTree(TREE *pt);
int findMinimum(NODE *r);
int findMin(TREE *pt);
int findMaximum(NODE *r);
int findMax(TREE *pt);
int searchNode(NODE *r, int ele);
int searchRecursive(TREE *pt, int ele);
NODE *delNode(NODE *r, int ele);
void deleteNode(TREE *pt, int ele);
// int search(NODE *r);
// int searchKey(TREE *pt);
int max(int a, int b);
int height(NODE *r);
int findHeight(TREE *pt);
int findLeafCount(NODE *r);
int leafCount(TREE *pt);
int findNodeCount(NODE *r);
int nodeCount(TREE *pt);

int main(){
    TREE tobj;
    initTree(&tobj);
    createTree(&tobj);

    printf("Inorder traversal:\n");
    inorder(&tobj);

    printf("Preorder traversal:\n");
    preorder(&tobj);

    printf("Postorder traversal:\n");
    postorder(&tobj);

    destroyTree(&tobj);

    int min=findMin(&tobj);
    if (min==-1){
        printf("Empty Tree\n");
    }
    else{
        printf("Min=%d\n", min);
    }

    int max=findMax(&tobj);
    if (max==-1){
        printf("Empty Tree\n");
    }
    else{
        printf("Max=%d\n", max);
    }

    int height = findHeight(&tobj);
    if (height==-1){
        printf("Empty Tree\n");
    }
    else{
        printf("Tree Height=%d\n", height);
    }

    int leafs = findHeight(&tobj);
    if (leafs==-1){
        printf("Empty Tree\n");
    }
    else{
        printf("Leaf Node count=%d\n", leafs);
    }

        int nodes = findHeight(&tobj);
    if (nodes==-1){
        printf("Empty Tree\n");
    }
    else{
        printf("Node count=%d\n", nodes);
    }

    int ele;
    printf("Enter an integer element\n");
    scanf("%d",&ele);

    if (searchRecursive(&tobj, ele)){
        // printf("%d found\n",ele);
        deleteNode(&tobj, ele);
    }
    else{
        printf("%d not found\n",ele);
    }

    return 0;
}

void initTree(TREE *pt){
    pt->root=NULL;
}

// NODE *createNode(void){
//     int choice;
//     NODE *temp=malloc(sizeof(NODE));
//     temp->left=temp->right=NULL;

//     printf("Enter info\n");
//     scanf("%d", &temp->info);

//     return temp;

// }

void createTree(TREE *pt){
    int choice;
    NODE *temp=malloc(sizeof(NODE));
    temp->left=temp->right=NULL;

    printf("Enter info\n");
    scanf("%d", &temp->info);
    pt->root=temp;

    printf("1.Create another node 2.Exit\n");
    scanf("%d",&choice);

    while (choice){
        temp=malloc(sizeof(NODE));
        temp->left=temp->right=NULL;

        printf("Enter info\n");
        scanf("%d", &temp->info); 

        NODE *p=pt->root;
        NODE *q=NULL;

        while(p!=NULL){
            if(temp->info <= p->info){
                q=p;
                p=p->left;
            }
            else{
                q=p;
                p=p->right;
            }
        }

        if(temp->info <= q->info){
            q->left=temp;
        }
        else{
            q->right=temp;
        }
    }
}

void inTraversal(NODE *r){
    if(r!=NULL){
        inTraversal(r->left);
        printf("%d",r->info);
        inTraversal(r->right);
    }
}

void inorder(TREE *pt){
    inTraversal(pt->root);
}

void preTraversal(NODE *r){
    if(r!=NULL){
        printf("%d",r->info);
        preTraversal(r->left);
        preTraversal(r->right);
    }
}

void preorder(TREE *pt){
    preTraversal(pt->root);
}

void postTraversal(NODE *r){
    if(r!=NULL){
        postTraversal(r->left);
        postTraversal(r->right);
        printf("%d",r->info);
    }
}

void postorder(TREE *pt){
    postTraversal(pt->root);
}

void destroyNode(NODE *r){
    if (r != NULL){
        // Recursively destroy the left and right subtrees
        destroyNode(r->left);
        destroyNode(r->right);
        // Free the current node
        free(r);
    }
}

void destroyTree(TREE *pt){
    // Start destroying from the root node
    destroyNode(pt->root);
    // After all nodes are destroyed, set the root to NULL
    pt->root = NULL;
}

int findMinimum(NODE *r){
    if(r==NULL){
        return -1;
    }
    while (r->left!=NULL){
        r=r->left;
    }
    return r->info;
    
}

int findMin(TREE *pt){
    return findMinimum(pt->root);
}

int findMaximum(NODE *r){
    if(r==NULL){
        return -1;
    }
    while (r->right!=NULL){
        r=r->right;
    }
    return r->info;
    
}

int findMax(TREE *pt){
    return findMaximum(pt->root);
}


int searchNode(NODE *r, int ele){
    if(r!=NULL){
        if(ele==r->info){
            return 1;
        }
        else if(ele<r->info){
            return searchNode(r->left,ele);
        }
        else if(ele>r->info){
            return searchNode(r->right,ele);
        }
        else{
            return -1;
        } 
    }
    return 0;
}

int searchRecursive(TREE *pt, int ele){
    return searchNode(pt->root,ele);
}

NODE *delNode(NODE *r, int ele){
    //case 1: leaf node
    //case 2: single child node
    //case 3: two child nodes
    NODE *temp;
    NODE *p, *q;
    if(r==NULL){
        return r;
    }
    if(ele<r->info){
        r->left=delNode(r->left, ele);
    }
    else if(ele>r->info){
        r->right=delNode(r->right, ele);
    }

    //case 2: single child node
    else if(r->left==NULL){
        temp=temp->right;
        free(r);
        return temp;
    }
    else if(r->right==NULL){
        temp=temp->left;
        free(r);
        return temp;
    }

    //case 3: two child nodes
    //inorder successor method 
    else{
        p=r->right;
        while (p->left!=NULL){
            q=p;
            p=p->left;
        }
        r->info=p->info;
        q->left=p->right;
        free(p);
    }
    return r;
    //for inorder predecessor switch all right and left in above code
}

void deleteNode(TREE *pt, int ele){
    pt->root=delNode(pt->root,ele);
}

int max(int a, int b){
    return (a > b) ? a : b;
}

int height(NODE *r) {
    if (r == NULL) {
        return -1;  
    } 
    else {
        return 1 + max(height(r->left),height(r->right));
    }
}

int findHeight(TREE *pt) {
    return height(pt->root);
}

int findLeafCount(NODE *r){
    if(r==NULL){
        return 0;
    }
    if (r->left==NULL && r->right==NULL){
        return 1;
    }
    return findLeafCount(r->left) + findLeafCount(r->right);
}

int leafCount(TREE *pt){
    if(pt->root==NULL){
        return -1;
    }
    return findLeafCount(pt->root);
}

int findNodeCount(NODE *r){
    if(r==NULL){
        return 0;
    }
    return(1+findNodeCount(r->left)+findNodeCount(r->right));
}

int nodeCount(TREE *pt){
    if(pt->root==NULL){
        return -1;
    }
    return findNodeCount(pt->root);
}
*/

