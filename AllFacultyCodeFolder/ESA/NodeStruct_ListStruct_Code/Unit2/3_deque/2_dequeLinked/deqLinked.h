typedef struct node
{
	struct node *prev;
	int info;
	struct node *next;
}NODE;

typedef struct queue
{
	NODE *front;
	NODE *rear;
}QUEUE;

void initQueue(QUEUE *pq);
void enqueueRear(QUEUE *pq,int ele);
void enqueueFront(QUEUE *pq,int ele);
int dequeueFront(QUEUE *pq);
int dequeueRear(QUEUE *pq);
int isEmpty(QUEUE *pq);
void display(QUEUE *pq);
void destroyQueue(QUEUE *pq);