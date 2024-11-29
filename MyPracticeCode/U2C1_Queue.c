#include<stdio.h>
#include<stdlib.h>
#define MAX 3

typedef struct queue{
    int q[MAX];
    int front;
    int rear;
}QUEUE;

void initQueue(QUEUE *pq);
void enqueue(QUEUE *pq, int ele);
int dequeue(QUEUE *pq);
int isFull(QUEUE *pq);
int isEmpty(QUEUE *pq);
void display(QUEUE *pq);

int main(){
    QUEUE q;
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

void initQueue(QUEUE *pq){
    pq->front=0;
    pq->rear=-1;
}

void enqueue(QUEUE *pq, int ele){
    pq->rear++;
    pq->q[pq->rear]=ele;
}

int dequeue(QUEUE *pq){
    int del = pq->q[pq->front];
    pq->front++;
    return del;
}

int isFull(QUEUE *pq){
    return pq->rear==MAX-1;
}

int isEmpty(QUEUE *pq){
    return pq->front > pq->rear;
}

void display(QUEUE *pq){
    if(isEmpty(pq)){
        printf("Queue is empty\n");
        return;
    }
    for(int i = pq->front; i <= pq->rear; i++){
        printf("%d ", pq->q[i]);
    }
}