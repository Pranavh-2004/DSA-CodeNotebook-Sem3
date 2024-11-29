/*
#include <stdio.h>
#include <stdlib.h>

// Structure definition

typedef struct node {
    int val;
    struct node* next;
    struct node* prev;
} NODE;

NODE* InsertEnd(NODE* tail, int value) {
//complete the function    
    NODE *temp = getNode(value);
    if (tail->head == NULL)
    {
        tail->head = temp;
        return;
    }
    NODE *p = tail->head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = temp;
    temp->prev = p;
}

// Function to print the list

void PrintList(NODE* head) {
    NODE* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->val);
        temp = temp->next;
    }
    printf("\n");
}

NODE* MergeTrains(NODE* list1, NODE* list2) {

   //complete the function
}
NODE* FreeList(NODE* head) {
    NODE* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
    return head;
}

int main() {
    NODE* list1 = NULL;
    NODE* tail1 = NULL;
    NODE* list2 = NULL;
    NODE* tail2 = NULL;
    int n1, n2, value;
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++) {
        scanf("%d", &value);
        if (list1 == NULL) {
            list1 = tail1 = InsertEnd(NULL, value);
        } else {
            tail1 = InsertEnd(tail1, value);
        }
    }
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++) {
        scanf("%d", &value);
        if (list2 == NULL) {
            list2 = tail2 = InsertEnd(NULL, value);
        } else {
            tail2 = InsertEnd(tail2, value);
        }
    }
    NODE* mergedtrain = MergeTrains(list1, list2);
  PrintList(mergedtrain);
   mergedtrain = FreeList(mergedtrain);

 return 0;
}
*/
/*
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    struct node* prev;
    int info;
    struct node* next;
} NODE;

typedef struct dlist
{
    NODE *head;
} DLIST;

void initList(DLIST *pdl);
void insertLast(DLIST *pdl, int ele);
void display(DLIST *pdl);
void freeList(DLIST *pdl);
void deleteAtPos(DLIST *pdl, int *pe, int pos);
int countNodes(DLIST *pdl);
NODE* getNode(int ele);
void edits(DLIST *pdl);
int deleteFront(DLIST *pdl, int *pe);
int deleteLast(DLIST *pdl, int *pe);
int countNodes(DLIST *pdl);

int main()
{
    DLIST lobj;
    initList(&lobj);
    int n, ele;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &ele);
        insertLast(&lobj, ele);
    }
  // Apply edits function
    edits(&lobj);

    display(&lobj);
    freeList(&lobj);
    return 0;
}

// Edits function that modifies the list based on multiples of 10

void edits(DLIST *pdl)
{
    NODE *p=pdl->head;
    NODE *tail=pdl->head;
    int nodecount=0;
    while(tail->next!=NULL){
        tail=tail->next;
    }
    while(p){
        nodecount++;
        if(p->info%10==0){
            if(p->prev!=pdl->head){
                p->prev->info++;
            }
            if(p->next!=tail){
                int deletedElement;
                deleteAtPos(&lobj,&deletedElement,nodecount+1);
            }
        }
    }

}
*/


/*
void edits(DLIST *pdl)
{
    NODE *p = pdl->head;
    NODE *tail = pdl->head;
    
    // Find the tail node
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    
    int nodecount = 0;
    while (p != NULL)
    {
        nodecount++;
        NODE *nextNode = p->next;

        if (p->info % 10 == 0)
        {
            if (p->prev != NULL)
            {
                p->prev->info++;
            }
            if (p->next != NULL && p != tail)
            {
                int deletedElement;
                deleteAtPos(pdl, &deletedElement, nodecount);  
                nodecount--;  
            }
        }

        p = nextNode;
    }
}

void initList(DLIST *pdl)
{
    pdl->head = NULL;
}

NODE *getNode(int ele)
{
    NODE *temp = (NODE *)malloc(sizeof(NODE));
    temp->prev = NULL;
    temp->info = ele;
    temp->next = NULL;
    return temp;
}

void insertLast(DLIST *pdl, int ele)
{
    NODE *temp = getNode(ele);
    if (pdl->head == NULL)
    {
        pdl->head = temp;
    }
    else
    {
        NODE *p = pdl->head;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = temp;
        temp->prev = p;
    }
}

void display(DLIST *pdl)
{
    NODE *p = pdl->head;
    if (p == NULL)
    {
        printf("Empty list\n");
    }
    else
    {
        while (p != NULL)
        {
            printf("%d ", p->info);
            p = p->next;
        }
        printf("\n");
    }
}
void freeList(DLIST *pdl)
{
    NODE *p = pdl->head;
    NODE *q = NULL;
    while (p != NULL)
    {
        q = p;
        p = p->next;
        free(q);
    }
    pdl->head = NULL;
}

void deleteAtPos(DLIST *pdl, int *pe, int pos){
    int n=countNodes(pdl);

    if(pos<0 || pos>n){
        return;
    }
    if (pos==0){
        deleteFront(pdl, pe);
        return;
    }
    if(pos==n){
        deleteLast(pdl, pe);
        return;
    }

    NODE *p=pdl->head;

    for(int i=0;i<pos;i++){
        p=p->next;
    }

    p->prev->next=p->next;
    p->next->prev=p->prev;
    free(p);

    return;
}

int deleteFront(DLIST *pdl, int *pe){
    if (pdl->head == NULL)
    {
        printf("DLL is empty\n");
        return 0;
    }
    NODE *p=pdl->head;
    pdl->head=p->next;

    *pe=p->info;
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
        *pe=p->info;
        free(p);
        return 1;
    }

    while (p->next!=NULL)
    {
        p=p->next;
    }
    
    *pe=p->info;
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
*/

/*
#include <stdio.h>
#include <stdlib.h>

// Structure definition

typedef struct node {
    int val;
    struct node* next;
    struct node* prev;
} NODE;

NODE *getNode(int ele)
{
    NODE *temp = malloc(sizeof(NODE));
    temp->next = NULL;
    temp->val = ele;
    temp->prev = NULL;
    return temp;
}

NODE* InsertEnd(NODE* tail, int value) {
//complete the function    
    NODE *temp = getNode(value);
    if (tail == NULL)
    {
        tail = temp;
        return 0;
    }
    NODE *p = tail;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = temp;
    temp->prev = p;
    
    return temp;
}

// Function to print the list

void PrintList(NODE* head) {
    NODE* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->val);
        temp = temp->next;
    }
    printf("\n");
}

NODE* MergeTrains(NODE* list1, NODE* list2) {
    NODE * merged=NULL;
    while(list1!=NULL && list2!=NULL){
        if(list1->val < list2->val){
            merged = InsertEnd(merged,list1->val);
            list1=list1->next;
        }
        else{
            merged = InsertEnd(merged,list2->val);
            list2=list2->next;
        }
    }

    while (list1!=NULL){
        merged = InsertEnd(merged,list1->val);
        list1=list1->next;
    }
    while (list2!=NULL){
        merged = InsertEnd(merged,list2->val);
        list2=list2->next;
    }
    while (merged->prev){
        merged=merged->prev;
    }
    return merged;
   
}
NODE* FreeList(NODE* head) {
    NODE* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
    return head;
}

int main() {
    NODE* list1 = NULL;
    NODE* tail1 = NULL;
    NODE* list2 = NULL;
    NODE* tail2 = NULL;
    int n1, n2, value;
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++) {
        scanf("%d", &value);
        if (list1 == NULL) {
            list1 = tail1 = InsertEnd(NULL, value);
        } else {
            tail1 = InsertEnd(tail1, value);
        }
    }
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++) {
        scanf("%d", &value);
        if (list2 == NULL) {
            list2 = tail2 = InsertEnd(NULL, value);
        } else {
            tail2 = InsertEnd(tail2, value);
        }
    }
    NODE* mergedtrain = MergeTrains(list1, list2);
    PrintList(mergedtrain);
    mergedtrain = FreeList(mergedtrain);

 return 0;
}
*/

/*
#include <stdio.h>
#include <stdlib.h>

// Structure definition

typedef struct node {
    int val;
    struct node* next;
    struct node* prev;
} NODE;

NODE *getNode(int ele)
{
    NODE *temp = malloc(sizeof(NODE));
    temp->next = NULL;
    temp->val = ele;
    temp->prev = NULL;
    return temp;
}

NODE* InsertEnd(NODE* tail, int value) {
    NODE *temp = getNode(value);
    if (tail == NULL) {
        return temp;  
    }
    tail->next = temp;
    temp->prev = tail;
    return temp;  
}

void PrintList(NODE* head) {
    NODE* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->val);
        temp = temp->next;
    }
    printf("\n");
}

NODE* MergeTrains(NODE* list1, NODE* list2) {
    NODE* merged = NULL;
    NODE* tail = NULL;

    while (list1 != NULL && list2 != NULL) {
        if (list1->val < list2->val) {
            tail = InsertEnd(tail, list1->val);
            if (merged == NULL) merged = tail;
            list1 = list1->next;
        } else {
            tail = InsertEnd(tail, list2->val);
            if (merged == NULL) merged = tail;
            list2 = list2->next;
        }
    }

    while (list1 != NULL) {
        tail = InsertEnd(tail, list1->val);
        if (merged == NULL) merged = tail;
        list1 = list1->next;
    }

    while (list2 != NULL) {
        tail = InsertEnd(tail, list2->val);
        if (merged == NULL) merged = tail;
        list2 = list2->next;
    }

    return merged;
}

NODE* FreeList(NODE* head) {
    NODE* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
    return head;
}

int main() {
    NODE* list1 = NULL;
    NODE* tail1 = NULL;
    NODE* list2 = NULL;
    NODE* tail2 = NULL;
    int n1, n2, value;

    scanf("%d", &n1);
    for (int i = 0; i < n1; i++) {
        scanf("%d", &value);
        if (list1 == NULL) {
            list1 = tail1 = InsertEnd(NULL, value);  
        } else {
            tail1 = InsertEnd(tail1, value);  
        }
    }

    scanf("%d", &n2);
    for (int i = 0; i < n2; i++) {
        scanf("%d", &value);
        if (list2 == NULL) {
            list2 = tail2 = InsertEnd(NULL, value);  
        } else {
            tail2 = InsertEnd(tail2, value);  
        }
    }

    NODE* mergedTrain = MergeTrains(list1, list2);

    PrintList(mergedTrain);

    mergedTrain = FreeList(mergedTrain);

    return 0;
}
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
  struct node* prev;
  int info;
  struct node* next;
} NODE;

typedef struct dlist
{
  NODE *head;
} DLIST;

void initList(DLIST *pdl);
void insertLast(DLIST *pdl, int ele);
void display(DLIST *pdl);
void freeList(DLIST *pdl);
void deleteAtPos(DLIST *pdl, int *pe, int pos);
int countNodes(DLIST *pdl);
NODE* getNode(int ele);
void edits(DLIST *pdl);

int main()
{
  DLIST lobj;
  initList(&lobj);
  int n, ele;

  scanf("%d", &n);

  for (int i = 0; i < n; i++)
  {
    scanf("%d", &ele);
    insertLast(&lobj, ele);
  }
  // Apply edits function
  edits(&lobj);

  display(&lobj);
  freeList(&lobj);
  return 0;
}

// Edits function that modifies the list based on multiples of 10
void edits(DLIST *pdl)
{
  NODE *head = pdl->head;
  int nodecount = 0;

  while (head!=NULL) {

    if (head->info % 10 == 0) {
      if (head->prev!=NULL)
        head->prev->info++;

      if (head->next!=NULL)
        deleteAtPos(pdl, NULL, nodecount+1);
    }
    
    nodecount++;
    head = head->next;
  }

}

void initList(DLIST *pdl)
{
  pdl->head = NULL;
}

NODE *getNode(int ele)
{
  NODE *temp = (NODE *)malloc(sizeof(NODE));
  temp->prev = NULL;
  temp->info = ele;
  temp->next = NULL;
  return temp;
}

void insertLast(DLIST *pdl, int ele)
{
  NODE *temp = getNode(ele);
  if (pdl->head == NULL)
  {
    pdl->head = temp;
  }
  else
  {
    NODE *p = pdl->head;
    while (p->next != NULL)
    {
      p = p->next;
    }
    p->next = temp;
    temp->prev = p;
  }
}

void display(DLIST *pdl)
{
  NODE *p = pdl->head;
  if (p == NULL)
  {
    printf("Empty list\n");
  }
  else
  {
    while (p != NULL)
    {
      printf("%d ", p->info);
      p = p->next;
    }
    printf("\n");
  }
}
void freeList(DLIST *pdl)
{
  NODE *p = pdl->head;
  NODE *q = NULL;
  while (p != NULL)
  {
    q = p;
    p = p->next;
    free(q);
  }
  pdl->head = NULL;
}

void deleteAtPos(DLIST *pdl, int *pe, int pos) {

  int nodecount = 0;
  NODE *temp = pdl->head;

  while (nodecount != pos) {
    temp = temp->next;
    nodecount++;
  }

  if (temp->prev)
    temp->prev->next = temp->next;


  if (temp->next)
    temp->next->prev = temp->prev;
}