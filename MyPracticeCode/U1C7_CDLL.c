#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} NODE;

typedef struct cdll
{
    NODE *head;
} CDLL;

void initList(CDLL *pl);
NODE *getNode(int ele);
void insertFront(CDLL *pl, int ele);
void insertLast(CDLL *pl, int ele);
void display(CDLL *pl);
void destroy(CDLL *pl);
int deleteFront(CDLL *pl, int *pe);
int deleteLast(CDLL *pl, int *pe);
int countNodes(CDLL *pl);
int insertAtpos(CDLL *pl, int ele, int pos);
int deleteAtpos(CDLL *pl, int *pe, int pos);


int main(){
    CDLL lobj;
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
        case 8: destroy(&lobj);
                printf("DLL destroyed\n");
                break;
        case 9: exit(1);
                break;
        default:
            break;
        }
    }while (choice<9);
    return 0;
}

void initList(CDLL *pl)
{
    pl->head=NULL;
}

NODE *getNode(int ele)
{
    NODE *temp = malloc(sizeof(NODE));
    temp->next = NULL;
    temp->data = ele;
    temp->prev = NULL;
    return temp;
}

void insertFront(CDLL *pl, int ele){
    NODE *temp=getNode(ele);

    if(pl->head==NULL){
        temp->next=temp;
        temp->prev=temp;
        pl->head=temp;
        return;
    }

    else if(pl->head->next=pl){
        pl->head->prev=temp;
        temp->next=pl->head;
        pl->head->next=temp;
        temp->prev=pl->head;
    }    
    
    else{
        NODE *last=pl->head->prev;

        temp->next=pl->head;
        temp->prev=pl->head->prev;
        last->next=temp;
        pl->head->prev=temp;
        pl->head=temp;
    }
}

void insertLast(CDLL *pl, int ele){
    NODE *temp=getNode(ele);

    if(pl->head==NULL){
        temp->next=temp;
        temp->prev=temp;
        pl->head=temp;
        return;
    }
    else{
        NODE *last=pl->head->prev;

        temp->prev=last;
        temp->next=pl->head;
        last->next=temp;
        pl->head->prev=temp;
    }
}

int countNodes(CDLL *pl){
    NODE *p=pl->head;
    NODE *last=pl->head->prev;
    int count=0;

    if(pl->head==NULL){
        return count;
    }
    else{
        while (p!=last)
        {
            count++;
            p=p->next;
        }
        count++;
        return count;
    }
}

void display(CDLL *pl){
    if (pl->head==NULL){
        printf("List is empty\n");
        return;
    }
    else{
        NODE *p=pl->head;
        do{
            printf("<-%d-> ",p->data);
            p=p->next;
        }while (p!=pl->head);
        printf("\n");
    }
}

void destroy(CDLL *pl){
    if(pl->head==NULL){
        return;
    }
    else{
        NODE *p=pl->head;
        NODE *last=pl->head->prev;
        while (pl->head!=last)
        {
            pl->head=p->next;
            free(p);
            p=pl->head;
        }
        free(pl->head);
    }
}

int deleteFront(CDLL *pl, int *pe){
    NODE *last=pl->head->prev;
    if(pl->head==NULL){
        return 0;
    }
    else if(pl->head=last){
        *pe=pl->head->data;
        free(pl->head);
        pl->head=NULL;
        return 1;
    }
    else{
        pl->head->next->prev=last;
        last->next=pl->head->next;

        *pe=pl->head->data;
        free(pl->head);
        pl->head=last->next;
        return 1;
    }
}

int deleteLast(CDLL *pl, int *pe){
    NODE *last=pl->head->prev;
    if(pl->head==NULL){
        return 0;
    }
    else if(pl->head=last){
        *pe=pl->head->data;
        free(pl->head);
        pl->head=NULL;
        return 1;
    }
    else{
        *pe=last->data;
        last->prev->next=pl->head;
        pl->head->prev=last->prev;
        free(last);
        return 1;
    }
}

int insertAtpos(CDLL *pl, int ele, int pos){
    int n=countNodes(pl);
    if (pos<0 || pos>n){
        return;
    }
    if (pos==0){
        insertFront(pl,ele);
        return;
    }
    if (pos==n){
        insertLast(pl,ele);
        return;
    }

    NODE *p=pl->head;
    for(int i=0; i<pos;i++){
        p=p->next;
    }

    NODE *temp=malloc(sizeof(NODE));
    temp->data=ele;

    temp->next=p;
    temp->prev=p->prev;
    p->prev->next=temp;
    p->prev=temp;

    return 0;
}

int deleteAtpos(CDLL *pl, int *pe, int pos){
    int n=countNodes(pl);
    if (pos<0 || pos>n){
        return;
    }
    if (pos==0){
        deleteFront(pl, pe);
        return;
    }
    if (pos==n){
        deleteLast(pl, pe);
        return;
    }

    NODE *p=pl->head;

    for(int i=0;i<pos;i++){
        p=p->next;
    }

    p->prev->next=p->next;
    p->next->prev=p->prev;

    *pe=p->data;
    free(p);

    return 0;
}