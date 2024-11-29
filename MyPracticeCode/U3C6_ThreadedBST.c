#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int info;
    struct node *left;
    struct node *right;
    int rthread;
}NODE;

typedef struct tree {
    struct node *root;
}TREE;

void setLeft(NODE *q, NODE *temp);
void setRight(NODE *p, NODE *temp);
void initTree(TREE *pt);
void createTree(TREE *pt);
NODE *createNode(int ele);
void inorder(TREE *pt);

int main(){
    TREE *tobj;
    initTree(&tobj);
    createTree(&tobj);

    printf("Inorder Traversal\n");
    inorderTree(&tobj);

    return 0;
}

void setLeft(NODE *q, NODE *temp){
    q->left=temp;
    temp->right=q;
}

void setRight(NODE *p, NODE *temp){
    temp->right=p->right;
    p->right=temp;
    p->rthread=0;
}

void initTree(TREE *pt){
    pt->root=NULL;
}

void createTree(TREE *pt){
    int ele, choice;
    printf("Enter root information\n");
    scanf("%d", &ele);
    pt->root=createNode(ele);

    printf("Do you want to add a new node?\n");
    scanf("%d", &choice);

    NODE *p, *q, *temp;
    while(choice){
        p=pt->root;
        q=NULL;
        printf("Enter node information\n");
        scanf("%d", &ele);
        temp=createNode(ele);

        while(p!=NULL){
            q=p;
            if(temp->info < p->info){
                p=p->left;
            }  
            else{
                if(p->rthread){
                    break;
                }
                p=p->right;
            }
        }
        if(p==NULL){
            setLeft(q, temp); 
        }
        else{
            setRight(p, temp);
        }
        printf("Do you want to add a new node?\n");
        scanf("%d", &choice);
    }
}

NODE *createNode(int ele){
    NODE *temp=malloc(sizeof(NODE));
    temp->info=ele;
    temp->left=NULL;
    temp->right=NULL;
    temp->rthread=1;
    return temp;
}

void inorder(TREE *pt){
    NODE *p=pt->root;
    NODE *q;
    do{
        while(p!=NULL){
        q=p;
        p=p->left;
        }
        if(q!=NULL){
            printf("%d", q->info);
            p=p->right;

            while(q->rthread && p!=NULL){
                printf("%d", p->info);
                q=p;
                p=p->right;
            }
        }
    }while(q!=NULL);
}