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

void delete_bst(int key)
{
    node *temp=NULL,*prev=NULL;
    node *last=NULL, *temp1=NULL;
    temp = root;//initialization for the start of loop
    prev = temp;
    while ((temp!=NULL) && (temp->info!=key))
    {
        prev = temp;
       if (temp->info < key)
            temp=temp->rptr;
       else
         temp = temp->lptr;
    }
    //check whether its UNSUCCESSFUL SEARCH
    if (temp == NULL)
    {
        printf("ELEMENT NOT FOUND\n");
        return;
    }
    else
    { //ELEMENT IS present in BST
        printf("Element %d IS FOUND AND DELETED\n",key);
        //case 1 - deleting LEAF NODE
        if((temp->lptr == NULL)&&(temp->rptr==NULL))
        {
            if(key < prev->info)
                prev->lptr=NULL;
            else
                prev->rptr=NULL;
                printf("Deleted a LEAF NODE\n");
            free(temp);
        }


        else
        {
                if ((temp->lptr != NULL) && (temp->rptr != NULL))
                {
                    printf("FIND SUCCESSOR and Delete\n");
                    temp1 = temp->rptr;
                    while(temp1 != NULL)
                    {
                        last = temp1;
                        temp1 = temp1->lptr;
                    }
                temp->info = last->info;
                last->lptr=NULL;
                free(last);
                    return;
                }//end of CASE 3

        if (temp->lptr != NULL) //case 2 - Deleting NODE with ONE SUBTREE
           {
               if (temp->info < prev->info)
                prev->lptr = temp->lptr;
               else
                prev->rptr = temp->lptr;
                printf("Deleting from ONLy LSB \n");
                free(temp);
           }
           else
           {
               if (temp->rptr != NULL)
               {
                   if(temp->info < prev->info)
                    prev->lptr = temp->rptr;
                   else
                    prev->rptr = temp->rptr;
                    printf("Deleting from ONLY RST \n");
                    free(temp);
               }
           }//end of else
      }//end of CASE 2

    //CASE 3 - Has both LST and RST

  }//end of outer else
}//end of FUNCTION Delete_BST

void menu(void)
{
    int choice, info;
    node *temp=NULL;
    while(1)
    {
        printf("INPUT 1 ---------> to INSERT ELEMENT ONTO BST\n");
        printf("      2 ---------> TRAVERSE IN INORDER\n");
        printf("      3 ---------> DELETE SPECIFIC NODE\n");
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
            case 3: if (root == NULL) printf("EMPTY TREE\n");
                    else
                    {
                        printf("Input the VALUE to be deleted\n");
                        scanf("%d",&info);
                        delete_bst(info);
                    }//end if ELSE
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
