#include<stdio.h>
#include<stdlib.h>
#define MAX 5

typedef struct double_ended_queue{
    int q[MAX];
    int front;
    int rear;
}DEQ;

void initQueue(DEQ *pq);
void enqueueRear(DEQ *pq, int ele);
int dequeueFront(DEQ *pq);
void enqueueFront(DEQ *pq, int ele);
int dequeueRear(DEQ *pq);
int isFull(DEQ *pq);
int isEmpty(DEQ *pq);
void display(DEQ *pq);

int main(){
    DEQ q;
    int choice, ele;
    initQueue(&q);
    do{
        printf("1.Enqueue Rear 2.Dequeue Front 3.Enqueue Front 4.Dequeue Rear 5.isFull 6.isEmpty 7.Display 8.Exit \n");
        printf("Enter your choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1: printf("Enter an element: ");
            scanf("%d",&ele);
            if(!isFull(&q)){
                enqueueRear(&q, ele);
                printf("%d enqueued\n", ele);
            }
            else{
                printf("queue is already full\n");
            }
            break;
        case 2: if(!isEmpty(&q)){
                printf("%d dequeued\n", dequeueFront(&q));
            }
            else{
                printf("queue is already empty\n");
            }
            break;
        case 3: printf("Enter an element: ");
            scanf("%d",&ele);
            if(!isFull(&q)){
                enqueueFront(&q, ele);
                printf("%d enqueued\n", ele);
            }
            else{
                printf("queue is already full\n");
            }
            break;
        case 4: if(!isEmpty(&q)){
                printf("%d dequeued\n", dequeueRear(&q));
            }
            else{
                printf("queue is already empty\n");
            }
            break;
        case 5: if(isFull(&q)){
                printf("queue is full\n");
            }
            else{
                printf("queue can take element\n");
            }
            break;
        case 6:  if(isEmpty(&q)){
                printf("queue is empty\n");
            }
            else{
                printf("queue is not empty\n");
            }
            break;
        case 7: display(&q);
            break;
        case 8: exit(0);
        default:
            break;
        }
    }while(choice<9);

    return 0;
}

void initQueue(DEQ *pq){
    pq->front=-1;
    pq->rear=-1;
}

void enqueueRear(DEQ *pq, int ele){
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

int dequeueFront(DEQ *pq){
    int del = pq->q[pq->front];
    if(pq->front==pq->rear){
        initQueue(pq);
    }
    else{
        pq->front=(pq->front+1)%MAX;
    }
    return del;
}

void enqueueFront(DEQ *pq, int ele){
    if(isEmpty(pq)){
        pq->front=0;
        pq->rear=0;
        pq->q[pq->rear]=ele;
    }
    else{
        pq->front=(pq->front-1+MAX)%MAX;
        pq->q[pq->front]=ele;
    }
}

int dequeueRear(DEQ *pq){
    int del = pq->q[pq->rear];  
    if (pq->front == pq->rear) {
        initQueue(pq);  // 
    } else {
        pq->rear = (pq->rear - 1 + MAX) % MAX;  
    }
    return del;
}

int isFull(DEQ *pq){
    return (pq->rear+1)%MAX==pq->front;
}

int isEmpty(DEQ *pq){
    return pq->front == -1;
}

void display(DEQ *pq){
    if(isEmpty(pq)){
        printf("Queue is empty\n");
        return;
    }
    for(int i = pq->front; i != pq->rear; i=(i+1)%MAX){
        printf("%d ", pq->q[i]);
    }
    printf("%d\n", pq->q[pq->rear]);
}

// mcq question: they may give DEQ diagram and ask for the significance of both MAXs' in the mcq
// pq->front = (pq->front-1+MAX)%MAX
//eg: (0-1+5)%5 = 4%5 = 4 where MAX=5