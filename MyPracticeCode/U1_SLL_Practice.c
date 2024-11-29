#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}NODE;

NODE *initList(NODE *head);
NODE *createnode(int ele);
NODE *insertFront(NODE *head, int ele);
NODE *insertLast(NODE *head, int ele);
NODE *deleteFront(NODE *head);
NODE *deleteLast(NODE *head);
NODE *insertAtpos(NODE *head, int pos, int ele);
NODE *deleteAtpos(NODE *head, int pos);
void display(NODE *head);

int main(){

}

NODE *initList(NODE *head){
    head=NULL;
    return head;
}

NODE *createnode(int ele){
    NODE *newnode=(NODE*)malloc(sizeof(NODE));
    newnode->data=ele;
    newnode->next=NULL;
    return newnode;
}

NODE *insertFront(NODE *head, int ele){
    NODE *newnode=createnode(ele);
    newnode->next=head;
    head=newnode;
    return head;
}

NODE *insertLast(NODE *head, int ele){
    NODE *newnode=createnode(ele);
    if (head == NULL) {
        return newnode;
    }
    NODE *p=head;
    while (p->next!=NULL)
    {
        p=p->next;
    }
    p->next=newnode;
    return head;
}

NODE *deleteFront(NODE *head){
    if(head==NULL){
        printf("List is empty\n");
    }
    else{
        NODE *p=head;
        printf("Deeleted element is: %d", p->data);
        head=p->next;
        free(p);
    }
    return head;
}

NODE *deleteLast(NODE *head){
    if(head==NULL){
        printf("List is empty\n");
    }
    else if (head->next == NULL) {  
        free(head);
        return NULL;
    }
    else{
        NODE *p=head;
        while (p->next->next!=NULL)
        {
            p=p->next;
        }
        NODE *pt=p->next;
        p->next=NULL;
        free(pt);
    }
    return head;
}

NODE *insertAtpos(NODE *head, int pos, int ele){
    NODE *newnode=createnode(ele);
    NODE *p=head;
    for(int i=0; i<pos;i++){
        p=p->next;
    }
    newnode->next=p->next;
    p->next=newnode;
    return head;
}

NODE *deleteAtpos(NODE *head, int pos){
    NODE *p=head;
    for(int i=0; i<pos-1;i++){
        p=p->next;
    }
    NODE *q=p->next;
    p->next=q->next;
    q->next=NULL;
    free(q);
    return head;
}

void display(NODE *head){
    NODE *pd=head;
    while (pd!=NULL)
    {
        printf("%d ",pd->data);
        pd=pd->next;
    }
    
}
