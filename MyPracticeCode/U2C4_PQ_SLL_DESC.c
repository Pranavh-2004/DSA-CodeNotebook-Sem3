#include<stdio.h>
#include<stdlib.h>

typedef struct priority_queue{
    int info;
    int priority;
    struct priority_queue* next;
} PQ;

typedef struct priority_queue_obj{
    PQ *head;
}PQSLL;

void initList(PQSLL *pl);
PQ *getPQnode(int ele, int priority);
void display(PQSLL *pl);
void dequeue(PQSLL *pl,int *pe);
void enqueue(PQSLL *pl,int ele, int priority);

int main(){
    PQSLL lobj;
    initList(&lobj);
    int choice, ele, priority;
    do{
        printf("1. Enqueue 2. Dequeue 3. Display 4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
        case 1: 
            printf("Enter an element: ");
            scanf("%d", &ele);
            printf("Enter priority: ");
            scanf("%d", &priority);
            enqueue(&lobj, ele, priority);
            break;
        case 2: 
            dequeue(&lobj, &ele);
            printf("Deleted element is %d\n", ele);
            break;
        case 3: 
            display(&lobj);
            break;
        case 4: 
            exit(1);
        default:
            printf("Invalid choice\n");
            break;
        }
    } while (choice < 5);

    return 0;
}

void initList(PQSLL *pl){
    pl->head = NULL;
}

PQ *getPQnode(int ele, int priority){
    PQ *temp = (PQ*)malloc(sizeof(PQ));
    temp->info = ele;
    temp->priority = priority;
    temp->next = NULL;
    return temp;
}

void display(PQSLL *pl){
    PQ *p = pl->head;
    if (pl->head == NULL) {
        printf("List is empty\n");
        return;
    }
    while (p != NULL) {
        printf("Element: %d, Priority: %d\n", p->info, p->priority);
        p = p->next;
    }
    printf("\n");
}

void dequeue(PQSLL *pl, int *pe){
    if (pl->head == NULL) {
        printf("Queue is empty\n");
        return;
    }
    PQ *p = pl->head;
    pl->head = p->next;
    *pe = p->info;
    free(p);
}

void enqueue(PQSLL *pl, int ele, int priority){
    PQ *temp = getPQnode(ele, priority);
    
    // Insert at head if the list is empty or if the new node has higher priority
    if (pl->head == NULL || pl->head->priority < priority) {
        temp->next = pl->head;
        pl->head = temp;
        return;
    }
    
    // Find the correct position to insert
    PQ *p = pl->head;
    while (p->next != NULL && p->next->priority >= priority) {
        p = p->next;
    }
    
    temp->next = p->next;
    p->next = temp;
}