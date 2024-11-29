#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} NODE;
typedef struct dlist
{
    NODE *head;
} DLIST;

void initList(DLIST *pdl);
NODE *getNode(int ele);
void insertFront(DLIST *pdl, int ele);
void insertLast(DLIST *pdl, int ele);
void display(DLIST *pdl);
void destroy(DLIST *pdl);
int deleteFront(DLIST *pdl, int *pe);
int deleteLast(DLIST *pdl, int *pe);
int countNodes(DLIST *pdl);
int insertAtpos(DLIST *pdl, int ele, int pos);
int deleteAtpos(DLIST *pdl, int *pe, int pos);

int main(){
    DLIST lobj;
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

void initList(DLIST *pdl)
{
    pdl->head=NULL;
}
NODE *getNode(int ele)
{
    NODE *temp = malloc(sizeof(NODE));
    temp->next = NULL;
    temp->data = ele;
    temp->prev = NULL;
    return temp;
}
void insertFront(DLIST *pdl, int ele)
{
    NODE *temp = getNode(ele);
    if (pdl->head == NULL)
    {
        pdl->head = temp;
        return;
    }
    temp->next = pdl->head;
    pdl->head->prev = temp;
    pdl->head = temp;
}
void insertLast(DLIST *pdl, int ele)
{
    NODE *temp = getNode(ele);
    if (pdl->head == NULL)
    {
        pdl->head = temp;
        return;
    }
    NODE *p = pdl->head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = temp;
    temp->prev = p;
}
void display(DLIST *pdl)
{
    NODE *p = pdl->head;
    if (pdl->head == NULL)
    {
        printf("List is empty");
    }
    else
    {
        while (p != NULL)
        {
            printf("%d", p->data);
            p=p->next;
        }
    }
}
void destroy(DLIST *pdl){
    if(pdl->head==NULL){
        return ;
    }
    else{
        while(pdl->head->next!=NULL){
            pdl->head=pdl->head->next;
            free(pdl->head->prev);
        }
        free(pdl->head);
        pdl->head=NULL;
    }
}
int deleteFront(DLIST *pdl, int *pe){
    if (pdl->head == NULL)
    {
        printf("DLL is empty\n");
        return 0;
    }
    NODE *p=pdl->head;
    pdl->head=p->next;

    *pe=p->data;
    free(p);

    if(pdl->head!=NULL){
        pdl->head->prev=NULL;
        return 1;
    }
    return 0;
}

int deleteLast(DLIST *pdl, int *pe){
    if(pdl->head==NULL){
        printf("DLL is empty\n");
        return 0;
    }

    NODE *p=pdl->head;
    if(p->next==NULL){
        pdl->head=NULL;
        *pe=p->data;
        free(p);
        return 1;
    }

    while (p->next!=NULL)
    {
        p=p->next;
    }
    
    *pe=p->data;
    p->prev->next=NULL;
    free(p);
    return 1;
}

int countNodes(DLIST *pdl){
    NODE *p=pdl->head;
    int count=0;

    if(pdl->head==NULL){
        return count;
    }
    else{
        while (p!=NULL)
        {
            count++;
            p=p->next;
        }
        return count;
    }
}

int insertAtpos(DLIST *pdl, int ele, int pos){
    int n=countNodes(pdl);

    if(pos<0 || pos>n){
        return 0;
    }
    if (pos==0){
        insertFront(pdl,ele);
        return 1;
    }
    if(pos==n){
        insertLast(pdl,ele);
        return 1;
    }
    NODE *temp=getNode(ele);
    NODE *p=pdl->head;

    for(int i=0;i<pos;i++){
        p=p->next;
    }

    temp->next=p;
    temp->prev=p->prev;
    p->prev->next=temp;
    p->prev=temp;

    return 0;
}

int deleteAtpos(DLIST *pdl, int *pe, int pos){
    int n=countNodes(pdl);

    if(pos<0 || pos>n){
        return 0;
    }
    if (pos==0){
        deleteFront(pdl, pe);
        return 1;
    }
    if(pos==n){
        deleteLast(pdl, pe);
        return 1;
    }

    NODE *p=pdl->head;

    for(int i=0;i<pos;i++){
        p=p->next;
    }

    p->prev->next=p->next;
    p->next->prev=p->prev;
    free(p);

    return 0;
}