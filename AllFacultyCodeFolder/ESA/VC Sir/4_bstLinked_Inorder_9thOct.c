#include <stdio.h>
#include <stdlib.h>

//Program to Implement Binary Search Tree using Dynamic Memory or Pointers

struct abb
{
    int info;
    struct abb *lptr;
    struct abb *rptr;
};

typedef struct abb node;

node *root=NULL;// pointer to the ROOT node of the BST

node *getnode(void)
{
    node *p;
    p =(node *)malloc(sizeof(node));
    return (p);
} //end of function GETNODE

void insert_bst(int x)
{
    node *temp=NULL, *prev = NULL, *p=NULL;
    p = getnode();
    if (p== NULL)
        printf("Insufficient MEMORY\n");
    else
    {
        p->info = x;
        p->lptr = NULL;
        p->rptr = NULL;
        //case 0
        if (root == NULL)
            root = p;
        else
        {
            //case 1 check for the correct location in BST
            temp = root;
            while(temp!=NULL)
            {
                prev = temp;
                if(x<temp->info)
                    temp = temp->lptr;
                else
                    temp = temp->rptr;
            }//end of while loop
            //Update Parent node
            if(x<prev->info)
                prev->lptr = p;
            else
                prev->rptr = p;
        }//end of Case1
    }//end of else
}//end of function INSERT_BST

void inorder(node *temp)
{

    if (temp != NULL)
    {
        inorder(temp->lptr);
        printf("Element is --> %d\n", temp->info);
        inorder(temp->rptr);
    }
}//end of INORDER traversal recursive function

void menu(void)
{
    int choice;
    node *temp=NULL;
    while(1)
    {
        printf("INPUT 1 ---------> to INSERT ELEMENT ONTO BST\n");
        printf("      2 ---------> TRAVERSE IN IORDER\n");
        printf("      ---->ANY OTHER VALUE to EXIT\n");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1: printf("Input Value to be Inserted on to BST\n");
                    scanf("%d",&choice);
                    insert_bst(choice);
                    break;
            case 2: printf("TRAVERSING IN INORDER\n");
                    temp = root;
                    inorder(temp);
                    break;
            default: exit(1);
        }//end of switch case
    }//end of while loop
}//end of function MENU

int main()
{
    printf("Hello world!\n");
    printf("PROGRAM TO SHOWCASE INSERT & TRAVERSE IN INORDER IN A BST\n");
    menu();
    return 0;
}
