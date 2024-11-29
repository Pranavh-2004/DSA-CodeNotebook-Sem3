#include<stdio.h>
#include<stdlib.h>
#define MAX 3

typedef struct circular_queue{
    int q[MAX];
    int front;
    int rear;
}CQ;

void initQueue(CQ *pq);
void enqueue(CQ *pq, int ele);
int dequeue(CQ *pq);
int isFull(CQ *pq);
int isEmpty(CQ *pq);
void display(CQ *pq);

int main(){
    CQ q;
    int choice, ele;
    initQueue(&q);
    do{
        printf("1.Enqueue 2.Dequeue 3.isFull 4.isEmpty 5.Display 6.Exit \n");
        printf("Enter your choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1: printf("Enter an element: ");
            scanf("%d",&ele);
            if(!isFull(&q)){
                enqueue(&q, ele);
                printf("%d enqueued\n", ele);
            }
            else{
                printf("queue is already full\n");
            }
            break;
        case 2: if(!isEmpty(&q)){
                printf("%d dequeued\n", dequeue(&q));
            }
            else{
                printf("queue is already empty\n");
            }
            break;
        case 3: if(isFull(&q)){
                printf("queue is full\n");
            }
            else{
                printf("queue can take element\n");
            }
            break;
        case 4:  if(isEmpty(&q)){
                printf("queue is empty\n");
            }
            else{
                printf("queue is not empty\n");
            }
            break;
        case 5: display(&q);
            break;
        case 6: exit(0);
        default:
            break;
        }
    }while(choice<7);

    return 0;
}

void initQueue(CQ *pq){
    pq->front=-1;
    pq->rear=-1;
}

void enqueue(CQ *pq, int ele){
    if(isEmpty(pq)){
        pq->front=0;
        pq->rear=0;
        pq->q[pq->rear]=ele;
    }
    else{
        pq->rear=(pq->rear+1)%MAX;
        pq->q[pq->rear]=ele;
    }
}

int dequeue(CQ *pq){
    int del = pq->q[pq->front];
    if(pq->front==pq->rear){
        initQueue(pq);
    }
    else{
        pq->front=(pq->front+1)%MAX;
    }
    return del;
}

int isFull(CQ *pq){
    return (pq->rear+1)%MAX==pq->front;
}

int isEmpty(CQ *pq){
    return pq->front == -1;
}

void display(CQ *pq){
    if(isEmpty(pq)){
        printf("Queue is empty\n");
        return;
    }
    for(int i = pq->front; i != pq->rear; i=(i+1)%MAX){
        printf("%d ", pq->q[i]);
    }
    printf("%d\n", pq->q[pq->rear]);
}