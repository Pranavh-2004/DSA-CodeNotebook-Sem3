#include<stdio.h>
#include<stdlib.h>

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
void Display(LLIST *pl);
void SLLcat(LLIST *pl1, LLIST *pl2);

int main(){
    LLIST lobj1;
    initList(&lobj1);
    LLIST lobj2;
    initList(&lobj2);
    int choice,ele,pos;
    do{
        printf("First list: \n 1.InsertFront 2.Display 3.Exit\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1: printf("Enter an element\n");
                scanf("%d",&ele);
                InsertFront(&lobj1,ele);
                break;
        case 2: Display(&lobj1);
                break;
        case 3: printf("Exited sll 1");
                break;
        default:
            break;
        }
    }while (choice<3);

        do{
        printf("second list: \n 1.InsertFront 2.Display 3.Exit\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1: printf("Enter an element\n");
                scanf("%d",&ele);
                InsertFront(&lobj2,ele);
                break;
        case 2: Display(&lobj2);
                break;
        case 3: SLLcat(&lobj1,&lobj2);
                break;
        case 4: exit(1);
                break;
        default:
            break;
        }
    }while (choice<3);
    
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

void SLLcat(LLIST *pl1, LLIST *pl2){
    NODE *p=pl1->head;
    if(pl1->head==NULL){
        pl1->head=pl2->head;
    return;
    }
    while (p->next!=NULL)
    {
        p=p->next;
    }
    p->next=pl2->head;

    NODE *pd=pl1->head;
    while (p!=NULL)
    {
        printf("%d",pd->info);
        pd=pd->next;
    }
}