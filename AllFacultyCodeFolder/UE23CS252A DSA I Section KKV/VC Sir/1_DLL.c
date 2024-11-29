#include <stdio.h>
#include <stdlib.h>

//Structure Definition of NODE with Information field as INTEGER and 2 pointers for NEXT & PREV node

typedef struct abb
{
    int info;//information field
    struct abb *next;
    struct abb *prev;
} NODE;
//global decl which points to the first node of the DLL
NODE *header = NULL;
//request for new node using malloc

NODE* getnode()
{
    NODE *p;
    p= (NODE *) malloc(sizeof (NODE));
    //return((NODE* )malloc(sizeof (NODE));
    return (p);
}

void insert_front(void)
{
    NODE *p;
    int x;
    p = (NODE *)getnode();
    //CASE 0
    if (p==NULL)
    {
        printf("Insufficient MEMORY");
    }
    else
    {
        printf("Input the data to be inserted into the DLL\n");
        scanf("%d",&x);
        p->info = x;
        p->next = NULL;
        p->prev = NULL;
        //case 1
        if (header == NULL) header = p;
        else
            { //Case 2
            header->prev = p;
        p->next = header;
        header = p;
        }//end of CASE 2
    }// end of ELSE for CASE0
}//end of Function Insert_Front()

int delete_front(void)
{
    int x = -999;
    NODE *p;
    p = header;// copy of address header
    if (header == NULL)
    {

       printf("EMPTY LIST\n"); return (x);
    }
    else{
        if (header->next == NULL) //case 1
        {
            printf("LAST NODE deleted\n");
            x = header->info;
            free (header);
            header = NULL;
            return(x);

        }
        else  //case 2
        {
            x = header->info;
            header = header->next;
            header->prev = NULL;
            free(p);
			return(x);
        } //end of case 2
    }// end of Case 0
}//end of function DELETE_FIRST

void display(void)
{
    NODE *p;
    p = header;
    if (p== NULL) printf("EMPTY LIST\n");
    else while(p != NULL)
            {
                printf("%d\n",p->info);
                p=p->next;
            }
        {


    }
}
void menu(void)
{
    int choice,x;
    printf (" Input ----> 1 for Insert at Front\n");
    printf(" -----> 2 for Delete at Front\n");
    printf("-----> 3 for Display of DLL elements\n");
    printf("-----> ANY other value to EXIT\n");
    scanf("%d",&choice);
    switch (choice)
    {
        case 1: insert_front(); break;
        case 2: x= delete_front();
                if (x==-999) printf("No ELEMENT oN DLL\n");
                else printf("Deleted element is %d\n",x);
                break;
        case 3: display(); break;
        default : exit(1);
    } //end of Switch case
}//end of function MENU


int main()
{
    printf("Hello this is a program for operations on DOUBLY LINKED LIST!\n");
   for(;;)
    menu();
    return 0;
}
