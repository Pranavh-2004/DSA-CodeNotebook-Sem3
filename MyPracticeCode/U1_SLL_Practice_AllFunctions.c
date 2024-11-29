#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}NODE;

NODE *initList(NODE *head);
NODE *createNode(int ele);
NODE *insertFront(NODE* head, int ele);
NODE *insertLast(NODE *head, int ele);
NODE *deleteFront(NODE *head);
NODE *deleteLast(NODE *head);
NODE *insertAtpos(NODE *head,int pos, int ele);
NODE *deleteAtpos(NODE *head,int pos);
int searchKey(NODE *head, int key);
NODE *bubbleSort(NODE *head);
int findMax(NODE *head);
int findMin(NODE *head);
int listMean(NODE *head);
NODE *reverseList(NODE *head);
void display(NODE *head);
NODE *freeList(NODE *head);

int main(){

    return 0;
}

NODE *initList(NODE *head){
    head=NULL;
    return head;
}

NODE *createNode(int ele){
    NODE *newnode=(NODE*)malloc(sizeof(NODE));
    newnode->data=ele;
    newnode->next=NULL;
    return newnode;
}

NODE *insertFront(NODE* head, int ele){
    NODE *pl=createNode(ele);
    pl->next=head;
    head=pl;
    return head;
}

NODE *insertLast(NODE *head, int ele){
    NODE *pl=createNode(ele);
    if(head==NULL){
        return pl;
    }
    NODE *p=head;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=pl;
    return head;
}

NODE *deleteFront(NODE *head){
    if (head==NULL){
        printf("List is empty\n");
    }
    else{
    NODE *pd=head;
    head=pd->next;
    free(pd);
    pd=NULL;
    }
    return head;
}

NODE *deleteLast(NODE *head){
    if (head==NULL){
        printf("List is empty\n");
    }
    else if(head->next==NULL){
        free(head);
        return NULL;
    }
    else{
        NODE *pd=head;
        while (pd->next->next!=NULL){
            pd=pd->next;
        }
        NODE *p=pd->next;
        pd->next=NULL;
        free(p);
        p=NULL;
    }
    return head;
}

NODE *insertAtpos(NODE *head,int pos, int ele){
    NODE *pl=createNode(ele);
    if(head==NULL || pos==0){
        insertFront(head, ele);
    }
    else{
        NODE *p=head;
        for(int i=0; i<pos-1; i++){
            p=p->next;
        }
        pl->next=p->next;
        p->next=pl;
    }
    return head;
}

NODE *deleteAtpos(NODE *head,int pos){
    if (head==NULL){
        printf("List is empty\n");
    }
    else if (pos==0){
        deleteFront(head);
    }
    else{
        NODE *p=head;
        for(int i=0; i<pos-1; i++){
            p=p->next;
        }
        NODE *pd=p->next;
        p->next=p->next->next;
        free(pd);
        pd=NULL;
    }
    return head;    
}

int searchKey(NODE *head, int key) {
    NODE *p = head;
    int pos = 0;
    while (p != NULL) {
        if (p->data == key) {
            printf("Position of element %d is: %d\n", key, pos);
            return p; 
        }
        p = p->next;
        pos++;
    }
    printf("Element %d not found in the list\n", key);
    return NULL;
}

NODE *bubbleSort(NODE *head) {
    if (head == NULL || head->next == NULL) {
        return head; 
    }
    NODE *end = NULL;
    int swapped;

    do {
        swapped = 0;  
        NODE *p = head;
        while (p->next != end) {
            if (p->data > p->next->data) {
                int temp = p->data;
                p->data = p->next->data;
                p->next->data = temp;
                swapped = 1;
            }
            p = p->next;
        }
        end = p; 
    } while (swapped);

    return head;
}

int findMax(NODE *head){
    if (head == NULL) {
        printf("List is empty\n");
        return -1;
    }
    NODE *p=head;
    int max=p->data;
    while (p!=NULL){
        if(p->data > max){
            max=p->data;
        }
        p=p->next;
    }
    printf("Max value in list is: %d\n", max);
    return max;
}

int findMin(NODE *head){
    if (head == NULL) {
        printf("List is empty\n");
        return -1;
    }
    NODE *p=head;
    int min=p->data;
    while (p!=NULL){
        if(p->data < min){
            min=p->data;
        }
        p=p->next;
    }
    printf("Min value in list is: %d\n", min);
    return min;
}

int listMean(NODE *head){
    if (head == NULL) {
        printf("List is empty\n");
        return -1;
    }
    NODE *p=head;
    int sum=0;
    int count=0;
    while (p!=NULL){
        sum+=p->data;
        count++;
        p=p->next;
    }
    float mean = (float)sum/count;
    printf("Mean value of list is: %.2f\n", mean);
    return mean;
}

NODE *reverseList(NODE *head) {
    NODE *prev = NULL;
    NODE *current = head;
    NODE *next = NULL;

    while (current != NULL) {
        next = current->next;  // Store the next node
        current->next = prev;  // Reverse the current node's pointer
        prev = current;        // Move `prev` to this node
        current = next;        // Move to the next node in the original list
    }

    head = prev;  // Set the new head to `prev`, which is the last non-NULL node
    return head;
}

void display(NODE *head){
    NODE *p=head;
    while (p!=NULL){
        printf("%d -> ",p->data);
        p=p->next;
    }
}

NODE *freeList(NODE *head){
    if(head==NULL){
        printf("List is empty\n");
    }
    NODE *p=head;
    while(head!=NULL){
        head=head->next;
        free(p);
        p=head;
    }
    return head;
}