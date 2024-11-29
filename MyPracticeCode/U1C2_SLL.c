#include<stdio.h>
#include<stdlib.h>
//single pointer
/*
typedef struct node{
    int info;
    struct node* next;
} NODE;

NODE *initList(NODE *head);

int main(){
    NODE *head;
    head=initList(head);
    if(head==NULL){
        printf("Empty list\n");
    }

    return 0;
}

NODE *initList(NODE *head){
    head=NULL;
    return head;
}
*/

//double pointer
/*
typedef struct node{
    int info;
    struct node* next;
} NODE;

void initList(NODE **phead);

int main(){
    NODE *head;
    initList(&head);
    if(head==NULL){
        printf("Empty list\n");
    }

    return 0;
}

void initList(NODE **phead){
    phead=NULL;
}
*/

//list object

typedef struct node{
    int info;
    struct node* next;
} NODE;

typedef struct llist{
    NODE *head;
}LLIST;

void initList(LLIST *pl);
void InsertFront(LLIST *pl,int ele);
NODE *getNode(int ele);
void InsertLast(LLIST *pl,int ele);
void Display(LLIST *pl);
void DeleteFront(LLIST *pl,int *pe);
void DeleteLast(LLIST *pl,int *pe);
void InsertAtpos(LLIST *pl,int ele, int pos);
void DeleteAtpos(LLIST *pl, int pos);

int main(){
    LLIST lobj;
    initList(&lobj);
    int choice,ele,pos;
    do{
        printf("1.InsertFront 2.InsertLast 3.DeleteFront 4.DeleteLast 5.Display 6.InsertAtpos 7.DeleteAtpos 8.Exit\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1: printf("Enter an element\n");
                scanf("%d",&ele);
                InsertFront(&lobj,ele);
                break;
        case 2: printf("Enter an element\n");
                scanf("%d",&ele);
                InsertLast(&lobj,ele);
                break;
        case 3: DeleteFront(&lobj,&ele);
                printf("Deleted element is %d",ele);
                break;
        case 4: DeleteLast(&lobj,&ele);
                printf("Deleted element is %d",ele);
                break;
        case 5: Display(&lobj);
                break;
        case 6: printf("Enter an element\n");
                scanf("%d",&ele);
                printf("Enter position to insert\n");
                scanf("%d",&pos);
                InsertAtpos(&lobj,ele,pos);
                break;
        case 7: printf("Enter position to delete\n");
                scanf("%d",&pos);
                DeleteAtpos(&lobj,pos);
                break;
        case 8: exit(1);
                break;
        default:
            break;
        }
    }while (choice<8);
    
    return 0;
}

void initList(LLIST *pl){
    pl->head=NULL;
}

NODE *getNode(int ele){
    NODE *temp=(NODE*)malloc(sizeof(NODE));
    temp->info=ele;
    temp->next=NULL;
    return temp;
}

void InsertFront(LLIST *pl,int ele){
    NODE *temp = getNode(ele);
    temp->next=pl->head;
    pl->head=temp;

}

/*
insert last:
case 1: List is empty
case 2: List is not empty
*/
void InsertLast(LLIST *pl,int ele){
    NODE *temp = getNode(ele);
    NODE *p=pl->head;
    if(pl->head==NULL){
        pl->head=temp;
    }
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=temp;
}

void Display(LLIST *pl){
    NODE *p=pl->head;
    if(pl->head==NULL){
    printf("List is empty\n");
    return;
    }
    while (p!=NULL)
    {
        printf("%d",p->info);
        p=p->next;
    }
    printf("\n");
}

/*
DeleteFront:
case 1: Single node
case 2: Multi node
*/

void DeleteFront(LLIST *pl,int *pe){
    NODE *p=pl->head;
    pl->head=p->next;
    *pe=p->info;
    free(p);
}

void DeleteLast(LLIST *pl,int *pe){
    NODE *p=pl->head;
    NODE *q;
    if(p->next==NULL){
        pl->head=NULL;
        *pe=p->info;
        free(p);
    }
    while (p->next!=NULL)
    {
        q=p;
        p=p->next;
    }
    q->next=NULL;
    *pe=p->info;
    free(p);
}

/*
InsertAtpos:
*/

void InsertAtpos(LLIST *pl,int ele, int pos){
    NODE *temp = getNode(ele);
    if (pos==0){
        temp->next=pl->head;
        pl->head=temp;
    }
    
    NODE *p=pl->head;
    NODE *q=NULL;
    temp->info=ele;
    for(int i=0;i<pos;i++){
        q=p;
        p=p->next;
    }
    q->next=temp;
    temp->next=p;
}

void DeleteAtpos(LLIST *pl, int pos){
    if (pos==0){
        printf("List is empty\n");
    }
    NODE *p=pl->head;
    NODE *q=NULL;
    for(int i=0;i<pos;i++){
        q=p;
        p=p->next;
    }

    //printf("%d %d",q->info,p->info);
    q->next=p->next;
    free(p);
}