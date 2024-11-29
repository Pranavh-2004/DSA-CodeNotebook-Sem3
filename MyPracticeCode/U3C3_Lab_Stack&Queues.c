// #include <stdio.h>
// #include <stdlib.h>

// #define MAX_QUEUE_SIZE 100

// typedef struct {
//     int data[MAX_QUEUE_SIZE];
//     int front;
//     int rear;
//     int size;
// } Queue;

// void initializeQueue(Queue* queue) {
//     //initilaize the queue
//     queue->front=0;
//     queue->rear=-1;
//     queue->size=0;
// }

// int isQueueEmpty(Queue* queue) 
// {
//     //check if the queue is empty
//     return queue->size==0;
// }


// void enqueue(Queue* queue, int person) 
// {
//     //complete this function to perform enqueue function , also if queue is full print "queue is full"
//     if(queue->rear==MAX_QUEUE_SIZE-1){
//         printf("queue is full");
//         return;
//     }
//     queue->rear++;
//     queue->data[queue->rear]=person;
//     queue->size++;
// }

// int dequeue(Queue* queue) 
// {
//     //function to dequeue element from queue
//     if (isQueueEmpty(queue)) {
//     printf("queue is empty\n");
//     return -1; // Handle empty queue case
//     }
//     int del = queue->data[queue->front];
//     queue->front++;
//     queue->size--;
//     return del;
// }

// Queue* createQueue()
//  {
//     Queue* queue = (Queue*)malloc(sizeof(Queue));
//     if (queue == NULL)
//     {
        
//         exit(EXIT_FAILURE);
//     }
//     initializeQueue(queue);
//     return queue;

// }

// void roundRobinDequeue(Queue** queues, int m, int n) {
//     int totalDequeued = 0;
//     int queueIndex = 0;
    
//     // Perform round-robin dequeue until all people are dequeued
//     while (totalDequeued < m) {
//         if (!isQueueEmpty(queues[queueIndex])) {
//             int person = dequeue(queues[queueIndex]);
//             printf("%d ", person); // Print the dequeued person
//             totalDequeued++;
//         }
//         queueIndex = (queueIndex + 1) % n; // Move to the next queue in round-robin
//     }
// }

// int main() {
//     int m, n;

//     // Read the total number of people and number of queues
//     scanf("%d", &m);
//     scanf("%d", &n);

//     // Read the people array
//     int* arr = (int*)malloc(m * sizeof(int));
//     for (int i = 0; i < m; ++i) {
//         scanf("%d", &arr[i]);
//     }

//     // Create and initialize queues
//     Queue** queues = (Queue**)malloc(n * sizeof(Queue*));
//     for (int i = 0; i < n; ++i) {
//         queues[i] = createQueue();
//     }

//     // Distribute people into queues in a round-robin fashion
//     for (int i = 0; i < m; ++i) {
//         enqueue(queues[i % n], arr[i]);
//     }

//     // Perform the round-robin dequeuing
//     roundRobinDequeue(queues, m, n);

//     // Free memory
//     free(arr);
//     for (int i = 0; i < n; ++i) {
//         free(queues[i]);
//     }
//     free(queues);

//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>

// #define MAX_QUEUE_SIZE 100

// typedef struct {
//     int data[MAX_QUEUE_SIZE];
//     int front;
//     int rear;
//     int size;
// } Queue;

// void initializeQueue(Queue* queue) {
//     // Initialize the queue
//     queue->front = 0;
//     queue->rear = -1;
//     queue->size = 0;
// }

// void enqueue(Queue* queue, int person) {
//     // Check if the queue is full
//     if (queue->size == MAX_QUEUE_SIZE) {
//         printf("queue is full\n");
//         return;
//     }
//     queue->rear++;
//     queue->data[queue->rear] = person;
//     queue->size++;
// }

// int dequeue(Queue* queue) {
//     // Check if the queue is empty
//     if (queue->size == 0) {
//         return -1; 
//     }
//     int person = queue->data[queue->front];
//     queue->front++;
//     queue->size--;
//     return person;
// }

// int isQueueEmpty(Queue* queue) {
//     // Check if the queue is empty
//     return queue->size == 0;
// }

// Queue* createQueue() {
//     Queue* queue = (Queue*)malloc(sizeof(Queue));
//     if (queue == NULL) {
//         exit(EXIT_FAILURE);
//     }
//     initializeQueue(queue);
//     return queue;
// }

// void roundRobinDequeue(Queue** queues, int n) {
//     int allEmpty = 0;
//     // Continue dequeuing until all queues are empty
//     while (!allEmpty) {
//         allEmpty = 1;
//         for (int i = 0; i < n; i++) {
//             if (!isQueueEmpty(queues[i])) {
//                 int person = dequeue(queues[i]);
//                 printf("%d ", person);
//                 allEmpty = 0; 
//             }
//         }
//     }
//     printf("\n");
// }

// int main() {
//     int m, n;

//     // Read the total number of people and number of queues
//     scanf("%d", &m);
//     scanf("%d", &n);

//     // Read the people array
//     int* arr = (int*)malloc(m * sizeof(int));
//     for (int i = 0; i < m; ++i) {
//         scanf("%d", &arr[i]);
//     }

//     // Create and initialize queues
//     Queue** queues = (Queue**)malloc(n * sizeof(Queue*));
//     for (int i = 0; i < n; ++i) {
//         queues[i] = createQueue();
//     }

//     // Distribute people into queues in a block-wise manner
//     int index = 0;
//     int blockSize = (m + n - 1) / n;  // block size for each queue (ceiling of m/n)
    
//     for (int i = 0; i < m; ++i) {
//         enqueue(queues[index], arr[i]);
//         // Move to the next queue when the block for the current queue is full
//         if ((i + 1) % blockSize == 0 && index < n - 1) {
//             index++;
//         }
//     }

//     // Perform the round-robin dequeuing
//     roundRobinDequeue(queues, n);

//     // Free memory
//     free(arr);
//     for (int i = 0; i < n; ++i) {
//         free(queues[i]);
//     }
//     free(queues);

//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>

// #define MAX_QUEUE_SIZE 100

// typedef struct {
//     int data[MAX_QUEUE_SIZE];
//     int front;
//     int rear;
//     int size;
// } Queue;

// void initializeQueue(Queue* queue) {
//     // Initialize the queue
//     queue->front = 0;
//     queue->rear = -1;
//     queue->size = 0;
// }

// void enqueue(Queue* queue, int person) {
//     // Check if the queue is full
//     if (queue->size == MAX_QUEUE_SIZE) {
//         printf("queue is full\n");
//         return;
//     }
//     queue->rear++;
//     queue->data[queue->rear] = person;
//     queue->size++;
// }

// int dequeue(Queue* queue) {
//     // Check if the queue is empty
//     if (queue->size == 0) {
//         return -1; 
//     }
//     int person = queue->data[queue->front];
//     queue->front++;
//     queue->size--;
//     return person;
// }

// int isQueueEmpty(Queue* queue) {
//     // Check if the queue is empty
//     return queue->size == 0;
// }

// Queue* createQueue() {
//     Queue* queue = (Queue*)malloc(sizeof(Queue));
//     if (queue == NULL) {
//         exit(EXIT_FAILURE);
//     }
//     initializeQueue(queue);
//     return queue;
// }

// void roundRobinDequeue(Queue** queues, int n)
// {
//   int i = 0;
//   int x = 0;
//   while (1) {
//     if (isQueueEmpty(queues[i])) {
//       if (x == n)
//         break;
//       x++;
//       i = (i + 1) % n;
//       continue;
//     }

//     x = 0;
//     int p = dequeue(queues[i]);
//     printf("%d ", p);
//     i = (i + 1) % n;
//   }
// }

// int main() {
//     int m, n;

//     // Read the total number of people and number of queues
//     scanf("%d", &m);
//     scanf("%d", &n);

//     // Read the people array
//     int* arr = (int*)malloc(m * sizeof(int));
//     for (int i = 0; i < m; ++i) {
//         scanf("%d", &arr[i]);
//     }

//     // Create and initialize queues
//     Queue** queues = (Queue**)malloc(n * sizeof(Queue*));
//     for (int i = 0; i < n; ++i) {
//         queues[i] = createQueue();
//     }

//     // Distribute people into queues in a block-wise manner
//     int index = 0;
//     int blockSize = (m + n - 1) / n;  // block size for each queue (ceiling of m/n)
    
//     for (int i = 0; i < m; ++i) {
//         enqueue(queues[index], arr[i]);
//         // Move to the next queue when the block for the current queue is full
//         if ((i + 1) % blockSize == 0 && index < n - 1) {
//             index++;
//         }
//     }

//     // Perform the round-robin dequeuing
//     roundRobinDequeue(queues, n);

//     // Free memory
//     free(arr);
//     for (int i = 0; i < n; ++i) {
//         free(queues[i]);
//     }
//     free(queues);

//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #define MAX 10
// void enqueue(int *queue, int ele, int *f, int *r);
// int dequeue(int *queue, int *f, int *r);
// int timecount(int *q, int ticket_count, int counter_close, int person, int *f, int *r);
// int main()
// {
//     int r,f;
//     r=f=0;
// 	return 0;
// }

// void enqueue(int *queue, int ele, int *f, int *r){

// }

// int dequeue(int *queue, int *f, int *r){

// }

// int timecount(int *q, int ticket_count, int counter_close, int person, int *f, int *r){

// }

#include <stdio.h>
#include <stdlib.h>
#define MAX 10

void enqueue(int *queue, int ele, int *f, int *r);
int dequeue(int *queue, int *f, int *r);
int timecount(int *q, int ticket_count, int counter_close, int person, int num_customers, int *f, int *r);
int isFull(int *q, int f, int r);
int isEmpty(int f);

int main() {
    int ticket_count, counter_close, num, pos;
    int queue[MAX];
    int front = -1;
    int rear = -1;
    
    scanf("%d", &num);
    
    for (int i = 0; i < num; i++) {
        int x;
        scanf("%d", &x);
        enqueue(queue, x, &front, &rear);
    }
    
    scanf("%d", &ticket_count);
    scanf("%d", &counter_close);
    scanf("%d", &pos);
    
    int total_time = timecount(queue, ticket_count, counter_close, pos, num, &front, &rear);
    printf("%d", total_time);
    
    return 0;
}

int isFull(int *q, int f, int r) {
    return (r + 1) % MAX == f;  
}

int isEmpty(int f) {
    return f == -1;
}

void enqueue(int *queue, int ele, int *f, int *r) {
    if (isFull(queue, *f, *r)) {
        return;
    }
    if (isEmpty(*f)) {
        *f = 0;
        *r = 0;
    } else {
        *r = (*r + 1) % MAX;
    }
    queue[*r] = ele;
}

int dequeue(int *queue, int *f, int *r) {
    if (isEmpty(*f)) {
        return -1;
    }
    int ele = queue[*f];
    if (*f == *r) {
        *f = -1;
        *r = -1;
    } else {
        *f = (*f + 1) % MAX;
    }
    return ele;
}

int timecount(int *q, int ticket_count, int counter_close, int person, int num_customers, int *f, int *r) {
    int time = 0;
    int pos = 0;
    int tickets_processed = 0; 
    
    while (!isEmpty(*f)) {
        time++;  
        int ticket = dequeue(q, f, r);
        
        if (pos == person && ticket == 1) {
            return time; 
        }
        
        if (ticket > 1) {
            ticket--; 
            enqueue(q, ticket, f, r);  
        }
        
        pos = (pos + 1) % num_customers;  
        
        tickets_processed++;  
        if (tickets_processed % ticket_count == 0 && !isEmpty(*f)) {
            time += counter_close;  
        }
    }
    
    return time;
}