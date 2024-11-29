#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct node{
    int info;
    struct node *left;
    struct node *right;
} NODE;

typedef struct tree{
    struct node *root;
} TREE;

typedef struct stack{
    int top;
    NODE *s[MAX];
}STACK;

void initTree(TREE *pt);
void createTree(TREE *pt);
void insertNode(TREE *pt, int ele);
void inorderTraversal(TREE *pt);
void preorderTraversal(TREE *pt);
void postorderTraversal(TREE *pt);
void destroyNode(NODE *r);
void destroyTree(TREE *pt);


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


void inorderTraversal(TREE *pt) {
    NODE *p=pt->root;
    STACK s;
    initStack(&s);

    while (p!=NULL || !isEmpty(&s)){
        if (p!=NULL){
            push(&s,p);
            p=p->left;
        }
        else{
            p=pop(&s);
            printf("%d", p->info);
            p=p->right;
        } 
    }
}


void preorderTraversal(TREE *pt) {
    NODE *p=pt->root;

    if(p==NULL){
        return;
    }

    STACK s;
    initStack(&s);

    push(&s,p);

    while (!isEmpty(&s)){
        p=pop(&s);
        printf("%d",p->info);

        if (p->right!=NULL){
            push(&s,p->right);
        }
        if (p->left!=NULL){
            push(&s,p->left);
        }
    }
}


void postorderTraversal(TREE *pt) {
    STACK s1, s2;
    initStack(&s1);
    initStack(&s2);

    NODE *p=pt->root;
    if(p==NULL){
        return;
    }
    push(&s1,p);
    while(!isEmpty(&s1)){
        p=pop(&s1);
        push(&s2,p);

        if (p->right!=NULL){
            push(&s1,p->right);
        }
        if (p->left!=NULL){
            push(&s1,p->left);
        }
    }

    while(!isEmpty(&s1)){
        p=pop(&s2);
        printf("%d ",p->info);
    }
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

void initStack(STACK *ps){
    ps->top=-1;
}

int isFull(STACK *ps){
    return ps->top==MAX-1;
}

int isEmpty(STACK *ps){
    return ps->top==-1;
}

int push(STACK *ps, int ele){
    if(isFull(ps)){
        return 0;
    }
    ps->top++;
    ps->s[ps->top]=ele; 

    //ps->s[++(ps->top)]=ele;
    return 1;
}

int pop(STACK *ps){
    if(isEmpty(ps)){
        return 0;
    }
    ps->top--;

    // *pe=ps->s[(ps->top)--];
    return 1;
}