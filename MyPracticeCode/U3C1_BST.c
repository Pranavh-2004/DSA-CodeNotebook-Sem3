#include<stdio.h>
#include<stdlib.h>
#define MAX 20

typedef struct node{
    int info;
    int used;
}NODE;

void initTree(NODE bst[MAX]);
void createTree(NODE bst[MAX]);
void levelorder(NODE bst[MAX]);
void inorder(NODE bst[MAX], int i);
void preorder(NODE bst[MAX], int i);
void postorder(NODE bst[MAX], int i);

int main(){
    NODE bst[MAX];
    initTree(bst);
    createTree(bst);

    printf("Tree in level order\n");
    levelorder(bst);
    printf("\n");

    printf("Tree in Inorder\n");
    inorder(bst, 0);
    printf("\n");

    printf("Tree in Preorder\n");
    preorder(bst, 0);
    printf("\n");

    printf("Tree in Postorder\n");
    postorder(bst, 0);
    printf("\n");

    return 0;
}

void initTree(NODE bst[MAX]){
    for(int i = 0; i < MAX; i++){
        bst[i].used = 0;
    }
}

void createTree(NODE bst[MAX]){
    int ele, choice;
    printf("Enter root info: ");
    scanf("%d", &ele);
    bst[0].info = ele;
    bst[0].used = 1;

    printf("Do you want to add another node? (0 for No, 1 for Yes): ");
    scanf("%d", &choice);
    int i;
    while(choice){
        printf("Enter the node info: ");
        scanf("%d", &ele);

        i = 0; // reset to root for each insertion
        while(i < MAX && bst[i].used){
            if(ele < bst[i].info){
                i = 2*i + 1;
            }
            else{
                i = 2*i + 2;
            }
        }
        if(i >= MAX){
            printf("Outside array bound\n");
            break;
        }
        bst[i].info = ele;
        bst[i].used = 1;
        printf("Do you want to add another node? (0 for No, 1 for Yes): ");
        scanf("%d", &choice);
    }
}

void levelorder(NODE bst[MAX]){
    int j = 1;
    for(int i = 0; i < MAX; i++){
        if(bst[i].used){  // only print used nodes
            if(i == j){
                printf("\n");
                j *= 2;
            }
            printf("%d ", bst[i].info);
        }
    }
    printf("\n");
}

void inorder(NODE bst[MAX], int i){ // LVR
    if(i < MAX && bst[i].used){
        inorder(bst, 2*i + 1); // L
        printf("%d ", bst[i].info); // V
        inorder(bst, 2*i + 2); // R
    }
}

void preorder(NODE bst[MAX], int i){ // VLR
    if(i < MAX && bst[i].used){
        printf("%d ", bst[i].info); // V
        preorder(bst, 2*i + 1); // L
        preorder(bst, 2*i + 2); // R
    }
}

void postorder(NODE bst[MAX], int i){ // LRV
    if(i < MAX && bst[i].used){
        postorder(bst, 2*i + 1); // L
        postorder(bst, 2*i + 2); // R
        printf("%d ", bst[i].info); // V
    }
}