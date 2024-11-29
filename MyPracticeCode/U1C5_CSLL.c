#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int info;
    struct node* next;
} NODE;

typedef struct CSLL{
    NODE *last;
}CSLL;

void initList(CSLL *pl);
NODE *getNode(int ele);
void insertFront(CSLL *pl, int ele);
void insertLast(CSLL *pl, int ele);
void display(CSLL *pl);
void destroy(CSLL *pl);
int deleteFront(CSLL *pl, int *pe);
int deleteLast(CSLL *pl, int *pe);
int countNodes(CSLL *pl);
int insertAtpos(CSLL *pl, int ele, int pos);
int deleteAtpos(CSLL *pl, int *pe, int pos);

int main(){
        CSLL lobj;
    initList(&lobj);
    int choice,ele,pos;
    do{
        printf("1.InsertFront 2.InsertLast 3.DeleteFront 4.DeleteLast 5.Display 6.InsertAtpos 7.DeleteAtpos 8.Destroy 9.Exit\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1: printf("Enter an element\n");
                scanf("%d",&ele);
                insertFront(&lobj,ele);
                break;
        case 2: printf("Enter an element\n");
                scanf("%d",&ele);
                insertLast(&lobj,ele);
                break;
        case 3: deleteFront(&lobj,&ele);
                printf("Deleted element is %d\n",ele);
                break;
        case 4: deleteLast(&lobj,&ele);
                printf("Deleted element is %d\n",ele);
                break;
        case 5: display(&lobj);
                break;
        case 6: printf("Enter an element\n");
                scanf("%d",&ele);
                printf("Enter position to insert\n");
                scanf("%d",&pos);
                insertAtpos(&lobj,ele,pos);
                break;
        case 7: printf("Enter position to delete\n");
                scanf("%d",&pos);
                int deletedElement; 
                deleteAtpos(&lobj, &deletedElement, pos);
                break;
        // case 8: destroy(&lobj);
        //         printf("DLL destroyed\n");
        //         break;
        case 9: exit(1);
                break;
        default:
            break;
        }
    }while (choice<9);
    return 0;
}

void initList(CSLL *pl)
{
    pl->last=NULL;
}

void insertFront(CSLL *pl, int ele){
        NODE *temp=malloc(sizeof(NODE));
        temp->info=ele;

        if(pl->last==NULL){
                temp->next=temp;
                pl->last=temp;
                return;
        }
        
        temp->next=pl->last->next;
        pl->last->next=temp;

}

/*we dont need 2 pointers for insert last in CSLL as the pl->last pointer holds address of both first and last nodes 
*/

void insertLast(CSLL *pl, int ele){
        NODE *temp=malloc(sizeof(NODE));
        temp->info=ele;

        if(pl->last==NULL){
                temp->next=temp;
                pl->last=temp;
                return;
        }

        temp->next=pl->last->next;
        pl->last->next=temp;
        pl->last=temp;

}

void display(CSLL *pl){
        NODE *p=pl->last->next;
        if(pl->last==NULL){
        printf("List is empty\n");
        }
        else{
                p=pl->last->next;
                while (p!=pl->last)
        {
                printf("%d",p->info);
                p=p->next;
        }
        printf("%d",p->info);
        }
        /*or 
        do{
        printf("%d",p->info);
                p=p->next;
        }while(p!=pl->last)
        */
}

int deleteFront(CSLL *pl, int *pe){
        //case 1: list is empty
        if(pl->last==NULL){
                printf("CSLL is empty\n");
                return 0;
        }
 
        //case 2: single node
        if(pl->last==pl->last->next){
                *pe = pl->last->info;
                free(pl->last);
                pl->last=NULL;
                return 1;
        }

        //case 3: multiple nodes 
        NODE *p=pl->last->next;
        pl->last->next=p->next;
        *pe=p->info;
        free(p);
        return 1;
}

int deleteLast(CSLL *pl, int *pe){
        //case 1: list is empty
        if(pl->last==NULL){
                printf("CSLL is empty\n");
                return 0;
        }
 
        //case 2: single node
        if(pl->last==pl->last->next){
                *pe = pl->last->info;
                free(pl->last);
                pl->last=NULL;
                return 1;
        }

        //case 3: multiple nodes 
        NODE *p=pl->last->next;
        while(p->next!=pl->last){
                p=p->next;
        }
        p->next=pl->last->next;
        *pe=pl->last->info;
        free(pl->last);
        pl->last=p;
        return 1;
}

int insertAtpos(CSLL *pl, int ele, int pos){
        NODE *temp=malloc(sizeof(NODE));
        temp->info=ele;

        NODE *p=pl->last;
        for(int i=0; i<pos; i++){
                p=p->next;
        }
        temp->next=p->next;
        p->next=temp;

        return 0;
}

int deleteAtpos(CSLL *pl, int *pe, int pos){
        NODE *pd=pl->last;
        for(int i=0;i<pos-1;i++){
                pd=pd->next;
        }
        NODE *pi=pd->next;
        pd->next=pd->next->next;
        int ele=pi;
        free(pi);
        pi=NULL;

        *pe = ele;
        return 0;
}

void destroy(CSLL *pl){
        if(pl->last==NULL){
                return 0;
        }
        else{
                NODE *pd=pl->last->next;
                pl->last->next=NULL;
                NODE *p=pd;
                while(pd!=NULL){
                        pd=pd->next;
                        free(p);
                        p=pd;
                }
        }
}